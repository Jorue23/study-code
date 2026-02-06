#include<stdio.h>

int main()
{
    int myNumbers[5] = {10,20,30,40,50};
    int *ptr1 = &myNumbers[1];
    int *ptr2 = &myNumbers[4];
    printf("%p\n", ptr1);
    printf("%p\n", ptr2);
    printf("%d", ptr1-ptr2);
}