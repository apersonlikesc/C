#include<stdio.h>
void init();
void game();
int score = 0;
int main(){
	
	init();
	while(1){
		game();
	}
	return 0;
}
void init(){
	printf("��ӭ����vi�������ϰ����\n");
	
}
void game(){
	char dir[] = {'h','j','k','l'};
	char dir2[4][3] = {{"��"},{"��"},{"��"},{"��"}};
	srand((unsigned)time(NULL));
	int a = rand()%4;
	printf("%d",a);
	char x = dir[a];
	//char y = [];
	printf("����%s�Ŀ�ݼ�:",dir2[a]);
	char ch;
	scanf("%s",&ch);
	printf("ch:%c\n",ch);
	printf("x:%c\n",x);
	if(ch == x){
		score= score + 10;
	}else{
		score-=10;
	}
	printf("Ŀǰ����Ϊ��%d\n",score);
}
