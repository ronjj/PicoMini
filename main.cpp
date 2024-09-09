#include <iostream>
#include <cstdlib>
#include <string>
#define cimg_display 0
#include "CImg.h"
using namespace cimg_library;

void output_pixels(cimg_library::CImg<unsigned char> img)
{
    int w = img.width();
    int h = img.height();
    int c = img.spectrum();
    std::cout << "Dimensions: " << w << "x" << h << " " << c << " channels" << std::endl;

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            std::cout << "Pixel(" << x << "," << y << "): ";
            for (int channel = 0; channel < c; channel++)
            {
                std::cout << (int)img(x, y, 0, channel);
                if (channel < c - 1)
                    std::cout << ",";
            }
            std::cout << std::endl;
        }
    }
}
std::vector<std::vector<std::array<unsigned char, 3>>> read_pixels_as_matrix(const cimg_library::CImg<unsigned char> &img)
{
    int w = img.width();
    int h = img.height();
    int c = img.spectrum();

    // Initialize the 2D vector with the correct dimensions
    std::vector<std::vector<std::array<unsigned char, 3>>> matrix(h, std::vector<std::array<unsigned char, 3>>(w));

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            std::array<unsigned char, 3> pixel;
            for (int channel = 0; channel < 3; channel++)
            {
                // If the image has fewer than 3 channels, duplicate the last channel
                pixel[channel] = (channel < c) ? img(x, y, 0, channel) : pixel[channel - 1];
            }
            matrix[y][x] = pixel;
        }
    }

    return matrix;
}

void save_image(const cimg_library::CImg<unsigned char> &img, const std::string &output_path)
{
    try
    {
        img.save(output_path.c_str());
        std::cout << "Image successfully saved to: " << output_path << std::endl;
    }
    catch (cimg_library::CImgException &e)
    {
        std::cerr << "Error saving image: " << e.what() << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <path_to_image>" << std::endl;
        return 1;
    }

    std::string imagePath = argv[1];

    try
    {
        CImg<unsigned char> img(imagePath.c_str());
        read_pixels_as_matrix(img);
    }
    catch (CImgException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
