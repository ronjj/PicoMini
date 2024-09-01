#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <fstream>

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

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " <image_path> <command1> [<command2> ...]" << std::endl;
        return 1;
    }

    std::string imagePath = argv[1];
    std::vector<std::string> commands(argv + 2, argv + argc);

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
        for (const auto &command : commands)
        {
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

            else
            {
                std::cerr << "Unknown command: " << command << std::endl;
            }
        }

        // Save the processed image
        std::string outputPath = "output.jpg";
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
