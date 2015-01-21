
#include "stack.h"
#include <stdio.h>

const int MAX_STACK_SIZE = 30;

Stack* stack_init(){
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->size = 0; 
        stack->data = (int *)malloc(sizeof(int) * MAX_STACK_SIZE);
	return stack;
}

bool stack_empty(Stack *stack){
	if (stack->size == 0){
		return true;

        }else { return false; }
}

bool stack_isfull(Stack *stack){
        if (stack->size == MAX_STACK_SIZE){
           return true;
       }else { 
              return false;
             }
}

int stack_top(Stack *stack){
	if (stack->size == 0){
	        return 0;
       }else { return stack->data[0];}

}

void stack_push(Stack *stack, int k){
	if (stack->size == 0) {
           stack->data[0] = k;
	   stack->size= stack->size + 1;
          }

        else if (stack->size == MAX_STACK_SIZE){   
	   return;
          
      } else {  
                for(int i = stack->size-1;i>=0;i=i-1){
                   stack->data[i+1] = stack->data[i];
               }
                stack->data[0] = k;
                stack->size = stack->size + 1;
             }
}

int stack_pop(Stack *stack){
       if (stack->size == 1){
          int val = stack->data[0];
          stack->size = stack->size - 1;
          stack->data[0] = 0;
          return val;
    
      }else if (stack->size == 0){
          return 0;   
     
      }else {
	      int item = stack->data[0];
              for (int i = 0; i<=stack->size-1; i++){
		   stack->data[i] = stack->data[i+1];
              } 
              stack->size = stack->size - 1;
              return item;
            }
}


void stack_free(Stack *stack){
    free(stack->data);
    free(stack);
}



