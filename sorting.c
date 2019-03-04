//2017年4月26日
//プログラミング演習Ⅰ 第2回 課題2 問題2
//BP16057 高橋 美帆

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100
void output_strings(char **array_p,int m){
  printf("%d\n",m);
  while(m>0){
    printf("%s\n",*(array_p++));
    m--;
  }
}
int main(void){
  int i,j;
  int n;
  char data[MAX_LEN]={};
  char **str_p;
  char *p;
  printf("Number of strings -> ");
  scanf("%d",&n);
  str_p=(char **)malloc(n*sizeof(char *));
  for(i=0;i<n;i++){
    printf("Input strings -> ");
    scanf("%s",data);
    str_p[i]=(char *)malloc((strlen(data)+1)*sizeof(char));
    if(str_p[i]==NULL)
      printf("str_p[%d]の領域を確保できませんでした。\n",i);
    strcpy(str_p[i],data);
  }
  printf("\n");
  printf("Before sorting\n");
  output_strings(str_p,n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(strlen(str_p[i])<strlen(str_p[j])){
	p=str_p[i];
	str_p[i]=str_p[j];
	str_p[j]=p;
      }
    }
  }
  printf("\n");
  //文字数の少ない順に並べる
  printf("After sorting\n");
  output_strings(str_p,n);
  for(i=0;i<n;i++)
    free(str_p[i]);
  free(str_p);
  return 0;
}
