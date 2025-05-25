#include <stdio.h>
#include <stdlib.h>
int check_sum_28(int a, int b, int c, int d) {
    return (a + b + c + d == 28);
}

int main(int ac, char  **av) {
    int num1 = atoi(av[1]), num2 = atoi(av[2]), num3 = atoi(av[3]), num4 = atoi(av[4]);

    if (check_sum_28(num1, num2, num3, num4)) {
        printf("The sum of %d, %d, %d, and %d is 28.\n", num1, num2, num3, num4);
    } else {
        printf("The sum is not 28.\n");
    }

    return 0;
}
