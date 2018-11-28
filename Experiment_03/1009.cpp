#include<iostream>
#include<cstring>

using namespace std;

int ii;
int count[3];

typedef struct BiThrNode{
    char data;
    struct BiThrNode *lchild, *rchild;
}BiThrNode, *BiThrTree;

void CreatTree(BiThrTree &tree, char *str){
    if(str[ii]!='0'&&str[ii]){
        int t=0;
        tree = new BiThrNode;
        tree->data = str[ii++];
        CreatTree(tree->lchild, str);
        CreatTree(tree->rchild, str);
        if(tree->lchild)    t++;
        if(tree->rchild)    t++;
        count[t]++;
    }
    else{
        tree = NULL;
        ii++;
    }
}

void ClearTree(BiThrNode *tree){
    if(tree){
        ClearTree(tree->lchild);
        ClearTree(tree->rchild);
        delete tree;
    }
}

int main(){
    char str0[100];
    BiThrNode *tree0;
    while(1){
        cin>>str0;
        if(!strcmp(str0, "0"))  break;
        memset(count,0,sizeof(count));
        ii=0;
        CreatTree(tree0, str0);
        cout<<count[0]<<' '<<count[1]<<' '<<count[2]<<endl;
        ClearTree(tree0);
    }
}
