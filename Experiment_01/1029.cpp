
#include<iostream>
#include<cstring>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

using namespace std;

typedef struct LNode{
	int elem;
	struct LNode* next;
}LNode, *LinkList;

Status InitLinkList(LinkList &L){
	L = new LNode;
	L->next = NULL;
	return OK;
}

Status GetElem(LinkList L, int i, int&e){
	LNode* p = L->next;
	for(int k=1;k<i;k++){
		if(!p->next)	return ERROR;
		p = p->next;
	}
	e = p->elem;
	return OK;
}

LNode* LocateElem(LinkList L, int e){
	LNode* p = L->next;
	while(p){
		if(e=p->elem)
			return p;
		p = p->next;
	}
	return NULL;
}

Status ListInsert(LinkList& L, int i, int e){
	LNode* p = L;
	for(int k=1;k<i;k++){
		if(!p->next)	return ERROR;
		p = p->next;
	}
	LNode* t = new LNode;
	t->elem = e;
	t->next = p->next;
	p->next = t;
	return OK;	
}

Status ListDelete(LinkList& L, int i){
	if(i<1) return ERROR;
	LNode* p = L;
	LNode* pp;
	for(int k=0;k<i;k++){
		if(!p->next)	return ERROR;
		pp = p;
		p = p->next;
	}
	LNode* t = pp->next;
	pp->next = t->next;
	delete t;
	return OK; 
}

Status ListClear(LinkList& L){
	if(L->next){
		ListClear(L->next);
		delete L->next;
	}
	else{
		L->next = NULL;
	}
	return OK; 
}

int ListLen(LinkList a){
	int i=0;
	while(a->next){
		i++;
		a = a->next;
	}
	return i;
}

Status InputList(LinkList& a, int n){
	LNode* p = a;
	for(int i=0;i<n;i++){
		p->next = new LNode;
		cin>>p->next->elem;
		p=p->next;
	}
	p->next = NULL;
}

Status OutputList(LinkList a){
	LNode* p = a->next;
	int f=0;
	while(p){
		if(f)
			cout<<' ';
		else
			f=1;
		cout<<p->elem;
		p = p->next;
	}
	cout<<endl;
}

int main(){
	int len;
	LinkList a;
	LNode *pa;
	InitLinkList(a);
	int min,max;
	while(1){
		int count = 0;
		cin>>len;
		if(!len)	break;
		InputList(a,len);
		cin>>min>>max;
		LNode *p=a;
		while(p->next){
			if(p->next->elem>=min&&p->next->elem<=max){
				LNode *t = p->next;
				p->next = t->next;
				delete t;
			}
			else{
				p=p->next;
			}
		}
        OutputList(a);
		ListClear(a);
	}
}
