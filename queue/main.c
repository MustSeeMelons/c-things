#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum op_status
{
    OK = 0,
    NOK = 1
} op_status_t;

// XXX a tail would be good, though better to create a seperate `root` queue struct then
typedef struct element
{
    void *data;
    struct element *next;
} queue_t;

typedef struct data
{
    uint8_t v;
} data_t;

queue_t *queue_last(queue_t *const queue)
{
    queue_t const *q = queue;

    if (q == NULL)
    {
        return NULL;
    }

    while (q->next != NULL)
    {
        q = q->next;
    }

    return q;
}

void queue_print(const queue_t *const queue)
{
    queue_t const *q = queue;
    uint8_t i = 0;

    while (q != NULL)
    {
        printf("Q at %d => %d\n\r", i++, ((data_t *)q->data)->v);
        q = q->next;
    }
}

op_status_t queue_push(queue_t **const queue, void *data)
{
    if (queue == NULL)
    {
        return NOK;
    }

    if (*queue == NULL)
    {
        queue_t *node = (queue_t *)malloc(sizeof(queue_t));

        if (node == NULL)
        {
            return NOK;
        }

        node->data = data;
        node->next = NULL;
        *queue = node;
    }
    else
    {
        queue_t *last = queue_last(*queue);

        if (last == NULL)
        {
            printf("Could not get last\n");
            return NOK;
        }

        queue_t *node = (queue_t *)malloc(sizeof(queue_t));

        if (node == NULL)
        {
            return NOK;
        }

        node->data = data;
        node->next = NULL;

        last->next = node;
    }

    return OK;
}

void *queue_pop(queue_t **const queue)
{
    if (queue == NULL)
    {
        return NULL;
    }

    // Get node
    queue_t *node = (*queue);

    if (node == NULL)
    {
        return NULL;
    }

    // Get data
    void *popped_data = node->data;

    // Update reference
    *queue = node->next;

    // Free node
    free(node);

    // Return data
    return popped_data;
}

int main(int argc, char *argv[])
{
    queue_t *queue = NULL;

    data_t one = {.v = 1};
    queue_push(&queue, (void *)&one);

    data_t two = {.v = 2};
    queue_push(&queue, (void *)&two);

    data_t three = {.v = 3};
    queue_push(&queue, (void *)&three);

    queue_print(queue);

    data_t *first = (data_t *)queue_pop(&queue);
    printf("First pop: %d\n\r", first->v);

    data_t *second = (data_t *)queue_pop(&queue);
    printf("Second pop: %d\n\r", second->v);

    data_t *third = (data_t *)queue_pop(&queue);
    printf("Third pop: %d\n\r", third->v);

    if (queue == NULL)
    {
        printf("Queue is empty\n\r");
    }
}