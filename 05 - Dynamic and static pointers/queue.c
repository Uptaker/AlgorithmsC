#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int queueArray[MAX];
int front = 0;
int rear = -1;
int queueCount = 0;

bool isFull() {
    return queueCount == MAX;
}

bool isEmpty() {
    return queueCount == 0;
}

void enqueue(int data) {
    if(!isFull()) {
	
        queueArray[front] = data;
        front++;
        queueCount++;
    } else {
        printf("\nQueue full!\n");
    }
}

int dequeue() {
    int data = queueArray[front++];
        
    if(front == MAX) {
        front = 0;
    }
        
    queueCount--;
    return data;  
}

int peek() {
    return queueArray[front];
}


void main() {

    while(1) {
        int option, num;
        printf("\n1 = enqueue, 2 = dequeue\n");
        scanf("%d", &option);
        if (option == 1) {
            printf("Number? ");
            scanf("%d", &num);
            enqueue(num);
        }
        else dequeue();

        printf("\nqueueCount: %d\n", queueCount);
        for(int i = 0; i < MAX; i++) {
            printf("%d ", queueArray[i]);
        }

        printf("\n");
    }

}