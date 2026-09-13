#include <stdio.h>
#include <limits.h>

void print_optimal_parens(int s[][100], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrix_chain_order(int p[], int n) {
    int m[100][100] = {0};
    int s[100][100] = {0};

    // L is chain length
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nMinimum Scalar Multiplications: %d\n", m[1][n]);
    printf("Optimal Parenthesization: ");
    print_optimal_parens(s, 1, n);
    printf("\n");
}

int main() {
    int n;
    printf("=== Matrix Chain Multiplication (MCM) ===\n");
    printf("Enter number of matrices (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of matrices must be positive.\n");
        return 1;
    }

    int p[n + 1];
    printf("Enter %d dimensions (p_0 to p_%d): ", n + 1, n);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    matrix_chain_order(p, n);

    return 0;
}