#include <stdio.h>
#include <string.h>

//-------------------------------function prototypes----------------------------------------------
void encriptionRotation(char *messageText, int rotationAmount);
void decriptionRotation(char *encriptedText, int rotationAmount);
void encriptionSubstitution(char *messageText, char *substitutionKey);
void decriptionSubstitution(char *encriptedText, char *substitutionKey);
void decriptionRotationWithoutKey();
void decriptionSubstitutionWithoutKey();

//-------------------------------main----------------------------------------------
int main() {
    FILE *inputs;
    inputs = fopen("inputs.txt", "r");
    
    int choice; //creates a vairiable for the choice of the user
    
    char messageText[200]; //creates a string to store a message that will be encripted
    char encriptedText[200]; //creates a string to store an encripted message that will be decripted
    char substitutionKey[200]; //creates a string to store the substitution key
    int rotationAmount; //creates an int variable to store a rotation amount
    
    printf("What would you like to do\n1: Encription of rotation\n2: Decription with key of rotation\n");   //
    printf("3: Encription of substitution\n4: Decription with key of substitution\n");                      //prints a menu for the user
    printf("5: Decription without key of rotation\n6: Decription without key of substitution\n");           //
    fscanf(inputs, "%d\n", &choice); //reads an input from the user and stores it in choice
    
    switch(choice) {
        case 1:
            printf("Enter your message text: \n");
            fgets(messageText, 200, inputs); //reads an input from the user and stores it in messageText
            printf("Enter your rotation amount: \n");
            fscanf(inputs, "%d\n", &rotationAmount); //reads an input from the user and stores it in rotationAmount
            encriptionRotation(messageText, rotationAmount); //runs encription of rotation function
            break;
        case 2:
            printf("Enter your encripted text: \n");
            fgets(encriptedText, 200, inputs);  //reads an input from the user and stores it in encriptedText
            printf("Enter your rotation amount: \n");
            fscanf(inputs, "%d\n", &rotationAmount); //reads an input from the user and stores it in rotationAmount
            decriptionRotation(encriptedText, rotationAmount); //runs decription of rotation function
            break;
        case 3:
            printf("Enter your message text: \n");
            fgets(messageText, 200, inputs); //reads an input from the user and stores it in messageText
            printf("enter your key: \n");
            fscanf(inputs, "%s\n", substitutionKey); //reads an input from the user and stores it in substitutionKey
            encriptionSubstitution(messageText, substitutionKey); //run encription of substitution function
            break;
        case 4:
            printf("Enter your encripted text: \n");
            fgets(encriptedText, 200, inputs); //reads an input from the user and stores it in messageText
            printf("enter your key: \n");
            fscanf(inputs, "%s\n", substitutionKey); //reads an input from the user and stores it in substitutionKey
            decriptionSubstitution(encriptedText, substitutionKey); //run decription of substitution function
            break;
        case 5:
            //run decription without key of rotation function
        case 6:
            //run decription without key of substitution function
        default:
            printf("Choice invalid, please enter a choice between 1 and 6\n"); //re ask for a choice from the user
    }
    fclose(inputs);
    return 0;
}


//-------------------------------functions----------------------------------------------
void encriptionRotation(char *messageText, int rotationAmount) {
    char encripted; //creates a char variable used for encription
    int encriptedValue; //creates an int variable used for encription
    int n; //creates an int variable used for counting
    
    printf("your encripted text is: ");
    
    for (n = 0 ; messageText[n] != '\0' && strlen(messageText) > n ; n++) { //loop that continues until it reaches a \0 or the string length is greater than the count variable   
		if ((int)messageText[n] == 32) {
		    printf(" ");
		}
		else {
		encriptedValue = ((int)messageText[n] - 65 + rotationAmount) % 26 + 65; //changes a letter from the messageText int to the ASCII code for the letter that is the rotatoion amount ahead of that letter
		encripted = (char)(encriptedValue); //changes the ASCII code back into a letter
		printf("%c", encripted); //prints that letter
        }
    }
    printf("\n"); //prints a new line
}

void decriptionRotation(char *encriptedText, int rotationAmount) {
    char decripted; //creates a char variable used for decription
    int decriptedValue; //creates an int variable used for decription
    int n; //creates an int variable used for counting
    
    printf("your decripted text is: ");
    
    for (n = 0 ; encriptedText[n] != '\0' && strlen(encriptedText) > n ; n++) { //loop that continues until it reaches a \0 or the string length is greater than the count variable
		if ((int)encriptedText[n] == 32) {
		    printf(" ");
		}
		else {
		decriptedValue = ((int)encriptedText[n] - 65 - rotationAmount) % 26 + 65; //changes a letter from the encriptedText into the ASCII code for the letter that is the rotatoion amount behind of that letter
		decripted = (char)(decriptedValue); //changes the ASCII code back into a letter
		printf("%c", decripted); //prints that letter
        }	
	}
	printf("\n"); //prints a new line
}

void encriptionSubstitution(char *messageText, char *substitutionKey) {
    char alphabet[200] = "abcdefghijklmnopqrstuvwxyz"; //creates a string that stores the alphabet in lower case
    int n, c; //creates int variables to be used for index's
    
    for (n = 0, c = 0 ; messageText[n] != '\0' && strlen(messageText) > n ; c++) { //loop that continues until it reaches a \0 or the string length is greater than the count variable
        if ((int)messageText[n] == 32) {
		    printf(" ");
		}
		else if (messageText[n] == alphabet[c]) { //if statement that finds the index for the letter, in the alphabet, that is to be changed in the message text
            messageText[n] = substitutionKey[c]; //changes the letter in the message text to the one that has the same index in the substitution key
            n++; //increments n, ie moves to the next letter
            c = -1; //resets c, didn't work with c being set to 0
        }
    }
    printf("your encripted text is %s\n", messageText); //prints the encripted text
}

void decriptionSubstitution(char *encriptedText, char *substitutionKey) {
    char alphabet[200] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //creates a string that stores the alphabet in upper case
    int n, c; //creates int variables to be used for index's
    
    for (n = 0, c = 0 ; encriptedText[n] != '\0' && strlen(encriptedText) > n ; c++) { //loop that continues until it reaches a \0 or the string length is greater than the count variable
        if ((int)encriptedText[n] == 32) {
		    printf(" ");
		}
		else if (encriptedText[n] == substitutionKey[c]) { //if statement that finds the index for the letter, in the substitution key, that is to be changed in the encripted text
            encriptedText[n] = alphabet[c]; //changes the letter in the message text to the one that has the same index in the alphabet
            n++; //increments n, ie moves to the next letter
            c = -1; //resets c, didn't work with c being set to 0
        }
    }
    printf("your decripted text is %s\n", encriptedText); //prints the decripted text
}

void decriptionRotationWithoutKey() {
    
}

void decriptionSubstitutionWithoutKey() {
    
}