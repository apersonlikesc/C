#include <stdio.h>
#include <conio.h>
#include <string.h>
//叶子节点数及最优二叉树节点数
#define n 5
#define m n*2-1

//最优二叉树节点存储信息
typedef struct
{ 
	float  weight;
	int lchrild, rchrild, parent;
 }hufmtree;

// 编码存储结构
typedef struct
{ 
	char bits[n];
	char ch;
}hufmcode;

//最优二叉树及节点编码存储
hufmtree tree[m];
hufmcode code[n];

void init(hufmtree tree[])
{
	for(int i=0; i<m; i++)
	{
		tree[i].lchrild = -1;
		tree[i].rchrild = -1;
		tree[i].weight = -1;
		tree[i].parent = -1;
	}
	for(int i=0; i<n; i++)
	{
		printf("输入第%d节点的权值",i+1);
		scanf("%f",&tree[i].weight);
	}
	//进行排序
}
//建立最优二叉树
void Hufm(hufmtree tree[])
{
		
	//找到最小的两个节点
	 for(int i = n; i<m ; i++)//空白部分
    { 
		float minweight1 = 101;
		float minweight2 = 101;
		int number1 = -1,number2 = -1;

	       for(int j = 0; j < i; j++)
		   {
		   	if(tree[j].parent == -1){
		   		if(tree[j].weight<minweight1)
				{
				minweight2 = minweight1; 
		       	minweight1 = tree[j].weight;
		       	number2 = number1; 
				number1 = j; 
				}
			   else if(tree[j].weight<minweight2)
			   {
	       			minweight2 = tree[j].weight;
					number2 = j;
				}
				
		   		
	}		  
		
    if(minweight1>minweight2)
		{
			float temp;
		
			temp = minweight1;
			minweight1 = minweight2;
			minweight2 = temp;
			
			int i;
			i = number1;
			number1 = number2;
			number2 = i; 
			
		}
		
		}
//			printf("minweight1是%f\n",minweight1);
//			printf("minweight2是%f\n",minweight2); 
//			printf("number1是%d\n",number1); 
//			printf("number2是%d\n",number2);
			tree[i].weight = tree[number1].weight + tree[number2].weight;
			tree[i].lchrild = number1;
		    tree[i].rchrild = number2;
		    tree[number1].parent = i;
		    tree[number2].parent = i;
			
	//通过序号进行连接
	//删除节点
 
}
} 

//哈夫曼编码
void Hufmcode(hufmtree tree[], hufmcode code[])
{
	//通过二叉树进行编码
//	int rootnumber = m-1;
//	printf("%f",tree[rootnumber].weight);
	for(int i = 0;i<n ; i++)
	{
		code[i].ch = i+97;
		
		int j = 0;
		int number = i;
		while(tree[number].parent != -1){
			
			if(tree[tree[number].parent].lchrild == number)
			{
				code[i].bits[j] = '0';
			
			}
			if(tree[tree[number].parent].rchrild == number){
				code[i].bits[j] = '1';
			}
			j++;
			number = tree[number].parent;			
		}
			
		code[i].bits[j] = '\0';
		char *a = code[i].bits;
		strrev(a);
		printf("%c:",code[i].ch);
//		printf("111111111");
		printf("%s",a);
//		while(code[i].bits[count] != '\0')
//		{
//			printf("%c",code[i].bits[count]);
//			count++;
//		}
		printf("\n");
//		break;
	}
	

}

// 哈夫曼解码
void Hufmdecode(hufmtree tree[], hufmcode code[])
{
	//通过编码生成二叉树 
	char string[128];
	printf("请输入01的编码:"); 
	scanf("%s",&string);
	int i = 0;
	int number = m-1;
	while(string[i] != '\0'){
		if(string[i] == '0'){
			
			if(tree[tree[number].lchrild].lchrild != -1){
				
				number = tree[number].lchrild;
			//	printf("1");
			}else{//是节点 
				//printf("2");
				number = tree[number].lchrild;
				printf("%c",(number + 97));
				number = m-1;	
			}
		}
		if(string[i] == '1'){
			if(tree[tree[number].rchrild].rchrild != -1){
				number = tree[number].rchrild;
			//	printf("3");
			}else{
			//	printf("4");
				number = tree[number].rchrild;
				printf("%c",(number + 97));
				number = m-1;		
			}
		}
		i++;
	}
	
}
void printtree(hufmtree tree[])
{
	for(int i = 0; i<m ; i++)
	{ 
		printf("第%d节点权值为：%f",i+1,tree[i].weight);
		if(tree[i].lchrild != -1 && tree[i].rchrild != -1)
		printf(",左孩子的权值为%f，右孩子的权值为%f",tree[tree[i].lchrild].weight,tree[tree[i].rchrild].weight); 
		if(tree[i].parent != -1)
		printf(",双亲的权值为%f",tree[tree[i].parent].weight); 
		printf("\n"); 
	} 
	//打印二叉树
	//如果是-1的话怎么办 
}
//主函数
int main()
{
//初始化
    init(tree);

 //建立哈夫曼树
    Hufm(tree);

 //打印哈夫曼树信息
    printtree(tree);

 //建立哈夫曼编码
    Hufmcode(tree,code);

 //解码
    Hufmdecode(tree,code);

return 0; 
}
