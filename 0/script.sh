#!/bin/bash

if [ ! -f "dane.txt" ]; then
    echo "Plik dane.txt nie istnieje." > wyniki.txt
    exit 1
fi

g++ -std=c++11 -o main main.cpp

if [ $? -eq 0 ]; then
    ./main < dane.txt > wyniki.txt
    echo "Program został uruchomiony." >> wyniki.txt
else
    echo "Kompilacja nie powiodła się. Sprawdź błędy kompilacji." > wyniki.txt
fi
