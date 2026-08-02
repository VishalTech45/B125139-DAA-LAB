#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i;
    int heads = 0;
    double probability;
    double r;

    srand(time(NULL));

    printf("Enter number of tosses: ");
    scanf("%d", &n);

    // Fair Coin
    heads = 0;

    for(i = 0; i < n; i++)
    {
        r = (double)rand() / RAND_MAX;

        if(r < 0.5)
        {
            heads++;
        }
    }

    probability = (double)heads / n;

    printf("\n----- Fair Coin -----\n");
    printf("Heads = %d\n", heads);
    printf("Probability of Head = %.4f\n", probability);

    // Biased Coin (70% Head)
    heads = 0;

    for(i = 0; i < n; i++)
    {
        r = (double)rand() / RAND_MAX;

        if(r < 0.7)
        {
            heads++;
        }
    }

    probability = (double)heads / n;

    printf("\n----- Biased Coin (70%% Head) -----\n");
    printf("Heads = %d\n", heads);
    printf("Probability of Head = %.4f\n", probability);

    return 0;
}