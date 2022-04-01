#include <stdio.h>
#include <stdlib.h>
#include "include/String.h"
#include "include/Lista.h"

int compar (const void * a, const void * b);
char * newListCallback (const void ** item, const int index, const ArrayList l);
char * reduceCallback (void ** accum, const void ** item, const int index, const ArrayList l);

int main()
{
    int i;
    ArrayList list = array_init();
    ArrayList list2;

    array_push(list, "teste9");
    array_push(list, "teste4");
    array_push(list, "teste8");
    array_push(list, "teste6");
    array_push(list, "teste2");
    array_push(list, "teste");
    array_push(list, "teste3");

    printf("%d\n", list->length);

    list2 = array_map(list, newListCallback);

    for (Node * no = list2->first; no; no = no->next) {
        printf("%s\n", (char *) no->content);
    }

    printf("%s\n", array_reduce(list, reduceCallback));

    return 0;
}

int compar (const void * a, const void * b)
{
    return strcmp((char *) b, (char *) a);
}

char * newListCallback (const void ** item, const int index, const ArrayList l)
{
    char * buffer = (char *) malloc(strlen((char *) item) + 7);

    strcpy(buffer, (char *) item);
    strcat(buffer, " - cat");

    return buffer;
}

char * reduceCallback (void ** accum, const void ** item, const int index, const ArrayList l)
{
    char * buffer = NULL;
    char * converted = (char *) item;
    if (accum == NULL) {
        buffer = (char *) malloc(strlen(converted));
        buffer = "";
    } else {
        buffer = (char *) malloc(strlen((char *) accum) + strlen(converted) + 1);
        buffer = (char *) accum;
    }

    strcat(buffer, converted);

    printf("%s\n", buffer);
    return buffer;
}

