//2017年7月3日
//プログラミング演習Ⅰ 第11回 問題1
//BP16057 高橋 美帆

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list{
  int data;
  struct list *next;
}LIST;
LIST *listhead=NULL;
LIST *sentinel=NULL;
void showlist(LIST *p){
  while(p!=NULL){
    printf("->%d",p->data);
    p=p->next;
  }
}
int main(void){
  LIST *p,*q,*post;
  int insert,n=0;
  char choice[3];
  while(1){
    printf("挿入するデータがありますか? (yes/no) ---> ");
    scanf("%s",choice);
    if(strcmp(choice,"yes")==0){
      printf("データを入力して下さい。 ---> ");
      scanf("%d",&insert);
      if(listhead==NULL){
	sentinel=(LIST *)malloc(sizeof(LIST));
	sentinel->data=insert;
	sentinel->next=NULL;
	listhead=sentinel;
      }
      else{
	if(insert<sentinel->data){
	  p=(LIST *)malloc(sizeof(LIST));
	  p->data=insert;
	  p->next=NULL;
	  q=listhead;
	  while(q!=NULL){
	    if(q->data<insert){
	      post=q;
	      n++;
	    }
	    else if(q->data>insert){
	      p->next=q;
	      post->next=p;
	      break;
	    }
	    else printf("すでに入力されています。\n");
	    q=q->next;
	  }
	  if(n==0){
	    listhead=p;
	  }
	  n=0;
	}
	  else{
	    q=listhead;
	    while(q!=sentinel){
	      q=q->next;
	      n++;
	    }
	    if(insert==sentinel->data)printf("すでに入力されています。\n");
	    else{
	      p=(LIST *)malloc(sizeof(LIST));
	      p->data=sentinel->data;
	      p->next=sentinel;
	      sentinel->data=insert;
	      q->next=p;
	      if(n==0){
		listhead=p;
	      }
	      n=0;
	    }
	  }
      }
      sentinel->next=NULL;
      showlist(listhead);
    }
      else{
	printf("挿入操作を終了します。\n");
	break;
      }
      printf("\n");
  }
  return 0;
}
