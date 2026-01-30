#include<stdio.h>
#include<string.h>

int drawBetweenLines();

char LETTER_ROWS[] = "ABCDEFGH";
int MAX_LINES = 8;

int main()
{  
    printf(" ");
    for(int i = 0; i < strlen(LETTER_ROWS); i++)
    {
        printf("   %c", LETTER_ROWS[i]);
    }
    printf("\n");
    drawBetweenLines();
    return 0;
}

int drawBetweenLines()
{
    printf("  ");
    for(int plus = 0; plus < strlen(LETTER_ROWS)+1; plus++)
    {
        printf("+");
        for(int h=0; h < 3 && plus < strlen(LETTER_ROWS); h++)
        {
            printf("-");
        }
    }
    printf("  ");
    return 0;

}