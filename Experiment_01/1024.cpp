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

int main(){
	int len_a,len_b;
	LinkList<Data> c;
	cin>>len_a>>len_b;
	while(1){
		if(!len_a&&!len_b)	break;
		int t;
		cin>>t;
		int point=1;
		for(LNode<Data>* p=c.begin.next;p;p=p->next){
			if(p->data.k==t){
				p->data.m++;
				
			}
		} 
	}
} 
