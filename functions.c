#include <stddef.h>
struct node {
  int i;
  struct node *next;
};

void print_list(struct node * p){
  printf("[");
  while(p != NULL){
    if (p->next == 0){
      printf("%d", p->i);
      p = p->next;
    } else{
      printf("%d, ", p->i);
      p = p->next;
    }
  }
  printf("]\n");
}

struct node * insert_front(struct node * p, int input){
  struct node * new_starting_node = calloc(sizeof(struct node),1);
  new_starting_node->i = input;
  new_starting_node->next = p;
  return new_starting_node;
}

struct node * free_list(struct node * p){
  struct node * placeholder;
  while(p != NULL){
    placeholder = p;
    p = p->next;
    free(placeholder);
  }
  return p;
}

struct node * remove_node(struct node *front, int data){
  struct node * p = front;
  struct node * placeholder;
  if(front->i == data){ //if I have to remove front node, it's a special case
    p = p->next;
    free(front);
    return p;
  }
  while(p->next != NULL){ //else, loop through, checking if my next node has to be removed
    if (p->next->i == data){ //if it does have to be removed, relink neccesary nodes, and free node
      placeholder = p->next;
      p->next = p->next->next;
      p = p->next;
      free(placeholder);
      return front;
    } else{ //if not, move on to next node
      p = p->next;
    }
  }
  return front;
}
