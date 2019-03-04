//2017年6月21日
//プログラミング演習Ⅰ 第9回 問題2
//BP16057 高橋 美帆

#include<stdio.h>
int euclid(int m,int n){
  int x;
 if(m<n){
    x=m;
    m=n;
    n=x;
  }
 if(m%n==0)return n;
 else return euclid(n,m%n);
}
int main(void){
  int m,n;
  printf("二つの自然数を入力して下さい--> ");
  scanf("%d %d",&m,&n);
  printf("%dと%dの最大公約数は%dです。\n",m,n,euclid(m,n));
  return 0;
 }
