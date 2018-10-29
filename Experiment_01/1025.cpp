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
	int count=0;
	while(p){
		if(f)
			cout<<' ';
		else
			f=1;
		cout<<p->elem;
		p = p->next;
		count++;
	}
	cout<<endl;
	cout<<count<<endl;
}

int main(){
	int la,lb;
	LNode *pa,*pb;
	LinkList a,b,c;
	InitLinkList(a);
	InitLinkList(b);
	InitLinkList(c);
	while(1){
		int count = 0;
		InitLinkList(c);
		cin>>la>>lb;
		if(la==0&&lb==0)	break;
		InputList(a,la);
		InputList(b,lb);
		pa = a->next;
		pb = b->next;
		while(pa&&pb){
			if(pa->elem < pb->elem){
				ListInsert(c,++count,pa->elem);
				pa = pa->next;
			}
			else if(pa->elem > pb->elem){
				pb = pb->next;
			}
			else{
				pa = pa->next;
				pb = pb->next;
			}
		}
		while(pa){
			ListInsert(c,++count,pa->elem);
			pa = pa->next;
		}
		OutputList(c);
		ListClear(a);
		ListClear(b);
		ListClear(c);
	}
}