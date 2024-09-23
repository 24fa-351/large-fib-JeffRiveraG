#include <stdio.h>
#include <stdint.h>

intmax_t fib_i(int userInput) {
    intmax_t number1 = 0;
    intmax_t number2 = 1;
    intmax_t result = 0;

    if (userInput == 0) {
        return 0;
    } else if (userInput == 1) {
        return 1;
    }

    for (int i = 2; i <= userInput; i++) {
        result = number1 + number2;
        number1 = number2;
        number2 = result;
    }
    return number2;
}

intmax_t fib_r(int userInput) {
    if (userInput <= 1) {
        return userInput;
    }
    return fib_r(userInput - 1) + fib_r(userInput - 2);
}

int main(int argc, char *argv[]) {
    int userInput;
    char input = argv[2][0];  
    //char *fileName = argv[3]; 
    sscanf(argv[1], "%d", &userInput);

    // FILE *fptr;
    // int fileNumber;

    // fptr = fopen(fileName, "r");

    // if (fptr == NULL) {
    //     printf("File does not exist: %s\n", fileName);
    //     return 1;
    // }

    // fscanf(fptr, "%d", &fileNumber);
    // fclose(fptr);

    // userInput += fileNumber;
    userInput -= 1;

    intmax_t result = -1;
    if (input == 'i') {
        result = fib_i(userInput);  
    } else if (input == 'r') {
        result = fib_r(userInput);  
    } else {
        printf("Invalid char, choose between i or r\n");
        return 1;
    }

    printf("%jd\n", result);
    return 0;
}
