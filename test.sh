# chmod +x test.sh

MIN_RANGE=-500000
MAX_RANGE=500000
TOTAL_NUMBERS=100
THRESHOLD=700
NUM_CASES=250
all_cases=()
count=0
max_moves=-1
total_moves=0
run_first_portion=true

echo  "\033[0;32m\nChecker:\n\033[0m"

for ((i=0; i<$NUM_CASES; i++)); do
    ARG=$(ruby -e "puts ($MIN_RANGE..$MAX_RANGE).to_a.shuffle[0..$((TOTAL_NUMBERS-1))].join(' ')")
    result=$(./push_swap $ARG | ./checker_Mac $ARG)
    if [ "$result" != "OK" ]; then
        all_cases+=("$ARG")
        echo "\033[0;31m$(printf "%02d" $((i+1))): $result\033[0m"
    else
        echo "$(printf "%02d" $((i+1))): $result"
    fi
done

echo  "\033[0;32m\nMOVES:\n\033[0m"

while [ $count -lt $NUM_CASES ]; do
    ARG=$(ruby -e "puts ($MIN_RANGE..$MAX_RANGE).to_a.shuffle[0..$((TOTAL_NUMBERS-1))].join(' ')")
    movess=$(./push_swap $ARG | wc -l)
    all_cases+=("$ARG $movess")
    
    if [ $movess -gt $max_moves ]; then
        max_moves=$movess
    fi
    
    if [ $movess -gt $THRESHOLD ]; then
        echo "\033[0;31m$(printf "%02d" $((count+1))): $movess\033[0m"
        red_cases+=("$ARG")
    else
        echo "$(printf "%02d" $((count+1))): $movess"
    fi
    ((count++))
done

for item in "${all_cases[@]}"; do
    total_moves=$((total_moves + ${item##* }))
done


average_moves=$(bc <<< "scale=0; ($total_moves + $NUM_CASES - 1) / $NUM_CASES")

if [ $max_moves -gt $THRESHOLD ] || [ $average_moves -gt $THRESHOLD ]; then
    echo "\033[0;31m\nMax Moves: $max_moves\nAverage Moves: $average_moves\n\033[0m"
else
    echo "\033[1;34m\nMax Moves: $max_moves\nAverage Moves: $average_moves\n\033[0m"
fi

printf "%s\n" "${all_cases[@]}" > numbers.txt