//2017年5月24日
//プログラミング演習Ⅰ 第5回 問題5
//BP16057 高橋 美帆

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct SCORE_DATA{
  char name[256];
  int score;
  struct SCORE_DATA *next;
};
typedef struct SCORE_DATA data;
int main(void){
  data *p;
  int i,n,max=0,min=0;
  printf("データ数→ ");
  scanf("%d",&n);
  if(n==0)return 0;
  p=(data *)malloc(sizeof(data)*n);
  for(i=0;i<n;i++){
  printf("%d人目のスコア: 名前と点数を入力(スペース区切り)→ ",i+1);
  scanf("%s %d",p[i].name,&p[i].score);
    if(p[i].score>p[max].score)max=i;
    if(p[i].score<p[min].score)min=i;
 }
  printf("最高点: %3d点 (%sさん)\n",p[max].score,p[max].name);
  printf("最低点: %3d点 (%sさん)\n",p[min].score,p[min].name);
  free(p);
  return 0;
}
