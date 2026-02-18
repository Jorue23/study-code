#include <stdio.h>
#include <string.h>

// int main(void) {
//     int x = 10;
//     int *p = &x;
//     int **pp = &p;

//     // TODO: complete the output statements
//     printf("x = %d\n", x);
//     printf("x via p = %d\n", *p);
//     printf("x via pp = %d\n", **pp);

//     return 0;
// }

int main(int argc, char **argv) {
        for(int i = 0; i < argc; i++) {
            printf("Argument %d at address \'%p\' has content: %s, and it's length is: %d\n", i, argv[i], argv[i], strlen(argv[i]));
        }
}