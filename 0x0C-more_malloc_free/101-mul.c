#include <stdio.h>
#include <stdlib.h>

/* Function to multiply two positive numbers */
int multiply(int num1, int num2) {
    return num1 * num2;
}

/* Function to check if a string contains only digits */
int isNumeric(const char *str) {
	while (*str) {
		if (*str < '0' || *str > '9') {
			return 0; // Not a digit
		}
		str++;
	}
	return 1; // All characters are digits
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Error\n");
		return 98;
	}

	if (!isNumeric(argv[1]) || !isNumeric(argv[2])) {
		printf("Error\n");
		return 98;
	}

	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);

	int result = multiply(num1, num2);
	printf("%d\n", result);

	return 0;
}
