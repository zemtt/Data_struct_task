#include<iostream>

using namespace std;

typedef struct BiTNode {
    int data;
    int count;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void SearchBST(BiTree &T, int x) {
    BiTNode *s, *f, *q;
    s = new BiTNode;
    s->data = x;
    s->count = 0;
    s->lchild = s->rchild = nullptr;
    if (!T) {
        T = s;
        return;
    }
    f = nullptr;
    q = T;
    while (q) {
        if (q->data == x) {
            q->count++;
            return;
        }
        f = q;
        if (x < q->data) {
            q = q->lchild;
        } else {
            q = q->rchild;
        }
    }
    if (f->data > x) {
        f->lchild = s;
    } else {
        f->rchild = s;
    }
}

void insertBST(BiTree &T, int a) {
    BiTNode *s;
    if (!T) {
        s = new BiTNode;
        s->data = a;
        s->count = 0;
        s->lchild = s->rchild = nullptr;
        T = s;
    } else if (a < T->data) {
        insertBST(T->lchild, a);
    } else if (a > T->data) {
        insertBST(T->rchild, a);
    }
}

void Create(BiTree &T, int n) {
    T = nullptr;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        insertBST(T, a);
    }
}

void InOrder(BiTree T, int &first) {
    if (T) {
        InOrder(T->lchild, first);
        if (first) {
            cout << T->data;
            first = 0;
        } else
            cout << " " << T->data;
        InOrder(T->rchild, first);
    }
}

void InOrdercount(BiTree T, int &first) {
    if (T) {
        InOrdercount(T->lchild, first);
        if (first) {
            cout << T->count;
            first = 0;
        } else
            cout << " " << T->count;
        InOrdercount(T->rchild, first);
    }
}

int main() {
    int n, x;
    BiTree T;
    while (cin >> n && n) {
        Create(T, n);
        cin >> x;
        SearchBST(T, x);
        int first = 1;
        InOrder(T, first);
        cout << endl;
        first = 1;
        InOrdercount(T, first);
        cout << endl;
    }
    return 0;
}