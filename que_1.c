//2017年6月5日
//プログラミング演習Ⅰ 第7回 問題1
//BP16057 高橋 美帆

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct cell{
  double num;
  struct cell *next;
};
typedef struct cell LIST;
LIST *listhead=NULL;
LIST *listtail=NULL;
LIST *p;
void enq(){
  p=(LIST *)malloc(sizeof(LIST));
  printf("追加する値を入力して下さい=> ");
  scanf("%lf",&p->num);
  p->next=NULL;
  if(listhead==NULL){
    printf("キュー内のデータ: -> %lf\n",p->num);
    listhead=p;
    listtail=p;
  }
  else{
    listtail->next=p;
    listtail=p;
    printf("キュー内のデータ: ");
    listtail=listhead;
    while(1){
      if(listtail==p){
	printf("->%lf",listtail->num);
	break;
      }
      printf("->%lf",listtail->num);
      listtail=listtail->next;
    }
    printf("\n");
  }
}
double deq(){
  double deq_num;
  deq_num=listhead->num;
  if(listhead==listtail){
    printf("%lfはキューから削除されました。\n",deq_num);
    printf("キュー内のデータ: ");
    listhead=NULL;
    return -1;
  }
  listhead=listhead->next;
  printf("%lfはキューから削除されました。\n",deq_num);
  listtail=p;
  if(listhead==listtail){
    printf("キュー内のデータ: -> %lf",listhead->num);
  }
  else {
    printf("キュー内のデータ: ");
    listtail=listhead;
    while(1){
      if(listtail==p){
	printf("->%lf",listtail->num);
	break;
      }
      printf("->%lf",listtail->num);
      listtail=listtail->next;
    }
  }
    return 1;
}
void end(){
  free(listhead);
  free(listtail);
}
int main(void){
  char choice[3];
  double x;
  while(1){
    printf("操作を入力して下さい(enq/deq/end)=> ");
    scanf("%s",choice);
    if(strcmp(choice,"enq")==0){
      enq();
    }
    else if(strcmp(choice,"deq")==0){
      if(x==-1){
	printf("キューにデータがありません。\n");
	break;
      }
      x=deq();
      printf("\n");
    }
    else if(strcmp(choice,"end")==0){
      end();
      break;
    }
    else printf("不正な入力です。\n");
  }
  printf("プログラムを終了します。\n");
  return 0;
}
