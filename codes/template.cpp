#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>

// Function Declaration
int displayResult(int* result, int resultLen, int* answer, int answerLen);

int main(int argc, char* argv[]){
    int received[100];
    int answer[100];
    int len, shiftNum;
    while (scanf("%d\t%d", &len, &shiftNum) != EOF) {
        // read the content and answer
        for (int i = 0; i < len; i++) scanf("%d", &received[i]);
        for (int i = 0; i < len; i++) scanf("%d", &answer[i]);

        // display the result and the answer
        displayResult(received, len, answer, len);
    }
    return 0;
}

// display the final result and correct answer
int displayResult(int* result, int resultLen, int* answer, int answerLen){
    bool ok = true;

    // display the result
    std::printf("Result:\n");
    for (int i = 0; i < resultLen; i++) std::printf("%d\t", result[i]);
    std::printf("\n");

    // display the answer
    std::printf("Answer:\n");
    for (int i = 0; i < answerLen; i++) {std::printf("%d\t", answer[i]); ok &= answer[i] == result[i]; }
    std::printf("\n");

    // judge the result
    const char *judgement[2] = {"Failed", "Correct"};
    std::printf("%s\n", judgement[ok]);
    return 0;
}