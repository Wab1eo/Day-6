#include <stdio.h>
#define NMAX 10

void input (int *buffer, int *length, int *check);
void output (int *buffer, int *length, int *check, int summ);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);

int main()
{
    int a, data[NMAX], buffer;
    int check = 1;
    input(data,  &a, &check);
	int summ = 0;
    if (check == 1){
        summ = sum_numbers(data, a);
		a = find_numbers(data, a, summ, data);
    }
	printf("\n");
    output(data,  &a, &check, summ);
    return 0;
}


void input (int *buffer, int *length, int *check){
    if (scanf("%d", length) != 1 || getchar() != '\n'){
        *check = 0;
    }
    else if (*length > NMAX){
        *check = 0;
    }
    else {
        for(int *p = buffer; p - buffer < *length; p++)
        {
            if (scanf("%d", p) != 1) {
                *check = 0;
            }
        }
        if (getchar() != '\n'){
            *check = 0;
        }
    }
}

void output (int *buffer, int *length, int *check, int summ){
    if (*check == 1){
		printf("%d\n", summ);
        for (int *p = buffer; p - buffer < *length; p++) {
            printf("%d ", *p);
        }
        printf("\n");
    }
    else {
        printf("n/a\n");
    }
}

int sum_numbers(int *buffer, int length)
{
	int sum = 0;
	for (int d = 0; d < length; d++)
	{
		if (buffer[d] % 2 == 0)
		{
			sum = sum + buffer[d];
		}
	}
	return sum;
}

int find_numbers(int* buffer, int length, int number, int* numbers)
{
    int i = 0;
    for (int *j = buffer; j - buffer < length; j++) {
        if (*j != 0) {
            if (number % *j == 0) {
                numbers[i] = *j;
                i++;
            }
        }
    }
    return i;
}