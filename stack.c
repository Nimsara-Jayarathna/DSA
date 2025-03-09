#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m;
    printf("Enter the size of the malloc : ");
    scanf("%d",  &m);
    int *pm = (int*)malloc(m * sizeof(int));
    if (pm == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("%llu", sizeof(pm));
}