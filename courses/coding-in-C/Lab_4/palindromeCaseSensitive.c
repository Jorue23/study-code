#include<stdio.h>
#include<string.h>
#include<math.h>


int main()
{
    char userInput[100] = "";
    char *p_return = "is a palindrome";

    printf("Please enter a word that's shorter then 100 characters. The app will check if it is a palindrome!\n");
    if (fgets(userInput, sizeof(userInput), stdin) == NULL)
    {
        printf("Invalid input.\n");
        return -1;
    }
    userInput[strcspn(userInput, "\n")] = '\0';


    int palLen = strlen(userInput);
    for(int i = 0; i < floor(palLen/2); i++)
    {
        if(userInput[i] != userInput[palLen - i - 1])
        {
            p_return = "is not a palindrome";
            break;
        }
    }
    
    printf("Your provided word \"%s\" %s\n", userInput, p_return);

    return 0;
}