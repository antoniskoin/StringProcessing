#include <stdio.h>
#include <string.h>
#define MAX 200 // limit of characters allowed to be provided by user

void frequencyLetters(char *s);
void substituteLetter(char *s);
void showMenu();
void checkWithUser();
int answer = 0; // Use to store answer from user (y/n)

int main()
{
    char *input;
    char userInput[MAX]; // input from user
    input = userInput;
    int userChoice;
    
    while (1) {
        while (1) {
            showMenu();
            printf("Please select an option: ");
            scanf("%d", &userChoice);
            if (userChoice > 0 && userChoice <= 3) {
                break;
            }
            else {
                getchar(); // Empty scanf buffer
                printf("Wrong input provided. Please try again.\n");
            }
        }    
        
        if (userChoice == 1) { // Count character frequency
            if (answer == 0) { // if user wants to enter new string
                getchar(); // Used to avoid problem for using fgets() after scanf(). Solution found at: https://www.geeksforgeeks.org/problem-with-scanf-when-there-is-fgetsgetsscanf-after-it/
                printf("Enter some text: ");
                fgets(userInput, MAX, stdin); 
            }
            printf("Text entered: %s\n", userInput);
            frequencyLetters(userInput);
        } else if (userChoice == 2) { // Substitute letters
            if (answer == 0) {
                getchar();
                printf("Enter some text: ");
                fgets(userInput, MAX, stdin); 
            }
            printf("Text entered: %s\n", userInput);
            substituteLetter(input);
        } else if (userChoice == 3) { // Exit
            printf("The program will now exit...");
            break;
        }
    }
    
    return 0;
}

void showMenu() { // Function that prints the menu
    printf("\n1. Count character frequency\n");
    printf("2. Substitute Letters\n");
    printf("3. Exit\n");
}

void checkWithUser() {
    char *input;
    char userInput[2];
    input = userInput;
    printf("Would you like to change the given text? (y/n) ");
    while (1) {
        scanf("%s", userInput);
        if (strcmp(input, "y") == 0) { // if input = 'y'
            answer = 0;
            break;
        }
        else if (strcmp(input, "n") == 0) { // if input = 'n'
            answer = 1;
            break;
        }
        else {
            printf("Wrong input provided. Please try again: ");
        }
    }
}

void frequencyLetters(char *s) {
   int slen = strlen(s); // store string length
   int LowerLetters[26]; // for the 26 letters of the alphabet
   int UpperLetters[26]; // for the 26 letters of the alphabet
   int countNumbers[9]; // Used to store the numbers
   int spaceCounter = 0;
   int specialCharCounter = 0;
   
   for (int i = 0; i < 26; i++) { // Initialize the array with 0
       LowerLetters[i] = 0;
       UpperLetters[i] = 0;
   }
   
   for (int i = 0; i < 9; i++) { // Initialize the array with 0
       countNumbers[i] = 0;
   }
   
   for (int i = 0; i < slen; i++) {
       if (s[i] >= 'a' && s[i] <= 'z') { // if lowercase
           LowerLetters[s[i] - 97]++; // using ascii (ex. t (116) - 97 (a) = 19) to increase counter for each letter
       }
       else if (s[i] >= 'A' && s[i] <= 'Z') { // if uppercase
           UpperLetters[s[i] - 65]++; // using ascii (ex. T (84) - 65 (a) = 19) to increase counter for each letter
       }
       else if (s[i] >= '0' && s[i] <= '9') { // if number
           countNumbers[s[i] - 48]++; // using ascii (ex. 54 (6) - 48 (a) = 6) to increase counter for each number
       }
       else if (s[i] == ' ') { // if space, increase counter
           spaceCounter++;
       }
       else { // if special character, increase counter
           specialCharCounter++;   
       }
   }
   
   printf("Lowercase Letters\n-------------\n");
   int foundLower = 0; // flag to check if lowercase letters exist
   for (int i = 0; i < 26; i++) {
       if (LowerLetters[i] != 0) {
           printf("%c = %d | %.4f%c \n", (i + 97), LowerLetters[i], ((float)LowerLetters[i] / slen) * 100, 37); // 37 is the ASCII code for the exclamation mark (!)
           foundLower = 1;
       }
   }    
   
   if (foundLower == 0) {
       printf("No lowercase letters were found.\n");
   }
   
   printf("\nUppercase Letters\n-------------\n");
   int foundUpper = 0; // flag to check if uppercase letters exist
   for (int i = 0; i < 26; i++) {
       if (UpperLetters[i] != 0) {
           printf("%c = %d | %.4f%c \n", ((i + 97)-32), UpperLetters[i], ((float)UpperLetters[i] / slen) * 100, 37); // Deduct 32 to convert letter to uppercase
           foundUpper = 1;
       }
   }   
   
   if (foundUpper == 0) {
       printf("No uppercase letters were found.\n");
   }
   
    printf("\nNumbers\n-------------\n");
    int foundNumbers = 0; // flag to check if numbers exist
    for (int i = 0; i < 9; i++) {
       if (countNumbers[i] != 0) {
           printf("%c = %d | %.4f%c \n", (i + 48), countNumbers[i], ((float)countNumbers[i] / slen) * 100, 37);
           foundNumbers = 1;
       }
    }  
   
    if (foundNumbers == 0) {
       printf("No numbers were found.\n");
    }
   
    printf("\nSpaces\n-------------\n");
    if (spaceCounter > 0) {
        printf("Spaces: %d | %.4f%c \n", spaceCounter, ((float)spaceCounter / slen) * 100, 37);
    }
    else {
        printf("No spaces found.\n");
    }
    
    printf("\nSpecial characters\n-------------\n");
    if (spaceCounter > 0) {
        printf("Special characters: %d | %.4f%c \n======================\n", specialCharCounter, ((float)specialCharCounter / slen) * 100, 37);
    }
    else {
        printf("No special characters found.\n======================\n");
    }
    checkWithUser(); // Check if user wants to proceed with the same text
}

void substituteLetter(char *s) {
    int slen = strlen(s); // store string length
    char temp[slen];
    
    for (int i = 0; i < slen; i++) { // store provided char array to a temp variable
       temp[i] = s[i];
   }
    
     for (int i = 0; i < slen; i++) {
       if (temp[i] >= 'a' && temp[i] <= 'z') { // if lowercase
           temp[i] = temp[i] + 1; 
       }
        else if (s[i] >= 'A' && s[i] <= 'Z') { // if uppercase
            temp[i] = temp[i] + 1;
       }
       else if (s[i] >= '0' && s[i] <= '9') { // if number
           temp[i] = temp[i] + 1;
       }
       else if (s[i] == ' ') { // if space
           temp[i] = temp[i]; // Do not process (remain the same)
       }
       else { // if special character
           temp[i] = temp[i] + 1;
       }
     }
   
    printf("New text: ");
    for (int i = 0; i < slen; i++) { // print new string
        printf("%c", temp[i]);
    }
   
   printf("\n");
   checkWithUser(); // Check if user wants to proceed with the same text
}