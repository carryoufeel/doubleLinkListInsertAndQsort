#include "qsort.h"
void initLinkedList(LinkedList* list) 
{
    if(list==NULL)
    {
        printf("list is NULL\n");
        return;
    }
    list->head = NULL;
    list->tail = NULL;
}

void insertNode(LinkedList* list, float data) 
{
    if(list==NULL)
    {
        printf("list is NULL\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL)
    {
        printf("can't malloc\n");
        return;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (list->head == NULL) 
	{
        list->head = newNode;
        list->tail = newNode;
    } 
	else 
	{
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// 快速排序算法
static Node* partition(Node* low, Node* high) 
{
    float pivot = high->data;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) 
	{
        if (j->data <= pivot) 
		{
            i = (i == NULL) ? low : i->next;
            float temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }

    i = (i == NULL) ? low : i->next;
    float temp = i->data;
    i->data = high->data;
    high->data = temp;

    return i;
}

void quickSort(Node* low, Node* high) 
{
    if (high != NULL && low != high && low != high->next) 
	{
        Node* pivot = partition(low, high);
        quickSort(low, pivot->prev);
        quickSort(pivot->next, high);
    }
}

void writeToFile(LinkedList* list, const char* filename) 
{
    if(list==NULL)
    {
        printf("list is NULL\n");
        return;
    }
    FILE* file = fopen(filename, "w");
    if (file == NULL) 
	{
        printf("Failed to open file.\n");
        return;
    }

    Node* curr = list->head;
    while (curr != NULL) 
	{
        fprintf(file, "%f ", curr->data);
        curr = curr->next;
    }
    fclose(file);
}

void destroyLinkedList(LinkedList* list) 
{
    if(list==NULL)
    {
        printf("list is NULL\n");
        return;
    }
    Node* curr = list->head;
    while (curr != NULL) 
	{
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    list->head = NULL;
    list->tail = NULL;
}

