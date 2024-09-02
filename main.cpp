#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <filesystem>

// Include CImg library
#include "CImg.h"
using namespace cimg_library;
namespace fs = std::filesystem;

// Function to check if a file exists
bool fileExists(const std::string &filePath)
{
    std::ifstream f(filePath.c_str());
    return f.good();
}

// Function to check if a directory is writable
bool isDirectoryWritable(const fs::path &dir)
{
    if (!fs::exists(dir) || !fs::is_directory(dir))
    {
        return false;
    }

    fs::path testFile = dir / "test_write_permission";
    try
    {
        std::ofstream file(testFile);
        if (file)
        {
            file.close();
            fs::remove(testFile);
            return true;
        }
    }
    catch (...)
    {
    }

    return false;
}

// Image processing functions
CImg<unsigned char> rotateClockwise90(const CImg<unsigned char> &input)
{
    return input.get_rotate(90);
}

CImg<unsigned char> rotateCounterClockwise90(const CImg<unsigned char> &input)
{
    return input.get_rotate(-90);
}

CImg<unsigned char> mirrorX(const CImg<unsigned char> &input)
{
    return input.get_mirror('x');
}

CImg<unsigned char> mirrorY(const CImg<unsigned char> &input)
{
    return input.get_mirror('y');
}

CImg<unsigned char> blur(const CImg<unsigned char> &input, float sigma)
{
    return input.get_blur(sigma);
}

CImg<unsigned char> resizeImage(const CImg<unsigned char> &input, int new_width, int new_height)
{
    // If new_height is -1, calculate it to maintain aspect ratio
    if (new_height == -1)
    {
        float aspect_ratio = static_cast<float>(input.height()) / input.width();
        new_height = static_cast<int>(new_width * aspect_ratio);
    }
    // If new_width is -1, calculate it to maintain aspect ratio
    else if (new_width == -1)
    {
        float aspect_ratio = static_cast<float>(input.width()) / input.height();
        new_width = static_cast<int>(new_height * aspect_ratio);
    }

    return input.get_resize(new_width, new_height, -100, -100, 5); // Using Mitchell interpolation (5)
}

// New function to adjust brightness
CImg<unsigned char> adjustBrightness(const CImg<unsigned char> &input, float factor)
{
    CImg<unsigned char> output = input;
    cimg_forXYC(output, x, y, c)
    {
        int newValue = std::min(255.0f, std::max(0.0f, input(x, y, c) * factor));
        output(x, y, c) = static_cast<unsigned char>(newValue);
    }
    return output;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " <image_path> <command1> [<command2> ...] [-o output_filename] [-d output_directory]" << std::endl;
        std::cerr << "Available commands: rotate90, rotate-90, mirrorx, mirrory, blur <amount>, brightness <factor>" << std::endl;
        return 1;
    }

    std::string imagePath = argv[1];
    std::vector<std::string> commands;
    fs::path outputFilename = "output.jpg";  // Default output filename
    fs::path outputDir = fs::current_path(); // Default to current directory

    // Parse commands and look for output filename and directory flags
    for (int i = 2; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg == "-o" && i + 1 < argc)
        {
            outputFilename = argv[++i];
        }
        else if (arg == "-d" && i + 1 < argc)
        {
            outputDir = argv[++i];
        }
        else
        {
            commands.push_back(arg);
        }
    }

    if (!fileExists(imagePath))
    {
        std::cerr << "Error: File does not exist: " << imagePath << std::endl;
        return 1;
    }

    // Validate output directory
    if (!isDirectoryWritable(outputDir))
    {
        std::cerr << "Warning: Specified output directory is not writable: " << outputDir << std::endl;
        std::cerr << "Defaulting to output in the current directory." << std::endl;
        outputDir = fs::current_path();
    }

    // Combine directory and filename
    fs::path outputPath = outputDir / outputFilename;

    try
    {
        // Load the image
        CImg<unsigned char> img(imagePath.c_str());
        std::cout << "Successfully read image: " << img.width() << "x" << img.height()
                  << " with " << img.spectrum() << " channels" << std::endl;

        // Process commands
        for (size_t i = 0; i < commands.size(); ++i)
        {
            const auto &command = commands[i];
            if (command == "rotate90")
            {
                std::cout << "Rotating image 90 degrees clockwise" << std::endl;
                img = rotateClockwise90(img);
            }
            else if (command == "rotate-90")
            {
                std::cout << "Rotating image 90 degrees counter clockwise" << std::endl;
                img = rotateCounterClockwise90(img);
            }
            else if (command == "mirrorx")
            {
                std::cout << "Mirroring image about x axis" << std::endl;
                img = mirrorX(img);
            }
            else if (command == "mirrory")
            {
                std::cout << "Mirroring image about y axis" << std::endl;
                img = mirrorY(img);
            }
            else if (command == "resize" && i + 1 < commands.size())
            {
                int new_width, new_height = -1;
                std::istringstream iss(commands[++i]);
                if (!(iss >> new_width))
                {
                    std::cerr << "Invalid resize width: " << commands[i] << std::endl;
                    continue;
                }
                if (i + 1 < commands.size())
                {
                    std::istringstream hss(commands[i + 1]);
                    if (hss >> new_height)
                    {
                        ++i; // Consume the height argument
                    }
                }
                std::cout << "Resizing image to " << new_width << "x" << (new_height == -1 ? "auto" : std::to_string(new_height)) << std::endl;
                img = resizeImage(img, new_width, new_height);
            }
            else if (command == "blur" && i + 1 < commands.size())
            {
                float sigma;
                std::istringstream iss(commands[++i]);
                if (!(iss >> sigma))
                {
                    std::cerr << "Invalid blur amount: " << commands[i] << std::endl;
                    continue;
                }
                std::cout << "Blurring image with sigma " << sigma << std::endl;
                img = blur(img, sigma);
            }
            else if (command == "brightness" && i + 1 < commands.size())
            {
                float factor;
                std::istringstream iss(commands[++i]);
                if (!(iss >> factor))
                {
                    std::cerr << "Invalid brightness factor: " << commands[i] << std::endl;
                    continue;
                }
                std::cout << "Adjusting brightness with factor " << factor << std::endl;
                img = adjustBrightness(img, factor);
            }
            else
            {
                std::cerr << "Unknown command: " << command << std::endl;
            }
        }

        // Save the processed image
        img.save(outputPath.string().c_str());
        std::cout << "Processed image saved to " << outputPath << std::endl;
    }
    catch (const CImgException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
