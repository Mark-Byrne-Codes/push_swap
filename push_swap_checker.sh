#!/bin/bash

# Function to generate a random sequence of unique numbers
generate_random_numbers() {
    local count=$1
    shuf -i 1-1000000 -n "$count" | tr '\n' ' '
}

# Check if push_swap exists
if [ ! -f ./push_swap ]; then
    echo "Error: push_swap executable not found in the current directory."
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

    echo "Testing with $size random numbers for $ITERATIONS iterations..."

    for ((i = 1; i <= ITERATIONS; i++)); do
        # Generate random numbers
        RANDOM_NUMBERS=$(generate_random_numbers "$size")

        # Run push_swap and count the number of lines in the output
        OPERATION_COUNT=$(./push_swap "$RANDOM_NUMBERS" | wc -l)

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
    echo "Summary for $size numbers: $pass_count passes, $fail_count fails"
    echo
done

