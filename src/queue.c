#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void enqueue(struct queue_t * q, struct pcb_t * proc) {
    if (q == NULL || proc == NULL) return;
    
    if (q->size == MAX_QUEUE_SIZE) {
        // Queue is full, cannot enqueue
        return;
    }
    
    // Find the correct position to insert (maintain priority order)
    int i = q->size - 1;
    while (i >= 0 && q->proc[i]->prio < proc->prio) {
        q->proc[i + 1] = q->proc[i];
        i--;
    }
    
    q->proc[i + 1] = proc;
    q->size++;
}

struct pcb_t * dequeue(struct queue_t * q) {
    if (q == NULL || q->size == 0) {
        return NULL; // Queue is empty
    }
    
    struct pcb_t * highest_priority_proc = q->proc[0];
    
    // Shift remaining elements to fill the gap
    for (int i = 0; i < q->size - 1; i++) {
        q->proc[i] = q->proc[i + 1];
    }
    
    q->size--;
    return highest_priority_proc;
}
