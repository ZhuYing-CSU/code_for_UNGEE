#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declaration
int displayResult(char* result, size_t resultLen, char* answer, size_t answerLen);

int main(int argc, char* argv[]){
    char* received;
    char* answer;
    size_t len = 0;
    size_t receivedLen;
    size_t answerLen;
    while ((receivedLen = getline(&received, &len, stdin)) != -1) {
        // read the content and answer
        len=0;
        answerLen = getline(&answer, &len, stdin);

        // display the result and the answer
        int status = displayResult(received, receivedLen, answer, answerLen);
        if (status == 0) return 1;
    }
    printf("All Passed\n");
    return 0;
}

// display the final result and correct answer
int displayResult(char* result, size_t resultLen, char* answer, size_t answerLen){
    int ok = strcmp(result, answer) == 0;

    // display the result
    printf("Result:\n");
    for (int i = 0; i < resultLen; i++) printf("%c", result[i]);
    printf("\n");

    // display the answer
    printf("Answer:\n");
    for (int i = 0; i < answerLen; i++) printf("%c", answer[i]);
    printf("\n");

    // judge the result
    const char *judgement[2] = {"Failed", "Correct"};
    printf("Status:\n");
    printf("%s\n\n", judgement[ok]);
    return ok;
}