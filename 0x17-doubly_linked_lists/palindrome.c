#include <stdio.h>

int isPalindrome(int num) {
    int original = num;
    int reversed = 0;

    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return original == reversed;
}

int main() {
    int largestPalindrome = 0;

    for (int i = 100; i < 1000; ++i) {
        for (int j = 100; j < 1000; ++j) {
            int product = i * j;

            if (isPalindrome(product) && product > largestPalindrome) {
                largestPalindrome = product;
            }
        }
    }

    printf("%d\n", largestPalindrome);

    FILE *file = fopen("102-result", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "%d\n", largestPalindrome);
    fclose(file);

    return 0;
}
