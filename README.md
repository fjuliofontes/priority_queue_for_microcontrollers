# priority_queue_for_microcontrollers

This repository contains a simple implementation of a priority queue for microcontrollers, like Texas MSP430 and so on. 
There is a simple main function that explains how everything work.

Below there are the several functions developed:

typedef struct node {
    uint8_t prio;
    uint8_t datalen;
    uint8_t data[RFM69H_MAX_MESG_SIZE];
    struct node *next;
} node_t;

 * uint8_t q_push(node_t **head, uint8_t *data, uint8_t datalen, uint8_t prio);
 * Input: node_t head pointer, uint8_t data pointer, data length and priority
 * Output: retval
 * Brief description:
 * This function add the following message to the head queue
 *  -On success returns 0
 *  -On error returns 1 : in case of being full or returns 2 : in case of malloc error

uint8_t q_push(node_t **head, uint8_t *data, uint8_t datalen, uint8_t prio);


 * uint8_t q_pull(node_t **result, node_t **head);
 * Input: node_t result pointer, node_t head pointer
 * Output: retval
 * Brief description:
 * This function pulls the most priority element from the queue
 *  -On success returns 0
 *  -On error returns 1 : is empty

uint8_t q_pull(node_t **result, node_t **head);

 * void print_list(node_t *head);
 * Input: null
 * Output: null
 * Brief description:
 * This function prints all the elements on the queue

void print_list(node_t *head);

 * uint8_t isEmpty();
 * Input: null
 * Output: retval
 * Brief description:
 *  -If is Empty returns 1
 *  -If is not Empty returns 0

uint8_t isEmpty();

 * uint8_t isFull();
 * Input: null
 * Output: retval
 * Brief description:
 *  -If is Full returns 1
 *  -If is not Full returns 0

uint8_t isFull();
