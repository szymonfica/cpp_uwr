#!/bin/bash

g++ -std=c++17 color.cpp color_transparent.cpp color_named.cpp color_tn.cpp pixel.cpp pixel_colored.cpp main.cpp -o main -lm

if [ $? -eq 0 ]
    then
        ./main
        echo "The program has been successfully compiled and run."
    else
        echo "Compilation failed. Check for compilation errors."
fi