#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
using namespace std;
#define maxsize 100

typedef struct{
	char *top;
	char *base;
	int stacksize;
}CharStack;

typedef struct{
	double *top;
	double *base;
	int stacksize;
}DoubleStack;

void InitStack(CharStack &oper,DoubleStack &oper_num)
{
	oper.base=new char[maxsize];
	oper_num.base=new double[maxsize];
	*oper.base='=';
	oper.top=oper.base+1;
	oper_num.top=oper_num.base;
	oper.stacksize=oper_num.stacksize=maxsize; 
}

int Compare(char ch,char t)
{
	if(ch=='+'&&(t=='('||t=='=')||ch=='-'&&(t=='('||t=='=')||ch=='*'&&(t=='+'||t=='-'||t=='('||t=='=')||ch=='/'&&(t=='+'||t=='-'||t=='('||t=='=')||ch=='(')
		return 1;
	else if(ch==')'&&t=='('||ch=='='&&t=='=')
		return 0;
	else
		return -1;
}

double Operate(double x,char ch,double y)
{
	if(ch=='+')
		return x+y;
	else if(ch=='-')
		return x-y;
	else if(ch=='*')
		return x*y;
	else if(ch=='/')
		return x/y;
}

void Evaluate1(CharStack &oper,DoubleStack &oper_num,char ch){
		int flag=Compare(ch,*(oper.top-1));
		if(flag>0)
			*oper.top++=ch;
		else if(flag<0){
			double x,y;
			y=*--oper_num.top;
			x=*--oper_num.top;
			*oper_num.top++=Operate(x,*--oper.top,y);
			Evaluate1(oper,oper_num,ch);
		}
		else
			oper.top--;
}

void Evaluate2(CharStack &oper,DoubleStack &oper_num,double num){
	*oper_num.top++=num;
}

int main()
{
	char s[maxsize];
	memset(s,'\0',sizeof(s));
	cin>>s;
	while(s[0]!='='){
		CharStack oper;
		DoubleStack oper_num;
		InitStack(oper,oper_num);
		char ch;
		double num;
		for(int i=0;s[i]!='\0';i++){
			if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='('||s[i]==')'||s[i]=='='){
				ch=s[i];
				Evaluate1(oper,oper_num,ch);
			}
			else{
				char t[10];
				memset(t,'\0',sizeof(t));
				int n=0;
				while(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='('&&s[i]!=')'&&s[i]!='='){
					t[n++]=s[i];
					i++;
				}
				i--;
				num=atof(t);
				Evaluate2(oper,oper_num,num);
			}
		}
		cout<<fixed<<setprecision(2)<<(*(oper_num.top-1))<<endl;
		cin>>s;
	}
	return 0;
}