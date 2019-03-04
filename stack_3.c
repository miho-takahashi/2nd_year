//2017年6月12日
//プログラミング演習Ⅰ 第8回 問題1
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
int main(void){
  char mozi[256],c;
  int i,n,flag;
  while(1){
    flag=0;
    printf("チェックする文字列かendを入力して下さい--> ");
    scanf("%s",mozi);
    if(strcmp(mozi,"end")==0)break;
    n=strlen(mozi);
    for(i=0;i<n;i++){
      if(mozi[i]=='('||mozi[i]=='<')push(mozi[i]);
      else if(mozi[i]==')'){
	c=pop();
	  if(c!='('){
	    flag++;
	  }
	}
      else if(mozi[i]=='>'){
	c=pop();
	if(c!='<'){
	  flag++;
	}
      }
    }
    if(flag==0)printf("正しい。\n");
    else{
      printf("正しくない。\n");
      printf("スタックを空にしました。\n");
    }       
}
  printf("プログラムを終了します。\n");
  return 0;
}
