#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  List *history = init_history();
  int noexit = 1;
  while(noexit){
    char input[100];
    printf("> ");

    fgets(input, 100, stdin);

    if(*input == '0'){
      noexit = 0;
    }
    else if(*input == 'h'){
      int i = atoi(input+1);
      char* his = get_history(history, i);
      printf("%s", his);

      char** tokenhis = tokenize(his);
      print_tokens(tokenhis);
    }
    else{
      char **tokens = tokenize(input);
      print_tokens(tokens);
      char *sameStr = copy_str(input, strlen(input));
      add_history(history, sameStr);
      free_tokens(tokens);
    }
  }
  //past output
  /*printf(space_char(' '));*/
}
