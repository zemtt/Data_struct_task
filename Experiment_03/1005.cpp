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

void CountTree(BiThrTree tree, int *v, int i){
    if(tree){
        v[i]++;
        CountTree(tree->lchild, v, i+1);
        CountTree(tree->rchild, v, i+1);
    }
}

int Max(int *t){
    int max = t[0];
    for(int i=1;i<100;i++){
        if(!t[i])    break;
        if(max<t[i])    max = t[i];
    }
    return max;
}

int main(){
    char str0[100];
    int count[100];
    BiThrNode *tree0;
    while(1){
        cin>>str0;
        memset(count, 0, sizeof(count));
        if(!strcmp(str0, "0"))  break;
        ii=0;
        CreatTree(tree0, str0);
        CountTree(tree0, count, 0);
        cout<<Max(count)<<endl;
        ClearTree(tree0);
    }
}
