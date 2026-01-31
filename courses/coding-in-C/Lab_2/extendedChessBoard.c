#include<stdio.h>
#include<string.h>

void drawLetterRows();
void drawBetweenLine();
void drawFields(int lineNumber);
void drawSpaces(int spaces);

int MAX_LINES = 8;
char LETTER_ROWS[] = "ABCDEFGH";
char WHITE_FIELD[] = "|   ";
char BLACK_FIELD[] = "|###";

int main()
{  
    drawLetterRows();
    drawBetweenLine();
    for(int currentLine = 0; currentLine < MAX_LINES; currentLine++)
    {
        drawFields(currentLine);
        drawBetweenLine();
    }
    drawLetterRows();
    return 0;
}

void drawLetterRows()
{
    drawSpaces(3);
    for(int i = 0; i < strlen(LETTER_ROWS); i++)
    {
        printf("   %c", LETTER_ROWS[i]);
    }
    printf("\n");
}

void drawBetweenLine()
{
    drawSpaces(4);
    for(int plus = 0; plus < strlen(LETTER_ROWS); plus++)
    {
        printf("+");
        printf("---");
    }
    printf("+");
    drawSpaces(2);
    printf("\n");
}

void drawFields(int lineNumber)
{
    drawSpaces(2);
    printf("%d ", 8 - lineNumber);
    if(lineNumber%2 == 0)
    {

        for(int o = 0; o < 4; o++)
        {
            printf("%s%s", BLACK_FIELD, WHITE_FIELD);
        }
    }
    else
    {
        for(int o = 0; o < 4; o++)
        {
            printf("%s%2s", WHITE_FIELD, BLACK_FIELD);
        }   
    }
    printf("| %d\n", 8 - lineNumber);
}

void drawSpaces(int spaces)
{
    for(int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}