#include<stdio.h>
#include<string.h>

int drawLetterRows();
int drawBetweenLine();
int drawFields(int lineNumber);

int MAX_LINES = 8;
int currentLine;
char LETTER_ROWS[] = "ABCDEFGH";
char WHITE_FIELD[] = "|   ";
char BLACK_FIELD[] = "|###";

int main()
{  
    drawLetterRows();
    drawBetweenLine();
    for(currentLine = 0; currentLine < MAX_LINES; currentLine++)
    {
        drawFields(currentLine);
        drawBetweenLine();
    }
    drawLetterRows();
    return 0;
}

int drawLetterRows()
{
    printf("   ");
    for(int i = 0; i < strlen(LETTER_ROWS); i++)
    {
        printf("   %c", LETTER_ROWS[i]);
    }
    printf("\n");
    return 0;
}

int drawBetweenLine()
{
    printf("    ");
    for(int plus = 0; plus < strlen(LETTER_ROWS)+1; plus++)
    {
        printf("+");
        for(int h=0; h < 3 && plus < strlen(LETTER_ROWS); h++)
        {
            printf("-");
        }
    }
    printf("  \n");
    return 0;
}

int drawFields(int lineNumber)
{
    printf("  ");
    printf("%d ", 8 - lineNumber);
    if(lineNumber%2 == 0)
    {

        for(int o = 0; o < 4; o++)
        {
            printf("%s", BLACK_FIELD);
            printf("%s", WHITE_FIELD);

        }
        printf("|");
    }
    else
    {
        for(int k = 0; k < 4; k++)
        {
            printf("%s", WHITE_FIELD);
            printf("%s", BLACK_FIELD);
        }
        printf("|");
        
    }
    printf(" %d\n", 8 - currentLine);
    return 0;
}