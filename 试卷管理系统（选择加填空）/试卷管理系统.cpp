#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ERROR 0
#define OK 1

const char* MENU_FUNCTION[] =
{
	"(1)�������","(2)����ɾ��","(3)����ȫ����Ŀ",
	"(4)ɾ��ȫ����Ŀ","(5)�����޸�","(6)�����ѯ:",
	"(7)ͳ����Ŀ","(8)��ѯ��Ŀ","(9)�Զ�������ȯ"
	,"(10)�˳�����"
};
  
typedef struct commodity {
	int num;//��Ŀ���
	char topic[256];
	int type;//��Ŀ����  1ѡ��  2���
	char choiceA[256];//ѡ����A 
	char choiceB[256];//ѡ����B
	char choiceC[256];//ѡ����C 
	char choiceD[256];//ѡ����D
	char answer[256];//�� 
} ElemType;

//��������//
typedef struct Node {
	ElemType data;//������ 

	struct Node* next;//ָ���� 
} SNode;
typedef struct Linklist {

	int choiceNum;
	int TKNum;

	SNode * head;//ָ���һ���ڵ�
	SNode * Tail;//��β��������ӽڵ�
} *SLinklist;
//��������//
bool Init_SLinkList(SLinklist *L);
bool Creat_SLinkList_Tail(SLinklist L, ElemType e);
SNode* Find_SLinkNode_Val(SLinklist L, int num);
int Delete_DatainList(SLinklist L, int num);

int freeDatainList(SLinklist L);//����
void saveFile();//����
bool loadFile();//���ر���

void mainMenu();//���˵�
void addTopic();//�����Ŀ
void deleteTopic();//ɾ����Ŀ
void seek();//�����ѯ
void modify();//�޸�
void seetAsStr();//���û������ѯ��Ŀ����ӡ
void scsj();//�����Ծ�
void savesj(SLinklist xzList, SLinklist tkList);//�����Ծ�
void saveDa(SLinklist xzList, SLinklist tkList);//�����
void scst(SLinklist xzList, SLinklist tkList, int choiceNum, int TKNum);//��������
int run_flag;//���б�ʶ
ElemType getCin;//��������

