#include <stdio.h>
#define NMAX 10

int input(int *linput, int *check, int *length, int *moving);
void output(int *linput, int *check, int *length);
void sort(int *linput, int moving, int a);

int main()
{
    int a, data[NMAX], moving;
    int check = 1;
    input(data, &check, &a, &moving);
    if (check == 1){
        sort(data, moving, a);
    }
    output(data, &check, &a);

    return 0;
}

int input(int *linput, int *check, int *length, int *moving)
{
    if (scanf("%d", length) != 1 || getchar() != '\n'){
        *check = 0;
    }
    else if (*length > NMAX){
        *check = 0;
    }
    else {
        for(int *p = linput; p - linput < *length; p++)
        {
            if (scanf("%d", p) != 1) {
                *check = 0;
            }
        }
        if (getchar() != '\n'){
            *check = 0;
        }
        if (scanf("%d", moving) != 1 && getchar() != '\n'){
            *check = 0;
        }
    }
}

void output(int *linput, int *check, int *length)
{
    if (*check == 1){
        for (int *p = linput; p - linput < *length; p++) {
            printf("%d ", *p);
        }
        printf("\n");
    }
    else {
        printf("n/a\n");
    }
}

void sort(int *linput, int moving, int a)
{
    if (moving > 0){
        for (int j = 0; j < moving; j++){
            int first = linput[0];
            for (int d = 0; d < a - 1; d++){
                linput[d] = linput[d + 1];
            }
            linput[a - 1] = first;
        }
    }
    else if (moving < 0){
        for (int j = 0; j < -moving; j++){
            int last = linput[a - 1];
            for (int d = a - 1; d > 0; d--){
                linput[d] = linput[d - 1];
            }
            linput[0] = last;
        }
    }
}