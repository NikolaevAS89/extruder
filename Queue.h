#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE (1<<5)
#define increaseIndex(index) ((index+1)&(QUEUE_SIZE-1))

struct Queue {
  unsigned char tail;
  unsigned char head;
  unsigned char buf[QUEUE_SIZE];
};

void put(struct Queue *queue, unsigned char byte);
unsigned char pop(struct Queue *queue);
unsigned char isEmpty(struct Queue *queue);

#endif //QUEUE_H
