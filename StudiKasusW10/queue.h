/*File header untuk ADT Queue*/

#ifndef queue_h
#define queue_h
#include "boolean.h"
#include "linked.h"
#define NBElement 10


typedef struct Queue {
    address_list front;
    address_list rear;
} Queue;

/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue (Queue *Q);

/*Memeriksa apakah queue kosong */
boolean is_Empty (Queue Q);

/*Memeriksa apakah queue penuh */
boolean is_Full (Queue Q);

/*Melekukan insertion pada queue*/
void EnQueue (Queue *Q, infotype_list X);

/*Melakukan deletion pada queue*/
void deQueue (Queue *Q, infotype_list *X);

/* Print queue */
void PrintQueue(Queue q);

#endif