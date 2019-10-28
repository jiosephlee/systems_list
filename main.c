#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headers.h"

int main() {

  struct node *list = NULL;
  int i;

  printf("\nInitial List <empty>\n");
  printf("Value of List:");
  print_list(list);

  for (i = 9;i > -1; i--){
    list = insert_front(list,i);
    printf("\nInserting at the front, Value: <%d>\n",i);
    printf("Value of List: ");
    print_list(list);
  }

  for(i = 0; i < 2; i++){
    list = remove_node(list, i);
    printf("\nRemoving from the front, Value: <%d>\n",i);
    printf("Value of List: ");
    print_list(list);
  }

  for(i = 3; i < 5; i++){
    list = remove_node(list, i);
    printf("\nRemoving from the middle, Value: <%d>\n",i);
    printf("Value of List: ");
    print_list(list);
  }

  for(i = 9; i > 7; i--){
    list = remove_node(list, i);
    printf("\nRemoving from the end, Value: <%d>\n",i);
    printf("Value of List: ");
    print_list(list);
  }
    list = free_list(list);
    printf("\nEmptying List ... Printing Emptied List: \n");
    print_list(list);
  return 0;
}
