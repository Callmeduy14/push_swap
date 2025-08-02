#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

# Config
CHECKER="./checker_Mac"  # Ganti dengan checker_linux jika perlu
PUSH_SWAP="./push_swap"
TEST_COUNT=100
SMALL_SIZE=100
LARGE_SIZE=500

# ------------------------------------------------------------------------------
# Helper Functions
# ------------------------------------------------------------------------------

print_header() {
    echo -e "\n${YELLOW}=== $1 ===${NC}"
}

run_test() {
    local name="$1"
    local command="$2"
    local condition="$3"

    echo -n "Testing $name... "
    if eval "$command" "$condition"; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}FAIL${NC}"
    fi
}

# ------------------------------------------------------------------------------
# Error Handling Tests
# ------------------------------------------------------------------------------

print_header "Error Handling"

run_test "Non-numeric Input" \
    "$PUSH_SWAP 1 2 three 4 2>&1 | grep -q 'Error'" \
    "|| echo -e '${RED}Expected Error message${NC}'"

run_test "Duplicate Numbers" \
    "$PUSH_SWAP 1 2 3 2 5 2>&1 | grep -q 'Error'" \
    "|| echo -e '${RED}Expected Error message${NC}'"

run_test "Empty Argument" \
    "$PUSH_SWAP '' 2>&1 | grep -q 'Error'" \
    "|| echo -e '${RED}Expected Error message${NC}'"

# ------------------------------------------------------------------------------
# Basic Functionality Tests
# ------------------------------------------------------------------------------

print_header "Basic Functionality"

run_test "Already Sorted (3 numbers)" \
    "$PUSH_SWAP 1 2 3 | wc -l | grep -q '^0$'" \
    "|| echo -e '${RED}Should return 0 operations${NC}'"

run_test "Sort 3 Numbers" \
    "$PUSH_SWAP 2 1 3 | $CHECKER 2 1 3 | grep -q 'OK'" \
    "|| echo -e '${RED}Failed to sort${NC}'"

run_test "Sort 5 Numbers" \
    "$PUSH_SWAP 1 5 2 4 3 | $CHECKER 1 5 2 4 3 | grep -q 'OK'" \
    "|| echo -e '${RED}Failed to sort${NC}'"

# ------------------------------------------------------------------------------
# Performance Tests
# ------------------------------------------------------------------------------

print_header "Performance Tests"

# Small stack (100 numbers)
total_ops_small=0
for i in $(seq 1 $TEST_COUNT); do
    ARG=$(ruby -e "puts (1..$SMALL_SIZE).to_a.shuffle.join(' ')")
    OPS=$($PUSH_SWAP $ARG | wc -l)
    total_ops_small=$((total_ops_small + OPS))

    # Verify sorting correctness
    $PUSH_SWAP $ARG | $CHECKER $ARG | grep -q "OK" || {
        echo -e "${RED}Failed to sort 100 numbers (Test $i)${NC}"
        exit 1
    }
done
avg_small=$((total_ops_small / TEST_COUNT))

# Large stack (500 numbers)
total_ops_large=0
for i in $(seq 1 20); do  # Fewer tests due to time
    ARG=$(ruby -e "puts (1..$LARGE_SIZE).to_a.shuffle.join(' ')")
    OPS=$($PUSH_SWAP $ARG | wc -l)
    total_ops_large=$((total_ops_large + OPS))

    $PUSH_SWAP $ARG | $CHECKER $ARG | grep -q "OK" || {
        echo -e "${RED}Failed to sort 500 numbers (Test $i)${NC}"
        exit 1
    }
done
avg_large=$((total_ops_large / 20))

# ------------------------------------------------------------------------------
# Results
# ------------------------------------------------------------------------------

print_header "Results"

echo -e "Small stack ($SMALL_SIZE numbers):"
echo -e "  Avg operations: $avg_small"
echo -e "  Target (5/5): <700 ${GREEN}${NC}"
echo -e "  Target (4/5): <1100"
echo -e "  Target (3/5): <1300"

echo -e "\nLarge stack ($LARGE_SIZE numbers):"
echo -e "  Avg operations: $avg_large"
echo -e "  Target (5/5): <5500 ${GREEN}${NC}"
echo -e "  Target (4/5): <7000"
echo -e "  Target (3/5): <8500"

# ------------------------------------------------------------------------------
# Bonus Checker Test
# ------------------------------------------------------------------------------

print_header "Bonus Checker Test"

echo "sa" > test_instructions
echo "pb" >> test_instructions
echo -n "Checker validation... "
$CHECKER 2 1 3 < test_instructions | grep -q "KO" && \
    echo -e "${GREEN}OK (Properly rejects wrong instructions)${NC}" || \
    echo -e "${RED}FAIL${NC}"
rm test_instructions
