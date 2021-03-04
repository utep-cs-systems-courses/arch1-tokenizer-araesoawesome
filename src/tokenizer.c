#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c){
  if(c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(c != '\t' || c != ' '){
    return 1;
  }
  return 0;
}

char *word_start(char *str){
  int i = 0;
  while(space_char(str[i]) == 1){
    i++;
  }
  return &str[i];
}

char *word_terminator(char *word){
  word  = word_start(word);
  int i = 0;
  
  while(non_space_char(word[i]) == 1){
    i = i+1;
  }
  
  return &word[i];
}

int count_words(char *str){
  int count = 0;
  int i = 0;
  while(str[i] != '\0') {
      if(space_char(str[i]) && non_space_char(str[i + 1]))
	count++;
      i++;
    }
    count++;
  return count;
}

char  *copy_str(char *inStr, short len){
  int i = 0;
  //MALLOC FOR NEW STR :D
  char *outStr = malloc((len+1) *sizeof(char));

  while(i<=len){
    outStr[i]  = inStr[i];
    i= i+1;
  }
  return outStr;
}

char **tokenize(char *str){
  int i;
  int len;
  int all = count_words(str);
  char **tokens = malloc((all+1) * sizeof(char*));
  char *pointer = str;

  int iter = 0;
  while(iter < all){
    pointer = word_start(pointer);
    len = (word_terminator(pointer) - word_start(pointer));
    tokens[i] = copy_str(pointer, len);
    pointer = word_terminator(pointer);
    iter = iter + 1;
  }
  tokens[i] = 0;
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
