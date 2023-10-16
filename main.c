#include "qsort.h"
int main()
{
    LinkedList list;
    initLinkedList(&list);
    FILE* file1 = fopen("resource/1.txt", "r");
    if (file1 == NULL) 
	{
        printf("Can't open 1.txt\n");
        return 0;
    }

    float num;
    while (fscanf(file1, "%f", &num) == 1) 
	{
        insertNode(&list, num);
    }

    fclose(file1);
    FILE* file2 = fopen("resource/2.txt", "r");
    if (file2 == NULL) 
	{
        printf("Can't open 2.txt\n");
        return 0;
    }
    while (fscanf(file2, "%f", &num) == 1) 
	{
        insertNode(&list, num);
    }

    fclose(file2);
    FILE* file3 = fopen("resource/3.txt", "r");
    if (file3 == NULL) 
	{
        printf("Can't open 3.txt\n");
        return 0;
    }

    while (fscanf(file3, "%f", &num) == 1) 
	{
        insertNode(&list, num);
    }
    fclose(file3);
    quickSort(list.head, list.tail);
    writeToFile(&list, "result.txt");
    destroyLinkedList(&list);

    return 0;
}
