// #include "sequence_list.c"
#include "link_list.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    int array1[] = {3,5,12,18,20,21,7};
    int array2[] = {6,10,13,19,20,28,4};

    // Link_list list = array2list(array1, sizeof(array1)/sizeof(array1[0]));
    /* Link_list list = NULL; */
    /* create_list_tail(&list, 5); */

    Link_list list = NULL;
    array2list(array1, sizeof(array1)/sizeof(array1[0]), &list);
    
    int element = 0;
    get_element(list, 5, &element);
    printf ("%d\n", element);
    
    delete_element(&list, 5, &element);
    get_element(list, 5, &element);
    printf ("%d\n", element);

    insert_element(&list, 5, 10);
    get_element(list, 5, &element);
    printf ("%d\n", element);
    
    return 0;
}

