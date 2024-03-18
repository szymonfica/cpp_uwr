#!/bin/bash

g++ -std=c++17 -o main main.cpp

if [ $? -eq 0 ]
then
    echo -n > wyniki.txt
    for i in "$@"; do
        ./main $i >> wyniki.txt
    done

    echo "The program has been successfully compiled and run."
else
    echo "Compilation failed. Check for compilation errors."
fi
