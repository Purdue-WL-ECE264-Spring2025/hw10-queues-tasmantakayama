#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) 
{
  // Allocate memory for the node
  struct list_node *new = malloc(sizeof(struct list_node));
  // Check for successful allocation
  if (new == NULL) 
  {
    return NULL;
  }

  // Set value
  new->value = value;
  // There is no next node yet
  new->next = NULL;
  return new;
}

void insert_at_head(struct linked_list *list, size_t value)
{
  // Make a new node
  struct list_node *new = new_node(value);
  // If no head, set the new node as head
  if (list->head == NULL) {
    list->head = new;
  }
  // Otherwise
  else 
  {
    // Set the new node's next to the front of the list
    new->next = list->head;
    // Set the new node as the head
    list->head = new;
  }
}

void insert_at_tail(struct linked_list *list, size_t value) 
{
  // Make a new node
  struct list_node *new = new_node(value);
  // If no head, set the new node as head
  if (list->head == NULL) 
  {
    list->head = new;
  } 
  // Otherwise
  else 
  {
    // Find the last node
    struct list_node *cur = list->head;
    while (cur->next != NULL) 
    {
      cur = cur->next;
    }
    // Set the new node as the last node
    cur->next = new;
  }
}

size_t remove_from_head(struct linked_list *list)
{
  // If nothing is there to remove, return 0
  if (list->head == NULL) {
    return 0;
  }
  // Otherwise, remove the first node
  struct list_node *old_head = list->head;
  size_t value = old_head->value;
  list->head = old_head->next;
  free(old_head);
  // Return the value of the removed node
  return value;
}

size_t remove_from_tail(struct linked_list *list) 
{
  // If nothing is there to remove, return 0
  if (list->head == NULL) 
  {
    return 0;
  }
  // If there is only one node, remove it
  struct list_node *cur = list->head;
  if (cur->next == NULL) 
  {
    size_t value = cur->value;
    free(cur);
    list->head = NULL;
    return value;
  }
  // Otherwise, find the last node
  while (cur->next->next != NULL) {
    cur = cur->next;
  }
  // Remove the last node
  size_t value = cur->next->value;
  free(cur->next);
  cur->next = NULL;
  // Return the value of the removed node
  return value;
}

void free_list(struct linked_list list) 
{
  // Go through the list and free each node
  struct list_node *cur = list.head;
  while (cur != NULL) {
    struct list_node *next = cur->next;
    free(cur);
    cur = next;
  }
  list.head = NULL;
}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
