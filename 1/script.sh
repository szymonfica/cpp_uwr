#!/bin/bash

g++ -std=c++11 -o main main.cpp

if [ $? -eq 0 ]
then
    echo -n > wyniki.txt
    for i in "$@"; do
        ./main $i >> wyniki.txt
    done

    echo "Program został uruchomiony."
else
    echo "Kompilacja nie powiodła się. Sprawdź błędy kompilacji."
fi
