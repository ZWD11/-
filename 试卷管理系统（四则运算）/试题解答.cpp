#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int gcd(int a,int b){//��������Լ�� 
int t; 
if(a < b){
	int t = a;
	a = b;
	a = t;
}
while (b>0){
    t = a % b;
    a = b;
    b = t;
}
return a;
}

int problem_easy(){
	clock_t start,end;//clock_t(�����ͣ���ʱ����������ֵ��ʾ�ó������������������ռ��cpu��ʱ�䣬����Ϊ��λ�� 
	start = clock();
	int sum=0;//��ʼ�����Ե���Ŀ���� 
	
	FILE *fp, *fp_ans;
	fp = fopen("D:\\�����\\easy.txt","r");
	fp_ans = fopen("D:\\�����\\solve_easy.txt","w");
	
	if(fp == NULL){
		printf("�ļ���ʧ��!\n");
		exit(0);//�������в��˳����� 
	}else{
		while(!feof(fp)){ //feof������ļ��������ĺ������������㣬����Ϊ�㣩 
			char buf[20];//����һ���ַ��������ַ���ʽ������Ŀ 
			fgets(buf,20,fp);//��fp�ļ��ж�ȡ 
			int len = strlen(buf);
			int a=0,b=0;
			char c;
			for(int i=0;i<len-1;i++)
				printf("%c",buf[i]);
				
			int flag = 0;//�ж��Ƿ������ 
			for(int i=0;i<len-1;i++){
				if(flag == 0){
				if(buf[i] >= '0' && buf[i] <='9'){
					a =  buf[i] - '0';//����ת�� 
				}
				}
				
				if(buf[i] == '+') flag=1,c='+';
				if(buf[i] == '-') flag=1,c='-';
				
				if(flag == 1){
					if(buf[i] >= '0' && buf[i] <='9'){
						b = b * 10 + buf[i] - '0';
					}			
				}		
			}
			int ans,your_ans;
			if(c == '+'){
				ans = a+b;
				fprintf(fp_ans,"%d",a);
				fputs(" + ",fp_ans);
				fprintf(fp_ans,"%d",b);
				fputs(" = ",fp_ans);
			}else if(c == '-'){
				ans = a-b;
				fprintf(fp_ans,"%d",a);
				fputs(" - ",fp_ans);
				fprintf(fp_ans,"%d",b);
				fputs(" = ",fp_ans);
			}

			scanf("%d",&your_ans);
			fprintf(fp_ans,"%d\n",your_ans);
			
			if(your_ans == ans)
			     sum++;	
			
		}	

		end = clock();
		double time = (double)(end-start)/CLK_TCK;	//����clk_tck�Ѻ��뻯Ϊ��	

		printf("�㱾�δ���ʱ��Ϊ:%.2lf��\n",time);
		printf("���ĵ÷�Ϊ:%d��\n",sum*5);	
		fputs("�����δ���ʱ��Ϊ��",fp_ans);
		fprintf(fp_ans,"%.2lf��",time);
		fputs("\n���ĵ÷�Ϊ:",fp_ans);
		fprintf(fp_ans,"%d��\n",sum*5);		 
	}
	fclose(fp);
	fclose(fp_ans);	
	//�������ļ������ļ�����
	fp = NULL;
	fp_ans = NULL;
	struct tm *p;//ͨ���˽ṹ���ȡʱ�� 
    char name[100];
    time_t timep;//time_tʱ�����ͺ��� ��1970�꿪ʼ��������� 
    timep = time(NULL);//��ȡʱ�䣬��λΪ�� 
    p=localtime(&timep);//��ȡ��1970������˶����룬����time_t���͵�timep�в�ת��Ϊstruct tm �ṹ 
    strftime( name, 100, "%Y.%m.%d_%H %M %S.txt", p);//strftime����ת����str�ַ�����ʱ���ʽ 
	rename("solve_easy.txt",name);//rename���������ļ�����Ŀ¼ �ɹ�����0������Ϊ-1�� 
	return 0;	
	}
