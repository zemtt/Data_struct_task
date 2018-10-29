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

int ListLen(LinkList a){
	int i=0;
	while(a->next){
		i++;
		a = a->next;
	}
	return i;
}

int main(){
	int la,lb;
	while(1){
		LinkList c;
		InitLinkList(c);
		cin>>la>>lb;
		if(la==0&&lb==0)	break;
		
		int count; 
		for(int i=0;i<la+lb;i++){
			int newNum;
			cin>>newNum;
			count = 1;
			for(LNode* p = c->next;p;p=p->next){
				if(p->elem<newNum) break;
				count++;
			}
			if(count)	ListInsert(c,count,newNum);
		}
		int flag=0;
		for(LNode* p = c->next;p;p=p->next){
			if(flag)	cout<<' ';
			else	flag=1;
			cout<<p->elem;
		}
		cout<<endl;
	}
}
