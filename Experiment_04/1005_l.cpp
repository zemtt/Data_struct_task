#include <iostream>

using namespace std;
const int MAXSIZE = 100;

typedef struct Node {
    int datum;
    struct Node *next = NULL;
} Node, *Np;

typedef struct Graph {
    int vertex_num, arc_num;
    Np vertex[MAXSIZE];
} Graph;

bool initGraph(Graph &g) {
    for (int i = 1; i < MAXSIZE + 1; ++i) {
        g.vertex[i] = new Node;
        g.vertex[i]->datum = i;
    }
    cin >> g.vertex_num >> g.arc_num;
    if (g.vertex_num == 0 && g.arc_num == 0) {
        return false;
    }
    for (int i = 0; i < g.arc_num; ++i) {
        int a, b;
        cin >> a >> b;
        Np t;
        t = new Node;
        t->datum = a;
        t->next = g.vertex[b]->next;
        g.vertex[b]->next = t;
        Np t2;
        t2 = new Node;
        t2->datum = b;
        t2->next = g.vertex[a]->next;
        g.vertex[a]->next = t2;
    }
    return true;
}

void showGraph(Graph &g) {
    for (int i = 1; i < g.vertex_num + 1; ++i) {
        Np t = g.vertex[i];
        while (t->next != nullptr) {
            cout << t->datum << ' ';
            t = t->next;
        }
        cout << t->datum << endl;
    }
}

void add(Graph &g, int v) {
    g.vertex_num++;
    g.vertex[g.vertex_num]->datum = v;
}

int main() {
    Graph g;
    while (initGraph(g)) {
        int v;
        cin >> v;
        add(g, v);
        showGraph(g);
    }
    return 0;
}