//��easy����һ�� 
int problem_medium(){
	clock_t start,end;
	start = clock();
	int sum=0;
	
	FILE *fp,*fp_ans;
	fp = fopen("D:\\�����\\medium.txt","r");
	fp_ans = fopen("D:\\�����\\solve_medium.txt","w");
	
	if(fp == NULL){
		printf("�ļ���ʧ�ܣ�\n");
		exit(0);
	}else{
		while(!feof(fp)){
			char buf[20];
			fgets(buf,20,fp);
			int len = strlen(buf);
			int a=0,b=0;
			char c;
			
			for(int i=0;i<len-1;i++)
				printf("%c",buf[i]);	
			int flag = 0;
			for(int i=0;i<len;i++){
				if(flag == 0){
					if(buf[i] >= '0' && buf[i] <='9'){
						a = a * 10 + buf[i] - '0';
					}
				}
				
				if(buf[i] == '+') flag=1,c='+';
				if(buf[i] == '-') flag=1,c='-';
				if(buf[i] == '*') flag=1,c='*';
				if(buf[i] == '/') flag=1,c='/';
								
				if(flag == 1){
					if(buf[i] >= '0' && buf[i] <='9'){
						b = b * 10 + buf[i] - '0';
					}			
				}		
			}			
			int ans,your_ans;

			if(c == '+'){
				ans = a+b;
				fprintf(fp_ans,"%d",a);//
				fputs(" + ",fp_ans);
				fprintf(fp_ans,"%d",b);
				fputs(" = ",fp_ans);
				scanf("%d",&your_ans);
				fprintf(fp_ans,"%d\n",your_ans);
				if(your_ans == ans)
					sum++;	
			}else if(c == '-'){
				ans = a-b;
				fprintf(fp_ans,"%d",a);
				fputs(" - ",fp_ans);
				fprintf(fp_ans,"%d",b);
				fputs(" = ",fp_ans);
				scanf("%d",&your_ans);
				fprintf(fp_ans,"%d\n",your_ans);
				if(your_ans == ans)
					sum++;
			}else if(c == '*'){
				ans = a*b;
				fprintf(fp_ans,"%d",a);
				fputs(" * ",fp_ans);
				fprintf(fp_ans,"%d",b);
				fputs(" = ",fp_ans);
				scanf("%d",&your_ans);
				fprintf(fp_ans,"%d\n",your_ans);
				if(your_ans == ans)
					sum++;				
			}else if(c == '/'){
				fprintf(fp_ans,"%d",a);
				fputs(" / ",fp_ans);
				fprintf(fp_ans,"%d",b);
				fputs(" = ",fp_ans);
				int ans_fenzi,ans_fenmu,your_fenzi,your_fenmu=0;
				int t = gcd(a,b);
				ans_fenzi = a/t;
				ans_fenmu = b/t;
				if(ans_fenmu == 1){
					char str[10];//���ַ�����ʽ���� 
					scanf("%s",str);
					int length = strlen(str);
					int student_ans = 0;
					for(int i=0;i<length;i++){
						if(str[i] >= '0' && str[i] <='9'){
							student_ans = student_ans * 10 + str[i] - '0';
							}
						}		
					fprintf(fp_ans,"%s\n",str);
				if(student_ans == ans_fenzi) //�����������ͬʱ
					sum++;
				}else{
					scanf("%d/%d",&your_fenzi,&your_fenmu);	
					if(your_fenmu != 0)
						fprintf(fp_ans,"%d/%d\n",your_fenzi,your_fenmu);
						else
						fprintf(fp_ans,"%d\n",your_fenzi);
					if((ans_fenzi == your_fenzi) && (ans_fenmu == your_fenmu))
						sum++;
				}
			}	
			
		}
		end = clock();
		double time = (double)(end-start)/CLK_TCK;		
		printf("�����δ����ʱ��Ϊ:%.2lf��\n",time);
		printf("���ĵ÷�Ϊ:%d��\n",sum*5);	
		fputs("�����εĴ���ʱ��Ϊ��",fp_ans);
		fprintf(fp_ans,"%.2lf��",time);
		fputs("\n���ĵ÷�Ϊ: ",fp_ans);
		fprintf(fp_ans,"%d��\n",sum*5);		
	}
	fclose(fp);
	fclose(fp_ans);
	//�������ļ������ļ�����
	fp = NULL;
	fp_ans = NULL;
	struct tm *p;
    char name[100];
    time_t timep;
    timep = time(NULL); 
    p=localtime(&timep);
    strftime(name, 100, "%Y.%m.%d_%H %M %S.txt", p);
	rename("solve_medium.txt",name);
	return 0;
}

