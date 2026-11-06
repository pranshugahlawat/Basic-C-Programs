#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

int isEmpty() { return front == -1 || front > rear; }
int isFull() { return rear == MAX - 1; }

void enqueue(int val) {
    if (isFull()) { printf("Queue Overflow!\n"); return; }
    if (front == -1) front = 0;
    q[++rear] = val;
    printf("Enqueued %d\n", val);
}

void dequeue() {
    if (isEmpty()) { printf("Queue Underflow!\n"); return; }
    printf("Dequeued %d\n", q[front++]);
}

void peek() {
    if (isEmpty()) printf("Queue is Empty!\n");
    else printf("Front Element: %d\n", q[front]);
}

void display() {
    if (isEmpty()) { printf("Queue is Empty!\n"); return; }
    printf("Queue Elements: ");
    for (int i = front; i <= rear; i++) printf("%d ", q[i]);
    printf("\n");
}

int main() {
    int ch, val;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
        }
    } while (ch != 5);
    return 0;
}