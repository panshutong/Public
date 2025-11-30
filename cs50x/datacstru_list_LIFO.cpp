#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    // Memory for numbers
    node *list = NULL;

    // Build list
    for (int i = 0; i < 3; i++)
    {
        // Allocate node for number
        node *n =(node*)malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        cout<<"Number: ";
        cin>>n->number;
        n->next = NULL;

        // Prepend node to list
        n->next = list;
        list = n;
    }
    node *ptr=list;
    while(ptr!=NULL){
        printf("%d\n",ptr->number);
        ptr=ptr->next;
    }
    return 0;
}