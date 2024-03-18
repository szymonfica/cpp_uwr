#!/bin/bash


g++ -std=c++17 structs.cpp point.cpp segment.cpp triangle.cpp main.cpp -o main

if [ $? -eq 0 ]
    then
        ./main
    else
        echo "Kompilacja nie powiodła się. Sprawdź błędy kompilacji."
fi

