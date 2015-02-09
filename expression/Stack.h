#ifndef _Stack_h

struct StackRecord;
typedef struct StackRecord *Stack;
int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(Stack S, char element);
char Top(Stack S);
void Pop(Stack S);
char Popget(Stack S);

#endif

#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
struct StackRecord {
	int capacity;
	int top;
	char *array;
};

Stack CreateStack(int MaxElements) {
	Stack S;
	if(MaxElements < MinStackSize){
		//Error("Stack is too small");
		printf("Error! Stack is too small");
		exit(1);
	}
	S = malloc(sizeof(struct StackRecord));
	if (S==NULL){
		printf("FatalError! size of mem is not enough");
		exit(1);
	}
	S->array = malloc(sizeof(char)*MaxElements);
	if (S->array == NULL) {
		printf("mem-size is not enough");
		exit(1);
	}
	S->capacity = MaxElements;
	MakeEmpty(S);
	return S;
}

void DisposeStack(Stack S){
	if(S != NULL) {
		free(S->array);
		free(S);
	}

}

int IsEmpty(Stack S){
	return S->top==EmptyTOS;
}

int IsFull(Stack S){
	if(S->capacity == (S->top - 1))
		return 1;
	else 
		return 0;

}
void MakeEmpty(Stack S){
	S->top = EmptyTOS;
}

void Push(Stack S,char element){
	if(IsFull(S))
		exit(1);
	else
		S->array[++S->top] = element;
}

char Top(Stack S){
	if(!IsEmpty(S)){
		return(S->array[S->top]);
	printf("error");
	return 0;
	}
}

void Pop(Stack S){
	if(IsEmpty(S)) {
		printf("Stack is empty");
	}
	else
		S->top--;
}

