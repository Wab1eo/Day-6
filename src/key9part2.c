#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void input (int *buff1, int *len1, int *buff2, int *len2, int *check);
void output (int *buff, int *len, int *check);
void move(int *buff, int n);

int main()
{
    int data1[LEN], data2[LEN], len1, len2;
    int check = 1;
    int result[LEN], result_length;
    input(data1, &len1, data2, &len2, &check);
    if (check == 1){
        sum(data1, len1, data2, len2, result, &result_length);
        output(result, &result_length, &check);
        sub(data1, len1, data2, len2, result, &result_length);
        output(result, &result_length, &check);
    }
    else {
        printf("n/a\n");
    }
    return 0;
}

void input (int *buff1, int *len1, int *buff2, int *len2, int *check){
    int *p = buff1 - 1;
    do {
        p++;
        if (scanf("%d", p) != 1 || *p > 9 || *p < 0){
            *check = 0;
        }
    }while (getchar() != '\n' && p - buff1 < LEN);
    *len1 = p - buff1 + 1;

    int *p2 = buff2 - 1;
    do {
        p2++;
        if (scanf("%d", p2) != 1 || *p2 > 9 || *p2< 0){
            *check = 0;
        }
    } while (getchar() != '\n' && p2 - buff2 < LEN);
    
    *len2 = p2 - buff2 + 1;
}

void output (int *buff, int *len, int *check){
    if (*check == 1){
        for (int *p = buff; p - buff < *len; p++) {
            printf("%d ", *p);
        }
        printf("\n");
    }
    else {
        printf("n/a\n");
    }
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length){
    int carry = 0;
    if (len1 > len2) {
        *result_length = len1 - 1;
        for(int j = len2 - 1; j >= 0; j--){
            int sum = buff1[j + (len1 - len2)] + buff2[j] + carry;
            if (sum > 9){
                result[*result_length] = sum - 10;
                carry = 1;
            }
            else {
                result[*result_length] = sum;
                carry = 0;
            }
            --*result_length;
        }
        for (int j = len1 - len2 - 1; j >= 0; j--) {
            result[*result_length] = buff1[j] + carry;
            --*result_length;
            carry = 0;
        }
        *result_length = len1;
        if (carry == 1){
            move(result, *result_length + 1);
            result[0] = carry;
            *result_length = len1 + 1;
        }
    }
    else {
        *result_length = len2 - 1;
        for(int j = len1 - 1; j >= 0; j--){
            int sum = buff1[j + (len2 - len1)] + buff2[j] + carry;
            if (sum > 9){
                result[*result_length] = sum - 10;
                carry = 1;
            }
            else {
                result[*result_length] = sum;
                carry = 0;
            }
            --*result_length;
        }
        for (int j = len2 - len1 - 1; j >= 0; j--) {
            result[*result_length] = buff1[j] + carry;
            --*result_length;
            carry = 0;
        }
        *result_length = len2;
        if (carry == 1){
            move(result, *result_length + 1);
            result[0] = carry;
            *result_length = len2 + 1;
        }
    }
}

void move(int *buff, int a) {
    int tmp = buff[0];
    int tmp1 = 0;
    for (int *p = buff + 1; p - buff < a; p++) {
        tmp1 = *p;
        *p = tmp;
        tmp = tmp1;
    }
}


void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length){
    int carry = 0;
    *result_length = len1 - 1;
    for(int j = len2 - 1; j >= 0; j--){
        int sum = buff1[j + (len1 - len2)] - buff2[j] - carry;
        if (sum < 0){
            result[*result_length] = sum + 10;
            carry = 1;
        }
        else {
            result[*result_length] = sum;
            carry = 0;
        }
        --*result_length;
    }
    for (int j = len1 - len2 - 1; j >= 0; j--) {
        result[*result_length] = buff1[j] - carry;
        --*result_length;
        carry = 0;
    }
    *result_length = len1;
    if (carry == 1){
        move(result, *result_length + 1);
        result[0] = carry;
        *result_length = len1 + 1;
    }
}