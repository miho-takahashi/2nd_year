//2017年4月17日
//プログラミング演習Ⅰ 第1回 問題6
//BP16057 高橋 美帆

#include<stdio.h>
char name[5][64];
void input_data(char name[5][64]){
  int i;
  for(i=0;i<5;i++){
    printf("%d番目の名前を入力: ",i);
    scanf("%s",name[i]);
  }
}
int find_data(char name[5][64],char key[64]){
  int len,flag,i,j,x;
  len=0;
  flag=0;
  while(key[len]!='\0')len++;
  for(i=0;i<5;i++){
    flag=0;
    for(j=0;j<len;j++){
      if(key[j]!=name[i][j])flag++;
    }  
    if(flag==0){
      x=i;
      break;
    }
    else flag=100;
  }
  if(flag==100){
    x=-1;
  }
  return x;
}
int main(void){
  int n; 
  char key[64];
  input_data(name);
  while(1){
    printf("検索する名前を入力→ ");
    scanf("%s",key);
    if(key[0]=='q'&&key[1]=='u'&&key[2]=='i'&&key[3]=='t'){
    printf("終了します。\n");
    break;
    }
    n=find_data(name,key);
    if(n==-1)printf("%sは見つかりません。\n",key);
    else printf("%sは%d番目に格納されています。\n",key,n);
  }
  return 0;
}
