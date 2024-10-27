done_exercises=0
all_exercises=6

make

for i in $(seq 1 $all_exercises)
do
    ./check.sh $i

    if [ $? -eq 0 ]
    then
        done_exercises=$((done_exercises+1))
    fi
done

make clean

echo ""

if [ $done_exercises -eq $all_exercises ]
then
    echo "🚀 😎 Programmer of the year! $done_exercises/$all_exercises exercises GG 😎 🚀"
    echo "https://youtu.be/MW8xhcqnUtg?si=2adzbZ6VCm5ORwlC"
    exit 0
else
    echo "Almost there! Keep going! ${done_exercises}/6 exercises completed. 🏃"
    exit 1
fi
