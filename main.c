#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    printf("How many passes do you want me to perform? : \n");
    scanf("%d", &n);

    time_t start = time(NULL);

    for (int j = 0; j < n; j++) {
        printf("Pass %d\n", j + 1);

        // Allocate an array of 1,000,000 integers
        int* A = (int*)malloc(1000000 * sizeof(int));
        if (A == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        // Fill the array with random numbers
        for (int i = 0; i < 1000000; i++) {
            A[i] = rand() % 1000000;
        }

        // Sort the array
        qsort(A, 1000000, sizeof(int), compare);

        // Free the allocated memory
        free(A);
    }

    time_t end = time(NULL);
    double elapsed_time = difftime(end, start);

    printf("%f seconds\n", elapsed_time);

    return 0;
}
