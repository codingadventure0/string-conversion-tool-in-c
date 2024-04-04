//Writing a program to a string as input from user and give him to options to change it to Capitalize, Uppercase and Lowercase format.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define clrscr() system("clear");

// Function to toggle case based on user option
void toggleCase(char *str, int option, char *orgStr) {
    int length = strlen(str);

    switch(option) {
        case 1: // Convert to UPPERCASE
            for (int i = 0; i < length; i++) {
                str[i] = toupper(str[i]);
            }
            clrscr(); // Clear screen
            printf("Original String: %s\n", orgStr);
            printf("String converted to UPPERCASE: %s\n", str);
            break;

        case 2: // Convert to lowercase
            for (int i = 0; i < length; i++) {
                str[i] = tolower(str[i]);
            }
            clrscr(); // Clear screen
            printf("Original String: %s\n", orgStr);
            printf("String converted to lowercase: %s\n", str);
            break;

        case 3: // Capitalize
            if (islower(str[0])) {
                str[0] = toupper(str[0]);
            }
            for (int i = 1; i < length; i++) {
                if (isspace(str[i-1]) && islower(str[i])) {
                    str[i] = toupper(str[i]);
                }
            }
            clrscr(); // Clear screen
            printf("Original String: %s\n", orgStr);
            printf("String converted to Capitalize format: %s\n", str);
            break;

        case 0: // Exit program
            clrscr(); // Clear screen
            printf("Exiting program.\n");
            printf("\t\t\t---------Thanks for using the String Conversion program.---------\n");
            break;

        default:
            printf("Invalid option!\n");
    }
}

int main() {
    char str[200];
    char orgStr[200];
    int option;

    do {
        printf("Enter a string: ");
        fgets(orgStr, sizeof(orgStr), stdin);
        orgStr[strcspn(orgStr, "\n")] = 0; // Remove newline character
        strcpy(str, orgStr);

        clrscr(); // Clear screen
        printf("Your String: %s\n", orgStr);
        printf("\nOptions:\n");
        printf("1. Convert to UPPERCASE\n");
        printf("2. Convert to lowercase\n");
        printf("3. Convert to Capitalize format\n");
        printf("0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        toggleCase(str, option, orgStr); // Call function to toggle case

        if (option != 0) {
            int continueOption;
            printf("\nOptions:\n");
            printf("0. Exit\n");
            printf("9. Enter a new string\n");
            printf("\nEnter your choice: ");
            scanf("%d", &continueOption);
            
            if (continueOption == 9) {
                getchar(); // Clear input buffer
            }
            
            if (continueOption == 0) {
                option = 0; // Exit program
                clrscr(); // Clear screen
                printf("Exiting program.\n");
                printf("\t\t\t---------Thanks for using the String Conversion program.---------\n");
            }
        }

    } while (option != 0);

    return 0;
}
