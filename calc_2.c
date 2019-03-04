//2017年5月8日
//プログラミング演習Ⅰ 第3回 問題8
//BP16057 高橋 美帆

#include<stdio.h>
#include<stdlib.h>
int main(void){
  FILE *fp;
  int data[10],x,i,j,k,min,sum=0;
  float average;
  if((fp=fopen("output_0307.txt","r"))==NULL){
	printf("ファイルをオープン出来ませんでした。");
      }
  else{
    printf("読み込んだデータ: ");
    for(i=0;i<=9;i++){
      fscanf(fp,"%d",&x);
      data[i]=x;
      printf("%d ",data[i]);
    }
    for(j=0;j<=9;j++){
      for(k=0;k<=9;k++){
	if(data[j]<data[k]){
	    min=data[j];
	    data[j]=data[k];
	    data[k]=min;
	  }
      }
    }
    printf("\n小さい順に並べ替え: ");
    for(i=0;i<=9;i++)printf("%d ",data[i]);
    for(i=0;i<=9;i++){
      sum=sum+data[i];
    }
    average=sum/10;
    printf("\n");
    printf("平均値=%f\n",average);
    printf("最大値=%d\n",data[9]);
    printf("最小値=%d\n",data[0]);
    fclose(fp);
  }
  return 0;
}
   

