#include<stdio.h>
#include<string.h>

int promptUserFloat(int position);
void promptUserOperation();

float first = 0.00;
float second = 0.00;
char operation;

int main()
{
    promptUserFloat(1);
    promptUserFloat(2);
    promptUserOperation();
    while(getchar() != '\n' && getchar() != EOF);
    getchar();
    return 0;
}

int promptUserFloat(int position)
{
    if(position == 1)
    {
        printf("Please enter a floating point number(e.g. 3.00). ");
        if(scanf("%f", &first) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }
    }
    else
    {
        printf("Please enter another floating point number(e.g. 3.00). ");
        if(scanf("%f", &second) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }
    }
}

void promptUserOperation()
{
    printf("Please select the operation. ");
    scanf(" %c", &operation);
    switch(operation)
    {   
        case '+':
            printf("%.2f %c %.2f %c %.2f", first, operation, second, '=', first + second);
            break;
        case '-':
            printf("%.2f %c %.2f %c %.2f", first, operation, second, '=', first - second);
            break;
        case '*':
            printf("%.2f %c %.2f %c %.2f", first, operation, second, '=', first * second);
            break;
        case '/':
            if(second == 0.0)
            {
                printf("Error: Tried to divide by zero.");
            }
            else
            {
                printf("%.2f %c %.2f %c %.2f", first, operation, second, '=', first / second);
                break;
            }
        default:
            printf("Invalid input please enter a valid operation (+, -, *, /).");
            break;
    }
}