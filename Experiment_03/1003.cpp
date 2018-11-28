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

bool CompareTree(BiThrNode *t0, BiThrNode *t1){
    if(t0&&t1){
        if(t0->data!=t1->data){
            return false;
        }
        else{
            return (
                CompareTree(t0->lchild, t1->lchild)
                &&
                CompareTree(t0->rchild, t1->rchild)
            );
        }
    }
    else if(!t0&&!t1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    char str0[100], str1[100];
    BiThrNode *tree0, *tree1;
    while(1){
        cin>>str0;
        if(!strcmp(str0, "0"))  break;
        cin>>str1;
        ii=0;
        CreatTree(tree0, str0);
        ii=0;
        CreatTree(tree1, str1);
        if(CompareTree(tree0, tree1))   cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
        ClearTree(tree0);
        ClearTree(tree1);
    }
}
