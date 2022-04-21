#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node* next;
};
typedef struct node st;

int val;
st *head = NULL;
st *temp, *ptr;

// function prototypes
void menu();
void createList();
void printList();
void countNodes();
void insertAtStart();
void insertAtEnd();
void insertAfterNode();
void insertBeforeNode();
void insertAtPosition();
void deleteAtStart();
void deleteAtEnd();
void deleteAfterNode();
void deleteBeforeNode();
void deleteAtPosition();
void reverseList();
void search();

int main(){
    menu();

    int choice;
    while (1){
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createList();
            break;
        case 2:
            printList();
            break;
        case 3:
            countNodes();
            break;
        case 4:
            insertAtStart();
            break;
        case 5:
            insertAtEnd();
            break;
        case 6:
            insertAtPosition();
            break;
        case 7:
            insertAfterNode();
            break;
        case 8:
            insertBeforeNode();
            break;
        case 9:
            deleteAtStart();
            break;
        case 10:
            deleteAtEnd();
            break;
        case 11:
            deleteAtPosition();
            break;
        case 12:
            deleteAfterNode();
            break;
        case 13:
            deleteBeforeNode();
            break;
        case 14:
            search();
            break;
        case 15:
            reverseList();
            break;
        case 16:
            printf("Exiting...");
            exit(0);
            break;
        default:
            printf("INVALID CHOICE !!");
            break;
        }
    }
    return 0;
}

void menu(){
    printf("____ MENU ____\n1. Create List\n2. Print List\n3. Count Nodes\n4. Insert at start\n5. Insert at end\n6. Insert at specific position\n7. Insert after a node\n8. Insert before a node\n9. Delete at start\n10. Delete at end\n11. Delete at specific position\n12. Delete after a node\n13. Delete before a node\n14. Search\n15. Reverse List\n16. Exit\n");
}

void createList(){
    int n;
    printf("How many numbers: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        (i == 0 ? insertAtStart() : insertAtEnd());
}

void printList(){
    if(head == NULL){
        printf("List is currently empty !! Insert sth to print !!\n");
        return;
    }
    ptr = head;
    printf("List: ");
    while(ptr != NULL){
        printf(" %d | ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertAtStart(){
    printf("Enter value to insert at start: ");
    scanf("%d", &val);
    temp = (st*)malloc(sizeof(st));
    temp->data = val;
    // head stores the address of first node, so next temp with head ie., first node
    temp->next = head; 
    head = temp; // now temp is our new head
}

void insertAtEnd(){
    printf("Enter value to insert at end: ");
    scanf("%d", &val);
    temp = (st*)malloc(sizeof(st));
    temp->data = val;
    ptr = head;
    // first, reach to the last node 
    while (ptr->next != NULL)
        ptr = ptr->next;
    // while loop ends and we are at last node 
    temp->next = NULL;
    ptr->next = temp; // next last node to new last node
}

void insertAfterNode(){
    int x;
    printf("Enter node value after which you want to insert: ");
    scanf("%d", &x);
    printf("Enter value to insert after a node: ");
    scanf("%d", &val);
    temp = (st*)malloc(sizeof(st));
    temp->data = val;
    ptr = head;
    // first, reach to the desired node 
    while (ptr->next != NULL){
        if(ptr->data == x)
            break;
        ptr = ptr->next;
    }
    // while loop ends and we are at last node 
    temp->next = ptr->next;
    ptr->next = temp; // next last node to new last node
}

void insertBeforeNode(){
    int x;
    printf("Enter node value before which you want to insert: ");
    scanf("%d", &x);
    printf("Enter value to insert after a node: ");
    scanf("%d", &val);
    temp = (st*)malloc(sizeof(st));
    temp->data = val;
    ptr = head;
    // first, reach to the predecessor of desired node 
    while (ptr->next != NULL){
        if(ptr->next->data == x)
            break;
        ptr = ptr->next;
    }
    // while loop ends and we are at last node 
    temp->next = ptr->next;
    ptr->next = temp; // next last node to new last node
}

void insertAtPosition(){
    int x;
    printf("Enter position at which you want to insert: ");
    scanf("%d", &x);
    printf("Enter value to insert at position %d: ", x);
    scanf("%d", &val);
    temp = (st*)malloc(sizeof(st));
    temp->data = val;
    ptr = head;
    // first, reach to the predecessor of desired node 
    for(int i=1; i<x-1 && ptr->next != NULL; i++){
        ptr = ptr->next;
    }
    // for loop ends and we are at behind desired node position 
    temp->next = ptr->next;
    ptr->next = temp; // next last node to new last node
}

void deleteAtStart(){
    printf("%d deleted from start of list!\n", head->data);
    temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd(){
    if(head->next == NULL){
        deleteAtStart();
        return;
    }
    ptr = head;
    while(ptr->next->next != NULL) // reach to the second last node
        ptr = ptr->next;
    
    temp = ptr->next; // store last node in temp
    ptr->next = NULL; // link second last node to NULL
    printf("%d deleted from end of list!\n", temp->data);
    free(temp);
}

void deleteAfterNode(){
    int x;
    printf("Enter node value after which you want to delete: ");
    scanf("%d", &x);
    if (x == 0)
    {
        deleteAtStart();
        return;
    }
    ptr = head;
    // first, reach to the predecessor of desired node 
    while(ptr->data != x){
        ptr = ptr->next;
    }
    // for loop ends and we are at behind desired node 
    temp = ptr->next;
    ptr->next = temp->next;
    printf("%d deleted after node %d.\n", temp->data, x);
    free(temp);
}

void deleteBeforeNode(){
    int x;
    printf("Enter node value before which you want to delete: ");
    scanf("%d", &x);

    ptr = head;
    // first, reach to the predecessor of desired node 
    while (ptr->next != NULL){
        if(ptr->next->next->data == x)
            break;
        ptr = ptr->next;
    }
    // while loop ends and we are at behind the node to be deleted 
    temp = ptr->next;
    ptr->next = temp->next; // link to next node of deleted node
    printf("%d deleted before node %d.\n", temp->data, x);
    free(temp);
}

void deleteAtPosition(){
    int x;
    printf("Enter position at which you want to delete: ");
    scanf("%d", &x);
    if (x == 1)
    {
        deleteAtStart();
        return;
    }
    ptr = head;
    // first, reach to the predecessor of desired node 
    for(int i=1; i<x-1 && ptr->next != NULL; i++){
        ptr = ptr->next;
    }
    // for loop ends and we are at behind desired node 
    temp = ptr->next;
    ptr->next = temp->next;
    printf("%d deleted from position %d.\n", temp->data, x);
    free(temp);
}

void countNodes(){
    // check if the list is empty
    if (head == NULL){
        printf("ERROR: List is currently empty !!\n");
        return;
    }
    int c = 0;
    ptr = head;
    while (ptr != NULL){
        c++;
        ptr = ptr->next;
    } // loop ends
    printf("Linked list has %d nodes.\n", c);
}

void search(){
    int x, pos = 1;
    printf("Enter number to search: ");
    scanf("%d", &x);
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == x)
            break;

        pos++;
        ptr = ptr->next;
    }
    ptr == NULL ? printf("Number not found in list !!\n") : printf("Number found at position %d\n", pos);
}

void reverseList(){
    st *back, *forward;
    back = NULL;
    ptr = head;
    while (ptr!=NULL)
    {
        forward = ptr->next;
        ptr->next = back;
        back = ptr;
        ptr = forward;
    }
    head = back;
}