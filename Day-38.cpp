#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return (front == -1);
}

// Check full
int isFull() {
    return (front == 0 && rear == MAX - 1);
}

// Push front
void push_front(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        printf("No space at front\n");
        return;
    } else {
        front--;
    }
    deque[front] = x;
}

// Push back
void push_back(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

// Pop front
void pop_front() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Pop back
void pop_back() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

// Display
void display() {
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}