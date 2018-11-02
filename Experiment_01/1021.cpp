#include<iostream>
#include<cstring>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

using namespace std;

typedef struct LNode{
	int data[2];
	struct LNode* next;
}LNode, *LinkList;

Status InitLinkList(LinkList &L){
	L = new LNode;
	L->next = NULL;
	return OK;
}

void ClearList(LinkList& a){
	LNode *p = a->next;
	a->next = NULL;
	while(p){
		LNode *t = p;
		p=p->next;
		delete t;
	}
}

void CreatList(LinkList& a, int len){
	LNode *p=a;
	for(int i=0;i<len;i++){
		p->next = new LNode;
		p = p->next;
		cin>>p->data[0]>>p->data[1];
	}
	p->next = NULL;
}

void OutPutList(LinkList a){
	LNode *p=a->next;
	int f=1,s=0;
	while(p){
		if(!p->data[0]){
			p=p->next;
			continue;
		}
		if(s&&p->data[0]>0)	cout<<'+';
		else	s=1;
		if(p->data[1])	cout<<p->data[0]<<"x^"<<p->data[1];
		else	cout<<p->data[0];
		f=0;
		p=p->next;
	}
	if(f)	cout<<'0'<<endl;
	else	cout<<endl;
}

void Add_to_L(LinkList &a, LNode *b, int f){
	LNode *p = a;
	int sign = 1;
	while(p->next){
		if(p->next->data[1] == b->data[1]){
			p->next->data[0] += b->data[0]*f;
			if(!p->next->data[0]){
				LNode *t = p->next;
				p->next = t->next;
				delete t;
			}
			sign = 0;
			break;
		}
		else if(p->next->data[1] < b->data[1]){
			LNode *t = new LNode;
			t->data[0] = b->data[0];
			t->data[1] = b->data[1];
			t->next = p->next;
			p->next = t;
			sign = 0;
			break;
		}
		p = p->next;
	}
	if(sign&&b->data[0]){
		LNode *t = new LNode;
		t->data[0] = b->data[0];
		t->data[1] = b->data[1];
		t->next = p->next;
		p->next = t;
	}
}



void oper_a(LinkList a, LinkList b){
	LinkList c;
	InitLinkList(c);
	for(LNode *p=a->next;p;p=p->next)	Add_to_L(c, p, 1);
	for(LNode *p=b->next;p;p=p->next)	Add_to_L(c, p, 1);
	OutPutList(c);
	ClearList(c);
}

void oper_b(LinkList a, LinkList b){
	for(LNode *p=b->next;p;p=p->next){
		Add_to_L(a, p, -1);
	}
	OutPutList(a);
}

void oper_c(LinkList a, LinkList b){
	LinkList c;
	InitLinkList(c);
	for(LNode *pa=a->next;pa;pa=pa->next){
		for(LNode *pb=b->next;pb;pb=pb->next){
			LNode *t = new LNode;
			t->data[0] = pa->data[0]*pb->data[0];
			t->data[1] = pa->data[1]+pb->data[1];
			Add_to_L(c,t,1);
			delete t;
		}
	}
	OutPutList(c);
	ClearList(c);
}

void oper_d(LinkList a, LinkList b){
	LinkList c;
	InitLinkList(c);
	for(LNode *p=a->next;p;p=p->next)
		if(--(p->data[1])>=0)
			Add_to_L(c, p, 1);
	OutPutList(c);
	ClearList(c);
	for(LNode *p=b->next;p;p=p->next)
		if(--(p->data[1])>=0)
			Add_to_L(c, p, 1);
	OutPutList(c);
	ClearList(c);
}

int main(){
	int k;
	LinkList a, b;
	int la, lb;
	char oper;
	InitLinkList(a);
	InitLinkList(b);
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>la>>lb;
		CreatList(a, la);
		CreatList(b, lb);
		cin>>oper;
		switch (oper){
			case '+': oper_a(a,b); break;
			case '-': oper_b(a,b); break;
			case '*': oper_c(a,b); break;
			case '\'': oper_d(a,b); break;
			default:break;
		}
		ClearList(a);
		ClearList(b);
	}
}
