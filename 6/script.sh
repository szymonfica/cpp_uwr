#!/bin/bash

g++ -std=c++17 polynomial.cpp main.cpp -o main

if [ $? -eq 0 ]
    then
        ./main
        echo "The program has been successfully compiled and run."
    else
        echo "Compilation failed. Check for compilation errors."
fi