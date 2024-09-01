# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/Users/ronaldjabouin/Documents/picominimain/build/_deps/cimg-src")
  file(MAKE_DIRECTORY "/Users/ronaldjabouin/Documents/picominimain/build/_deps/cimg-src")
endif()
file(MAKE_DIRECTORY
  "/Users/ronaldjabouin/Documents/picominimain/build/_deps/cimg-build"
  "/Users/ronaldjabouin/Documents/picominimain/build/_deps/cimg-subbuild/cimg-populate-prefix"
  "/Users/ronaldjabouin/Documents/picominimain/build/_deps/cimg-subbuild/cimg-populate-prefix/tmp"
  "/Users/ronaldjabouin/Documents/picominimain/build/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp"
  "/Users/ronaldjabouin/Documents/picominimain/build/_deps/cimg-subbuild/cimg-populate-prefix/src"
  "/Users/ronaldjabouin/Documents/picominimain/build/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/ronaldjabouin/Documents/picominimain/build/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/ronaldjabouin/Documents/picominimain/build/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
