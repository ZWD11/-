#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h> 

//��������С��Լ�� 
    int gcd(int a,int b){
    int t; 
    while (b>0){
    t = a % b;
    a = b;
    b = t;
    }
    return a;
    }

//�����Ծ����� 
void problem_easy(){ 
	srand(time(NULL));//��ʱ��Ϊ���ӣ�ʹ����������� 
	FILE *fp,*fp_ans;
	fp = fopen("D:\\�����\\easy.txt","w");
	fp_ans = fopen("D:\\�����\\answer_easy.txt","w");
	int a,b;
	char c;	
	for(int i=0;i<20;i++){
		a = rand() % 11;//ʹa��ʮ���� ������ʮ�� 
		b = rand() % 11;//ʹb��ʮ���� ������ʮ��
		c = rand() % 4 + 42;
		while(c != 43 && c != 45)//ʹ�����ֻ��Ϊ�Ӻͼ� 
			c = rand()%4 + 42;
		while(c == 45 && b > a){//ʹ��Ϊ���� 
			a = rand() % 11;
		}
			int ans;
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

		fprintf(fp,"%d %c %d = \n",a,c,b);
		fprintf(fp_ans,"%d\n",ans);
	}
	fclose(fp);
	fclose(fp_ans);
}

//medium���Ծ����� 
void problem_medium(){
	srand(time(NULL));
	FILE *fp,*fp_ans;
	fp = fopen("D:\\�����\\medium.txt","w");
	fp_ans = fopen("D:\\�����\\answer_medium.txt","w");
	int a,b;
	char c;
	for(int i=0;i<20;i++){
		a = rand() % 101;//ʹÿ��������100���ڣ�����100�� 
		b = rand() % 101;
		c = rand() % 6 + 42;
		while(c != 43 && c != 45 && c != 42 && c!= 47)//���������Ϊ�Ӽ��˳� 
			c = rand()%6 + 42;
		if(c == 45 && b > a)
			c = 43;
		if(c == 47 && b == 0)
			c = 42;
		while((c == 43 && a + b>100) || (c == 42 && a*b > 100)){//ʹ�������ͽ����100�� 
			a = rand() % 101;	
     	}
     	
			if(c == '+'){
				int ans;
				ans = a+b;
				fprintf(fp_ans,"%d",a);//
				fputs(" + ",fp_ans);
				fprintf(fp_ans,"%d",b);
				fputs(" = ",fp_ans);
				fprintf(fp_ans,"%d\n",ans);
		}else if(c == '-'){
			    int ans;
				ans = a-b;
				fprintf(fp_ans,"%d",a);
				fputs(" - ",fp_ans);
				fprintf(fp_ans,"%d",b);
				fputs(" = ",fp_ans);
				fprintf(fp_ans,"%d\n",ans);
		}else if(c == '*'){
			    int ans;
				ans = a*b;
				fprintf(fp_ans,"%d",a);
				fputs(" * ",fp_ans);
				fprintf(fp_ans,"%d",b);
				fputs(" = ",fp_ans);
				fprintf(fp_ans,"%d\n",ans);		
		}else if(c == '/'){
				fprintf(fp_ans,"%d",a);
				fputs(" / ",fp_ans);
				fprintf(fp_ans,"%d",b);
				fputs(" = ",fp_ans);
				int ans_fenzi,ans_fenmu;
				int t = gcd(a,b);
				ans_fenzi = a/t;
				ans_fenmu = b/t;
				if(ans_fenmu == 1){
		           fprintf(fp_ans,"%d\n",ans_fenzi);
				}else{
					fprintf(fp_ans,"%d/%d\n",ans_fenzi,ans_fenmu);
				}
			}
			fprintf(fp,"%d %c %d = \n",a,c,b);
	}
	fclose(fp);
	fclose(fp_ans);		
}

