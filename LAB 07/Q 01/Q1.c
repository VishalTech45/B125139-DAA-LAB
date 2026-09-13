#include <stdio.h>

int main() {
    int n;

    printf("=== Coin-Triangle Inversion ===\n");
    printf("Enter side length (number of rows/n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input! Side length must be a positive integer.\n");
        return 1;
    }

    // Formula calculation
    long long total_coins = (long long)n * (n + 1) / 2;
    long long min_moves = (long long)n * (n + 2) / 6;

    printf("\n--- Results ---\n");
    printf("Total coins in triangle: %lld\n", total_coins);
    printf("Minimum moves required : %lld\n", min_moves);

    return 0;
}