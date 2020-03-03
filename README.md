# Priority Queue for Microcontrollers

### This repository contains a simple implementation of a priority queue for microcontrollers, like Texas MSP430, Arduino and so on. 

#### This Priority Queue was implemented in a wireless network for traffic management (QoS) and the node_t structure contains the necessary parameters for my application. However, this structure can be easily modified for something else.

##### In *Examples* folder you can compile the software, and test it by yourself. For that you need to type:
```
mkdir build && cd build
cmake ..
make
./queue
```

##### node_t structure:
```
typedef struct node {
    uint8_t prio;
    uint8_t datalen;
    uint8_t data[RFM69H_MAX_MESG_SIZE];
    struct node *next;
} node_t;
```
##### functions:

```
uint8_t q_push(node_t **head, uint8_t *data, uint8_t datalen, uint8_t prio);
```
```
uint8_t q_pull(node_t **result, node_t **head);
```
```
void print_list(node_t *head);
```
```
uint8_t isEmpty();
```
```
uint8_t isFull();
```
