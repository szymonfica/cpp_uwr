#!/bin/bash

g++ -std=c++11 -o main main.cpp

if [ $? -eq 0 ]; then
    ./main 7 13 27 > wyniki.txt
    echo "Program został uruchomiony." >> wyniki.txt
else
    echo "Kompilacja nie powiodła się. Sprawdź błędy kompilacji." >> wyniki.txt
fi
