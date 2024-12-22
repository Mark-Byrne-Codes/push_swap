#!/bin/bash

# Function to generate a random sequence of unique numbers
generate_random_numbers() {
    local count=$1
    shuf -i 1-1000000 -n "$count" | tr '\n' ' '
}

# Check if push_swap and checker_linux exist
if [ ! -f ./push_swap ]; then
    echo "Error: push_swap executable not found in the current directory."
    exit 1
fi

if [ ! -f ./checker_linux ]; then
    echo "Error: checker_linux executable not found in the current directory."
    exit 1
fi

# Number of elements to test and their corresponding operation limits
TEST_SIZES=(100 500)
OPERATION_LIMITS=(700 5500)

# Number of iterations
ITERATIONS=10

# Loop through test sizes
for index in "${!TEST_SIZES[@]}"; do
    size=${TEST_SIZES[index]}
    limit=${OPERATION_LIMITS[index]}
    pass_count=0
    fail_count=0
    checker_fail_count=0

    echo "Testing with $size random numbers for $ITERATIONS iterations..."

    for ((i = 1; i <= ITERATIONS; i++)); do
        # Generate random numbers
        RANDOM_NUMBERS=$(generate_random_numbers "$size")

        # Run push_swap and count the number of lines in the output
        OPERATIONS=$(./push_swap $RANDOM_NUMBERS)
        OPERATION_COUNT=$(echo "$OPERATIONS" | wc -l)

        # Validate using the checker
        CHECKER_RESULT=$(echo "$OPERATIONS" | ./checker_linux $RANDOM_NUMBERS)

        # Check correctness
        if [ "$CHECKER_RESULT" != "OK" ]; then
            echo "FAIL ($i/$ITERATIONS): Checker failed for $size numbers. Result: $CHECKER_RESULT"
            ((checker_fail_count++))
            continue
        fi

        # Check if the number of operations meets the requirement
        if [ "$OPERATION_COUNT" -le "$limit" ]; then
            echo "PASS ($i/$ITERATIONS): $size numbers sorted in $OPERATION_COUNT operations (Limit: $limit)"
            ((pass_count++))
        else
            echo "FAIL ($i/$ITERATIONS): $size numbers sorted in $OPERATION_COUNT operations (Limit: $limit)"
            ((fail_count++))
        fi
    done

    # Summary for this test size
    echo "Summary for $size numbers: $pass_count passes, $fail_count fails, $checker_fail_count checker failures"
    echo
done

