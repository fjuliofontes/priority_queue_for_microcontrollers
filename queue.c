#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static uint8_t q_length = 0;

uint8_t isFull(){
    if(q_length >= QUEUE_MAX_SIZE){
        return 1;
    }else{
        return 0;
    }
}

uint8_t isEmpty(){
    if(q_length == 0){
        return 1;
    }else{
        return 0;
    }
}

uint8_t q_push(node_t **head, uint8_t *data, uint8_t datalen, uint8_t prio) {
    if(isFull() == 0){
        uint8_t i;
        node_t *current, *prev = NULL;
        node_t *new_node = malloc(sizeof(node_t));
        if (!new_node){ return 2; }
        new_node->prio    = prio;
        new_node->datalen = datalen;
        for(i = 0; i < datalen; i++){ new_node->data[i] = data[i]; }

        // If is the first node, add it right the way
        // Otherwise organize it accordently to the priority
        if(*head == NULL){                 // first time
            new_node->next = *head;
            *head = new_node;
        }else if((*head)->prio >= prio){   // head have a bigger or equal priority
            current = *head;
          while ((current->next != NULL) && (current->prio >= prio)) {
              prev = current;
              current = current->next;
          }
          if(prev != NULL){
              if(prev->prio == prio){
                  new_node->next = prev->next;
                  prev->next = new_node;
              }else{
                  new_node->next = current->next;
                  current->next = new_node;
              }
          }else{
              new_node->next = current->next;
              current->next = new_node;
          }
        }else{                            // new data have a bigger priority
            new_node->next = *head;
            *head = new_node;
        }
        q_length ++;
        return 0; // ok :)
    }else{
        return 1; // isFull
    }
}

uint8_t q_pull(node_t **result, node_t **head) {
    if(isEmpty() == 0){
        node_t *current, *next;
        uint8_t i;

        current = *head;
        next    = (*head)->next;

        (*result)->datalen = current->datalen;
        for(i = 0; i < (*result)->datalen; i++){ (*result)->data[i] = current->data[i]; }
        (*result)->prio = current->prio;

        free(current);

        if(next != NULL) { *head = next; }
        else { *head = NULL; }
        q_length --;
        return 0; // ok :)
    }else{
        return 1; // isEmpty
    }
}

void print_list(node_t *head) {
    uint8_t i;
    node_t *current = head;
    while (current != NULL) {
        _printf("MESG PRIO %d | MESG LEN %d | MESG DATA ", current->prio, current->datalen);
        for (i = 0; i < current->datalen; i++){
            _printf("%c ", current->data[i]);
        }
        _printf("\r\n");
        current = current->next;
    }
}