int problem_difficult(){
	clock_t start,end;
	start = clock();
	int sum=0;
	
	FILE *fp,*fp_ans;
	fp = fopen("D:\\�����\\difficult.txt","r");
	fp_ans = fopen("D:\\�����\\solve_difficult.txt","w");
	
	if(fp == NULL){
		printf("�ļ���ʧ�ܣ�\n");
		exit(0);
	}else{
		while(!feof(fp)){
			char buf[20];
			fgets(buf,20,fp);
			int len = strlen(buf);
			int a=0,b=1,c=0,d=1;//�ֱ�洢�������ķ��ӡ���ĸ
			char op;//��¼����
			for(int i=0;i<len-1;i++)
				printf("%c",buf[i]);

			int flag = 0;//�����ж�ǰ����������
			a = buf[0] - '0';
			if(buf[1] == '/')
				b = buf[2] - '0';
				else
				b = 1;
				
			if(b == 1)//��¼����
				op = buf[2];
				else
				op = buf[4];
				
			for(int i=3;i<len;i++){
				if(buf[i] >= '0' && buf[i] <= '9' && flag == 0){
					c = buf[i] - '0';
					flag = 1;
					i++;//��ֹ�ظ���¼
				}
				if(flag == 1 && buf[i] >= '0' && buf[i] <= '9'){
					d = buf[i] - '0';
					
				}	
			}
									
			if(op == '+'){
				if(b == 1)	//���Ծ�д�������Ծ�
					fprintf(fp_ans,"%d",a);
					else
					fprintf(fp_ans,"%d/%d",a,b);
				fputs(" + ",fp_ans);
				if(d == 1)
					fprintf(fp_ans,"%d",c);
					else
					fprintf(fp_ans,"%d/%d",c,d);
				fprintf(fp_ans," = ");
				
				int ans_fenzi,ans_fenmu,yourans_fenzi,yourans_fenmu=0;	//�������������Ĵ����Ƚ�
				int da_fenzi = b * d; 
				int da_fenmu = a*d + b*c;
				int t = gcd(da_fenmu,da_fenzi);
				ans_fenzi = da_fenzi / t;
				ans_fenmu = da_fenmu / t;
				
				if(ans_fenmu == 1){//���𰸵ķ�ĸΪ1ʱ������ӦΪһ����������ֹ�û�������ַ�������
					char str[10];
					scanf("%s",str);
					int length = strlen(str);
					int student_ans ;
					for(int i=0;i<length;i++){
						if(str[i] >= '0' && str[i] <='9'){
								student_ans = student_ans * 10 + str[i] - '0';
							}
					}		
					fprintf(fp_ans,"%s\n",str);
					if(student_ans == ans_fenzi) //�����������ͬʱ
						sum++;
				}else{
					scanf("%d/%d",&yourans_fenzi,&yourans_fenmu);
					if(yourans_fenmu != 0)		//��ֹ�û�������
						fprintf(fp_ans,"%d/%d\n",yourans_fenzi,yourans_fenmu);
						else
						fprintf(fp_ans,"%d\n",yourans_fenzi);
					if((ans_fenzi == yourans_fenzi) && (ans_fenmu == yourans_fenmu))
						sum++;
				}
				
			}else if(op == '-'){		//����
				if(b == 1)					//���Ծ�д�������Ծ�
					fprintf(fp_ans,"%d",a);
					else
					fprintf(fp_ans,"%d/%d",a,b);
				fputs(" - ",fp_ans);
				if(d == 1)
					fprintf(fp_ans,"%d",c);
					else
					fprintf(fp_ans,"%d/%d",c,d);
				fprintf(fp_ans," = ");
				
				int ans_fenzi,ans_fenmu,yourans_fenzi,yourans_fenmu=0;
				int da_fenmu = b * d;//�������������Ĵ����Ƚ�
				int da_fenzi = a*d - b*c;
				int t = gcd(da_fenmu,da_fenzi);
				ans_fenzi = da_fenzi / t;
				ans_fenmu = da_fenmu / t;
				if(ans_fenmu == 1){	//���𰸵ķ�ĸΪ1ʱ������ӦΪһ����������ֹ�û�������ַ�������
					char str[10];
					scanf("%s",str);
					int	length= strlen(str);
					int stu_ans ;
					for(int i=0;i<length;i++){
						if(str[i] >= '0' && str[i] <='9'){
								stu_ans = stu_ans * 10 + str[i] - '0';
							}
					}		
					fprintf(fp_ans,"%s\n",str);
					if(stu_ans == ans_fenzi) //�����������ͬʱ
						sum++;
				}else{
					scanf("%d/%d",&yourans_fenzi,&yourans_fenmu);
					if(yourans_fenmu != 0)
						fprintf(fp_ans,"%d/%d\n",yourans_fenzi,yourans_fenmu);
					else
						fprintf(fp_ans,"%d\n",yourans_fenzi);
					if((ans_fenzi == yourans_fenzi) && (ans_fenmu == yourans_fenmu))
						sum++;
				}										
			}else if(op == '*'){
				if(b == 1)					//���Ծ�д�������Ծ�
					fprintf(fp_ans,"%d",a);
					else
					fprintf(fp_ans,"%d/%d",a,b);
				fputs(" * ",fp_ans);
				if(d == 1)
					fprintf(fp_ans,"%d",c);
					else
					fprintf(fp_ans,"%d/%d",c,d);
				fprintf(fp_ans," = ");
								
				int ans_fenzi,ans_fenmu,yourans_fenzi,yourans_fenmu=0;
				int da_fenmu = b * d;				//�������������Ĵ����Ƚ�
				int da_fenzi = a * c;
				int t = gcd(da_fenmu,da_fenzi);
				ans_fenzi = da_fenzi / t;
				ans_fenmu = da_fenmu / t;
				
				if(ans_fenmu == 1){				//���𰸵ķ�ĸΪ1ʱ������ӦΪһ����������ֹ�û�������ַ������� 
					char str[10];
					scanf("%s",str);
					int length = strlen(str);
					int stu_ans ;
					for(int i=0;i<length;i++){
						if(str[i] >= '0' && str[i] <='9'){
								stu_ans = stu_ans * 10 + str[i] - '0';
							}
					}
					
					fprintf(fp_ans,"%s\n",str);
					if(stu_ans == ans_fenzi) //�����������ͬʱ
						sum++;		
				}else{
					scanf("%d/%d",&yourans_fenzi,&yourans_fenmu);
					if(yourans_fenmu != 0)
						fprintf(fp_ans,"%d/%d\n",yourans_fenzi,yourans_fenmu);
					else
						fprintf(fp_ans,"%d\n",yourans_fenzi);
					if((ans_fenzi == yourans_fenzi) && (ans_fenmu == yourans_fenmu))
						sum++;
				}								
			}else if(op == '/'){//��������˷����ƣ��˵�������
				if(b == 1)	//���Ծ�д�������Ծ�
					fprintf(fp_ans,"%d",a);
					else
					fprintf(fp_ans,"%d/%d",a,b);
				fputs(" / ",fp_ans);
				if(d == 1)
					fprintf(fp_ans,"%d",c);
					else
					fprintf(fp_ans,"%d/%d",c,d);
				fprintf(fp_ans," = ");
				
				int ans_fenzi,ans_fenmu,yourans_fenzi,yourans_fenmu=0;
				int tempt = c; //���ó˷�ģ�壬�ߵ�һ�³������ӷ�ĸ
				c = d;
				d = tempt;
				
				int da_fenmu = b * d;				//�������������Ĵ����Ƚ�
				int da_fenzi = a * c;
				int t = gcd(da_fenmu,da_fenzi);
				ans_fenzi = da_fenzi / t;
				ans_fenmu = da_fenmu / t;
				
				if(ans_fenmu == 1){				//���𰸵ķ�ĸΪ1ʱ������ӦΪһ����������ֹ�û�������ַ�������
					char str[10];
					scanf("%s",str);
					int length = strlen(str);
					int stu_ans ;
					for(int i=0;i<length;i++){
						if(str[i] >= '0' && str[i] <='9'){
								stu_ans = stu_ans * 10 + str[i] - '0';
							}
					}
					
					fprintf(fp_ans,"%s\n",str);
					if(stu_ans == ans_fenzi) //�����������ͬʱ
						sum++;		
				}else{
					scanf("%d/%d",&yourans_fenzi,&yourans_fenmu);
					if(yourans_fenmu != 0)
						fprintf(fp_ans,"%d/%d\n",yourans_fenzi,yourans_fenmu);
					else
						fprintf(fp_ans,"%d\n",yourans_fenzi);
					if((ans_fenzi == yourans_fenzi) && (ans_fenmu == yourans_fenmu))
						sum++;
				}									
										
			}

		}
		end = clock();
		double time = (double)(end-start)/CLK_TCK;		
		
		printf("�����δ����ʱ��Ϊ:%.2lf��\n",time);
		printf("���ĵ÷�Ϊ:%d��\n",sum*5);
		fputs("���Ĵ���ʱ��Ϊ��",fp_ans);
		fprintf(fp_ans,"%.2lf��",time);
		fputs("\n���ĵ÷�Ϊ:",fp_ans);
		fprintf(fp_ans,"%d��\n",sum*5);		 
	}
	fclose(fp);
	fclose(fp_ans);
	//�ļ����� 
	fp = NULL;
	fp_ans = NULL;
	struct tm *p;
    char name[100];
    time_t timep;
    timep = time(NULL); 
    p=localtime(&timep);
    strftime( name, 100, "%Y.%m.%d_%H %M %S.txt", p);
	rename("solve_difficult.txt",name);	
	
	return 0;	
}

int main(){
	int nandu;
	printf("��ѡ���Ѷ� E easy M medium D difficult\n");
	        scanf("%c",&nandu);
	if(nandu == 'E'){
		problem_easy();
	}
		else if(nandu == 'M'){ 
			problem_medium();
		}
			else if(nandu == 'D'){
				problem_difficult();
				}
		system("pause");
}
