#include <stdio.h>
#include <math.h>
#include <string.h>

struct func_data {
    char name[30];
    double value;   // storing log2 of actual value (numbers are too big otherwise)
};

int main() {

    double n;
    printf("Enter a large number: ") ;
    scanf("%lf",&n) ;

    double logn = log2(n);

    struct func_data list[13];


    strcpy(list[0].name, "1");
    list[0].value = 0;

    strcpy(list[1].name, "log2n");
    list[1].value = log2(logn);

    strcpy(list[2].name, "12*sqrt(n)");
    list[2].value = log2(12) + 0.5 * logn;

    strcpy(list[3].name, "50*sqrt(n)");
    list[3].value = log2(50) + 0.5 * logn;

    strcpy(list[4].name, "n^0.51");
    list[4].value = 0.51 * logn;

    strcpy(list[5].name, "n");
    list[5].value = logn;

    strcpy(list[6].name, "n*log2n");
    list[6].value = logn + log2(logn);

    strcpy(list[7].name, "n^2-324");
    list[7].value = 2 * logn;

    strcpy(list[8].name, "100n^2+6n");
    list[8].value = log2(100) + 2 * logn;

    strcpy(list[9].name, "2n^3");
    list[9].value = log2(2) + 3 * logn;

    strcpy(list[10].name, "n^(log2n)");
    list[10].value = logn * logn;

    strcpy(list[11].name, "3^n");
    list[11].value = n * log2(3);

    strcpy(list[12].name, "2^(3n)");
    list[12].value = 3 * n;

    // simple bubble sort based on value (ascending)
    int i, j;
    struct func_data temp;
    for (i = 0; i < 13 - 1; i++) {
        for (j = 0; j < 13 - i - 1; j++) {
            if (list[j].value > list[j + 1].value) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    printf("Order of growth (increasing), n = %.0lf:\n\n", n);
    for (i = 0; i < 13; i++) {
        printf("%d. %s\n", i + 1, list[i].name);
    }

    return 0;
}