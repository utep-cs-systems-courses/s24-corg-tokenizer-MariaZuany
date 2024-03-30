#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokenizer.h"
#include "history.h"

int main(){

  List *history =init_history();
  puts("Hi :)");

  while (True){

    fputs("Welcome!   Input 'f' to see the full history, 's' to enter a sentence, 'vs' to view a specific history, or 'e' to Exit\n>", stdout);
    fflush(stdout);

    int a = getchar();
    getchar();

    switch(a){
      
      case 's':

	fputs("Enter your sentence: ", stdout);
	fflush(stdout);
	//establish the max length for the input sentence
	char sen[100];
	fgets(sen, sizeoff(sen),stdin);
	char **tokens = tokenize(sen);

	print_tokens(tokens);
	free_tokens(tokens);
	add_history(history,sen);

	break;

      case 'f':

	print_history(history);
	break;
	
      case 'vs':

	fputs("Enter the id of the history: ", stdout);
	fflush(stdout);

	int id;
	scanf("%d", &id);
	printf("History:%d %s\n", id, get_history(history, id));

	break;
      case 'e':
	puts("You chose to Exit. Thank you for your visit :)");
	free_history(history);
	break;
    }//switch
  }//while
  return 0;
}//main
