#include "stack.h"
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>


int main(){
  
  int seed = time(NULL);
  printf("seed: %d\n", seed);
  srand(seed);
  
  Stack *s = stack_init();

  for (int i = 0; i < 20; i++) {
   
      int r = rand() % 3;

      if (r != 0) {
            int value = rand() % 20;
            if (stack_isfull(s) == true){
                printf("Stack is full, value not pushed\n");
         
       	   }else{
                printf("pushed value: %d\n", value);
                stack_push(s, value);
                }
     }else{
            if (stack_empty(s) == true){
                 printf("Stack is empty, no value can be popped\n");
           }else {
                  printf("popped value: %d\n", stack_pop(s));
                 }
          }
    }
   printf("\n");
   printf("Contents of Stack:\n");
   printf("Top\n");
  
  for(int i = 0; i<s->size; i++){
    printf("Stack #%d: %d\n",i,s->data[i]);
     }  
  printf("Bottom\n");
  printf("\n");  
  stack_free(s);
  return 0;  
}
