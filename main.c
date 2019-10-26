struct node {
  int i;
  struct node *next;
};

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

int main() {
  struct node *list = calloc(sizeof(struct node), 1);
  int i;

  printf("\nInitial List <empty>\n",list);
  printf("Value of List:");
  print_list(list);

  for (i = 9;i > -1; i--){
    list = insert_front(list,i);
    printf("\n\nInserting <%d>\n",i);
    printf("Value of List: ");
    print_list(list);
  }
    free_list(list);
    printf("Printing List");
    print_list(list);
  return 0;
}
