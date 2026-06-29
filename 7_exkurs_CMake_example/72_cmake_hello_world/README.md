# Tasks to Compile the Program Using CMake (Command Line)

## Create a build directory  

    mkdir build
    cd build

## Generate build files with CMake

    cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..

Note: The `-G "MinGW Makefiles"` option specifies the generator for MinGW. Adjust this if you're using a different compiler or IDE. `-DCMAKE_BUILD_TYPE=Debug` is optional and can be set to `Release` for an optimized build.

## Build the project

    cmake --build .

## Run the executable  

    .\hello_world.exe

Note: The executable name may vary based on your CMake configuration. Check the `CMakeLists.txt` for the exact target name.
