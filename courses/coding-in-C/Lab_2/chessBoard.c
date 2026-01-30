#include<stdio.h>
#include<string.h>

char LETTER_ROWS[] = "ABCDEFGH";
int MAX_LINES = 8;

int main()
{   
    for(int j = MAX_LINES; j > 0; j--)
    {
        for(int i = 0; i < strlen(LETTER_ROWS); i++)
        {
            printf("%c%d ", LETTER_ROWS[i], j);
        }
        printf("\n");
    }
}
