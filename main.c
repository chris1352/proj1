#include <stdio.h>

int encriptionRotation(int message, int rotationAmount);

int main() {
    int choice; //declare a vairiable for the choice of the user
    int messageText;
    int rotaionAmount;
    printf("what would you like to do\n1: Encription of rotation\n2: Decription with key of rotation\n");
    printf("what would you like to do\n3: Encription of substitution\n4: Decription with key of substitution\n");
    printf("what would you like to do\n5: Decription without key of rotation\n6: Decription without key of substitution");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("enter your message text");
            scanf("%d", &messageText);
            printf("enter your rotation amount");
            scanf("%d", &rotationAmount);
            printf("%d", encriptionRotation()) //run encription of rotation function
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
            printf("please enter a choice between 1 and 6");
            //re ask for a choice from the user
    }
    return 0;
}

int encriptionRotation(int message, int rotationAmount) {
    int encripted
    
    return encripted;
}