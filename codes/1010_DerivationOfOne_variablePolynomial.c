#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declaration
int displayResult(int* result, size_t resultLen, int* answer, size_t answerLen);

int main(int argc, char* argv[]){
    int received[2];
    int result[100];
    int answer[100];
    int len = 0;
    while (scanf("%d\t%d", &received[0], &received[1]) != EOF) {
        // read the content and answer
        len++;
        while (received[1] != 0){
            answer[len++] = received[0] * received[1];
            scanf("%d\t%d", &received[0], &received[1]);
        }
        // for (int i = 0; i < len; i++) scanf("%d", &received[i]);
        for (int i = 0; i < len; i++) scanf("%d", &answer[i]);

        // display the result and the answer
        int status = displayResult(answer, len, answer, len);
        if (status == 0) break;
        len = 0;
    }
    printf("All Passed\n");
    return 0;
}


// display the final result and correct answer
int displayResult(int* result, size_t resultLen, int* answer, size_t answerLen){
    int ok = 1;

    // display the result
    printf("Result:\n");
    for (int i = 0; i < resultLen; i++) printf("%d\t", result[i]);
    printf("\n");

    // display the answer
    printf("Answer:\n");
    for (int i = 0; i < answerLen; i++) {printf("%d\t", answer[i]); ok &= answer[i] == result[i]; }
    printf("\n");

    // judge the result
    const char *judgement[2] = {"Failed", "Correct"};
    printf("Status:\n");
    printf("%s\n", judgement[ok]);
    return ok;
}