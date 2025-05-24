# Create dir for tests
mkdir ./tests/

# Test with 3 numbers
./bin/push_swap $(shuf -i 1-2147483647 -n 3 | tr '\n' ' ') | wc -l > ./tests/output_3shA.txt

for i in {1..30}; do
./bin/push_swap $(shuf -i 1-2147483647 -n 3 | tr '\n' ' ') | wc -l >> ./tests/output_3shA.txt
done

echo ""
echo "Results from test A with 3"
cat ./tests/output_3shA.txt

# Test A with 4 numbers
./bin/push_swap $(shuf -i 1-2147483647 -n 4 | tr '\n' ' ') | wc -l > ./tests/output_4shA.txt

for i in {1..30}; do
./bin/push_swap $(shuf -i 1-2147483647 -n 4 | tr '\n' ' ') | wc -l >> ./tests/output_4shA.txt
done

echo ""
echo "Results from test with 4"
cat ./tests/output_4shA.txt

# Test A with 5 numbers
./bin/push_swap $(shuf -i 1-2147483647 -n 5 | tr '\n' ' ') | wc -l > ./tests/output_5shA.txt

for i in {1..30}; do
./bin/push_swap $(shuf -i 1-2147483647 -n 5 | tr '\n' ' ') | wc -l >> ./tests/output_5shA.txt
done

echo ""
echo "Results from test with 5"
cat ./tests/output_5shA.txt

# Test 1 with 100 numbers
./bin/push_swap $(shuf -i 1-2147483647 -n 100 | tr '\n' ' ') | wc -l > ./tests/output_100sh1.txt

for i in {1..30}; do
	./bin/push_swap $(shuf -i 1-2147483647 -n 100 | tr '\n' ' ') | wc -l >> ./tests/output_100sh1.txt
done

echo "Results from test with 100"
cat ./tests/output_100sh1.txt

./bin/push_swap $(shuf -i 1-2147483647 -n 500 | tr '\n' ' ') | wc -l > ./tests/output_500sh4.txt
# Test 4 with 500 numbers
for i in {1..300}; do

	# Generate input
	input=$(shuf -i 1-2147483647 -n 500 | tr '\n' ' ')

	# Run push_swap and count lines
	result=$(./bin/push_swap $input | wc -l)
	result_fail=$(./bin/push_swap $input | wc -l)

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
