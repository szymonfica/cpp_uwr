#!/bin/bash

if [ ! -f "dane.txt" ]
then
    echo "Plik dane.txt nie istnieje."
    exit 1
fi

g++ -std=c++11 -o main main.cpp

if [ $? -eq 0 ]
then
    if [ $# == 3 ]
    then 
        ./main $1 $2 $3
        echo "Program został uruchomiony."
    else
        echo "Nieprawidłowa ilość argumentów." 
    fi
     
else
    echo "Kompilacja nie powiodła się. Sprawdź błędy kompilacji."
fi
