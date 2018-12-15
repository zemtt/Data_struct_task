#include <iostream>

using namespace std;

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void Insert(BiTree &T, int x) {
    if (!T) {
        T = new BiTNode;
        T->data = x;
        T->lchild = nullptr;
        T->rchild = nullptr;
    } else {
        if (x < T->data) {
            Insert(T->lchild, x);
        } else {
            Insert(T->rchild, x);
        }
    }
}

void InOrder(BiTree T, int k, bool &first) {
    if (T) {
        InOrder(T->lchild, k, first);
        if (T->data >= k) {
            if (first) {
                cout << T->data;
                first = false;
            } else {
                cout << " " << T->data;
            }
        }
        InOrder(T->rchild, k, first);
    }
}

int main() {
    int n, x;
    BiTree T;
    while (cin >> n && n) {
        T = nullptr;
        int data;
        while (n--) {
            cin >> data;
            Insert(T, data);
        }
        cin >> x;
        bool first = true;
        InOrder(T, x, first);
        cout << endl;
    }
    return 0;
}