SLinklist list;//��Ŀ����
int main()
{
	int item;
	Init_SLinkList(&list);
	run_flag = 1;
	printf("�Ƿ��ȡ������⣿\n1.����2.������");
		scanf("%d", &item);
	if (item == 1)
	{
		while (!loadFile())
		{
			printf("\n�Ƿ��ȡ������⣿\n1.����2.������");
			scanf("%d", &item);
			if (item != 1)
				break;
		}

	}
	while (run_flag)
	{
		mainMenu();
	}
	return 0;
}
void  mainMenu()
{

	int num;
	system("cls"); //����
	printf(" \n\n                    \n\n");
	printf("  ******************************************************\n\n");
	printf("  *                  ��Ŀ����ϵͳ                    *\n \n");
	printf("  ******************************************************\n\n");
	printf("*********************ϵͳ���ܲ˵�*************************\n");
	printf("     *********************************************     \n");
	for (int i = 0; i < 10; i++)
	{
		printf("     %s\n", MENU_FUNCTION[i]);
		printf("               ******************                            \n");
	}
	printf("                  --------------------                    \n");
	printf("     ��ѡ��˵����:");
	scanf("%d", &num);
	getchar();
	switch (num)
	{
	case 1:
		addTopic();//�����Ŀ
		break;
	case 2:
		deleteTopic();//ɾ����Ŀ
		break;

	case 3:
		saveFile();
		break;
	case 4:
		freeDatainList(list);//����
		Init_SLinkList(&list);//Ҫ�ڳ�ʼ��һ��
		printf("ɾ�����!\n");
		system("pause");
		break;
	case 5:
		modify();//�޸�
		break;
	case 6:
		seek();//�����ѯ
		break;
	case 7:
		printf("\n����ѡ��%d", list->choiceNum);
		printf("\n�������%d", list->TKNum);
		system("pause");
		break;
	case 8:
		seetAsStr();
		break;
	case 9:
		scsj();//�����Ծ�
		break;
	case 10:
		printf("�����˳�����!\n");
		run_flag = 0;
		break;
	default:
		printf("����1-8֮��ѡ��\n");
	}
};
void savesj(SLinklist xzList, SLinklist tkList)//�����Ծ�
{

	int i=1;
	FILE *fp;
	char path[100];
	printf("�������Ծ���λ��\n");
	scanf("%s", path);
	fp = fopen(path, "w");
	if (!fp)
	{
		printf("\n�ļ�����ʧ�ܣ�\n");
		return;
	}
	fprintf(fp, "������_______ �༶��______ ����:_____\n");
	fprintf(fp, "\nһ��ѡ��\n");
	SNode * Node_L;
	Node_L = xzList->head;
	while (Node_L)
	{
		fprintf(fp, "(%d):%s\n", i++, Node_L->data.topic);
		fprintf(fp, "A:%s\n", Node_L->data.choiceA);
		fprintf(fp, "B:%s\n", Node_L->data.choiceB);
		fprintf(fp, "C:%s\n",  Node_L->data.choiceC);
		fprintf(fp, "D:%s\n", Node_L->data.choiceD);
		Node_L = Node_L->next;
	}

	fprintf(fp, "\n������գ�\n");
	i = 1;
	Node_L = tkList->head;
	while (Node_L)
	{
		fprintf(fp, "(%d):%s\n", i++, Node_L->data.topic);
		Node_L = Node_L->next;
	}
	fclose(fp);
	printf("\n�Ծ������");
}
void saveDa(SLinklist xzList, SLinklist tkList)//�����
{
	int i = 1;
	FILE *fp;
	char path[100];
	printf("������𰸱���λ��\n");
	scanf("%s", path);
	fp = fopen(path, "w");
	if (!fp)
	{
		printf("\n�ļ�����ʧ�ܣ�\n");
		return;
	}
	fprintf(fp, "��\n");
	fprintf(fp, "\nһ��ѡ��\n");
	SNode * Node_L;
	Node_L = xzList->head;
	while (Node_L)
	{
		fprintf(fp, "(%d):%s\n", i++, Node_L->data.answer);
	
		Node_L = Node_L->next;
	}

	fprintf(fp, "\n������գ�\n");
	i = 1;
	Node_L = tkList->head;
	while (Node_L)
	{
		fprintf(fp, "(%d):%s\n", i++, Node_L->data.answer);
		Node_L = Node_L->next;
	}
	fclose(fp);
	printf("\n�𰸱������");

}
void scst(SLinklist xzList, SLinklist tkList, int choiceNum,int TKNum)
{
	srand((unsigned)time(NULL)); // ��ʼ������� ��ʱ��Ϊ�֣��Դﵽ�����Ŀ�� 
		SNode * Node_find;
	Node_find = list->head;//��ͷ��ʼ����
	while (Node_find != NULL)
	{
		int scTKdlag = rand() % (list->TKNum +5)- TKNum;//����Ϊ������ɵ�����������������⣬����0����� tkList ����������
	    int scXZdlag = rand() % (list->choiceNum + 5) - choiceNum;// ������������⣬����0����� ����0����� xzList ����������

		if (Node_find->data.type==1)
		{
			if (scXZdlag > 0)
			{
				if (xzList->choiceNum >= choiceNum)
				{
					continue;//�ﵽҪ��
				}
				if (!Find_SLinkNode_Val(xzList, Node_find->data.num))//��֤��Ŀ��Ų��ظ�
				{
					Creat_SLinkList_Tail(xzList, Node_find->data);
				}
				
	       
			}
		}
		else
		{
			if (scTKdlag > 0)
			{
				if (tkList->TKNum>= TKNum)
				{
					continue;//�ﵽҪ��
				}
				if (!Find_SLinkNode_Val(tkList, Node_find->data.num))//��֤���ظ�
				{
					Creat_SLinkList_Tail(tkList, Node_find->data);//����һ������β��������������� 
				}
			
			}
		}
				
		Node_find = Node_find->next;
	}
}
void scsj()//�����Ծ�
{
	int item;
	int choiceNum;//ѡ������
	int TKNum;//�������
	char sjFileName[253];//�Ծ��ļ��� 
	char daFileName[256];//���ļ���
	SLinklist xzList;//ѡ��������
	SLinklist tkList;//���������
	Init_SLinkList(&xzList);//��յ�ַ 
	Init_SLinkList(&tkList);//��յ�ַ 
	while (1)
	{


		memset(&getCin, 0, sizeof(ElemType));//������0
		system("cls"); //����
		printf("  ******************************************************\n\n");
		printf("  *                    �����Ծ�                          *\n \n");
		printf("  ******************************************************\n\n");
		printf("  ---------------------------");

		printf("\n������Ҫ���ɵ�ѡ����������" );

		scanf("%d", &choiceNum);
		while (list->choiceNum < choiceNum)//ֱ����Ŀ��Ų��ظ����ֶ�����
		{
			printf("\n�������С�������������1�������룬2����");
			scanf("%d", &item);
			if (item != 1)
			{
				freeDatainList(xzList);//��ֹ�ڴ�й¶       
				freeDatainList(tkList);//��ֹ�ڴ�й¶
				return;
			}

			printf("\n  ******************\n");
			printf("  ������Ҫ���ɵ�ѡ��������:");
			scanf("%d", &choiceNum);
		}
		printf("\n������Ҫ���ɵ������������");
		scanf("%d", &TKNum);
		while (list->TKNum < TKNum)//ֱ����Ŀ��Ų��ظ����ֶ�����
		{
			printf("\n�������С�������������1�������룬2����");
			scanf("%d", &item);
			if (item != 1)
			{
				freeDatainList(xzList);//��ֹ�ڴ�й¶       
				freeDatainList(tkList);//��ֹ�ڴ�й¶

				return;
			}
			printf("\n  ******************\n");
			printf("  ������Ҫ���ɵ����������:");
			scanf("%d", &TKNum);
		} 
		while (1)
		{
			scst(xzList, tkList, choiceNum, TKNum);
			if (xzList->choiceNum>=choiceNum&&tkList->TKNum>=TKNum)//֪������Ҫ���˳�
			{
				break;
			}
		}

		savesj(xzList, tkList);
		saveDa(xzList, tkList);
		system("pause");
		break;//�������˵�

	}

	freeDatainList(xzList);//��ֹ�ڴ�й¶       
	freeDatainList(tkList);//��ֹ�ڴ�й¶

}
void seetAsStr()
{
	int item;
	while (1)
	{


		memset(&getCin, 0, sizeof(ElemType));//������0
		system("cls"); //����
		printf("  ******************************************************\n\n");
		printf("  *                    �����ѯ(����)                          *\n \n");
		printf("  ******************************************************\n\n");
		printf("  ---------------------------");
		printf("  ������Ҫ��ѯ��Ŀ����:");
		scanf("%s", &getCin.topic);
		SNode * Node_find;
		Node_find = list->head;//��ͷ��ʼ����
		while (Node_find != NULL)
		{
			char * i = strstr(Node_find->data.topic, getCin.topic);/*�ж��Ƿ����������iָ����ַ�����һ�γ��ֵĵ�ַ*/
			SNode *    nodet = Node_find;
			if (i)
			{
				printf("\n-------------------------------\n");
				printf("��Ŀ:%s\n", nodet->data.topic);
				if (nodet->data.type == 1)
				{

					printf("A:%s\n", nodet->data.choiceA);
					printf("B:%s\n", nodet->data.choiceB);
					printf("C:%s\n", nodet->data.choiceC);
					printf("D:%s\n", nodet->data.choiceD);

				}
				printf("��:%s\n", nodet->data.answer);

			}
			Node_find = Node_find->next;
		}

		printf("\n\t\n1������ѯ��2����");
		scanf("%d", &item);
		if (item != 1)
			return;

	}

}
void saveFile()//����
{
	FILE *fp;
	char path[100];
	printf("�����뱸��·��\n");
	scanf("%s", path);
	fp = fopen(path, "w");
	if (!fp)
	{
		printf("\n�ļ�����ʧ�ܣ�\n");
		return;
	}
	SNode * Node_L;
	Node_L = list->head;
	while (Node_L)
	{
		fwrite(&Node_L->data, sizeof(ElemType), 1, fp);
		Node_L = Node_L->next;
	}
	fclose(fp);
}
bool loadFile()//���ر���
{
	FILE* fp; char path[100];
	printf("������Ҫ����ı����ļ�\n");
	scanf("%s", path);
	fp = fopen(path, "r");
	if (!fp)
	{
		printf("\n�ļ�����ʧ�ܣ�\n");
		return false;
	}

	while (fread(&getCin, sizeof(ElemType), 1, fp))
	{
		Creat_SLinkList_Tail(list, getCin);
	}
	fclose(fp);
	return true;
}
void seek()//�����ѯ
{

	int item;
	while (1)
	{


		memset(&getCin, 0, sizeof(ElemType));//������0
		system("cls"); //����
		printf("  ******************************************************\n\n");
		printf("  *                    �����ѯ(���)                          *\n \n");
		printf("  ******************************************************\n\n");
		printf("  ---------------------------");
		printf("  ������Ҫ��ѯ��Ŀ���:");
		scanf("%d", &getCin.num);
		while (!Find_SLinkNode_Val(list, getCin.num))//ֱ����Ŀ��Ų��ظ����ֶ�����
		{
			printf("\n����Ŀ��Ų����ڣ�1�������룬2����");
			scanf("%d", &item);
			if (item != 1)
				return;
			printf("\n  ******************\n");
			printf("  ������Ҫ��ѯ��Ŀ���:");
			scanf("%d", &getCin.num);
		}
		SNode* nodet = Find_SLinkNode_Val(list, getCin.num);
		printf("\n-------------------------------\n");
		printf("��Ŀ:%s\n", nodet->data.topic);
		if (nodet->data.type == 1)
		{

			printf("A:%s\n", nodet->data.choiceA);
			printf("B:%s\n", nodet->data.choiceB);
			printf("C:%s\n", nodet->data.choiceC);
			printf("D:%s\n", nodet->data.choiceD);

		}
		printf("��:%s\n", nodet->data.answer);
		printf("\n\t\n1������ѯ��2����");
		scanf("%d", &item);
		if (item != 1)
			return;
	}
}
void modify()//�޸�
{
	int item;
	while (1)
	{
		printf("������");

		memset(&getCin, 0, sizeof(ElemType));//������0
		system("cls"); //����
		printf("  ******************************************************\n\n");
		printf("  *                    �޸���Ŀ                          *\n \n");
		printf("  ******************************************************\n\n");
		printf("  ---------------------------");
		printf("  ������Ҫ�޸���Ŀ���:");
		scanf("%d", &getCin.num);
		while (!Find_SLinkNode_Val(list, getCin.num))//ֱ����Ŀ��Ų��ظ����ֶ�����
		{
			printf("\n����Ŀ��Ų����ڣ�1�������룬2����");
			scanf("%d", &item);
			if (item != 1)
				return;
			printf("\n  ******************\n");
			printf("  ������Ҫ�޸���Ŀ���:");
			scanf("%d", &getCin.num);
		}
		SNode* nodet = Find_SLinkNode_Val(list, getCin.num);

		printf("  �������µ���Ŀ����(1ѡ��,2���):");
		scanf("%d", &nodet->data.type);
		while (nodet->data.type < 1 || nodet->data.type>2)//��Ŀ��ű���Ϊ1��2
		{
			printf("\n����1-2�м�ѡ��");
			printf("\n  ******************\n");
			printf("  ��������Ŀ��(1ѡ��,2���):");
			scanf("%d", &nodet->data.num);
		}
		printf("\n  ******************\n");

		printf("\n�������µ���Ŀ��");
		scanf("%s", nodet->data.topic);
		if (nodet->data.type == 1)
		{
			printf("\n  ******************\n");
			printf("\n������ѡ��A:");
			scanf("%s", nodet->data.choiceA);
			printf("\n������ѡ��B:");
			scanf("%s", nodet->data.choiceB);
			printf("\n������ѡ��C:");
			scanf("%s", nodet->data.choiceC);
			printf("\n������ѡ��D:");
			scanf("%s", nodet->data.choiceD);

		}
		printf("\n�������:");
		scanf("%s", nodet->data.answer);

		while (nodet->data.type == 1 &&
			nodet->data.answer[0] != 'A'&&
			nodet->data.answer[0] != 'B'&&
			nodet->data.answer[0] != 'C'&&
			nodet->data.answer[0] != 'D')//��Ŀ��ű���Ϊ1��2
		{
			printf("\nѡ������� A B C D�м�ѡ��");
			printf("\n  ******************\n");
			printf("  �������:");
			scanf("%s", nodet->data.answer);
		}

		printf("\n\t\t�޸ĳɹ���1�����޸ģ�2����");
		scanf("%d", &item);
		if (item != 1)
			return;
	}
}
void deleteTopic()//ɾ����Ŀ
{
	int item;
	while (1)
	{
		printf("������");

		memset(&getCin,0, sizeof(ElemType));//������0
		system("cls"); //����
		printf("  ******************************************************\n\n");
		printf("  *                    ɾ����Ŀ                          *\n \n");
		printf("  ******************************************************\n\n");
		printf("  ---------------------------");
		printf(" ������Ҫɾ����Ŀ���:");
		scanf("%d", &getCin.num);
		while (!Find_SLinkNode_Val(list, getCin.num))//ֱ����Ŀ��Ų��ظ����ֶ�����
		{
			printf("\n����Ŀ��Ų����ڣ�1�������룬2����");
			scanf("%d", &item);
			if (item != 1)
				return;
			printf("\n  ******************\n");
			printf("  ������Ҫɾ����Ŀ���:");
			scanf("%d", &getCin.num);
		}

		Delete_DatainList(list, getCin.num);
		printf("\n\t\tɾ���ɹ���1����ɾ����2����");
		scanf("%d", &item);
		if (item != 1)
 			return;
	}

}
void addTopic()//�����Ŀ
{
	int item;
	while (1)
	{
		printf("������");
		memset(&getCin, 0, sizeof(ElemType));//������0
		system("cls"); //����
		printf("  ******************************************************\n\n");
		printf("  *                    �����Ŀ                          *\n \n");
		printf("  ******************************************************\n\n");
		printf("  ---------------------------");
		printf("  ��������Ŀ���:");
		scanf("%d", &getCin.num);
		while (Find_SLinkNode_Val(list, getCin.num))//ֱ����Ŀ��Ų��ظ����ֶ�����
		{
			printf("\n����Ŀ����Ѵ��ڣ�1�������룬2����");
			scanf("%d", &item);
			if (item != 1)
				return;
			printf("\n  ******************\n");
			printf("  ��������Ŀ���:");
			scanf("%d", &getCin.num);
		}
		printf("\n  ******************\n");
		printf("  ��������Ŀ����(1ѡ��,2���):");
		scanf("%d", &getCin.type);
		while (getCin.type < 1 || getCin.type>2)//��Ŀ��ű���Ϊ1��2
		{
			printf("\n����1-2�м�ѡ��");
			printf("\n  ******************\n");
			printf("  ��������Ŀ��(1ѡ��,2���):");
			scanf("%d", &getCin.num);
		}
		printf("\n  ******************\n");

		printf("\n��������Ŀ��");
		scanf("%s", getCin.topic);
		if (getCin.type == 1)
		{
			printf("\n  ******************\n");
			printf("\n������ѡ��A:");
			scanf("%s", getCin.choiceA);
			printf("\n������ѡ��B:");
			scanf("%s", getCin.choiceB);
			printf("\n������ѡ��C:");
			scanf("%s", getCin.choiceC);
			printf("\n������ѡ��D:");
			scanf("%s", getCin.choiceD);

		}
		printf("\n�������:");
		scanf("%s", getCin.answer);
		while (getCin.type == 1 &&
			getCin.answer[0] != 'A'&&
			getCin.answer[0] != 'B'&&
			getCin.answer[0] != 'C'&&
			getCin.answer[0] != 'D')//��Ŀ��ű���Ϊ1��2
		{
			printf("\nѡ������� A B C D�м�ѡ��");
			printf("\n  ******************\n");
			printf("  �������:");
			scanf("%s", getCin.answer);
		}

		Creat_SLinkList_Tail(list, getCin);//��������

		printf("\n\t\t��ӳɹ���1�������룬2����");
		scanf("%d", &item);
		if (item != 1)
			return;
	}



}

