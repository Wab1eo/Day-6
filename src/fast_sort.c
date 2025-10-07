#include <stdio.h>
#define NMAX 10

int input(int *a, int *check);
void output(int *a, int *check);
void bubbleSort(int *a);
void insertionSort(int *a);

int main()
{
    int data[NMAX];
    int check = 1;
    input(data, &check);
    printf("\n");
    if (check == 1){
        bubbleSort(data);
    }
    output(data, &check);
    if (check == 1){
        bubbleSort(data);
    }
    output(data, &check);
    return 0;
}

int input(int *a, int *check)
{
    for(int *p = a; p - a < NMAX; p++)
    {
        if (scanf("%d", p) != 1) {
            *check = 0;
        }
    }
    if (getchar() != '\n'){
        *check = 0;
    }
    return *check;
}

void output(int *a, int *check)
{
    if (*check == 1){
        for (int *p = a; p - a < NMAX; p++) {
            printf("%d ", *p);
        }
        printf("\n");
    }
    else {
        printf("n/a\n");
    }
}

void bubbleSort(int *a)
{
    for (int *i = a; i < NMAX + a; i++) {
        for (int *j = a; j < NMAX + a - 1; j++) {
            if (*j > *(j + 1)) {
                int temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
            }
        }
    }
}

void insertionSort(int *a)
{
    for (int g = 1; g < NMAX; ++g) {
        int key = a[g];
        int h = g - 1;
        while (h >= 0 && a[h] > key) {
            a[h + 1] = a[h];
            h = h - 1;
        }
        a[h + 1] = key;
    }
}