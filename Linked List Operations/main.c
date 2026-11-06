#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL;

void display() {
    struct Node *t = head;
    printf("List: ");
    while (t) { printf("%d -> ", t->data); t = t->next; }
    printf("NULL\n");
}

void insertBeg(int v) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = v; n->next = head; head = n; display();
}

void insertEnd(int v) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node)), *t = head;
    n->data = v; n->next = NULL;
    if (!head) head = n;
    else { while (t->next) t = t->next; t->next = n; }
    display();
}

void insertPos(int v, int pos) {
    if (pos == 1) { insertBeg(v); return; }
    struct Node *n = (struct Node *)malloc(sizeof(struct Node)), *t = head;
    n->data = v;
    for (int i = 1; i < pos - 1 && t; i++) t = t->next;
    if (t) { n->next = t->next; t->next = n; }
    display();
}

void insertSorted(int v) {
    if (!head || head->data >= v) { insertBeg(v); return; }
    struct Node *n = (struct Node *)malloc(sizeof(struct Node)), *t = head;
    n->data = v;
    while (t->next && t->next->data < v) t = t->next;
    n->next = t->next; t->next = n; display();
}

void deleteBeg() {
    if (!head) return;
    struct Node *t = head; head = head->next; free(t); display();
}

void deleteEnd() {
    if (!head) return;
    if (!head->next) { free(head); head = NULL; display(); return; }
    struct Node *t = head;
    while (t->next->next) t = t->next;
    free(t->next); t->next = NULL; display();
}

void deleteVal(int v) {
    if (!head) return;
    if (head->data == v) { deleteBeg(); return; }
    struct Node *t = head;
    while (t->next && t->next->data != v) t = t->next;
    if (t->next) { struct Node *del = t->next; t->next = del->next; free(del); }
    display();
}

void searchNode(int v) {
    struct Node *t = head; int pos = 1;
    while (t) { if (t->data == v) { printf("Found at pos %d\n", pos); return; } t = t->next; pos++; }
    printf("Not found.\n");
}

void reverseList() {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) { next = curr->next; curr->next = prev; prev = curr; curr = next; }
    head = prev; display();
}

void removeDuplicates() {
    struct Node *p1 = head, *p2, *dup;
    while (p1 && p1->next) {
        p2 = p1;
        while (p2->next) {
            if (p1->data == p2->next->data) {
                dup = p2->next; p2->next = p2->next->next; free(dup);
            } else p2 = p2->next;
        }
        p1 = p1->next;
    }
    display();
}

void stats() {
    if (!head) return;
    int c = 0, sum = 0, max = head->data, min = head->data;
    for (struct Node *t = head; t; t = t->next) {
        c++; sum += t->data;
        if (t->data > max) max = t->data;
        if (t->data < min) min = t->data;
    }
    printf("Total Nodes: %d | Sum: %d | Max: %d | Min: %d\n", c, sum, max, min);
}

int main() {
    insertEnd(10); insertEnd(30); insertBeg(5);
    insertSorted(20); insertEnd(20);
    printf("After Removing Duplicates -> "); removeDuplicates();
    searchNode(20);
    stats();
    printf("Reversed -> "); reverseList();
    deleteVal(20);
    return 0;
}