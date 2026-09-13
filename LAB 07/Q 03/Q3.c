#include <stdio.h>
#include <math.h>

int move_count = 0;

// Standard 3-peg Hanoi recursive procedure
void hanoi_3peg(int n, char src, char dst, char aux) {
    if (n == 0) return;
    hanoi_3peg(n - 1, src, aux, dst);
    printf("Move disk %d from %c -> %c\n", n, src, dst);
    move_count++;
    hanoi_3peg(n - 1, aux, dst, src);
}

// Frame-Stewart 4-peg algorithm for Reve's Puzzle
void reves_4peg(int n, char src, char dst, char aux1, char aux2) {
    if (n == 0) return;
    if (n == 1) {
        printf("Move disk 1 from %c -> %c\n", src, dst);
        move_count++;
        return;
    }

    // Optimal k choice for Frame-Stewart strategy
    int k = n - (int)round(sqrt(2 * n + 1)) + 1;

    // Step 1: Move top k disks from src to aux1 using 4 pegs
    reves_4peg(k, src, aux1, dst, aux2);

    // Step 2: Move remaining (n-k) disks from src to dst using 3 pegs
    hanoi_3peg(n - k, src, dst, aux2);

    // Step 3: Move k disks from aux1 to dst using 4 pegs
    reves_4peg(k, aux1, dst, src, aux2);
}

int main() {
    int n;
    printf("=== Reve's Puzzle (4-Peg Hanoi) ===\n");
    printf("Enter number of disks (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of disks must be greater than 0.\n");
        return 1;
    }

    printf("\n--- Move Sequence ---\n");
    reves_4peg(n, 'A', 'B', 'C', 'D');
    printf("\nTotal moves executed: %d\n", move_count);

    return 0;
}