
#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

void insertFront(int value) {
    if ((front == 0 && rear == SIZE - 1) ||
        (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }

    deque[front] = value;
    printf("%d inserted at Front\n", value);
}

void insertRear(int value) {
    if ((front == 0 && rear == SIZE - 1) ||
        (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
    printf("%d inserted at Rear\n", value);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("%d deleted from Front\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("%d deleted from Rear\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Remaining elements: ");
    int i = front;

    while (1) {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main() {
    insertFront(10);
    insertRear(20);
    insertFront(30);

    deleteFront();
    deleteRear();

    display();

    return 0;
}
