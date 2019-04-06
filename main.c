#include <stdio.h>
#include <string.h>

void encriptionRotation(char *message, int rotationAmount);

int main() {
    int choice; //declare a vairiable for the choice of the user
    char messageText[200];
    int rotationAmount;
    printf("what would you like to do\n1: Encription of rotation\n2: Decription with key of rotation\n");
    printf("3: Encription of substitution\n4: Decription with key of substitution\n");
    printf("5: Decription without key of rotation\n6: Decription without key of substitution\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("enter your message text:\n");
            scanf("%s", messageText);
            printf("enter your rotation amount:\n");
            scanf("%d", &rotationAmount);
            encriptionRotation(messageText, rotationAmount); //run encription of rotation function
            break;
        case 2:
            //run decription of rotation function
        case 3:
            //run encription of substitution function
        case 4:
            //run decription of substitution function
        case 5:
            //run decription without key of rotation function
        case 6:
            //run decription without key of substitution function
        default:
            printf("please enter a choice between 1 and 6\n");
            //re ask for a choice from the user
    }
    return 0;
}

void encriptionRotation(char *message, int rotationAmount) {
    char encripted;
    int encriptedValue;
    int n;
    for (n = 0 ; message[n] != '\0' && strlen(message) > n ; n++) {
		encriptedValue = ((int)message[n] -97 + rotationAmount) % 26 + 97;
		encripted = (char)(encriptedValue);
		printf("%c", encripted);
	}
	printf("\n");
}