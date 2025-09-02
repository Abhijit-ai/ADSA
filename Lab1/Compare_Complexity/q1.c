#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double fun1(double a) { return a * (log(a) / log(2)); }
double fun2(double a) { return 12 * sqrt(a); }
double fun3(double a) { return 1.0 / a; }
double fun4(double a) { return pow(a, log(a) / log(2)); }
double fun5(double a) { return 100 * pow(a,2) + 6*a; }
double fun6(double a) { return pow(a, 0.51); }
double fun7(double a) { return pow(a,2) - 324; }
double fun8(double a) { return 50 * sqrt(a); }
double fun9(double a) { return 2 * pow(a,3); }
double fun10(double a) { return pow(3,a); }
double fun11(double a) { return ((double)pow(2,32)) * a; }
double fun12(double a) { return log(a) / log(2); }

int main() {
    FILE *gp = popen("gnuplot -persistent", "w");
    if (gp == NULL) {
        printf("Could not open gnuplot.\n");
        return 1;
    }

    
    fprintf(gp, "set title 'Comparison of Functions (Growth Rates)'\n");
    fprintf(gp, "set xlabel 'n'\n");
    fprintf(gp, "set ylabel 'f(n)'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set logscale y\n");   // important to compare all together
    fprintf(gp, "set key outside\n");

    // Tell gnuplot to expect 12 datasets
    fprintf(gp,
        "plot '-' with lines title 'n*log2(n)', "
        "'-' with lines title '12*sqrt(n)', "
        "'-' with lines title '1/n', "
        "'-' with lines title 'n^log2(n)', "
        "'-' with lines title '100*n^2+6n', "
        "'-' with lines title 'n^0.51', "
        "'-' with lines title 'n^2-324', "
        "'-' with lines title '50*sqrt(n)', "
        "'-' with lines title '2*n^3', "
        "'-' with lines title '3^n', "
        "'-' with lines title '(2^32)*n', "
        "'-' with lines title 'log2(n)'\n"
    );
    int maxn;
    printf("Enter the value of n\n");
    scanf("%d", &maxn);

    int *ptr = (int *)calloc(maxn, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d numbers:\n", maxn);
    for (int i = 0; i < maxn; i++)
        scanf("%d", &ptr[i]);

    printf("You entered:\n");
    for (int i = 0; i < maxn; i++)
        printf("%d ", ptr[i]);
    printf("\n\n");

    for (int n = 0; n < maxn; n++)
    {printf("n=%d %f\n", ptr[n], fun1(ptr[n]));
     printf("n=%d %f\n", ptr[n], fun2(ptr[n]));
     printf("n=%d %f\n", ptr[n], fun3(ptr[n]));
     printf("n=%d %f\n", ptr[n], fun4(ptr[n]));
     printf("n=%d %f\n", ptr[n], fun5(ptr[n]));
     printf("n=%d %f\n", ptr[n], fun6(ptr[n]));
     printf("n=%d %f\n", ptr[n], fun7(ptr[n]));
     printf("n=%d %f\n", ptr[n], fun8(ptr[n]));
     printf("n=%d %f\n", ptr[n], fun9(ptr[n]));
     printf("n=%d %f\n", ptr[n], fun10(ptr[n]));
     printf("n=%d %f\n", ptr[n], fun11(ptr[n]));
     printf("n=%d %f\n", ptr[n], fun12(ptr[n]));
     printf("\n\n\n");
    
    }

    
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun1(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun2(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun2(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun2(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun2(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun3(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun4(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun5(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun6(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun7(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun8(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun9(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun10(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun11(ptr[n]));} fprintf(gp, "e\n");
    for (int n = 0; n < maxn; n++) {fprintf(gp, "%d %f\n", ptr[n], fun12(ptr[n]));} fprintf(gp, "e\n");

    pclose(gp);
    return 0;
}
