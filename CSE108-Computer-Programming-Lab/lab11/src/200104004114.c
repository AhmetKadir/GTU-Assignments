#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    float number;
    char* name;
    struct node *next;
};

void insert_end(struct node **head, int val, float num, char* name_)
{
    //create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->number = num;
    newNode->name = name_;
    newNode->next = NULL;

    //if head is NULL, it is an empty list
    if(*head == NULL)
         *head = newNode;
    //Otherwise, find the last node and add the newNode
    else
    {
        struct node *lastNode = *head;

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }

}

void printList_withLoop(struct node *head)
{
    //iterate the entire linked list and print the data with loop
    while(head != NULL){
        printf("\n%d->%f->%s",head->data, head->number, head->name);
        head = head->next;
    }
    printf("\n\n");
}
void printList_withRecursive(struct node *list) {
   
   printf("%d->%f->%s",list->data, list->number, list->name);
   if (list->next != NULL) printf(", ");
   if (list->next != NULL){
       printList_withRecursive(list->next);
   }
   if (list->next == NULL) printf("]\n");
}


void sortedInsert(struct node** head_ref, struct node* new_node)
{
   // Sort according to string into the node struct.
   // It's name is "name".
   // You will sort ascending order.
   
    if(*head_ref == NULL){
         *head_ref = new_node;
    }
    else{
        /*printf("\nchecking %s and %s\n",new_node->name, (*head_ref)->name);*/
        
        if(strcmp(new_node->name,(*head_ref)->name)<0){
            
            struct node *tempNode = (*head_ref);
            *head_ref = new_node;
            new_node->next= tempNode;
        }
        else sortedInsert((&(*head_ref)->next),new_node);
    }

}
 
 
/* A utility function to create a new node */
struct node* newNode(int new_data, float num, char* name_)
{
    /* allocate node */
    struct node* newNode = malloc(sizeof(struct node));
 
    /* put in the data  */
    newNode->data = new_data;
    newNode->number = num;
    newNode->name = name_;
    newNode->next = NULL;
}


bool search(struct node* head, int x)
{
    // Search according to "data" which defined in node struct.
	// You will control x number comparision with "data" which struct element.
    while(head != NULL){
        if (head->data == x)
            return true;
        head = head->next;
    }
    return false;
}

int main()
{
     struct node *head = NULL;

     insert_end(&head,10,5.5,"hello1");
     insert_end(&head,20,5.5,"hello2");
     insert_end(&head,30,5.5,"hello3");

     printf("\n\nprintList_withLoop(): \n");
     printList_withLoop(head);

     
     struct node* new_node = newNode(1,5.5, "a");
     sortedInsert(&head, new_node);

     new_node = newNode(3,5.5, "c");
     sortedInsert(&head, new_node);
     
     new_node = newNode(2,5.5, "d");
     sortedInsert(&head, new_node);
     
     new_node = newNode(2,5.5, "b");
     sortedInsert(&head, new_node);
     
     printf("Print List with Recursive: \n[");
     printList_withRecursive(head);
	 
	 printf("\nIs 20 belong this linked list?: " );
     printf(search(head, 20) ? "YES \n" : "NO \n");
     
     printf("\nIs 18 belong this linked list?: " );
     printf(search(head, 18) ? "YES \n" : "NO \n");


     return 0;
}