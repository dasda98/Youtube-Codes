#include <stdio.h>
#include <stdlib.h>


int main() {

    // Size of array
    unsigned int N = 10;

    // Alloacte memory
    int* array = calloc(N, sizeof(int));

    // Check allocation
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Add some data
    for (int i=0; i<N; i++) {
        array[i] = i;
    }

    // Print data
    for (int i=0; i<N; i++) {
        printf("%d ", array[i]);
    }
    putchar('\n');

    // Increase array size
    N += 5;

    // Reallocate memory
    int* tmp_array = realloc(array, sizeof(int) * N);

    // Check reallocation
    if (tmp_array == NULL) {
        fprintf(stderr, "Memory reallocation failed!\n");
        free(array);
        array = NULL;

        return 1;
    }

    array = tmp_array;

    // Add extra data
    for (int i=N-5; i<N; i++) {
        array[i] = i;
    }

    // Print data
    for (int i=0; i<N; i++) {
        printf("%d ", array[i]);
    }

    // Free memory
    free(array);
    array = NULL;

    return 0;
}