//��ʼ��������
bool Init_SLinkList(SLinklist* L)
{
	//����ͷ�ڵ�ռ�
	(*L) = (SLinklist)malloc(sizeof(SNode));
	if (!(*L))
	{
		printf("malloc error!");
		return false;
	}
	//��ʼû�нڵ�ͷ ��βָ���

	(*L)->choiceNum = 0;//ѡ������
	(*L)->TKNum = 0;//�������
	(*L)->head = NULL;
	(*L)->Tail = NULL;
	return true;
}

//β�巨����������
bool Creat_SLinkList_Tail(SLinklist L, ElemType e)
{

	SNode *  Node_new;

	Node_new = (SNode *)malloc(sizeof(SNode));
	if (!Node_new)
	{
		printf("malloc error!");
		return false;
	}
	Node_new->data = e;//�½ڵ����ݸ�ֵ
	Node_new->next = NULL;//�½ڵ���һ��û������

	if (!L->head)//����ͷû������  ָ���һ��
	{
		L->Tail = L->head = Node_new;

	}
	else
	{
		L->Tail->next = Node_new;//β�ڵ���һ���ڵ�ָ���µĽڵ�
		L->Tail= Node_new;
	}
		
	if (e.type == 1) {
		(L)->choiceNum++;//ѡ������


	}
	else
	{
		(L)->TKNum++;//�������

	}


	return true;
}

