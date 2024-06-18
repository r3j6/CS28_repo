#include <stdio.h>
#include <stdlib.h>

//Function prototypes
struct Node* NEWNODE(int data);
void insertAtStart(struct Node** headRef, int data);
void insertAtEnd(struct Node** headRef, int data);
void insertSpecific(struct Node** headRef, int data, int pos);
void deleteItem(struct Node** headRef, int data);
void displayList(struct Node* head);
void deleteList(struct Node** headRef);

//Node structure
struct Node{
    int data;
    struct Node* next;
};

int main(){
    struct Node* head = NULL;
    int choice, data, pos;
    do{
    	printf("\n=================================\n");
        printf("\tLIST MENU\n");
        printf("\t[1] Add Item\n");
        printf("\t[2] Delete Item\n");
        printf("\t[3] Display List\n");
        printf("\t[4] Delete List\n");
        printf("\t[0] Exit Program\n");
        printf("=================================\n");
		printf("\tEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            	printf("=================================\n");
                printf("Please enter the item to be added [number only]: ");
                scanf("%d", &data);
                printf("Where to add the item?\n");
                printf("[1] Start of the list\n");
                printf("[2] End of the list\n");
                printf("[3] Specific position\n");
                printf("[0] Cancel\n");
                printf("Enter choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        insertAtStart(&head, data);
                        break;
                    case 2:
                        insertAtEnd(&head, data);
                        break;
                    case 3:
                        printf("Enter the position to insert: ");
                        scanf("%d", &pos);
                        insertSpecific(&head, data, pos);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 2:
                printf("Enter the item to delete: ");
                scanf("%d", &data);
                deleteItem(&head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                deleteList(&head);
                printf("The list has been emptied!\n");
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while (choice != 0);
    return 0;
}

//Function to create a new node using the NEWNODE function
struct Node* NEWNODE(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert a node at the start of the list
void insertAtStart(struct Node** headRef, int data){
    struct Node* newNode = NEWNODE(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** headRef, int data){
    struct Node* newNode = NEWNODE(data);
    if (*headRef == NULL){
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node at a specific position in the list
void insertSpecific(struct Node** headRef, int data, int pos){
    if(pos <= 0){
        printf("Invalid position!\n");
        return;
    }
    if(pos == 1){
        insertAtStart(headRef, data);
        return;
    }
    struct Node* newNode = NEWNODE(data);
    struct Node* current = *headRef;
    int i;
    for(i = 1; i < pos - 1 && current != NULL; ++i){
        current = current->next;
    }
    if(current == NULL){
        printf("Position out of range, adding to the end of the list...\n");
        insertAtEnd(headRef, data);
    }else{
        newNode->next = current->next;
        current->next = newNode;
    }
}

//Function to delete an item from the list
void deleteItem(struct Node** headRef, int data){
    struct Node* temp = *headRef;
    struct Node* prev = NULL;

    while(temp != NULL && temp->data != data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("The list contains no such element.\n");
        return;
    }
    if(prev == NULL){
        *headRef = temp->next;
    }else{
        prev->next = temp->next;
    }
    printf("The element %d has been deleted.\n", temp->data);
    free(temp);
}
//Function to display the content of the list
void displayList(struct Node* head){
	printf("=================================\n");
    printf("List contents:\n");
    int pos = 1;
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
        pos++;
    }
}
//Function to delete the entire list
void deleteList(struct Node** headRef){
    struct Node* current = *headRef;
    struct Node* next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}