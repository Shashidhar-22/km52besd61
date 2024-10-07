#include<stdio.h>
#include <string.h>

char* lowercase(char input[]) {
    int i;
    for(i = 0; input[i]!='\0'; i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            // Convert uppercase to lowercase by adding 32 to ASCII value
            input[i] += 32;
        }
    }
    return input;
}

int main() {
    char input[50];
    printf("Enter a string in Uppercase: ");
    scanf("%49[^\n]s", input); // Limit input to 49 characters to avoid buffer overflow

    printf("Output is: %s\n", lowercase(input));

    return 0;
}