//�������Ծ����� 
void problem_difficult(){
	srand(time(NULL));
	FILE *fp,*fp_ans;
	fp = fopen("D:\\�����\\difficult.txt","w");
	fp_ans = fopen("D:\\�����\\answer_difficult.txt","w");
	int a,b=1,d,e=1;
	char c;
	int flag1=0,flag2=0;//flag1Ϊ�ж�ǰ����Ǹ��Ƿ�Ϊ��ʽ��flag2Ϊ�����Ǹ� 
	
	for(int i=0;i<20;i++){
		a = rand() % 9 +1;//ʹÿ��������1���� 
		b = rand() % 9 +1;
		c = rand()%6 + 42;//ʹc�����42��47�� 
		d = rand() % 9 +1;
		e = rand()%9 + 1;
		
		while(c != 43 && c != 45 && c != 42 && c != 47)//���������Ϊ�Ӽ��˳� 
			c = rand()%6 + 42;

		while( (double)a/b < (double)d/e && c == 45)//ʹ�����Ϊ���� 
			c = 43;
		
		if(a >= b && a % b==0){
			flag1 = 1;
			a = a/b;//ʹ��Ϊ���ʽ 
		}
		if(d >= e && d % e == 0){
			flag2 = 1;
			d = d/e;
		}
		if(a < b && b % a ==0){
			int m = gcd(b,a);
			a=a/m;//ʹ��ʽ���� 
			b=b/m;
		}
		if(d < e && e % d ==0){
			int m = gcd(e,d);
			d=d/m;
			e=e/m;
		}					
			if(c == '+'){
				if(b == 1){
					fprintf(fp_ans,"%d",a);
					fprintf(fp,"%d",a);
				}
					else{
					fprintf(fp_ans,"%d/%d",a,b);
					fprintf(fp,"%d/%d",a,b);
					}
				fputs(" + ",fp_ans);
				fputs(" + ",fp);
				if(e == 1){
				
					fprintf(fp_ans,"%d",d);
					fprintf(fp,"%d",d);
				}
					else{
					
					 fprintf(fp_ans,"%d/%d",d,e);
					 	fprintf(fp,"%d/%d",d,e);
						 }
				fputs(" = ",fp_ans);
				fputs(" = \n",fp);
				
				int ans_fenzi,ans_fenmu;
				int da_fenmu = b * e;
				int da_fenzi = a*e + b*d;
				int t = gcd(da_fenmu,da_fenzi);
				ans_fenzi = da_fenzi / t;
				ans_fenmu = da_fenmu / t;
				if(ans_fenmu == 1){
					fprintf(fp_ans,"%d\n",ans_fenzi);
				}else{
					fprintf(fp_ans,"%d/%d\n",ans_fenzi,ans_fenmu);
				}
			}else if(c == '-'){				
				if(b == 1){
							
					fprintf(fp_ans,"%d",a);
					fprintf(fp,"%d",a);}
					else{
					
					fprintf(fp_ans,"%d/%d",a,b);
					fprintf(fp,"%d/%d",a,b);
				}
				fputs(" - ",fp_ans);
					fputs(" - ",fp);
				if(e == 1){
				
					fprintf(fp_ans,"%d",d);
					fprintf(fp,"%d",d);
				}
					else{
					
					fprintf(fp_ans,"%d/%d",d,e);
					fprintf(fp,"%d/%d",d,e);
				}
				fputs(" = ",fp_ans);
				fputs(" = \n",fp);
				
				int ans_fenzi,ans_fenmu;
				int da_fenmu = b * e;
				int da_fenzi = a*e - b*d;
				int t = gcd(da_fenmu,da_fenzi);
				ans_fenzi = da_fenzi / t;
				ans_fenmu = da_fenmu / t;
			if(ans_fenmu == 1){
					fprintf(fp_ans,"%d\n",ans_fenzi);
				}else{
					fprintf(fp_ans,"%d/%d\n",ans_fenzi,ans_fenmu);
				}
			}else if(c == '*'){
				if(b == 1){
			
					fprintf(fp_ans,"%d",a);
					fprintf(fp,"%d",a);
					}
					else{
					
					fprintf(fp_ans,"%d/%d",a,b);
					fprintf(fp,"%d/%d",a,b);
				}
				fputs(" * ",fp_ans);
				fputs(" * ",fp);
				if(e == 1){
				
					fprintf(fp_ans,"%d",d);
					fprintf(fp,"%d",d);}
					else{
					
					fprintf(fp_ans,"%d/%d",d,e);
					fprintf(fp,"%d/%d",d,e);}
				fputs(" = ",fp_ans);
				fputs(" = \n",fp);
								
				int ans_fenzi,ans_fenmu,yourans_fenzi,yourans_fenmu=0;
				int da_fenmu = b * e;			
				int da_fenzi = a * d;
				int t = gcd(da_fenmu,da_fenzi);
				ans_fenzi = da_fenzi / t;
				ans_fenmu = da_fenmu / t;
					if(ans_fenmu == 1){
					fprintf(fp_ans,"%d\n",ans_fenzi);
				}else{
					fprintf(fp_ans,"%d/%d\n",ans_fenzi,ans_fenmu);
				}
			}else if(c == '/'){//��������˷����ƣ��˵�������
				if(b == 1){
				
					fprintf(fp_ans,"%d",a);
					fprintf(fp,"%d",a);}
					else{
					
					fprintf(fp_ans,"%d/%d",a,b);
					fprintf(fp,"%d/%d",a,b);}
				fputs(" / ",fp_ans);
				fputs(" / ",fp);
				if(e == 1){
				
					fprintf(fp_ans,"%d",d);
					fprintf(fp,"%d",d);}	
					else{
					
					fprintf(fp_ans,"%d/%d",d,e);
					fprintf(fp,"%d/%d",d,e);
				}
				fputs(" = ",fp_ans);
				fputs(" = \n",fp);
				
				int ans_fenzi,ans_fenmu,yourans_fenzi,yourans_fenmu=0;
				int tempt = d; //���ó˷�ģ�壬�ߵ�һ�³������ӷ�ĸ
				d = e;
				e = tempt;
				
				int da_fenmu = b * e;				//�������������Ĵ����Ƚ�
				int da_fenzi = a * d;
				int t = gcd(da_fenmu,da_fenzi);
				ans_fenzi = da_fenzi / t;
				ans_fenmu = da_fenmu / t;
					if(ans_fenmu == 1){
					fprintf(fp_ans,"%d\n",ans_fenzi);
				}else{
					fprintf(fp_ans,"%d/%d\n",ans_fenzi,ans_fenmu);
				}
			}
	}
	fclose(fp);
	fclose(fp_ans);		
}

int main(){
	problem_easy();
	problem_medium();
	problem_difficult();
	printf("\n�Ծ���������ɣ�\n\n");	
	system("pause");
}
