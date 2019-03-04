//2017年7月12日
//プログラミング演習Ⅰ 第13回 問題1
//BP16057 高橋 美帆

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 70
#define MAX_LEN 128
#define MAX_LENGTH 1024
typedef struct{
  char name[MAX_LEN];
  int number;
}DATA;
int h_x(char *s,int size){
  int i=0;
  int hv=0;
  while(s[i]!='\0')
    hv+=(unsigned char)s[i++];
  return hv % size;
}
int main(int argc,char *argv[]){
  FILE *fp;
  DATA member[SIZE];
  DATA temp_member;
  int i,data=0,hv;  
  char s[SIZE],search[200];
  for(i=0;i<SIZE-1;i++){
    strcpy(member[i].name,"");
    member[i].number=0;
    }
  if (( fp = fopen( argv[1], "r" ) ) == NULL ) {
    fprintf( stderr, "File open error %s\n", argv[1] );
    exit( 1 );
  }
  while( fgets( s, MAX_LENGTH, fp ) != NULL ) {
    if ( data == SIZE-1) {
      fprintf( stderr, "配列が足りません\n" );
      exit( 1 );
    }
    sscanf(s,"%s %d",
	   temp_member.name,
	   &temp_member.number);
    hv=h_x(temp_member.name,SIZE-1);
    if(!strcmp(member[hv].name,""))member[hv]=temp_member;
    else{
      hv++;
      if(!strcmp(member[hv].name,""))member[hv]=temp_member;
    }
    data++;
  }
  while(1){
    printf("名前,または!を入力して下さい: ");
    scanf("%s",search);
    if(strcmp(search,"!")==0){
      printf("プログラムを終了します。\n");
      exit(1);
    }
    for(i=0;i<SIZE;i++){
      if(strcmp(search,member[i].name)==0)  {
	printf("内線番号:%d\n",member[i].number);
	break;
      }
      if(i==SIZE-1)printf("%sの名前はハッシュ表に登録されていません。\n",search);
    }
  }
  return 0;
}
