//2017年6月5日
//プログラミング演習Ⅰ 第7回 問題2
//BP16057 高橋 美帆

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
  char choice[3];
  double ring_buff[10];
  int head=0,tail=0,i;
  while(1){
    printf("操作を選択してください(enq/deq/end)=> ");
    scanf("%s",choice);
    if(strcmp(choice,"enq")==0){
      printf("追加する値を入力してください=> ");
      scanf("%lf",&ring_buff[tail]);
      tail++;
      if(tail==10)tail=0;
    }
    else if(strcmp(choice,"deq")==0){
      printf("%lfはキューから削除されました。\n",ring_buff[head]);
      head++;
      if(head==10)head=0;
      if(head==tail){
	printf("キューにデータがありません。\n");
	break;
      }
    }
    else if(strcmp(choice,"end")==0)break;
    else printf("不正な入力です。\n");
    printf("キュー内のデータ: ");
    if(head<tail){
      for(i=head;i<tail;i++)printf("->%lf",ring_buff[i]);
    }
    else{
      for(i=head;i<10;i++)printf("->%lf",ring_buff[i]);
      for(i=0;i<tail;i++)printf("->%lf",ring_buff[i]);
    }
    printf("\n");
  }
  printf("プログラムを終了します。\n");
  return 0;
}
