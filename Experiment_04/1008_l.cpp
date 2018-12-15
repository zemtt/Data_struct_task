#include <iostream>

using namespace std;

const int MaxSize = 100;

typedef struct Node {
    int datum;
    struct Node *next = NULL;
} Node, *Np;

typedef struct Graph {
    int vertex_num, arc_num;
    Np list[MaxSize];
} Graph;

bool initGraph(Graph &g) {
    cin >> g.vertex_num >> g.arc_num;
    if (g.arc_num == 0 && g.vertex_num == 0) {
        return false;
    }
    for (int i = 0; i < MaxSize; ++i) {
        g.list[i] = new Node;
        g.list[i]->datum = i;
    }
    for (int i = 1; i < g.arc_num + 1; ++i) {
        int a, b;
        cin >> a >> b;
        Np t1, t2;
        t1 = new Node;
        t1->datum = a;
        t1->next = g.list[b]->next;
        g.list[b]->next = t1;
        t2 = new Node;
        t2->datum = b;
        t2->next = g.list[a]->next;
        g.list[a]->next = t2;
    }
    return true;
}

void showGraph(Graph &g) {
    for (int i = 1; i < g.vertex_num + 1; ++i) {
        Np t = g.list[i];
        while (t->next != NULL) {
            cout << t->datum << ' ';
            t = t->next;
        }
        cout << t->datum << endl;
    }
}

void addArc(Graph &g, int a, int b) {
    Np t1, t2;
    t1 = new Node;
    t1->datum = a;
    t1->next = g.list[b]->next;
    g.list[b]->next = t1;
    t2 = new Node;
    t2->datum = b;
    t2->next = g.list[a]->next;
    g.list[a]->next = t2;
}

int main() {
    Graph g;
    while (initGraph(g)) {
        int a, b;
        cin >> a >> b;
        addArc(g, a, b);
        showGraph(g);
    }
    return 0;
}