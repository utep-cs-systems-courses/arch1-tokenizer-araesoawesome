#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history() {
  List *history;
  //MALLOC FOR THE LIST :D
  history = (List*) malloc(sizeof(List));
  
  //list root null
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str){
  Item *item = (Item*) malloc(sizeof(Item));

  //if first item :)
  if(list->root == NULL){
    item->id = 1;
    list->root = item;
  }
  
  else{
    Item *nextItem = list->root;
    while(nextItem->next != NULL){
      nextItem = nextItem->next;
    }
    nextItem->next = item;
    item -> id = nextItem -> id+1;
  }
  
  item->str = str;
  item->next=NULL;
}

char *get_history(List *list, int id) {
  // list empty
if (list->root == NULL) {
  return "Empty History.\n";
}
 
else {
  Item* nextItem = list->root;
  
  while (nextItem != NULL) {
    if (nextItem->id == id){
      return nextItem->str;
    }
    nextItem = nextItem->next;
  }
  
  return "ID not found.\n";
  }
}

void print_history(List *list) {
  //same algorithm in get_history, loops thru list
  Item* nextItem = (list->root);
  
  while (nextItem != NULL) {
   printf("Item [%d]: %s \n", nextItem->id, nextItem->str);
   nextItem = nextItem->next;
  }
}

void free_history(List *list) {
  Item* nextItem;
  Item* nextestItem;
  
  nextestItem = list->root;

  //only need to keep track of second iterator
  while (nextestItem != NULL) {
    nextItem = nextestItem;
    nextestItem = nextestItem->next;
    free(nextItem);
  }
  free(list);
}
