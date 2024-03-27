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
  Item *new_node = (Item*)malloc(sizeof(Item));//create new node

  if(new_node == NULL){
    printf("Error allocating memory for a new node\n");
    return;
  }

  new_node->next=NULL;
  new_node->id = 0; //index 0
  new_node->str = str;

  if (list->root==NULL){//if the head list is empty
    list->root = new_node;//create a node
  }

  //traverse the list
  Item *curr = list->root; //current node is the head
  while (curr->next != NULL){//if the next of the current is not null we move
    curr = curr->next;//move the pointer curr to the next node
  }
  curr->next = new_node;
  
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
