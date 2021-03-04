#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  while(1){
    char input[100];
    printf(">");

    fgets(input, 100, stdin);

    printf("%s", "Input received:", input, "\n", "Tokens:\n");

    
    char **tokens = tokenize(input);
    print_tokens(tokens);

  }
  //past output
  /*printf(space_char(' '));*/
}
