#!/bin/bash

g++ -std=c++17 -o main main.cpp

if [ $? -eq 0 ]
then
    if [ $# -gt 0 ]
    then 
        ./main "$@"
        echo "The program has been successfully compiled and run."
    else
        echo "Incorrect number of arguments." 
    fi
else
    echo "Compilation failed. Check for compilation errors."
fi