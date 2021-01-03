#include <stdio.h>
#define MAX 5

int isEmpty (int count){
  if (count == 0){
    return 1;
  }else{
    return 0;
  }
}

int isFull(int count){
  if (count==MAX){
    return 1;
  }else{
    return 0;
  }
}

void enqueue(int *Pqueue,int *Prear,int *Pcount){
  if (isFull(*Pcount) == 0){
    if (*Prear == MAX - 1){
      *Prear = -1;
    }
    int data;
    printf("enqueue data :");
    scanf("%d",&data);
   *Prear = *Prear+1;
   *(Pqueue + *Prear) = data;
   *Pcount=*Pcount+1;
  }else{
    printf("queue FULL");
  }
}


void dequeue(int *Pqueue, int *Pfront,int*Pcount){
  if(isEmpty(*Pcount)==0){
    int data = *(Pqueue + (*Pfront));
    *Pfront =*Pfront+1;
    if (*Pfront == MAX){
      *Pfront = 0;
    }
    *Pcount = *Pcount - 1;
    printf("data = %d",data);
  }else{
    printf("queue kosong");
  }
}
 
void show (int queue[],int front,int rear,int count){
  if (isEmpty(count)==0){
    printf("Queue : \n");
    for (int i = rear;i>=front;i--){

      printf("%d ", queue[i]);
    }
  }else{
    printf("queue kosong");
  }
}


int main(void) {
  int queue[MAX]={0},pil,i;
  int front =0;
  int rear = -1;
  int count = 0;

  while (1){
    printf("\n1. Enqueue \n2.Dequeue\n3.Show\n4.Clear\n5.Exit\n\nMasukkan Pilihan:");
    scanf("%d",&pil);
    switch(pil){
      case 1:
        enqueue(&queue[0],&rear,&count);
        break;
      case 2:
        dequeue(&queue[0],&front,&count);
        break;
      case 3:
        show(queue,front,rear,count);
        break;
      default:
        return 0;
    }
  }



}

