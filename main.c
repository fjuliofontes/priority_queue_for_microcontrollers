#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main() {
    node_t *head = NULL;
    node_t *result = malloc(sizeof(node_t));
    uint8_t package[20],i;
    uint8_t retval;

    /* First Example : shows that messages with the same priority are
    organized following the behavior of a FIFO */
    package[0] = '0'; package[1] = 'a';
    retval = q_push(&head, package, 2, 0);
    _printf("retval = %u \r\n",retval);
    package[0] = '2'; package[1] = 'a';
    retval = q_push(&head, package, 2, 2);
    _printf("retval = %u \r\n",retval);
    package[0] = '0'; package[1] = 'b';
    retval = q_push(&head, package, 2, 0);
    _printf("retval = %u \r\n",retval);
    package[0] = '2'; package[1] = 'b';
    retval = q_push(&head, package, 2, 2);
    _printf("retval = %u \r\n",retval);
    package[0] = '2'; package[1] = 'c';
    retval = q_push(&head, package, 2, 2);
    _printf("retval = %u \r\n",retval);

    /* Print the priority queue list */
    print_list(head);

    /* Second Example : shows that isFull() is working */
    for (i = 0; i < 5; i ++){
      package[0] = (char)i; package[1] = 'a';
      retval = q_push(&head, package, 2, 0);
      _printf("retval = %u \r\n",retval);
    }

    /* Third Example : shows that isEmpty() is working */
    while(q_pull(&result,&head) == 0){
        _printf("Prio = %c%c\r\n",result->data[0],result->data[1]);
    }

    /* Fourth Example : shows that priority queue is working */
    for (i = 0; i < 5; i ++){
      package[0] = (char)i; package[1] = 'a';
      retval = q_push(&head, package, 2, i);
      _printf("retval = %u \r\n",retval);
    }

    /* Print the priority queue list */
    print_list(head);

    /* Free queue */
    while(q_pull(&result,&head) == 0);

    /* Sixt Example : shows that mantaining the same priority
    a normal behavior of a FIFO is presented */
    for (i = 0; i < 5; i ++){
      package[0] = i;
      retval = q_push(&head, package, 1, 7);
      _printf("retval = %u \r\n",retval);
    }
    while(q_pull(&result,&head) == 0){
        _printf("Prio = %i Val = %i\r\n",result->prio,result->data[0]);
    }

    _printf("done. head=%p\n", head);

    return 0;
}
