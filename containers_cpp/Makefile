PP=g++
FLAGS=-Wall -Wextra -Werror -std=c++17 -Wpedantic
all: clean test
clean:
	@clear
	@rm -rf *.[og]* COVERAGE* test_* test
test:
	@echo "==========================="
	@echo "The program is being tested\n==========="
	@echo "Please wait\n==========="
	@$(PP) $(FLAGS) -o test test.cpp -lgtest -lgtest_main --coverage
	@chmod +x test
	@./test
coverage:
	gcovr -r . --html-details -o COVERAGE
	rm -rf COVERAGE.t* COVERAGE.su*
rebuild: all
format:
	@clang-format -i *.cpp *.h -style=Google
cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.cpp *.h
valgrind:
	valgrind --tool=memcheck --leak-check=yes ./test_*
test_array:
	@echo "==========================="
	@echo "The program is being tested\n==========="
	@echo "Please wait\n==========="
	@echo "\nARRAY:"
	@$(PP) $(FLAGS) -o test_array testing_array.cpp -lgtest -lgtest_main --coverage
	@chmod +x test_array
	@./test_array
test_list:
	@echo "\nLIST:"
	@$(PP) $(FLAGS) -o test_list testing_list.cpp -lgtest -lgtest_main --coverage
	@chmod +x test_list
	@./test_list
test_map:
	@echo "\nMAP:"
	@$(PP) $(FLAGS) -o test_map testing_map.cpp -lgtest -lgtest_main --coverage
	@chmod +x test_map
	@./test_map
test_multiset:
	@echo "\nMULTISET:"
	@$(PP) $(FLAGS) -o test_multiset testing_multiset.cpp -lgtest -lgtest_main --coverage
	@chmod +x test_multiset
	@./test_multiset
test_queue:
	@echo "\nLIST:"
	@$(PP) $(FLAGS) -o test_queue testing_queue.cpp -lgtest -lgtest_main --coverage
	@chmod +x test_queue
	@./test_queue
test_set:
	@echo "\nMAP:"
	@$(PP) $(FLAGS) -o test_set testing_set.cpp -lgtest -lgtest_main --coverage
	@chmod +x test_set
	@./test_set
test_stack:
	@echo "\nMULTISET:"
	@$(PP) $(FLAGS) -o test_stack testing_stack.cpp -lgtest -lgtest_main --coverage
	@chmod +x test_stack
	@./test_stack
test_vector:
	@echo "\nMULTISET:"
	@$(PP) $(FLAGS) -o test_vector testing_vector.cpp -lgtest -lgtest_main --coverage
	@chmod +x test_vector
	@./test_vector
all_test: test_array test_list test_map test_multiset test_queue test_set test_stack test_vector
