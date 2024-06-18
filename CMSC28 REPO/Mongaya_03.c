//Mongaya CMSC28 K-1L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MSize 10
#define SLENGTH 50

// Define the queue
typedef struct {
    char customer[MSize][SLENGTH];
    float payment[MSize];
    int front;
    int rear;
} Queue;

// To Initialize the queue
void INIT(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Forward declaration of amount function
float amount(Queue *queue);


// To add name and order in the queue
void ENQUEUE(Queue *queue, const char *name, float payment) {
    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    strcpy(queue->customer[queue->rear], name);
    queue->payment[queue->rear] = payment;
}

// To remove name and order from queue
char *DEQUEUE(Queue *queue) {
    if (queue->front == -1) {
        return NULL;
    }

    char *dequeuedCustomer = strdup(queue->customer[queue->front]);
    if (dequeuedCustomer == NULL) {
        return NULL;
    }

    int i;
    for (i = 0; i < queue->rear; i++) {
        strcpy(queue->customer[i], queue->customer[i + 1]);
        queue->payment[i] = queue->payment[i + 1];
    }

    queue->rear--;

    return dequeuedCustomer;
}

// To check if queue is empty
int EMPTY(Queue *queue) {
    return (queue->rear == -1);
}

// To return front string
char *FRONT(Queue *queue) {
    if (queue->rear == -1) {
        return NULL;
    }
    return queue->customer[queue->front];
}


// To return front amount
float amount(Queue *queue) {
    if (EMPTY(queue)) {
        return 0; // If queue is empty, return 0
    }
    return queue->payment[queue->front];
}

// To clear the Queue
void CLEAR(Queue *queue) {
    if (EMPTY(queue)) {
        printf("The QUEUE is EMPTY. No customer/s to serve.\n");
        return;
    }

    while (!EMPTY(queue)) {
        printf("Now serving %s with total amount payable of %.4f.\n", DEQUEUE(queue), amount(queue));
    }
    printf("All customers have been served.\n");
}

// Main Function
int main() {
    Queue queue;
    int choice;
    float payment;
    char name[SLENGTH];

    INIT(&queue);

    // Display checkout system main menu
    do {
        printf("---------------------------------------\n");
        printf("\n\tSHOP SHOP SHOP!!! Counter 0:\n\n");
        printf("\t[1] Fall in Line\n");
        printf("\t[2] Serve Customer\n");
        printf("\t[3] Next Customer\n");
        printf("\t[4] Closing Time\n");
        printf("\t[0] Exit\n");
        printf("\n---------------------------------------\n");
        printf("\tEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\tName of Customer: ");
                scanf("%s", name);
                printf("\tTotal amount payable: ");
                scanf("%f", &payment);
                ENQUEUE(&queue, name, payment);
                break;

            case 2:
                if (!EMPTY(&queue)) {
                    printf("Now serving %s with total amount payable of %.4f.\n", DEQUEUE(&queue), amount(&queue));
                } else {
                    printf("The QUEUE is EMPTY. No orders to serve.\n");
                }
                break;

            case 3:
                if (!EMPTY(&queue)) {
                    printf("Next order: For %s with total amount payable of %.4f.\n", FRONT(&queue), amount(&queue));
                } else {
                    printf("The QUEUE is EMPTY. No order to serve.\n");
                }
                break;

            case 4:
                CLEAR(&queue);
                break;

            case 0:
                printf("\nSystem Closing.....\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);
    return 0;
}

