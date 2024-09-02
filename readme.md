A C++ CLI photo editor

Photo Editor Usage:
./picomini <image_path> <command1> [<command2> ...] [-o output_filename] [-d output_directory]

Options:
-h, --help Display this help message
-o <filename> Specify the output filename (default: output.jpg)
-d <directory> Specify the output directory (default: current directory)

Available Commands:
rotate90
Rotate the image 90 degrees clockwise

rotate-90
Rotate the image 90 degrees counter-clockwise

mirrorx
Mirror the image horizontally (flip about the x-axis)

mirrory
Mirror the image vertically (flip about the y-axis)

blur <amount>
Apply Gaussian blur to the image
<amount>: Strength of the blur (sigma value), e.g., 2.5

brightness <factor>
Adjust the brightness of the image
<factor>: Brightness factor, where:
1.0 is no change >1.0 increases brightness
<1.0 decreases brightness

resize <width> [<height>]
Resize the image
<width>: New width in pixels
<height>: New height in pixels (optional)
If omitted, height will be calculated to maintain aspect ratio

pad <width> <height> [<r> <g> <b>]
Pad the image to specified dimensions
<width>: New width in pixels
<height>: New height in pixels
<r> <g> <b>: Optional RGB values for padding color (0-255 for each)
Default is white (255 255 255) if not specified

Examples:
./picomini input.jpg rotate90 blur 2.5 -o rotated_blurred.jpg
./picomini input.jpg resize 800 brightness 1.2 -o resized_brighter.jpg
./picomini input.jpg pad 1000 1000 0 0 0 -o padded_black.jpg
