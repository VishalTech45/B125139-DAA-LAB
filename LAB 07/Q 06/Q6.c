#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
    int type; // -1 for death, +1 for birth
} Event;

// Comparator for qsort
int compare_events(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;

    if (e1->year != e2->year) {
        return e1->year - e2->year; // Sort by year ascending
    }
    return e1->type - e2->type; // Death (-1) comes before Birth (+1)
}

int main() {
    int n;
    printf("=== The Best Time to be Alive ===\n");
    printf("Enter number of scientists: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of scientists must be positive.\n");
        return 1;
    }

    Event events[2 * n];
    for (int i = 0; i < n; i++) {
        int birth, death;
        printf("Scientist %d (Birth Year Death Year): ", i + 1);
        scanf("%d %d", &birth, &death);

        events[2 * i]     = (Event){birth, 1};  // Birth event
        events[2 * i + 1] = (Event){death, -1}; // Death event
    }

    // Sort timeline events
    qsort(events, 2 * n, sizeof(Event), compare_events);

    int current_alive = 0, max_alive = 0, best_year = 0;

    for (int i = 0; i < 2 * n; i++) {
        current_alive += events[i].type;
        if (current_alive > max_alive) {
            max_alive = current_alive;
            best_year = events[i].year;
        }
    }

    printf("\n--- Results ---\n");
    printf("Peak year with most scientists alive: %d\n", best_year);
    printf("Maximum scientists alive concurrently: %d\n", max_alive);

    return 0;
}