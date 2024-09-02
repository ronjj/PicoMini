#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <sstream>

// Include CImg library
#include "CImg.h"
using namespace cimg_library;

// Function to check if a file exists
bool fileExists(const std::string &filePath)
{
    std::ifstream f(filePath.c_str());
    return f.good();
}

// Function to rotate image 90 degrees clockwise
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

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " <image_path> <command1> [<command2> ...] [-o output_filename]" << std::endl;
        std::cerr << "Available commands: rotate90, rotate-90, mirrorx, mirrory, blur <amount>" << std::endl;
        return 1;
    }

    std::string imagePath = argv[1];
    std::vector<std::string> commands;
    std::string outputPath = "output.jpg"; // Default output filename

    // Parse commands and look for output filename flag
    for (int i = 2; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg == "-o" && i + 1 < argc)
        {
            outputPath = argv[++i];
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
            else
            {
                std::cerr << "Unknown command: " << command << std::endl;
            }
        }

        // Save the processed image
        img.save(outputPath.c_str());
        std::cout << "Processed image saved to " << outputPath << std::endl;
    }
    catch (const CImgException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
