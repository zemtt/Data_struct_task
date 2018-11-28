#include<iostream>
#include<cstring>

using namespace std;

int ii;

typedef struct BiThrNode{
    char data;
    struct BiThrNode *lchild, *rchild;
}BiThrNode, *BiThrTree;

void CreatTree(BiThrTree &tree, char *str){
    if(str[ii]!='0'&&str[ii]){
        tree = new BiThrNode;
        tree->data = str[ii++];
        CreatTree(tree->lchild, str);
        CreatTree(tree->rchild, str);
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

void PrintTree(BiThrTree tree){
    if(tree){
        cout<<tree->data;
        PrintTree(tree->lchild);
        cout<<tree->data;
        PrintTree(tree->rchild);
    }
}

int main(){
    char str0[100];
    BiThrNode *tree0;
    while(1){
        cin>>str0;
        if(!strcmp(str0, "0"))  break;
        ii=0;
        CreatTree(tree0, str0);
        PrintTree(tree0);
        cout<<endl;
        ClearTree(tree0);
    }
}