#!/bin/bash

rozwiazania() {
a=$1
b=$2
c=$3

delta=$((b*b-4*a*c))

if [ $delta -gt 0 ]; then
    x1=$(echo "scale=6; (-$b + sqrt($delta)) / (2*$a)" | bc)
    x2=$(echo "scale=6; (-$b - sqrt($delta)) / (2*$a)" | bc)
    echo "x1 = $x1, x2 = $x2"
elif [ $delta -eq 0 ]; then
    x=$(echo "scale=6; (-$b) / (2*$a)" | bc)
    echo "x = $x"
else
    echo "x nalezy do zbioru pustego"
fi
}

echo "a*x^2 + b*x + c = 0"
echo "a: "
read a

if [[ "$a" =~ ^[+-]?[0-9]+$ ]]; then
	echo "b: "
    read b
    if [[ "$b" =~ ^[+-]?[0-9]+$ ]]; then
        echo "c: "
        read c
        if [[ "$c" =~ ^[+-]?[0-9]+$ ]]; then
            if [ $a -ne 0 ]; then
                rozwiazania "$a" "$b" "$c"
            elif [ $b -ne 0 ]; then
                x=$(echo "scale=6; (-1*$c) / ($b)" | bc)
                echo "x = $x"
            elif [ $c -eq 0 ]; then
                echo "x jest dowolna liczba rzeczywista"
            else
                echo "x nalezy do zbioru pustego"
            fi

        else
            echo "Blad, podaj liczbe!"
        fi
    else
        echo "Blad, podaj liczbe!"
    fi
else
	echo "Blad, podaj liczbe"
fi