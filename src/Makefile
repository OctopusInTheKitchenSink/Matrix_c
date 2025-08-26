CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11
CFLAGS = -lrt -lcheck -lpthread -lsubunit -lm
GCFLAGS = -lrt -lcheck -lpthread -lsubunit -lm -fprofile-arcs -ftest-coverage  

all: s21_matrix.a test gcov_report clean

s21_matrix.a: clean
	gcc -c s21_additional_functions.c -o s21_additional_functions.o
	gcc -c s21_create_matrix.c -o s21_create_matrix.o
	gcc -c s21_remove_matrix.c -o s21_remove_matrix.o
	gcc -c s21_eq_matrix.c -o s21_eq_matrix.o
	gcc -c s21_sum_matrix.c -o s21_sum_matrix.o
	gcc -c s21_sub_matrix.c -o s21_sub_matrix.o
	gcc -c s21_mult_number.c -o s21_mult_number.o
	gcc -c s21_mult_matrix.c -o s21_mult_matrix.o
	gcc -c s21_transpose.c -o s21_transpose.o
	gcc -c s21_calc_complements.c -o s21_calc_complements.o
	gcc -c s21_determinant.c -o s21_determinant.o
	gcc -c s21_inverse_matrix.c -o s21_inverse_matrix.o
	ar -crs s21_matrix.a *.o

test: clean
	@mkdir -p test
	@mkdir -p executable_file
	@checkmk clean_mode=1 checks/s21_eq_matrix.check > test/test_eq_matrix.c
	@checkmk clean_mode=1 checks/s21_sum_matrix.check > test/test_sum_matrix.c
	@checkmk clean_mode=1 checks/s21_sub_matrix.check > test/test_sub_matrix.c
	@checkmk clean_mode=1 checks/s21_mult_matrix.check > test/test_mult_matrix.c
	@checkmk clean_mode=1 checks/s21_mult_number.check > test/test_mult_number.c
	@checkmk clean_mode=1 checks/s21_transpose.check > test/test_transpose.c
	@checkmk clean_mode=1 checks/s21_calc_complements.check > test/test_calc_complements.c
	@checkmk clean_mode=1 checks/s21_determinant.check > test/test_determinant.c
	@checkmk clean_mode=1 checks/s21_inverse_matrix.check > test/test_inverse_matrix.c
	@checkmk clean_mode=1 checks/s21_create_matrix.check > test/test_create_matrix.c
	@$(CC) $(FLAGS) -o executable_file/test_eq_matrix test/test_eq_matrix.c *.c $(GCFLAGS)
	@$(CC) $(FLAGS) -o executable_file/test_sum_matrix test/test_sum_matrix.c *.c $(GCFLAGS)
	@$(CC) $(FLAGS) -o executable_file/test_sub_matrix test/test_sub_matrix.c *.c $(GCFLAGS)
	@$(CC) $(FLAGS) -o executable_file/test_mult_matrix test/test_mult_matrix.c *.c $(GCFLAGS)
	@$(CC) $(FLAGS) -o executable_file/test_mult_number test/test_mult_number.c *.c $(GCFLAGS)
	@$(CC) $(FLAGS) -o executable_file/test_transpose test/test_transpose.c *.c $(GCFLAGS)
	@$(CC) $(FLAGS) -o executable_file/test_calc_complements test/test_calc_complements.c *.c $(GCFLAGS)
	@$(CC) $(FLAGS) -o executable_file/test_determinant test/test_determinant.c *.c $(GCFLAGS)
	@$(CC) $(FLAGS) -o executable_file/test_inverse_matrix test/test_inverse_matrix.c *.c $(GCFLAGS)
	@$(CC) $(FLAGS) -o executable_file/test_create_matrix test/test_create_matrix.c *.c $(GCFLAGS)
	@./executable_file/test_eq_matrix
	@./executable_file/test_sum_matrix
	@./executable_file/test_sub_matrix
	@./executable_file/test_mult_matrix
	@./executable_file/test_mult_number
	@./executable_file/test_transpose
	@./executable_file/test_calc_complements
	@./executable_file/test_determinant
	@./executable_file/test_inverse_matrix
	@./executable_file/test_create_matrix

gcov_report: test
	gcov executable_file/*.gcno executable_file/*.gcda 
	find ./executable_file/ ! -name '*s21*' -type f -delete
	gcovr -r . --html --html-details -o coverage_report.html
	open coverage_report.html

clean:
	rm -rf *.o executable_file/* test/* *.out *.html *.css *.c.gcov *.a