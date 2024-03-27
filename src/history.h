#ifndef _HISTORY_
#define _HISTORY_

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *new_list =(List*)malloc(sizeof(List));//memory allocation
  if (new_list != NULL){
    new_list->root = NULL; //Empty list
    return new_list;
  }
  printf("Error allocating memory for new list\n");
  return NULL;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Node *new_node = (Node*)malloc(sizeof(Node));//create new node

  if(new_node == NULL){
    printf("Error allocating memory for a new node\n");
    return NULL;
  }

  new_node->next=NULL;
  
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id);

/*Print the entire contents of the list. */
void print_history(List *list);

/*Free the history list and the strings it references. */
void free_history(List *list);

#endif
