GCC=gcc -x c++ -lstdc++
GFLAGS=-Wall -Wextra -Werror -std=c++17
SOURCE=cpp_files/*
all: clean format s21_matrix_oop.a test coverage
clean:
	@echo cleaning
	@rm -rf [uogre]* *.a
test:
#sudo apt-get install libgtest-dev
	@echo testing
	@$(GCC) $(GFLAGS) -c test.cpp
	@$(GCC) $(GFLAGS) -c $(SOURCE) --coverage
	@g++ $(GFLAGS) -o unit_test *.o --coverage -lgtest -lgtest_main
	@mkdir o_files 
	@mv *.o o_files
	@chmod a+x unit_test
	@./unit_test
s21_matrix_oop.a:
	@echo archiving
	@$(GCC) $(GFLAGS) -c $(SOURCE)
	@ar src s21_matrix_oop.a *.o
rebuild: all
coverage:
	@echo covering
	@lcov -o report.info -c -d . --no-external --rc lcov_branch_coverage=1 -q
	@genhtml -o report report.info --rc lcov_branch_coverage=1 | grep :
	@mkdir g_files
	@mv *.gcda *.gcno g_files
	@mv report.info report
	@cp report/index.html e_OPEN_ME_I_AM_REPORT.html
	@sed -i 's/src="/src="report\//g' e_OPEN_ME_I_AM_REPORT.html
	@sed -i 's/href="index/href="report\/index/g' e_OPEN_ME_I_AM_REPORT.html
	@sed -i 's/gcov.css/report\/gcov.css/g' e_OPEN_ME_I_AM_REPORT.html
	@sed -i 's/"cpp/"report\/cpp/g' e_OPEN_ME_I_AM_REPORT.html
format:
	@echo formating
	@cp ../materials/linters/.clang-format .clang-format
	@clang-format -i *.h *.cpp cpp_files/*
	@rm -rf .clang-format
