#include<stdio.h>
#include<string.h>

void promptUserFloat(int position);
void promptUserOperation();

float first = 0.00;
float second = 0.00;
char operation;

int main()
{
    promptUserFloat(1);
    promptUserFloat(2);
    promptUserOperation();
    return 0;
}

void promptUserFloat(int position)
{
    if(position == 1)
    {
        printf("Please enter a floating point number(e.g. 3.00). ");
        int result = scanf("%f", &first);
        if(result != 1) 
        {
            printf("Invalid input try again!\n");
            while(getchar() != '\n');
            promptUserFloat(1);
        }
        while(getchar() != '\n');
    }
    else
    {
        printf("Please enter a floating point number(e.g. 3.00). ");
        int result = scanf("%f", &second);
        if(result != 1) 
        {
            printf("Invalid input try again!\n");
            while(getchar() != '\n');
            promptUserFloat(2);
        }
        while(getchar() != '\n');
    }
}

void promptUserOperation()
    {
        printf("Please select the operation. ");
        scanf(" %c", &operation);
        if(getchar() != '\n' || operation == '\n' || operation == ' ' || operation == '\t')
        {
            printf("Invalid input please try again!");
            while(getchar() != '\n');
            promptUserOperation();
        }
        else
        {
            switch(operation)
            {   
                case '+':
                    printf("%f %c %f %c %f", first, operation, second, '=', first + second);
                    break;
                case '-':
                    printf("%f %c %f %c %f", first, operation, second, '=', first - second);
                    break;
                case '*':
                    printf("%f %c %f %c %f", first, operation, second, '=', first * second);
                    break;
                case '/':
                    if(second == 0.0)
                    {
                        printf("Tried to divide by zero. Please enter a different operation or restart the program.");
                    }
                    else
                    {
                        printf("%f %c %f %c %f", first, operation, second, '=', first / second);
                        break;
                    }
                default:
                    printf("Invalid input please enter a valid operation (+, -, *, /).");
                    break;
            }
        }
    }