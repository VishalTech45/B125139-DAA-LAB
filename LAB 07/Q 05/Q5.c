#include <stdio.h>

void solve_target(int n) {
    if (n <= 1) {
        printf("No strategy needed/possible for n <= 1.\n");
        return;
    }
    if (n == 2) {
        printf("Shooting sequence: Spot 1, Spot 1\n");
        printf("Total shots: 2\n");
        return;
    }

    printf("\nGuaranteed Shooting Strategy (Total %d shots):\n", 2 * (n - 2));
    int shot = 1;

    // Pass 1: Sweep left-to-right (catches target if initially on EVEN spot)
    printf("Pass 1 (Catch Even positions): ");
    for (int i = 2; i <= n - 1; i++) {
        printf("%d ", i);
    }

    // Pass 2: Sweep left-to-right again (catches target if initially on ODD spot)
    printf("\nPass 2 (Catch Odd positions) : ");
    for (int i = 2; i <= n - 1; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int n;
    printf("=== Hitting a Moving Target ===\n");
    printf("Enter number of hiding spots (n > 1): ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Number of spots must be greater than 1.\n");
        return 1;
    }

    solve_target(n);
    return 0;
}