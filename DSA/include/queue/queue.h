#include <stdint.h>
#include <stdio.h>
struct queue
{
    size_t size;
    int rear;
    int front;
    int* queue_array;

};
