#include <stdio.h>

int total_moves = 0;

void turn_off(int n);
void turn_on(int n);

void turn_off(int n) {
    if (n <= 0) return;
    if (n == 1) {
        printf("Move %d: Turn OFF switch 1\n", ++total_moves);
        return;
    }
    turn_off(n - 2);
    printf("Move %d: Turn OFF switch %d\n", ++total_moves, n);
    turn_on(n - 2);
    turn_off(n - 1);
}

void turn_on(int n) {
    if (n <= 0) return;
    if (n == 1) {
        printf("Move %d: Turn ON  switch 1\n", ++total_moves);
        return;
    }
    turn_on(n - 1);
    turn_off(n - 2);
    printf("Move %d: Turn ON  switch %d\n", ++total_moves, n);
    turn_on(n - 2);
}

int main() {
    int n;
    printf("=== Security Switches Puzzle ===\n");
    printf("Enter number of security switches (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("\nSequence of toggles to turn off all switches:\n");
    turn_off(n);
    printf("\nTotal operations taken: %d\n", total_moves);

    return 0;
}