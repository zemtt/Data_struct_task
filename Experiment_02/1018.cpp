#include<iostream>
#include<cstring>
using namespace std;

struct Element{
    char c;
    int count;
};

typedef struct LNode{
    Element data;
    struct LNode* next;
}LNode, *LinkList;

void InitLinkList(LinkList &L){
    L = new LNode;
    L->next = NULL;
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

void InPut(char* a, LinkList& l){
    char *cp = a;
    while(*cp){
        int f = 1;
        for(LNode *p = l->next;p;p=p->next){
            if(p->data.c==*cp){
                p->data.count ++;
                f = 0;
            }
        }
        if(f){
            LNode *n = new LNode;
            LNode *p;
            n->data.c = *cp;
            n->data.count = 1;
            for(p = l;p->next;p=p->next){
                if(p->next->data.c > n->data.c) break;
            }
            n->next = p->next;
            p->next = n;
        }
        cp++;
    }
}

void OutPut(LinkList& l){
    LNode *p = l->next;
    while(p){
        cout<<p->data.c<<':'<<p->data.count<<endl;
        p = p->next;
    }
}

int main(){
    LinkList a;
    InitLinkList(a);
    char str[100];
    while(1){
        cin>>str;
        if(!strcmp(str,"0"))    break;
        InPut(str, a);
        OutPut(a);
        ClearList(a);
    }
}
