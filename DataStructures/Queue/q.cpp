/*
    unlike stack which has last in first out policy, queue follows first in first out policy. the element that was inserted first is going to be removed first. (ex. line of people in a queue).

    the insertion operation is called ENQUEUE and delete operation is called DEQUEUE.

    insertion occurs at tail index and deletion occurs at head index.
*/
#include <queue>
#include <iostream>
using namespace std;


#define MAX 50
struct Queue {
    int arr[MAX];
    // empty queue
    int head, tail;
};

// define the queue
void initQueue(struct Queue* q) {
    q->head = -1;
    q->tail = -1;
}

// checker fn
int isFull(struct Queue* q) {
    return q->tail == MAX-1;
}

int isEmpty(struct Queue* q) {
    return q->head == -1 || q->head > q->tail;
}

void enqueue(struct Queue* q, int data) {
    if(isFull(q)) {
        cout << "q is full!\n";
        return;
    }
    if(q->head == -1) {
        q->head = 0;
    }
    q->tail++;
    q->arr[q->tail] = data;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        cout << "q is empty!\n";
        return;
    }

    int removed = q->arr[q->head];
    q->head++;

    return removed;
}