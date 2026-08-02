#include <stdio.h>
#include <stdlib.h>
 
#include <math.h>

int main() {


    int trials = 1000000;
    int heads = 0;
    int i;
    double p_hat, se, margin;

    // ---- Fair coin ----
    heads = 0;
    for (i = 0; i < trials; i++) {
        double r = (double)rand() / RAND_MAX;
        if (r < 0.5) {
            heads = heads + 1;
        }
    }

    p_hat = (double)heads / trials;
    se = sqrt(p_hat * (1 - p_hat) / trials);   // standard error of proportion
    margin = 1.96 * se;                        // 95% confidence, z = 1.96

    printf("--- Fair coin (p = 0.5) ---\n");
    printf("Total tosses: %d\n", trials);
    printf("Heads count: %d\n", heads);
    printf("Observed P(Heads) = %.4f\n", p_hat);
    printf("95%% CI: [%.4f, %.4f]\n\n", p_hat - margin, p_hat + margin);

    // ---- Biased coins ----
    printf("--- Biased coins ---\n");

    double bias1 = 0.3;
    double bias2 = 0.7;
    double bias3 = 0.9;

    // coin 1
    heads = 0;
    for (i = 0; i < trials; i++) {
        double r = (double)rand() / RAND_MAX;
        if (r < bias1) {
            heads = heads + 1;
        }
    }
    p_hat = (double)heads / trials;
    se = sqrt(p_hat * (1 - p_hat) / trials);
    margin = 1.96 * se;
    printf("True p = %.2f -> Observed = %.4f  CI: [%.4f, %.4f]\n", bias1, p_hat, p_hat - margin, p_hat + margin);

    // coin 2
    heads = 0;
    for (i = 0; i < trials; i++) {
        double r = (double)rand() / RAND_MAX;
        if (r < bias2) {
            heads = heads + 1;
        }
    }
    p_hat = (double)heads / trials;
    se = sqrt(p_hat * (1 - p_hat) / trials);
    margin = 1.96 * se;
    printf("True p = %.2f -> Observed = %.4f  CI: [%.4f, %.4f]\n", bias2, p_hat, p_hat - margin, p_hat + margin);

    // coin 3
    heads = 0;
    for (i = 0; i < trials; i++) {
        double r = (double)rand() / RAND_MAX;
        if (r < bias3) {
            heads = heads + 1;
        }
    }
    p_hat = (double)heads / trials;
    se = sqrt(p_hat * (1 - p_hat) / trials);
    margin = 1.96 * se;
    printf("True p = %.2f -> Observed = %.4f  CI: [%.4f, %.4f]\n", bias3, p_hat, p_hat - margin, p_hat + margin);

    return 0;
}