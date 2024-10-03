#!/bin/bash

g++ -std=c++17 classes.cpp main.cpp -o main -lm

if [ $? -eq 0 ]
    then
        ./main
        echo "The program has been successfully compiled and run."
    else
        echo "Compilation failed. Check for compilation errors."
fi