//����Ŀ��Ų��ҵ�����
SNode* Find_SLinkNode_Val(SLinklist L, int num)
{
	SNode * Node_find;
	Node_find = L->head;//��ͷ��ʼ����
	while (Node_find != NULL)
	{

		if (Node_find->data.num == num)
		{
			return Node_find;
		}
		Node_find = Node_find->next;
	}
	return NULL;

}
//ɾ��������ָ����Ŀ��ŵ�����//
int Delete_DatainList(SLinklist L, int num)
{

	SNode * node_L, *node_delete;
	node_L = NULL;
	node_delete = L->head;

	while (node_delete != NULL)
	{
		if (node_delete->data.num == num)
		{
			break;//�ҵ�����ѭ��
		}
		node_L = node_delete;//����ǰһ���ڵ�
		node_delete = node_L->next;
	}
	if (!node_delete)
	{

		return false;
	}
	if (!node_L)//ɾ��ͷ�ڵ�
	{
		L->head = node_delete->next;
	}
	else {

		node_L->next = node_delete->next;

	}
	if (node_delete->data.type == 1) {
		(L)->choiceNum--;//ѡ������

	}
	else
	{
		(L)->TKNum--;//�������

	}
	free(node_delete);

	return OK;//�궨���� okΪ 1 
}
int freeDatainList(SLinklist L)
{
	int len = 0;//�����ȳ�ʼ�� 
	SNode * Node_L;
	Node_L = L->head;
	while (Node_L != NULL)
	{
		SNode * de = Node_L;//��ʱ����ɾ���ڵ�ָ��
		len++;//��������� 
		Node_L = Node_L->next;//ָ����һ�ڵ�
		free(de);//�ͷŽڵ��ڴ�
	}
	free(L);//�ͷ�����ͷ
	return len;//������������
}
