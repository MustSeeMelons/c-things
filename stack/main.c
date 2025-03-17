#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct data
{
    uint8_t v;
} data_t;

typedef struct stack_node
{
    void *data;
    struct stack_node *next;
} stack_node_t;

/**
 * @brief Prints a pretty stack.
 *
 * @param root_node
 */
void stack_print(stack_node_t *root_node)
{
    if (root_node == NULL)
    {
        printf("Stack empty!\n\r");
    }
    else
    {
        uint8_t index = 0;
        stack_node_t *node = root_node;
        while (node != NULL)
        {
            printf("Element %d: %d\n\r", index, ((data_t *)node->data)->v);

            node = node->next;
            index++;
        }
    }
}

/**
 * @brief Adds new node to the stack, making the new the top.
 * It is a stack, what did you think would happen?
 *
 * @param root_node
 * @param data
 */
void stack_push(stack_node_t **root_node, void *data)
{
    // XXX we should limit the max length, otherwise print will fail
    // Create new node
    stack_node_t *pushed_node = (stack_node_t *)malloc(sizeof(stack_node_t));

    if (pushed_node == NULL)
    {
        return NULL;
    }

    // Set data
    pushed_node->data = data;

    if (*root_node != NULL)
    {
        // Set the current root as the next of the pushed node
        pushed_node->next = *root_node;
    }

    *root_node = pushed_node;
}

/**
 * @brief Returns the top data of the stack.
 *
 * @param node
 * @return void* or NULL
 */
void *stack_pop(stack_node_t **node)
{
    if (*node == NULL)
    {
        return NULL;
    }

    // Dereference our pointer to pointer to get the original pointer pointing to the element
    stack_node_t *temp = *node;

    // Get the data we have to return
    void *return_data = temp->data;

    // Dereference, yielding us the real pointer, and point it to the new node
    *node = (*node)->next;

    // Cleanup or unused stack node
    free(temp);

    // Return the data!
    return return_data;
}

int main(int argc, char *argv[])
{
    data_t one = {.v = 1};
    data_t two = {.v = 2};
    data_t three = {.v = 3};

    stack_node_t *root = NULL;

    stack_push(&root, (void *)&one);
    stack_push(&root, (void *)&two);
    stack_push(&root, (void *)&three);

    stack_print(root);

    // XXX should check for NULL
    // Passing the address of the pointer
    data_t *pop_one = (data_t *)stack_pop(&root);
    data_t *pop_two = (data_t *)stack_pop(&root);
    data_t *pop_three = (data_t *)stack_pop(&root);

    printf("First  pop: %d \n\r", pop_one->v);
    printf("Second pop: %d \n\r", pop_two->v);
    printf("Third  pop: %d \n\r", pop_three->v);
}