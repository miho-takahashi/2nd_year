//2017年5月31日
//プログラミング演習Ⅰ 第6回 問題1
//BP16057 高橋 美帆

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct cell{
  char C;
  struct cell *next;
};
typedef struct cell LIST;
LIST *stack=NULL;
LIST *listhead=NULL;
void push(char mozi){
  stack=(LIST *)malloc(sizeof(LIST));
  stack->C=mozi;
  stack->next=NULL;
  stack->next=listhead;
  listhead=stack;
}
char pop(){
  char c;
  if(listhead==NULL){
    c='\0';
    return c;
  }
  c=listhead->C;
  stack=listhead;
  listhead=listhead->next;
  free(stack);
  return c;
}
void free_stack(){
  if(listhead!=NULL)
    free(stack);
}
void print_stack(){
  if(stack==NULL){
    printf("スタックは空です。\n");
  }
  while(stack!=NULL){
    printf("->%c",stack->C);
    stack=stack->next;
  }
}
int main(void){
  char mozi[64],c;
  while(1){
  printf("\npushする文字かpop/endを入力して下さい→ ");
  scanf("%s",mozi);
  if(strcmp(mozi,"end")==0){
    printf("スタックを空にしました。\n");
    printf("プログラムを終了します。\n");
    free_stack();
    return 0;
  }
  else if(strcmp(mozi,"pop")==0){
    c=pop();
    if(c!='\0'){
      printf("popされた文字は%cです。",c);
    }
    else printf("スタックは空です。\n");
  }
  else if (strlen(mozi)==1){
    push(*mozi);
    print_stack();
  }
  else {
    printf("不正な入力です。\n");
    printf("スタックを空にしました。\n");
    printf("プログラムを終了します。\n");
    return 0;
  }
  }
  return 0;
}

    
   
