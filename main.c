#include <stdio.h>
#include <stdlib.h>
#include "include/String.h"
#include "include/Lista.h"

int compar (const void * a, const void * b);

int main()
{
    int i;
    ArrayList list = array_init();

    array_push(list, "teste9");
    array_push(list, "teste4");
    array_push(list, "teste8");
    array_push(list, "teste6");
    array_push(list, "teste2");
    array_push(list, "teste");
    array_push(list, "teste3");

    printf("%d\n", list->length);

    array_sort(list, compar);

    for (i = 0; i < list->length; i++) {
        printf("%s\n", (char *) array_item(list, i));
    }

    return 0;
}

int compar (const void * a, const void * b)
{
    return strcmp((char *) b, (char *) a);
}
