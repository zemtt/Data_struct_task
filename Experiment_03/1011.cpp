#include<iostream>
#include<cstring>

using namespace std;

int ii;

typedef struct BiThrNode{
    char data;
    struct BiThrNode *lchild, *rchild;
}BiThrNode, *BiThrTree;

void CreatTree(BiThrTree &tree, char *str, int begin, int end){
    BiThrNode *p = NULL;
    BiThrNode *root = NULL;
    for(int i=begin; i<end; i++){
        if(str[i]<='9'&&str[i]>='0')    continue;
        if(!p){
            p = 
        }
    }
}

void FeedTree(BiThrNode *tree, char *str){

}

int CountTree(BiThrNode *tree){

}

void ClearTree(BiThrNode *tree){
    if(tree){
        ClearTree(tree->lchild);
        ClearTree(tree->rchild);
        delete tree;
    }
}

int main(){
    char str[100];
    BiThrNode *tree;
    while(1){
        cin>>str;
        int len = strlen(str);
        CreatTree(tree, str, 0, len);
        FeedTree(tree, str);
        cout<<CountTree(tree)<<endl;
    }
}
