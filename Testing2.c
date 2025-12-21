#include <stdio.h>
#include <stdlib.h>

static int read_size(int *n);
static int read_array(int n, int **arr);
static void square_array(int n, int *arr);
static void print_array(int n, int *arr);

int main(void) {
    int n = 0;
    int *arr = NULL;

    if (!read_size(&n)) {
        printf("n/a");
        return 0;
    }
    if (!read_array(n, &arr)) {
        printf("n/a");
        return 0;
    }

    square_array(n, arr);
    print_array(n, arr);

    free(arr);
    return 0;
}

static int read_size(int *n) {
    if (!n) return 0;
    if (scanf("%d", n) != 1) return 0;
    if (*n <= 0) return 0;
    return 1;
}

static int read_array(int n, int **arr) {
    if (n <= 0 || !arr) return 0;
    *arr = (int *)malloc(sizeof(int) * n);
    if (!*arr) return 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &((*arr)[i])) != 1) {
            free(*arr);
            *arr = NULL;
            return 0;
        }
    }
    return 1;
}

static void square_array(int n, int *arr) {
    for (int i = 0; i < n; i++) {
        long long v = arr[i];
        arr[i] = (int)(v * v);  // при переполнении стандартного int поведение зависит от реализации
    }
}

static void print_array(int n, int *arr) {
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}
