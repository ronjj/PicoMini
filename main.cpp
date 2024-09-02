#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <unordered_map>
#include <functional>

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

CImg<unsigned char> grayscale(const CImg<unsigned char> &input)
{
    CImg<unsigned char> output = input;
    cimg_forXYC(output, x, y, c)
    {
        int r = input(x, y, 0, 0);
        int g = input(x, y, 0, 1);
        int b = input(x, y, 0, 2);

        int grayscale = (r + g + b) / 3;

        output(x, y, 0, 0) = grayscale;
        output(x, y, 0, 1) = grayscale;
        output(x, y, 0, 2) = grayscale;
    }
    return output;
}

CImg<unsigned char> padImage(const CImg<unsigned char> &input, int new_width, int new_height,
                             unsigned char r = 255, unsigned char g = 255, unsigned char b = 255)
{
    // If new dimensions are smaller than current, return the original image
    if (new_width <= input.width() && new_height <= input.height())
    {
        return input;
    }

    // Create a new image with the desired dimensions and color
    CImg<unsigned char> output(new_width, new_height, 1, input.spectrum());
    const unsigned char color[] = {r, g, b};
    output.draw_rectangle(0, 0, new_width - 1, new_height - 1, color);

    // Calculate offsets to center the original image
    int offset_x = (new_width - input.width()) / 2;
    int offset_y = (new_height - input.height()) / 2;

    // Copy the original image into the center of the new image
    output.draw_image(offset_x, offset_y, 0, 0, input);

    return output;
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

void printHelp()
{
    std::cout << "Photo Editor Usage:" << std::endl;
    std::cout << "./picomini <image_path> <command1> [<command2> ...] [-o output_filename] [-d output_directory]" << std::endl;
    std::cout << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -h, --help     Display this help message" << std::endl;
    std::cout << "  -o <filename>  Specify the output filename (default: output.jpg)" << std::endl;
    std::cout << "  -d <directory> Specify the output directory (default: current directory)" << std::endl;
    std::cout << std::endl;
    std::cout << "Available Commands:" << std::endl;
    std::cout << "  rotate90" << std::endl;
    std::cout << "    Rotate the image 90 degrees clockwise" << std::endl;
    std::cout << std::endl;
    std::cout << "  rotate-90" << std::endl;
    std::cout << "    Rotate the image 90 degrees counter-clockwise" << std::endl;
    std::cout << std::endl;
    std::cout << "  mirrorx" << std::endl;
    std::cout << "    Mirror the image horizontally (flip about the x-axis)" << std::endl;
    std::cout << std::endl;
    std::cout << "  mirrory" << std::endl;
    std::cout << "    Mirror the image vertically (flip about the y-axis)" << std::endl;
    std::cout << std::endl;
    std::cout << "  blur <amount>" << std::endl;
    std::cout << "    Apply Gaussian blur to the image" << std::endl;
    std::cout << "    <amount>: Strength of the blur (sigma value), e.g., 2.5" << std::endl;
    std::cout << std::endl;
    std::cout << "  brightness <factor>" << std::endl;
    std::cout << "    Adjust the brightness of the image" << std::endl;
    std::cout << "    <factor>: Brightness factor, where:" << std::endl;
    std::cout << "              1.0 is no change" << std::endl;
    std::cout << "              >1.0 increases brightness" << std::endl;
    std::cout << "              <1.0 decreases brightness" << std::endl;
    std::cout << std::endl;
    std::cout << "  resize <width> [<height>]" << std::endl;
    std::cout << "    Resize the image" << std::endl;
    std::cout << "    <width>: New width in pixels" << std::endl;
    std::cout << "    <height>: New height in pixels (optional)" << std::endl;
    std::cout << "              If omitted, height will be calculated to maintain aspect ratio" << std::endl;
    std::cout << std::endl;
    std::cout << "  pad <width> <height> [<r> <g> <b>]" << std::endl;
    std::cout << "    Pad the image to specified dimensions" << std::endl;
    std::cout << "    <width>: New width in pixels" << std::endl;
    std::cout << "    <height>: New height in pixels" << std::endl;
    std::cout << "    <r> <g> <b>: Optional RGB values for padding color (0-255 for each)" << std::endl;
    std::cout << "                 Default is white (255 255 255) if not specified" << std::endl;
    std::cout << std::endl;
    std::cout << "Examples:" << std::endl;
    std::cout << "  ./picomini input.jpg rotate90 blur 2.5 -o rotated_blurred.jpg" << std::endl;
    std::cout << "  ./picomini input.jpg resize 800 brightness 1.2 -o resized_brighter.jpg" << std::endl;
    std::cout << "  ./picomini input.jpg pad 1000 1000 0 0 0 -o padded_black.jpg" << std::endl;
}

// Define a type for our command functions
using CommandFunction = std::function<void(CImg<unsigned char> &, const std::vector<std::string> &, size_t &)>;

int main(int argc, char *argv[])
{
    if (argc < 2 || std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")
    {
        printHelp();
        return 0;
    }

    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " <image_path> <command1> [<command2> ...] [-o output_filename] [-d output_directory]" << std::endl;
        std::cerr << "Use -h or --help for more information." << std::endl;
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

    // Define the command map
    std::unordered_map<std::string, CommandFunction> commandMap = {
        {"rotate90", [](CImg<unsigned char> &img, const std::vector<std::string> &, size_t &)
         {
             std::cout << "Rotating image 90 degrees clockwise" << std::endl;
             img = rotateClockwise90(img);
         }},
        {"rotate-90", [](CImg<unsigned char> &img, const std::vector<std::string> &, size_t &)
         {
             std::cout << "Rotating image 90 degrees counter clockwise" << std::endl;
             img = rotateCounterClockwise90(img);
         }},
        {"mirrorx", [](CImg<unsigned char> &img, const std::vector<std::string> &, size_t &)
         {
             std::cout << "Mirroring image about x axis" << std::endl;
             img = mirrorX(img);
         }},
        {"mirrory", [](CImg<unsigned char> &img, const std::vector<std::string> &, size_t &)
         {
             std::cout << "Mirroring image about y axis" << std::endl;
             img = mirrorY(img);
         }},
        {"grayscale", [](CImg<unsigned char> &img, const std::vector<std::string> &, size_t &)
         {
             std::cout << "Grayscaling image" << std::endl;
             img = grayscale(img);
         }},
        {"blur", [](CImg<unsigned char> &img, const std::vector<std::string> &commands, size_t &i)
         {
             if (i + 1 >= commands.size())
             {
                 std::cerr << "Blur command requires an amount" << std::endl;
                 return;
             }
             float sigma;
             std::istringstream iss(commands[++i]);
             if (!(iss >> sigma))
             {
                 std::cerr << "Invalid blur amount: " << commands[i] << std::endl;
                 return;
             }
             std::cout << "Blurring image with sigma " << sigma << std::endl;
             img = blur(img, sigma);
         }},
        {"brightness", [](CImg<unsigned char> &img, const std::vector<std::string> &commands, size_t &i)
         {
             if (i + 1 >= commands.size())
             {
                 std::cerr << "Brightness command requires a factor" << std::endl;
                 return;
             }
             float factor;
             std::istringstream iss(commands[++i]);
             if (!(iss >> factor))
             {
                 std::cerr << "Invalid brightness factor: " << commands[i] << std::endl;
                 return;
             }
             std::cout << "Adjusting brightness with factor " << factor << std::endl;
             img = adjustBrightness(img, factor);
         }},
        {"pad", [](CImg<unsigned char> &img, const std::vector<std::string> &commands, size_t &i)
         {
             if (i + 2 >= commands.size())
             {
                 std::cerr << "Pad command requires at least width and height" << std::endl;
                 return;
             }
             int new_width, new_height;
             unsigned char r = 255, g = 255, b = 255; // Default to white
             std::istringstream wss(commands[++i]);
             std::istringstream hss(commands[++i]);
             if (!(wss >> new_width) || !(hss >> new_height))
             {
                 std::cerr << "Invalid pad dimensions: " << commands[i - 1] << " " << commands[i] << std::endl;
                 return;
             }
             // Check if RGB values are provided
             if (i + 3 < commands.size())
             {
                 std::istringstream rss(commands[++i]);
                 std::istringstream gss(commands[++i]);
                 std::istringstream bss(commands[++i]);
                 int r_tmp, g_tmp, b_tmp;
                 if (rss >> r_tmp && gss >> g_tmp && bss >> b_tmp)
                 {
                     r = static_cast<unsigned char>(std::clamp(r_tmp, 0, 255));
                     g = static_cast<unsigned char>(std::clamp(g_tmp, 0, 255));
                     b = static_cast<unsigned char>(std::clamp(b_tmp, 0, 255));
                 }
                 else
                 {
                     std::cerr << "Invalid RGB values, using default white" << std::endl;
                     i -= 3; // Revert the index if RGB parsing failed
                 }
             }
             std::cout << "Padding image to " << new_width << "x" << new_height
                       << " with color RGB(" << static_cast<int>(r) << ","
                       << static_cast<int>(g) << "," << static_cast<int>(b) << ")" << std::endl;
             img = padImage(img, new_width, new_height, r, g, b);
         }},
        {"resize", [](CImg<unsigned char> &img, const std::vector<std::string> &commands, size_t &i)
         {
             if (i + 1 >= commands.size())
             {
                 std::cerr << "Resize command requires at least a width" << std::endl;
                 return;
             }
             int new_width, new_height = -1;
             std::istringstream iss(commands[++i]);
             if (!(iss >> new_width))
             {
                 std::cerr << "Invalid resize width: " << commands[i] << std::endl;
                 return;
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
         }}};

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
            auto it = commandMap.find(command);
            if (it != commandMap.end())
            {
                it->second(img, commands, i);
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
