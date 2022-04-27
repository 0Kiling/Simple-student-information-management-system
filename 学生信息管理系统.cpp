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
	printf("****************�˵�***************\n");
	printf("   ��ӭ��������ѧ����Ϣ����ϵͳ~\n");
	printf("1.����ѧ����¼       2.ɾ��ѧ����¼\n");
	printf("3.����ѧ����¼       4.��ʾѧ����¼\n");
	printf("5.�˳�ϵͳ\n");
	printf("***********************************\n\n\n");
}

void add()
{
	struct student *nodep=(struct student*)malloc(sizeof(struct student));
	printf("������ѧ����������\n");
	scanf("%s",nodep->name );
	printf("������ѧ����ѧ�ţ�\n");
	scanf("%d",&nodep->id );
	printf("������ѧ�����Ա�\n");
	scanf("%s",nodep->gender );
	printf("������ѧ�������䣺\n");
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
	printf("¼��ɹ���\n\n\n"); 
}

void print_stu(struct student*curp)
{
	printf("������%s  ѧ�ţ�&d  �Ա�%s  ���䣺%d",curp->name,curp->id,curp->gender,curp->age);
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
	printf("��������Ҫɾ��ѧ����ѧ�ţ�");
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
			printf("ɾ���ɹ�\n\n\n");
			return;
		}
		else
		{
			prep=curp;
			curp=curp->next;
		}
	}
	printf("��ѧ�������ڣ��޷�ɾ��\n\n\n");
}

void find()
{
	int xh;
	printf("��������Ҫ��ѯ��ѧ����ѧ�ţ�");
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
	printf("û��ѧ��Ϊ%d��ѧ��\n\n\n",xh);
}

void print_all()
{
	if(headp==NULL)
	printf("��ǰû��ѧ��\n\n\n");
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
			printf("���������ѡ��1~5����");
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
