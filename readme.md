A C++ CLI photo editor

Ways to modify image:

- Rotate 90 degrees clockwise
- Rotate 90 degrees counter clockwise
- Mirror over x axis
- Mirror over y axis
- Blur

Users can pass in -o tag to give image custom filename

Example usage after building with CMake:
./picomini file/path.jpg rotate90 mirrory blur 20.0 -o example.jpg
