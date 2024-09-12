#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    double data;
    struct node_t* next;
} node_t;

typedef struct queue_t {
    node_t* front;
    node_t* rear;
} queue_t;

queue_t* create_queue() {
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(queue_t* q, double value) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = value;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

double dequeue(queue_t* q) {
    if (q->front == NULL) {
        return -1;
    }
    node_t* temp = q->front;
    double value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}