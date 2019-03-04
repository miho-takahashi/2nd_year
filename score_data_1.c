//2017年5月15日
//プログラミング演習Ⅰ 第4回 問題4
//BP16057 高橋 美帆

#include<stdio.h>
#include<stdlib.h>
struct SCORE_DATA{
  char name[256];
  int score;
};
struct SCORE_DATA data[5];
int search_max(struct SCORE_DATA *x){
  int i,max=0;
  for(i=0;i<5;i++){
    if(x[i].score>x[max].score)max=i;
  }
  return max;
}
int search_min(struct SCORE_DATA *y){
  int i,min=0;
  for(i=0;i<5;i++){
    if(y[i].score<y[min].score)min=i;
  }
  return min;
}
int main(void){
  int i,max_i,min_i;
  for(i=0;i<5;i++){
    printf("%d人目のスコア: 名前と点数を入力(スペース区切り→",i);
    scanf("%s %d",data[i].name,&data[i].score);
  }
  max_i=search_max(data);
  min_i=search_min(data); 
  printf("最高点: %3d点 (%sさん)\n",data[max_i].score,data[max_i].name);
  printf("最低点: %3d点 (%sさん)\n",data[min_i].score,data[min_i].name);
  return 0;
}
