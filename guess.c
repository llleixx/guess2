#include <stdio.h>
#include <string.h>
#include<time.h>
#include<stdlib.h>

char id[20],pwd[20],text[50];

//��¼ 
int login()
{
	printf("��¼����\n");
	printf("ID��");
	gets(id);
	printf("PWD��");
	gets(pwd); 
	strcat(id,pwd);
	strcat(id,"\n");
	
	int ok=0;
	FILE *fp = fopen("user.txt", "r");
	if(NULL == fp)
	{
		printf("Failed to open user.txt\n");
		return 0; 
	}
	
	while(!feof(fp))
	{
		memset(text, 0, sizeof(text));
		fgets(text, sizeof(text) - 1, fp); 
		if(strcmp(id,text) == 0)
		{
			ok=1;
			break;
		}
	}
	
	if(ok)
	{
		printf("��¼�ɹ�!\n");
	}
	else
	{
		printf("��¼ʧ��!\n");
		login();
	}	
	fclose(fp);
	return 0;
}

//ע�� 
void regist()
{
	printf("ע�����\n");
	FILE *fp = fopen("user.txt","a");
	printf("ID��");
	gets(id);
	printf("PWD��");
	gets(pwd); 
	fputs(id,fp);
	fputs(pwd,fp);
	fputs("\n",fp);
	fflush(stdin);
	fclose(fp);
	login();
}

//��Ϸ 
void game()
{	 
	srand(time(0));
	clock_t start, end;
	start = clock();
	int num = rand() % 1000;  
	int guess, i = 0;   
	int min = 0, max = 1000; 
	while (1)
	{
		printf("Please guess the number:");
		scanf("%d", &guess);
		if (num > guess)
		{
			i++;	
			printf("��С��\n");
			min = guess;
			printf("��Χ:%d - %d\n", min, max);
		}
		else if (num < guess)
		{
			i++;	
			printf("�´���\n");
			max = guess;
			printf("��Χ:%d - %d\n", min, max);
		}
		else
		{
			i++;	
			end = clock();
			int t=(end-start)/1000;
			printf("�¶���!\n����������%d��\n��ʱ��%d��", i, t);  
			break;
		}
		
	}
}

//�˵� 
void meun()
{
	printf("1 ע��\n");
	printf("0 ��¼\n");
	int a = 0;
	scanf("%d",&a);
	fflush(stdin);
	if(a)
		regist();
	else
		login();
}

int check(int a)
{
	switch (a)
	{
	case 1:
		game();
		return 0;
		
	case 0:
		return 0;
		
		default:
			printf("ѡ�����!\n���������룺\n");
			return 1;
	}
}

int main()
{ 
	int a;
	meun();
	printf("1 Play\n");
	printf("0 Exit\n");
	while(scanf("%d",&a)&&check(a)){}
	return 0;
}
