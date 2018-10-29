#include <iostream>
#include <cstring>
#include <iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

using namespace std;

template<typename T>
class LNode{
public:
    LNode();
    LNode(T);
    void operator=(const LNode);

    T data;
    LNode* next;
};

template<typename T>
LNode<T>::LNode(){
    data = T();
    next = NULL;
}

template<typename T>
LNode<T>::LNode(T a){
    data = a;
    next = NULL;
}

template<typename T>
void LNode<T>::operator=(const LNode<T> node){
    data = node.data;
}

template<typename T>
class LinkList{
public:
    LNode<T> begin;
    int len;

    LinkList();
    LinkList(int);
    ~LinkList();
    void clear(LNode<T>* p);
    void clear();
    bool empty();
    int lenth();
    Status getElem(int, T&);
    LNode<T>* locateElem(T);
    Status insert(T, int);
    Status delete_(int);
};

template<typename T>
LinkList<T>::LinkList(){
    begin = LNode<T>();
    len = 0;
}

template<typename T>
LinkList<T>::~LinkList(){
    clear();
    len = 0;
}

template<typename T>
void LinkList<T>::clear(LNode<T>* p){
    if(p != NULL){
        clear(p->next);
        delete p->next;
    }
}

template<typename T>
void LinkList<T>::clear(){
    clear(&begin);
    len = 0;
    begin.next = NULL;
}


template<typename T>
bool LinkList<T>::empty(){
    return bool(len);
}

template<typename T>
int LinkList<T>::lenth(){
    return len;
}

template<typename T>
Status LinkList<T>::getElem(int i, T& elem){
    if(i<1||i>lenth())  return ERROR;
    T* p = &begin;
    for(int i=0;i<i;i++){
        p = p->next;
    }
    elem = p->data;
    return OK;
}

template<typename T>
LNode<T>* LinkList<T>::locateElem(T elem){
    T* p = &begin;
    for(int i=0;i<len;i++){
        p = p->next;
        if(elem==p->data)   return p;
    }
    return NULL;
}

template<typename T>
Status LinkList<T>::insert(T elem, int i){
    if((i<1||(i>len+1)))    return ERROR;
    
    LNode<T>* p_s = &begin;
    for(int k=0;k<i-1;k++){
        p_s = p_s->next;
    }
    LNode<T>* p_e = p_s->next;

    LNode<T>* a = new LNode<T>;
    p_s->next = a;
    a->data = elem;
    a->next = p_e;

    len++;
    return OK;
}

template<typename T>
Status LinkList<T>::delete_(int i){
    if((i<1||(i>len)))    return ERROR;

    LNode<T>* p_s = &begin;

    for(int k=0;k<i-1;k++){
        p_s = p_s->next;
    }
    LNode<T>* p_e = p_s->next;
    p_s->next = p_e->next;
    delete p_e;
    len--;
    return OK;
}

struct Data{
	int k, m;
};

void oper_a(LinkList<Data>& a, LinkList<Data>& b){
	LinkList<Data> c;
	for(LNode<Data>* p=a.begin.next;p;p=p->next){
		int count = 1;
		for(LNode<Data>* pc=c.begin.next;pc;pc=pc->next){
			if(pc->data.m<p->data.m)	break;
			if(pc->data.m==p->data.m){
				pc->data.k += p->data.k;
				count = 0;
				break;
			}
			count++;
		}
		if(count)
			c.insert(p->data,count);
	}
	for(LNode<Data>* p=b.begin.next;p;p=p->next){
		int count = 1;
		for(LNode<Data>* pc=c.begin.next;pc;pc=pc->next){
			if(pc->data.m<p->data.m)	break;
			if(pc->data.m==p->data.m){
				pc->data.k += p->data.k;
				count = 0;
				break;
			}
			count++;
		}
		if(count)
			c.insert(p->data,count);
	}
	int flag=0;
	int flag2=0;
	for(LNode<Data>* p=c.begin.next;p;p=p->next){
		if(flag)	cout<<'+';
		else	flag=1;
		if(!p->data.k)
			continue;
		if(p->data.m)
			cout<<p->data.k<<"x^"<<p->data.m;
		else
			cout<<p->data.k;
		flag2=1;
	}
	if(!flag2)
		cout<<'0';
	cout<<endl; 
}

