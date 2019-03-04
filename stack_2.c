//2017年5月31日
//プログラミング演習Ⅰ 第6回 問題2
//BP16057 高橋 美帆

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
int main(void){
  char mozi[256],kaibun;
  int i,n;
  while(1){
    printf("文字列かendを入力してください-> ");
    scanf("%s",mozi);
    if(strcmp(mozi,"end")==0){
      break;
    }
    else{
    n=strlen(mozi);
    for(i=0;i<n;i++){
      printf("%c",mozi[i]);
      push(mozi[i]);
    }
    while(listhead!=NULL){
      kaibun=pop();
      printf("%c",kaibun);
    }
    printf("\n");
    }
  }
  printf("プログラムを終了します。\n");
  return 0;
}
