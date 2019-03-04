//2017年5月24日
//プログラミング演習Ⅰ 第5回 問題9
//BP16057 高橋 美帆

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct SCORE_DATA_LIST{
  char name[256];
  int score;
  struct SCORE_DATA_LIST *next;
};
typedef struct SCORE_DATA_LIST data;
int main(void){
  int i=0,x=0;
  char s[256];
  data *p;
  data *listhead=NULL;
  data *listtail=NULL;
  data *max=NULL;
  data *min=NULL;
  while(1){
    do{
      printf("データ入力を続けますか(y/n)→ ");
      scanf("%s",s);
    }while(strcmp(s,"n")!=0&&strcmp(s,"y")!=0);
    if(strcmp(s,"n")==0){
      if(x==0)break;
      p=listhead;
      max=listhead;
      while(p!=NULL){
	if((max->score)<(p->score)){
	  max=p;
	}
	p=p->next;
      }
      p=listhead;
      min=listhead;
      while(p!=NULL){
	if((min->score)>(p->score)){
	  min=p;
	}
	p=p->next;
      }
      printf("最高点: %d点 (%sさん)\n",max->score,max->name);
      printf("最低点: %d点 (%sさん)\n",min->score,min->name);
      break;
    }
    else if(strcmp(s,"y")==0){
      x++;
      if(x==1){
	p=(data *)malloc(sizeof(data));
	printf("%d人目のスコア: 名前と点数を入力(スペース区切り)→ ",i+1);
	scanf("%s %d",p->name,&(p->score));
	p->next=NULL;
	listhead=p;
	listtail=p;
      }
      else if(x>1){
	p=(data *)malloc(sizeof(data));
	printf("%d人目のスコア: 名前と点数を入力(スペース区切り)→ ",i+1);
	scanf("%s %d",p->name,&(p->score));
	p->next=NULL;
	listtail->next=p;
	listtail=p;
      }
      i++;
    }
  }
  p=listhead;
  while(p!=NULL){
    printf("->%s %d ",(p->name),(p->score));
    p=p->next;
  }
  printf("\n");
  while(listhead!=NULL){
    p=listhead;
    listhead=listhead->next;
    free(p);
  }
  return 0;
}