void oper_b(LinkList<Data> a, LinkList<Data> b){
	LinkList<Data> c;
	for(LNode<Data>* p=a.begin.next;p;p=p->next){
		int count = 1;
		for(LNode<Data>* pc=c.begin.next;pc;pc=pc->next){
			if(pc->data.m<p->data.m)	break;
			if(pc->data.m==p->data.m){
				pc->data.k -= p->data.k;
				count = 0;
				break;
			}
			count++;
		}
		if(count)
			c.insert(p->data,count);
	}
	for(LNode<Data>* p=b.begin.next;p;p=p->next){
		int count = 1;
		for(LNode<Data>* pc=c.begin.next;pc;pc=pc->next){
			if(pc->data.m<p->data.m)	break;
			if(pc->data.m==p->data.m){
				pc->data.k -= p->data.k;
				count = 0;
				break;
			}
			count++;
		}
		if(count)
			c.insert(p->data,count);
	}
	int flag=0;
	int flag2=0;
	for(LNode<Data>* p=c.begin.next;p;p=p->next){
		if(flag)	cout<<'+';
		else	flag=1;
		if(!p->data.k)
			continue;
		if(p->data.m)
			cout<<p->data.k<<"x^"<<p->data.m;
		else
			cout<<p->data.k;
		flag2=1;
	}
	if(!flag2)
		cout<<'0';
	cout<<endl; 
}

void oper_c(LinkList<Data> a, LinkList<Data> b){
	
}

void oper_d(LinkList<Data> a, LinkList<Data> b){
	LinkList<Data> c;
	for(LNode<Data>* p=a.begin.next;p;p=p->next){
		int count = 1;
		for(LNode<Data>* pc=c.begin.next;pc;pc=pc->next){
			if(pc->data.m<p->data.m)	break;
			if(pc->data.m==p->data.m){
				pc->data.k -= p->data.k;
				count = 0;
				break;
			}
			count++;
		}
		if(count)
			c.insert(p->data,count);
	}
	int flag=0;
	int flag2=0;
	for(LNode<Data>* p=c.begin.next;p;p=p->next){
		if(flag)	cout<<'+';
		else	flag=1;
		if(!p->data.k||p->data.m-1<0)
			continue;
		if(p->data.m-1)
			cout<<p->data.k<<"x^"<<p->data.m-1;
		else
			cout<<p->data.k;
		flag2=1;
	}
	if(!flag2)
		cout<<'0';
	cout<<endl; 
	c.clear();
	for(LNode<Data>* p=b.begin.next;p;p=p->next){
		int count = 1;
		for(LNode<Data>* pc=c.begin.next;pc;pc=pc->next){
			if(pc->data.m<p->data.m)	break;
			if(pc->data.m==p->data.m){
				pc->data.k -= p->data.k;
				count = 0;
				break;
			}
			count++;
		}
		if(count)
			c.insert(p->data,count);
	}
	flag=0;
	flag2=0;
	for(LNode<Data>* p=c.begin.next;p;p=p->next){
		if(flag)	cout<<'+';
		else	flag=1;
		if(!p->data.k||p->data.m-1<0)
			continue;
		if(p->data.m-1)
			cout<<p->data.k<<"x^"<<p->data.m-1;
		else
			cout<<p->data.k;
		flag2=1;
	}
	if(!flag2)
		cout<<'0';
	cout<<endl; 
}

int main(){
	int n;
	cin>>n;
	while(n>0){
		n--;
		LinkList<Data> a,b;
		int len_a, len_b;
		cin>>len_a>>len_b;
		for(int i=0;i<len_a;i++){
			Data dt;
			cin>>dt.k>>dt.m;
			a.insert(dt,1);
		}
		for(int i=0;i<len_b;i++){
			Data dt;
			cin>>dt.k>>dt.m;
			b.insert(dt,1);
		}
		char oper;
		cin>>oper;
		switch(oper){
		case'+':oper_a(a,b);break;
		case'-':oper_b(a,b);break;
		case'*':oper_c(a,b);break;
		case'\'':oper_d(a,b);break;
		default:break;
		}
	}
}
