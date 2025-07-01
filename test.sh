#!/bin/bash
# Create dir for tests
mkdir ./tests/

rm valgrind.txt
touch valgrind.txt

# Test errors
touch ./tests/errors.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap 2>> valgrind.txt | wc -l >> ./tests/errors.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap 1 1 2>> valgrind.txt | wc -l >> ./tests/errors.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap 30000000000000000000 1 2 3 2>> valgrind.txt | wc -l >> ./tests/errors.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap 1.2 3 2>> valgrind.txt | wc -l >> ./tests/errors.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap 1 one 2 2>> valgrind.txt | wc -l >> ./tests/errors.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap one 2>> valgrind.txt | wc -l >> ./tests/errors.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap -30000000000000000000 1 2 3 2>> valgrind.txt | wc -l >> ./tests/errors.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap 1 2 3 4 5 1 2>> valgrind.txt | wc -l >> ./tests/errors.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap -2147483648 4 5 6 -2147483648 2>> valgrind.txt | wc -l >> ./tests/errors.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap -2147483649 4 5 6 -2147483648 2>> valgrind.txt | wc -l >> ./tests/errors.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap 4 5 6 2147483647 2147483647 2>> valgrind.txt | wc -l >> ./tests/errors.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap 4 5 6 2147483648 2>> valgrind.txt | wc -l >> ./tests/errors.txt

# Test with extreme numbers
touch ./tests/extreme_numbers.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap 1 -2147483648 4 5 6 2>> valgrind.txt | wc -l >> ./tests/extreme_numbers.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap 8 -2147483648 4 5 7 6 2147483647 2>> valgrind.txt | wc -l >> ./tests/extreme_numbers.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap 4 5 6 2147483647 1 3 2 2>> valgrind.txt | wc -l >> ./tests/extreme_numbers.txt

# Test with a numbers that are already ordered
touch ./tests/longstring.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap "1 one 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77" 2>> valgrind.txt | wc -l >> ./tests/longstring.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap "1 1.5 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77" 2>> valgrind.txt | wc -l >> ./tests/longstring.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap "-1 1 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77" 2>> valgrind.txt | wc -l >> ./tests/longstring.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap "1 1 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77" 2>> valgrind.txt | wc -l >> ./tests/longstring.txt

# Test with a numbers that are already ordered
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77" 2>> valgrind.txt | wc -l > ./tests/output_orderedsh.txt
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap 1 2 3 4 5 6 7 8 2>> valgrind.txt | wc -l > ./tests/output_orderedsh.txt

# Test with 3 numbers
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap $(shuf -i 1-2147483647 -n 3 | tr '\n' ' ') 2>> valgrind.txt | wc -l > ./tests/output_3shA.txt


for i in {1..30}; do
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap $(shuf -i 1-2147483647 -n 3 | tr '\n' ' ') 2>> valgrind.txt | wc -l >> ./tests/output_3shA.txt
done

echo ""
echo "Results from test A with 3"
cat ./tests/output_3shA.txt

# Test A with 4 numbers
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap $(shuf -i 1-2147483647 -n 4 | tr '\n' ' ') 2>> valgrind.txt | wc -l > ./tests/output_4shA.txt

for i in {1..30}; do
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap $(shuf -i 1-2147483647 -n 4 | tr '\n' ' ') 2>> valgrind.txt | wc -l >> ./tests/output_4shA.txt
done

echo ""
echo "Results from test with 4"
cat ./tests/output_4shA.txt

# Test A with 5 numbers
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap $(shuf -i 1-2147483647 -n 5 | tr '\n' ' ') 2>> valgrind.txt | wc -l > ./tests/output_5shA.txt

for i in {1..30}; do
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap $(shuf -i 1-2147483647 -n 5 | tr '\n' ' ') 2>> valgrind.txt | wc -l >> ./tests/output_5shA.txt
done

echo ""
echo "Results from test with 5"
cat ./tests/output_5shA.txt

# Test 1 with 100 numbers
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap $(shuf -i 1-2147483647 -n 100 | tr '\n' ' ') 2>> valgrind.txt | wc -l > ./tests/output_100sh1.txt

for i in {1..20}; do
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap $(shuf -i 1-2147483647 -n 100 | tr '\n' ' ') 2>> valgrind.txt | wc -l >> ./tests/output_100sh1.txt
done

echo "Results from test with 100"
cat ./tests/output_100sh1.txt

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap $(shuf -i 1-2147483647 -n 500 | tr '\n' ' ') 2>> valgrind.txt | wc -l > ./tests/output_500sh4.txt
# Test 4 with 500 numbers
for i in {1..15}; do

	# Generate input
	input=$(shuf -i 1-2147483647 -n 500 | tr '\n' ' ')

	# Run push_swap and count lines
	result=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap $input 2>> valgrind.txt | wc -l)
	result_fail=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/push_swap $input 2>> valgrind.txt | wc -l)

	echo "$i"
	# Output based on result
	if [ "$result" -gt 5500 ]; then
		echo "$result_fail" >> ./tests/output_500sh4.txt
	else
		echo "$result" >> ./tests/output_500sh4.txt
	fi
done

echo ""
echo "Results from test 4 with 500"
cat ./tests/output_500sh4.txt
