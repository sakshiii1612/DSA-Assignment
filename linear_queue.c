#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Insert an element into the queue
void insert(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;
        printf("%d inserted\n", value);
    }
}

// Delete an element from the front
void deleteElement() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("%d deleted\n", queue[front]);
        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }
}

// Display queue elements
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Remaining elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    deleteElement();
    deleteElement();

    insert(40);

    display();

    return 0;
}
