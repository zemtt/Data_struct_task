#include<iostream>
#include<cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX 1000
typedef int Status;

using namespace std;

typedef struct{
    char* top;
    char *base;
    int stack_size;
}Stack;

Status InitStack(Stack& a){
    a.base = new char[MAX];
    if(!a.base) exit(OVERFLOW);
    a.top = a.base;
    a.stack_size = MAX;
    return OK;
}

bool StackEmpty(Stack a){
    return a.top == a.base;
}

int StackLength(Stack a){
    return a.top - a.base;
}

Status ClearStack(Stack& a){
    a.top = a.base;
    return OK;
}

Status DestroyStack(Stack &s){
    delete s.base;
    s.stack_size = 0;
    s.base = NULL;
    s.top = NULL;
    return OK;
}

Status Push(Stack& a, char e){
    if(a.top - a.base == a.stack_size)    return ERROR;
    *a.top++ = e;
    return OK;
}

Status Pop(Stack& a, char& e){
    if(a.top == a.base) return ERROR;
    else e = *--a.top;
    return OK;
}

Status GetTop(Stack a, char& e){
    if(a.top = a.base)  return ERROR;
    e = *(a.top-1);
    return OK;
}

int operCmp(char op1, char op2){
    // 大于返回1 小于返回0 右括号返回-1
    if(op2==')')    return -1;
    if(
        (op1 == '+' || op1 == '-')  &&  (op2 == '*' || op2 == '/') ||
        (op1 == '*' || op2 == '\\') && (op2 == '(')
    )   return 0;
    cout<<"Ni"<<endl;
    return 1;
}

int main(){
    char str[100];
    Stack oper;
    char t;
    while(1){
        InitStack(oper);
        cin>>str;
        if(!strcmp(str,"="))    break;
        for(char *c = str;*c;c++){
            if(*c=='='){
                while(1){
                    if(Pop(oper, t)!=OK)    break;
                    else    cout<<t;
                }
                cout<<endl;
                break;
            }
            if(*c<='9'&&*c>='0')    cout<<*c;
            else{
                if(GetTop(oper, t)==OK){
                    int result = operCmp(t, *c);
                    if(result==1){
                        Pop(oper, t);
                        cout<<t;
                        Push(oper,*c);
                    }
                    else if(result==-1){
                        while(1){
                            Pop(oper, t);
                            if(t=='(')  break;
                            cout<<t;
                        }
                    }
                }
                else
                    Push(oper, *c);
            }
        }
    }
}
