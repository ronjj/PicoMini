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

cimg_library::CImg<unsigned char> make_image_white(const cimg_library::CImg<unsigned char> &img)
{
    auto pixel_matrix = read_pixels_as_matrix(img);
    auto height = pixel_matrix.size();
    auto width = pixel_matrix[0].size();

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixel_matrix[y][x][0] = 255;
            pixel_matrix[y][x][1] = 255;
            pixel_matrix[y][x][2] = 255;
        }
    }

    // Create a new CImg object with the same dimensions as the original
    cimg_library::CImg<unsigned char> result(width, height, 1, 3);

    // Copy the edited matrix data back to the CImg object
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            for (int c = 0; c < 3; c++)
            {
                result(x, y, 0, c) = pixel_matrix[y][x][c];
            }
        }
    }

    return result;
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
        auto white_img = make_image_white(img);
        save_image(white_img, "/Users/ronaldjabouin/Desktop/output.jpg");
    }
    catch (CImgException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
