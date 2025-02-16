#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 1000

// Function Declarations
void programDescription();
void expandString();
void compressString();
void mainMenu();
int isNumber(char c);
int isLetter(char c);

// Main Function
int main() {
    mainMenu();
    return 0;
}

// Function to Check if Character is a Number
int isNumber(char c) {
    return c >= '0' && c <= '9';
}

// Function to Check if Character is a Letter
int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Display Program Description
void programDescription() {
    printf("\nProgram Description: This program performs string expansion and compression.\n");
    printf("--- [P] - Displays program details.\n");
    printf("--- [E] - Takes compressed string from input and EXPANDS it\n");
    printf("          - eg. 'b2o2k2eper' into 'bookkeeper'\n");
    printf("--- [C] - Takes expanded string from input and COMPRESSES it\n");
    printf("          - eg. 'bookkeeper' into 'b2o2k2eper'\n");
    printf("--- [X] - Exits the program.\n");
    printf("\nProgram Developers:\n");
    printf("- Justin Dominic S. Veloso (2023-07851)\nContribution: Programmed String Expansion and Compression functions\n");
    printf("- Kyle Senoy (2023-06686)\nContribution: Composed main and menu functions\n");
    printf("\nDate Developed: February 15, 2025\n");
}

// Function to Expand Compressed String
void expandString() {
    char input[MAX_LEN], output[MAX_LEN];
    int i = 0, j = 0, count = 0;

    printf("\nEnter compressed string: ");
    scanf("%s", input);

    /**
     * Loop each character in the input string
     * - If number, build a multi-digit count
     * - If letter, repeat it {count} times
     * - If invalid character, display an error message
     */
    while (input[i] != '\0') {
        if (isNumber(input[i])) {
            count = count * 10 + (input[i] - '0');  // Handle multi-digit numbers
        } 
        else if (isLetter(input[i])) {
            int repeat = (count == 0) ? 1 : count;
            while (repeat > 0) {
                output[j++] = input[i];
                repeat--;
            }
            count = 0;  // Reset count after processing a letter
        } 
        else {
            printf("Error: Invalid input format.\n");
            return;
        }
        i++;
    }

    output[j] = '\0';  // Null-terminate the output string
    printf("Expanded Form: %s\n", output);
}

// Function to Compress Expanded String
void compressString() {
    char input[MAX_LEN], output[MAX_LEN];
    int i = 0, j = 0, count = 1;
    
    printf("\nEnter expanded string: ");
    scanf("%s", input);

    /**
     * Loop each character in the input string
     * - If not a letter, display error message
     * - If consecutive letters, store count
     * - when different character, save letter in output array, but if count > 1, save {count} before letter.
     */
    while (input[i] != '\0') {
        if (!isLetter(input[i])) {
            printf("Error: Invalid input format.\n");
            return;
        }
        if (input[i] == input[i + 1]) {
            count++;
        } 
        else {
            if (count > 1) {
                int temp = count, digits = 0, k;
                char numStr[15];

                // Convert count to a string (digits array in reverse order)
                while (temp > 0) {
                    numStr[digits++] = (temp % 10) + '0';
                    temp /= 10;
                }
                // Append the count to the output in correct order
                for (k = digits; k > 0; k--) {
                    output[j++] = numStr[k - 1];
                }
            }
            output[j++] = input[i];  // Save letter
            count = 1; 
        }
        i++;
    }

    output[j] = '\0';  // Null-terminate the output string
    printf("Compressed Form: %s\n", output);
}

// Display Main Menu
void mainMenu() {
    char choice;
    do {
        printf("\nWelcome to the String Expansion/Compression program!\n");
        printf("[P] Program Description\n[E] String Expansion\n[C] String Compression\n[X] Exit\nChoice: ");
        scanf(" %c", &choice);

        choice = toupper(choice);  // Convert lowercase input to uppercase

        switch (choice) {
            case 'P':
                programDescription();
                break;
            case 'E':
                expandString();
                break;
            case 'C':
                compressString();
                break;
            case 'X':
                printf("Exiting program...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);  // Loop until 'X' is chosen
}

