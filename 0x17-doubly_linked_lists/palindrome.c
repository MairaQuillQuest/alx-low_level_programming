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

    for (int i = 999; i >= 100; --i) {
        for (int j = i; j >= 100; --j) {
            int product = i * j;
            if (product <= largestPalindrome) {
                break;  // Since we're going in descending order, no need to check further
            }
            if (isPalindrome(product) && product > largestPalindrome) {
                largestPalindrome = product;
            }
        }
    }

    printf("%d", largestPalindrome);

    FILE *file = fopen("102-result", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "%d", largestPalindrome);
    fclose(file);

    return 0;
}
