#include <stdio.h>
#include <math.h>
#include <string.h>

struct func_data {
    char name[30];
    double value;   // Stores log2 of the function value
};

int main() {

    double n;
    printf("Enter a large number (n > 1): ");
    scanf("%lf", &n);

    if (n <= 1) {
        printf("Please enter a value greater than 1.\n");
        return 0;
    }

    double logn = log2(n);

    struct func_data list[13];

    // 1/n
    strcpy(list[0].name, "1/n");
    list[0].value = -logn;     // log2(1/n)

    // log2(n)
    strcpy(list[1].name, "log2(n)"); // Store the time complexity name and its corresponding function
    list[1].value = logn;

    // 12*sqrt(n)
    strcpy(list[2].name, "12*sqrt(n)");
    list[2].value = log2(12) + 0.5 * logn;

    // 50*sqrt(n)
    strcpy(list[3].name, "50*sqrt(n)");
    list[3].value = log2(50) + 0.5 * logn;

    // n^0.51
    strcpy(list[4].name, "n^0.51");
    list[4].value = 0.51 * logn;

    // n
    strcpy(list[5].name, "n");
    list[5].value = logn;

    // n log2(n)
    strcpy(list[6].name, "n*log2(n)");
    list[6].value = logn + log2(logn);

    // n^2 - 324 (approximation for large n)
    strcpy(list[7].name, "n^2-324");
    list[7].value = 2 * logn;

    // 100n^2 + 6n (approximation for large n)
    strcpy(list[8].name, "100n^2+6n");
    list[8].value = log2(100) + 2 * logn;

    // 2n^3
    strcpy(list[9].name, "2n^3");
    list[9].value = log2(2) + 3 * logn;

    // n^(log2 n)
    strcpy(list[10].name, "n^(log2n)");
    list[10].value = logn * logn;

    // 3^n
    strcpy(list[11].name, "3^n");
    list[11].value = n * log2(3);

    // 2^(3n)
    strcpy(list[12].name, "2^(3n)");
    list[12].value = 3 * n;

    // Bubble Sort (Ascending Order)
    int i, j;
    struct func_data temp;

    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12 - i; j++) {
            if (list[j].value > list[j + 1].value) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    printf("\nOrder of Growth (Increasing), n = %.0lf\n\n", n);

    for (i = 0; i < 13; i++) {
        printf("%2d. %-15s\n", i + 1, list[i].name);
    }

    return 0;
}