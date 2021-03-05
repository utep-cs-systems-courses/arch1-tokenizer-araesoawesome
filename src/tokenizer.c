#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int space_char(char c){
  if(c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(c != '\t' || c != ' ' || c != '\0'){
    return 1;
  }
  return 0;
}

char *word_start(char *str){
  int i = 0;
  while(space_char(str[i]) == 1){
    if(str[i] == '\0'){
      return NULL;
    }
    i++;
  }
  return &str[i];
}

char *word_terminator(char *word){
  word  = word_start(word);
  int i = 0;
  
  while(non_space_char(word[i]) == 1){
    if(word[i] == '\0'){
      return NULL;
    }
    i = i+1;
  }
  
  return &word[i];
}

int count_words(char *str){
  int index = 0;
  int counter = 0;
  while(str[index] != '\0'){
    while(space_char(*(str+index))){
      index = index + 1;
    }
    if(non_space_char(*(str+index))){
      counter = counter + 1;
    }
    while(non_space_char(*(str+index))){
      index = index + 1;
    }
  }
  return counter;
}

char *copy_str(char *inStr, short len){
  int i = 0;
  //MALLOC FOR NEW STR :D
  char *outStr = malloc((len+1) *sizeof(char));
  if (outStr == NULL) {
    fprintf(stderr, "error: allocating memory\n");
    return NULL;
  }
  
  while(i<len){
    outStr[i]  = inStr[i];
    i= i+1;
  }
  outStr[i] = '\0';
  return outStr;
}

char **tokenize(char *str){
  int i = 0;
  int all = count_words(str);
  char **tokens = (char**)malloc((all+1) * sizeof(char*));
  if (tokens == NULL) {
    fprintf(stderr, "error: allocating memory\n");
    return NULL;
  }
  char *start = str, *end = str;

  while(i <= all){
    start = word_start(end);
    end = word_terminator(start);
    tokens[i] = copy_str(start, end - start);
    i++;
  }
  tokens[i] = NULL;
  return tokens;
}

void print_tokens(char **tokens){
  int i = 0;
  while(tokens[i] !=  NULL){
    printf("%s\n", tokens[i]);
    i =  i + 1;
  }
}

void free_tokens(char **tokens){
  int i = 0;
  //can't pass  len as param  :D
  while(tokens[i] != 0){
    free(tokens[i]);
    i = i + 1;
  }
  free(tokens);
}
