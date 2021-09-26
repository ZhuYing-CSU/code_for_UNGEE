#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declaration
int solver(int *received, int len, int *A1, int *A2, int *A3, float *A4, int *A5);
int displayResult(int A1, int A2, int A3, float A4, int A5, int ansA1, int ansA2, int ansA3, float ansA4, int ansA5);

int main(int argc, char* argv[]){
    int received[1000];
    int A1, A2, A3, A5, ansA1, ansA2, ansA3, ansA5;
    float A4, ansA4;
    int len;
    while (scanf("%d", &len) != EOF) {
        // read the content and answer
        for (int i = 0; i < len; i++) scanf("%d", &received[i]);
        scanf("%d", &ansA1);
        scanf("%d", &ansA2);
        scanf("%d", &ansA3);
        scanf("%f", &ansA4);
        scanf("%d", &ansA5);

        solver(received, len, &A1, &A2, &A3, &A4, &A5);

        // display the result and the answer
        int status = displayResult(A1, A2, A3, A4, A5, ansA1, ansA2, ansA3, ansA4, ansA5);
        if (status == 0) return 1;
    }
    printf("All Passed\n");
    return 0;
}

int solver(int *received, int len, int *A1, int *A2, int *A3, float *A4, int *A5) {
    // A1
    *A1 = 0;
    for (int i = 0; i < len; i++) {
        if (received[i] % 10 != 0) continue;
        *A1 += received[i];
    }

    // A2
    *A2 = 0;
    int addSign = 1;
    for (int i = 0; i < len; i++) {
        if (received[i] % 5 != 1) continue;
        *A2 += received[i] * addSign;
        addSign *= -1;
    }

    // A3
    *A3 = 0;
    for (int i = 0; i < len; i++) {
        if (received[i] % 5 != 2) continue;
        (*A3)+=1;
    }

    // A4
    *A4 = 0;
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (received[i] % 5 != 3) continue;
        *A4 += received[i];
        cnt++;
    }
    if (cnt != 0) *A4 /= cnt;

    // A5
    *A5 = 0;
    for (int i = 0; i < len; i++) {
        if (received[i] % 5 != 4) continue;
        if (received[i] > *A5) *A5 = received[i];
    }

    return 1;
}

// display the final result and correct answer
int displayResult(int A1, int A2, int A3, float A4, int A5, int ansA1, int ansA2, int ansA3, float ansA4, int ansA5){
    int ok = 1;

    // display the result
    printf("Result:\n");
    printf("%d\t", A1);
    printf("%d\t", A2);
    printf("%d\t", A3);
    printf("%.1f\t", A4);
    printf("%d", A5);
    printf("\n");

    // display the answer
    printf("Answer:\n");
    printf("%d\t", ansA1); ok &= A1 == ansA1;
    printf("%d\t", ansA2); ok &= A2 == ansA2;
    printf("%d\t", ansA3); ok &= A3 == ansA3;
    printf("%.1f\t", ansA4); ok &= abs(A4 - ansA4) < 1e-1;
    printf("%d", ansA5); ok &= A5 == ansA5;
    printf("\n");

    // judge the result
    const char *judgement[2] = {"Failed", "Correct"};
    printf("Status:\n");
    printf("%s\n\n", judgement[ok]);
    return ok;
}