
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Circular Queue is full\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d inserted\n", value);
}

void deleteElement() {
    if (front == -1) {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("%d deleted\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    deleteElement();
    deleteElement();

    insert(50);
    insert(60);

    display();

    return 0;
}
