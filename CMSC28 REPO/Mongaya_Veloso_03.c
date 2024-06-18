// VELOSO & MONGAYA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10
#define STR_LENGTH 50

// Define the stack
typedef struct {
    char items[MAX_SIZE][STR_LENGTH];
    int top;
} Stack;

// Initialize stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Check if stack is empty
int EMPTY(Stack *stack) {
    return (stack->top == -1);
}

// Check if stack is full
int FULL(Stack *stack) {
    return (stack->top == (MAX_SIZE - 1));
}

// Push a string onto the stack
void PUSH(Stack *stack, const char *name) {
    if (FULL(stack)) {
        printf("The STACK is FULL. Cannot add kitchenware.\n");
        return;
    }
    strcpy(stack->items[++(stack->top)], name);
}

// Pop a string from the stack
char *POP(Stack *stack) {
    if (EMPTY(stack)) {
        return NULL;
    }
    return stack->items[(stack->top)--];
}

// Return top string
char *TOP(Stack *stack) {
    if (EMPTY(stack)) {
        return NULL;
    }
    return stack->items[stack->top];
}

// Clears the Stack
void MAKENULL(Stack *stack) {
    while(!EMPTY(stack)){
        printf("The %s is being washed.\n", POP(stack));
    }
    printf("No more kitchenware to wash.\n");
}

int main() {
    Stack stack;
    int choice;
    char name[STR_LENGTH];
    initialize(&stack);
    
    // Display menu loop
    do{
    	printf("=================================\n");
        printf("\tLIST MENU\n");
        printf("\t[1] Add Kitchenware\n");
        printf("\t[2] Wash Kitchenware\n");
        printf("\t[3] Top Kitchenware\n");
        printf("\t[4] Wash All\n");
        printf("\t[0] Exit\n");
        printf("=================================\n");
		printf("\tEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the name of kitchenware: ");
                scanf("%s", &name);
                PUSH(&stack, name);
                break;
            case 2:
                if(!EMPTY(&stack)){
                    printf("The %s is being washed.\n", POP(&stack));
                } else {
                    printf("The STACK is EMPTY. No kitchenware to wash.\n");
                }
                break;
            case 3:
                if(!EMPTY(&stack)){
                    printf("%s is next to be washed.\n", TOP(&stack));
                } else {
                    printf("The STACK is EMPTY. No kitchenware to wash.\n");
                }
                break;
            case 4:
                MAKENULL(&stack);
                break;
            case 0:
                printf("Closing washing machine... Thank you for using.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while (choice != 0);
    return 0;
}
