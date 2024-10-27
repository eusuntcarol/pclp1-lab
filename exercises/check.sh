#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Usage: $0 <exercise_number>"
    exit 1
fi

if [ $1 -lt 1 ] || [ $1 -gt 6 ]
then
    echo "Invalid exercise number! Choose between 1 and 6."
    exit 1
fi

if [ ! -d "ex$1" ]
then
    echo "ex$1 directory not found! Check what you have downloaded. Tests are missing."
    exit 1
fi

if [ ! -f "ex$1.c" ]
then
    echo "ex$1.c not found!"
    exit 1
fi

make ex$1.out &> /dev/null || gcc -Wall -Wextra -Werror -o ex$1.out ex$1.c -lm &> /dev/null

ex_result=1

tests=0

if [ $1 -eq 1 ]
then
    tests=6
elif [ $1 -eq 2 ]
then
    tests=3
elif [ $1 -eq 3 ]
then
    tests=3
elif [ $1 -eq 4 ]
then
    tests=6
elif [ $1 -eq 5 ]
then
    tests=3
elif [ $1 -eq 6 ]
then
    tests=4
fi

for i in $(seq 1 "$tests")
do
    rm -rf "ex${1}/${i}_yours.out"
    ./ex$1.out < "ex${1}/${i}.in" > "ex${1}/${i}_yours.out"
    diff "ex${1}/${i}_yours.out" "ex${1}/${i}_ref.out"

    if [ $? -eq 0 ]
    then
        echo "[ex $1] TEST $i PASSED"
    else
        ex_result=0
        echo "[ex $1] TEST $i FAILED"
    fi
done

if [ $ex_result -eq 0 ]
then
    echo "[ex $1] Try again! Something's off with your output. 🫢"
    echo ""
    exit 1
else
    echo "[ex $1] Well done! All tests passed. 🎉"
    echo ""
    exit 0
fi
