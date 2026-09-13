#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int solve_egg_drop(int eggs, int floors) {
    int dp[eggs + 1][floors + 1];

    // Base cases
    for (int i = 1; i <= eggs; i++) {
        dp[i][0] = 0; // 0 floors = 0 drops
        dp[i][1] = 1; // 1 floor = 1 drop
    }
    for (int j = 1; j <= floors; j++) {
        dp[1][j] = j; // 1 egg = linear search
    }

    // Fill DP table
    for (int e = 2; e <= eggs; e++) {
        for (int f = 2; f <= floors; f++) {
            int min_drops = 1e9;
            for (int k = 1; k <= f; k++) {
                int worst_case = 1 + MAX(dp[e - 1][k - 1], dp[e][f - k]);
                if (worst_case < min_drops) {
                    min_drops = worst_case;
                }
            }
            dp[e][f] = min_drops;
        }
    }

    return dp[eggs][floors];
}

int main() {
    int eggs, floors;

    printf("=== Super Egg Testing Experiment ===\n");
    printf("Enter number of eggs (E): ");
    scanf("%d", &eggs);
    printf("Enter number of floors (F): ");
    scanf("%d", &floors);

    if (eggs <= 0 || floors <= 0) {
        printf("Invalid input! Eggs and floors must be positive.\n");
        return 1;
    }

    int result = solve_egg_drop(eggs, floors);
    printf("\nMinimum drops required in worst-case: %d\n", result);

    return 0;
}