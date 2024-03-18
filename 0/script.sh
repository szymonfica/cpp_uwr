#!/bin/bash

if [ ! -f "dane.txt" ]
then
    echo "File dane.txt does not exist."
    exit 1
fi

g++ -std=c++11 -o main main.cpp

if [ $? -eq 0 ]
then
    if [ $# == 3 ]
    then 
        ./main $1 $2 $3
        echo "The program has been successfully compiled and run"
    else
        echo "Incorrect number of arguments." 
    fi
     
else
    echo "Compilation failed. Check for compilation errors."
fi
