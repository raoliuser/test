#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void getMemory(char * s)
{
    s = malloc(100);

    strcpy(s, "hello ");
}

int main()
{
    char *str = NULL;

    getMemory(str);
    printf("str addr: %p", str);
    printf("value: %s", str);

}