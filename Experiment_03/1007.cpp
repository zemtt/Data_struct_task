#include<iostream>
#include<cstring>

using namespace std;

int ii;
int cc;

typedef struct BiThrNode{
    char data;
    struct BiThrNode *lchild, *rchild;
}BiThrNode, *BiThrTree;

char path[100][100];
char v[100];

void copy(char *a, char *b, int len){
    for(int i=0;i<=len;i++){
        a[i] = b[len-i];
    }
}

void CreatTree(BiThrTree &tree, char *str, int vv){
    if(str[ii]!='0'&&str[ii]){
        tree = new BiThrNode;
        tree->data = str[ii++];
        v[vv] = tree->data;
        CreatTree(tree->lchild, str, vv+1);
        CreatTree(tree->rchild, str, vv+1);
        if(!tree->lchild&&!tree->rchild)
            copy(path[cc++], v, vv);
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
        cc = 0;
        memset(path, 0, sizeof(path));
        ii=0;
        CreatTree(tree0, str0, 0);
        int i;
        for(i=0; path[i][0]; i++)
            cout<<path[i]<<endl;
        ClearTree(tree0);
    }
}
