#ifndef QSORT__H
#define QSORT__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    float data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} LinkedList;

extern void initLinkedList(LinkedList* list);
extern void insertNode(LinkedList* list, float data);
extern void quickSort(Node* low, Node* high);
extern void writeToFile(LinkedList* list, const char* filename);
extern void destroyLinkedList(LinkedList* list);


#endif