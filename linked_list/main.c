/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief A linked list implementation where the user must handle allocation/freeing element data. Takes no ownership.
 * @version 0.1
 * @date 2024-02-25
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef enum list_status
{
    LIST_OK = 0,
    LIST_NOK = 1
} list_status_t;

typedef struct linked_list_node
{
    void *data;
    struct linked_list_node *next;
} linked_list_node_t;

typedef struct
{
    uint8_t v;
} list_item_t;

/**
 * @brief Returns the last element in the list
 *
 * @param list
 * @return linked_list_node_t* or NULL
 */
static linked_list_node_t *linked_list_get_tail(linked_list_node_t *const list)
{
    if (list == NULL)
    {
        return NULL;
    }

    linked_list_node_t *p = list;

    while (p->next != NULL)
    {
        p = p->next;
    }

    return p;
}

/**
 * @brief Return list item at index
 *
 * @param list head node
 * @param index item at index to get
 * @return linked_list_node_t* or NULL
 */
linked_list_node_t *linked_list_get(linked_list_node_t *const list, uint8_t index)
{
    linked_list_node_t *p = list;

    for (uint8_t i = 0; i < index; i++)
    {
        if (p->next != NULL)
        {
            p = p->next;
        }
        else
        {
            return NULL;
        }
    }

    return p;
}

/**
 * @brief Adds an item to the rear
 *
 * @param list head element
 * @param element the new data
 * @return linked_list_node_t*
 */
list_status_t linked_list_push(linked_list_node_t **const list, void *element)
{
    if (*list == NULL)
    {
        linked_list_node_t *node = malloc(sizeof(linked_list_node_t));

        if (node == NULL)
        {
            return LIST_NOK;
        }

        node->data = element;
        node->next = NULL;

        *list = node;

        return LIST_OK;
    }

    linked_list_node_t *tail = linked_list_get_tail(*list);

    // We have data in the head, add a new node with the data
    linked_list_node_t *node = malloc(sizeof(linked_list_node_t));

    if (node != NULL)
    {
        tail->next = node;
        node->data = element;
        node->next = NULL;
    }
    else
    {
        return LIST_NOK;
    }

    return LIST_OK;
}

/**
 * @brief Removes the element at the specified index from.
 * Does not free memory of the data!
 *
 * @param list pointer to head element
 * @param index index we wish to remove
 * @return linked_list_node_t* as the head node or NULL if last element is removed
 */
list_status_t linked_list_remove(linked_list_node_t **const list, uint8_t index)
{
    if (list == NULL)
    {
        return LIST_NOK;
    }

    if (index == 0)
    {
        if ((*list)->next != NULL)
        {
            // If we have a next, that is the new head
            linked_list_node_t *new_head = (*list)->next;

            free(*list);

            *list = new_head;

            return LIST_OK;
        }
        else
        {
            // Node head - no more list
            free(*list);

            *list = NULL;

            return LIST_OK;
        }
    }
    else
    {
        linked_list_node_t *prev = linked_list_get(*list, index - 1);

        // We are out of bounds
        if (prev == NULL)
        {
            return LIST_NOK;
        }

        linked_list_node_t *curr = prev->next;

        // We are still out of bounds
        if (curr == NULL)
        {
            return LIST_NOK;
        }

        prev->next = curr->next;

        free(curr);

        return LIST_OK;
    }
}

/**
 * @brief Insert item into a index
 *
 * @param list head node
 * @param index index into which to insert
 * @param element the data to insert
 * @return linked_list_node_t* head node
 */
list_status_t linked_list_insert(linked_list_node_t **list, uint8_t index, void *element)
{
    // No list? It a push!
    if (list == NULL)
    {
        return linked_list_push(list, element);
    }

    linked_list_node_t *target_node = linked_list_get(*list, index);

    // Get node after, if any
    linked_list_node_t *after = target_node != NULL ? target_node->next : NULL;

    // This is just a push
    if (after == NULL)
    {
        return linked_list_push(list, element);
    }

    // Create a new node to insert after target_node
    linked_list_node_t *new_node = malloc(sizeof(linked_list_node_t));

    if (new_node == NULL)
    {
        return LIST_NOK;
    }

    // New node points to the one after the target
    new_node->next = after;
    // New node gets data of the target
    new_node->data = target_node->data;

    // The one in the target index points to our new node
    target_node->next = new_node;
    // Assign the new data
    target_node->data = element;

    return LIST_OK;
}

/**
 * @brief Returns the element count/length of the list.
 *
 * @param list head node
 * @return uint8_t
 */
uint8_t linked_list_length(linked_list_node_t const *const list)
{
    uint8_t len = 1;
    linked_list_node_t const *p = list;

    if (list == NULL)
    {
        return 0;
    }

    while (true)
    {
        if (p->next != NULL)
        {
            len++;
            p = p->next;
        }
        else
        {
            break;
        }
    }

    return len;
}

/**
 * @brief
 *
 * @param list head node
 */
void pretty_print_list(linked_list_node_t const *const list)
{
    linked_list_node_t const *p = list;

    printf("\n\r");

    uint8_t counter = 0;
    while (p != NULL)
    {
        printf("Item %d, data: %d\r\n", counter, ((list_item_t *)p->data)->v);

        p = p->next;
        counter++;
    }

    printf("\n\r");
}

int main(int argc, char *argv[])
{
    // Empty list of `linked_list_node_t`
    linked_list_node_t *list = NULL;

    // Push a few elements
    list_item_t item_1 = {.v = 1};
    linked_list_push(&list, (void *)&item_1);

    list_item_t item_2 = {.v = 2};
    linked_list_push(&list, (void *)&item_2);

    list_item_t item_3 = {.v = 3};
    linked_list_push(&list, (void *)&item_3);

    // Insert an element after the tail
    list_item_t item_4 = {.v = 4};
    linked_list_insert(&list, 5, (void *)&item_4);

    printf("After push:\n\r");
    pretty_print_list(list);

    // Perform a few valid insertions
    list_item_t item_5 = {.v = 5};
    linked_list_insert(&list, 0, (void *)&item_5);

    list_item_t item_6 = {.v = 6};
    linked_list_insert(&list, 3, (void *)&item_6);

    printf("After insert:\n\r");
    pretty_print_list(list);

    // Remove the 5th element
    linked_list_remove(&list, 4);

    printf("After all:\n\r");
    pretty_print_list(list);

    uint8_t list_len = linked_list_length(list);
    printf("List length: %d\r\n\n", list_len);

    // Remove it all
    for (int16_t i = list_len - 1; i > -1; i--)
    {
        linked_list_remove(&list, i);
    }

    if (list == NULL)
    {
        printf("List is empty\n\r");
    }

    return 0;
}