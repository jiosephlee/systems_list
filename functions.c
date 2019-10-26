struct node {
  int i;
  struct node *next;
};
void print_list(struct node * p){
  printf("[ ");
  while(p->next != 0){
    printf("%d  ", p->i);
    p = p->next;
  }
  printf(" ]\n");
}
struct node * insert_front(struct node * p, int input){
  struct node * new_starting_node = calloc(sizeof(struct node),1);
  new_starting_node->i = input;
  new_starting_node->next = p;
  return new_starting_node;
}
struct node * free_list(struct node * p){
  struct node * placeholder;
  while(p->next != 0){
    placeholder = p;
    p = p->next;
    free(placeholder);
  }
  if(p->next == 0){
    free(p);
  }
}
