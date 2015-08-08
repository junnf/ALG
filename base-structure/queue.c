#include<stdio.h>
#define MAX_QUEUE_SIZE 100
//front rear 0
//
typedef struct {
    int key;
  } element;

int rear = 0; 
int front = 0;
int *p_rear = &rear;
int *p_front = &front;
element queue[MAX_QUEUE_SIZE];

void queue_full(rear){
    
}

void addq(int front, int *prear, element item){
    *prear = (*prear + 1) % MAX_QUEUE_SIZE;
    if(front == *prear){
        queue_full(prear);    
        return ;
    }
    queue[*rear] = item;
}

element deletq(int *front, int rear, element item){
    element item;


}

int main(void){
    return 0;
}
