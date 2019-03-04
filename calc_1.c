//2017年4月17日
//プログラミング演習Ⅰ 第1回 問題1
//BP16057 高橋 美帆

#include<stdio.h>
int main(void){
  int n,x;
  printf("1以上の整数nを入力してください。");
  printf("n=");
  scanf("%d",&n);
  while(n>1){
    if(n%2==0){
      x=n;
      n=n/2;
      printf("%d÷ 2=%d\n",x,n);
    }
    else{
      x=n;
      n=3*n+1;
      printf("%d× 3+1=%d\n",x,n);
    }
  }
  return 0;
}
