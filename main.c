#include <stdio.h>
#include <string.h>

//-------------------------------function prototypes----------------------------------------------
void encriptionRotation(char *messageText, int rotationAmount);
void decriptionRotation(char *encriptedText, int rotationAmount);
void encriptionSubstitution(char *messageText, char *substitutionKey);
void decriptionSubstitution();
void decriptionRotationWithoutKey();
void decriptionSubstitutionWithoutKey();

//-------------------------------main----------------------------------------------
int main() {
    int choice; //creates a vairiable for the choice of the user
    
    char messageText[200]; //creates a string to store a message that will be encripted
    char encriptedText[200]; //creates a string to store an encripted message that will be decripted
    char substitutionKey[200];
    int rotationAmount; //creates an int variable to store a rotation amount
    
    printf("What would you like to do\n1: Encription of rotation\n2: Decription with key of rotation\n");   //
    printf("3: Encription of substitution\n4: Decription with key of substitution\n");                      //prints a menu for the user
    printf("5: Decription without key of rotation\n6: Decription without key of substitution\n");           //
    scanf("%d", &choice); //reads an input from the user and stores it in choice
    
    switch(choice) {
        case 1:
            printf("Enter your message text: \n");
            scanf("%s", messageText); //reads an input from the user and stores it in messageText
            printf("Enter your rotation amount: \n");
            scanf("%d", &rotationAmount); //reads an input from the user and stores it in rotationAmount
            encriptionRotation(messageText, rotationAmount); //runs encription of rotation function
            break;
        case 2:
            printf("Enter your encripted text: \n");
            scanf("%s", encriptedText); //reads an input from the user and stores it in encriptedText
            printf("Enter your rotation amount: \n");
            scanf("%d", &rotationAmount); //reads an input from the user and stores it in rotationAmount
            decriptionRotation(encriptedText, rotationAmount); //runs decription of rotation function
            break;
        case 3:
            printf("Enter your message text: \n");
            scanf("%s", messageText);
            printf("enter your key: \n");
            scanf("%s", substitutionKey);
            encriptionSubstitution(messageText, substitutionKey); //run encription of substitution function
            break;
        case 4:
            //run decription of substitution function
        case 5:
            //run decription without key of rotation function
        case 6:
            //run decription without key of substitution function
        default:
            printf("Choice invalid, please enter a choice between 1 and 6\n");
            //re ask for a choice from the user
    }
    return 0;
}


//-------------------------------functions----------------------------------------------
void encriptionRotation(char *messageText, int rotationAmount) {
    char encripted; //creates a char variable used for encription
    int encriptedValue; //creates an int variable used for encription
    int n; //creates an int variable used for counting
    
    printf("your encripted text is: ");
    for (n = 0 ; messageText[n] != '\0' && strlen(messageText) > n ; n++) { //loop that continues until it reaches a \0 or the string length is greater than the count variable   
		encriptedValue = ((int)messageText[n] - 65 + rotationAmount) % 26 + 65; //changes a letter fromm the messageText int to the ASCII code for the letter that is the rotatoion amount ahead of that letter
		encripted = (char)(encriptedValue); //changes the ASCII code back into a letter
		printf("%c", encripted); //prints that letter
	}
	printf("\n"); //prints a new line
}

void decriptionRotation(char *encriptedText, int rotationAmount) {
    char decripted; //creates a char variable used for decription
    int decriptedValue; //creates an int variable used for decription
    int n; //creates an int variable used for counting
    printf("your decripted text is: ");
    for (n = 0 ; encriptedText[n] != '\0' && strlen(encriptedText) > n ; n++) { //loop that continues until it reaches a \0 or the string length is greater than the count variable   
		decriptedValue = ((int)encriptedText[n] - 65 - rotationAmount) % 26 + 65; //changes a letter fromm the encriptedText into the ASCII code for the letter that is the rotatoion amount behind of that letter
		decripted = (char)(decriptedValue); //changes the ASCII code back into a letter
		printf("%c", decripted); //prints that letter
	}
	printf("\n"); //prints a new line
}

void encriptionSubstitution(char *messageText, char *substitutionKey) {
    char alphabet[200] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n, c;
    for (n = 0, c = 0 ; messageText[n] != '\0' && strlen(messageText) > n ; c++) {
        if (messageText[n] == alphabet[c]) {
            messageText[n] = substitutionKey[c];
            n++;
            c = 0;
        }
    }
    printf("your encripted text is %s\n", messageText);
}

void decriptionsubstitution() {
    
}

void decriptionRotationWithoutKey() {
    
}

void decriptionSubstitutionWithoutKey() {
    
}