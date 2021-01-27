#include "queue.h"

void put(struct Queue *queue, unsigned char byte) {
    queue->buf[queue->head] = byte;
    queue->head=increaseIndex(queue->head);
}

unsigned char pop(struct Queue *queue) {
    unsigned char byte = queue->buf[queue->tail];
    queue->tail = increaseIndex(queue->tail);
    return byte;
}

unsigned char isEmpty(struct Queue *queue) {
    return (queue->tail==queue->head);
}
