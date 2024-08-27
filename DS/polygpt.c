#include <stdio.h>

void read_poly(int a[2][10], int n) {
    int i;
    printf("Enter the polynomial \n");
    for (i = 0; i < n; i++) {
        printf("Enter the co-efficient and exponent of the %d term", i + 1);
        scanf("%d%d", &a[0][i], &a[1][i]);
    }
}


int main() {
    int p1[2][10], p2[2][10], sum[2][10], t1, t2, q;

    printf("Enter the terms of the first polynomial\n");
    scanf("%d", &t1);
    read_poly(p1, t1);

    printf("Enter the terms of the second polynomial\n");
    scanf("%d", &t2);
    read_poly(p2, t2);

    printf("The first polynomial \n");
    for (q = 0; q < t1; q++) {
        printf("%dX^%d+", p1[0][q], p1[1][q]);
    }

    printf("\nThe second polynomial \n");
    for (q = 0; q < t2; q++) {
        printf("%dX^%d+", p2[0][q], p2[1][q]);
    }

    return 0;
}
