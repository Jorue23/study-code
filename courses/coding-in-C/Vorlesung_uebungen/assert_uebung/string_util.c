#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int custom_len(char str[]) {
    int i = 0;

    if(str == NULL) {
        return 0;
    }

    while(str[i] != '\0') {
        i++;
    }

    return i;
}

char *read_line_dynamic() {
    char str[1024];
    if (fgets(str, sizeof(str)-1, stdin) == NULL)
    {
        printf("Invalid input.\n");
        return -1;
    }
    int len = custom_len(str);
    char *p_mem = malloc(len+1);
    if(!p_mem) {
        return NULL;
    }
    strcpy(p_mem, str);

    return p_mem;
}