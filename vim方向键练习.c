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
	printf("欢迎来到vi方向键练习界面\n");
	
}
void game(){
	char dir[] = {'h','j','k','l'};
	char dir2[4][3] = {{"左"},{"下"},{"上"},{"右"}};
	srand((unsigned)time(NULL));
	int a = rand()%4;
	printf("%d",a);
	char x = dir[a];
	//char y = [];
	printf("输入%s的快捷键:",dir2[a]);
	char ch;
	scanf("%s",&ch);
	printf("ch:%c\n",ch);
	printf("x:%c\n",x);
	if(ch == x){
		score= score + 10;
	}else{
		score-=10;
	}
	printf("目前分数为：%d\n",score);
}
