#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
	char name[20];
	int id;
	char gender[20];
	int age;
	struct student *next;
};

struct student *headp=NULL;
struct student *tailp=NULL;

void menu()
{
	printf("****************菜单***************\n");
	printf("   欢迎来到简易学生信息管理系统~\n");
	printf("1.增加学生记录       2.删除学生记录\n");
	printf("3.查找学生记录       4.显示学生记录\n");
	printf("5.退出系统\n");
	printf("***********************************\n\n\n");
}

void add()
{
	struct student *nodep=(struct student*)malloc(sizeof(struct student));
	printf("请输入学生的姓名：\n");
	scanf("%s",nodep->name );
	printf("请输入学生的学号：\n");
	scanf("%d",&nodep->id );
	printf("请输入学生的性别：\n");
	scanf("%s",nodep->gender );
	printf("请输入学生的年龄：\n");
	scanf("%d",&nodep->age  );
	nodep->next =NULL;
	if(headp==NULL)
	{
		headp==nodep;
		tailp==nodep;
	}
	else
	{
		tailp->next =nodep;
		tailp=nodep;
	}
	printf("录入成功！\n\n\n"); 
}

void print_stu(struct student*curp)
{
	printf("姓名：%s  学号：&d  性别：%s  年龄：%d",curp->name,curp->id,curp->gender,curp->age);
}

void print_list(struct student*headp)
{
	while(headp!=NULL)
	{
		print_stu(headp);
		headp=headp->next ;
	}
}

void delete_stu()
{
	int xh;
	printf("请输入想要删除学生的学号：");
	scanf("%d",&xh);
	struct student*curp=headp;
	if(curp->id==xh)
	{
		headp=headp->next;
		free(curp);
		curp=NULL;
		return;
	}
	struct student*prep=curp;
	curp=curp->next;
	while(curp)
	{
		if(curp->id==xh)
		{
			struct student*next=curp->next;
			prep->next=next;
			free(curp);
			curp=NULL;
			printf("删除成功\n\n\n");
			return;
		}
		else
		{
			prep=curp;
			curp=curp->next;
		}
	}
	printf("该学生不存在，无法删除\n\n\n");
}

void find()
{
	int xh;
	printf("请输入想要查询的学生的学号：");
	scanf("%d",&xh);
	struct student*curp=headp;
	int flag=0;
	while(curp!=NULL)
	{
		if(curp->id==xh)
		{
			print_stu(curp);
			flag=1;
			break;
		}
		else
		{
			curp=curp->next; 
		}
	}
	if(flag==0)
	printf("没有学号为%d的学生\n\n\n",xh);
}

void print_all()
{
	if(headp==NULL)
	printf("当前没有学生\n\n\n");
	else
	print_list(headp);
}



int main()
{
	int chioce;
	while(1)
	{
		menu();
		while(1)
		{
			printf("请输入你的选择（1~5）：");
			scanf("%d",&chioce);
			if(chioce>=1&&chioce<=5)
			{
				switch(chioce)
				{
					case 1:add() ; break;
					case 2:delete_stu() ;break;
					case 3:find() ;break;
					case 4:print_all() ;break;
					case 5:exit(0);
				}
			break;
			}
		}
	}
	return 0;
}
