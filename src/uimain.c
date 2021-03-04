#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  int noexit = 1;
  while(noexit){
    char input[100];
    printf("> ");

    fgets(input, 100, stdin);

    if(*input == '0'){
      noexit = 0;
    }
    else{
      char** tokens = tokenize(input);
      print_tokens(tokens);
      free_tokens(tokens);
    }
  }
  //past output
  /*printf(space_char(' '));*/
}
