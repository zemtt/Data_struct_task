#include <iostream>

using namespace std;

const int MAXSIZE = 100;

typedef struct {
    int vertex[MAXSIZE];
    int arcs[MAXSIZE][MAXSIZE];
    int vex_num, arc_num;
} Graph;

bool initGraph(Graph &g) {
    cin >> g.vex_num >> g.arc_num;
    if (g.vex_num == 0 && g.arc_num == 0) {
        return false;
    }
    for (int i = 0; i < g.vex_num; ++i) {
        g.vertex[i + 1] = i + 1;
    }
    for (auto &arc : g.arcs) {
        for (int &j : arc) {
            j = 0;
        }
    }
    for (int i = 0; i < g.arc_num; ++i) {
        int a, b;
        cin >> a >> b;
        g.arcs[a][b] = 1;
        g.arcs[b][a] = 1;
    }
    return true;
}

void showGraph(Graph g) {
    cout << 0;
    for (int i = 1; i < g.vex_num + 1; ++i) {
        cout << ' ' << g.vertex[i];
    }
    cout << endl;
    for (int i = 1; i < g.vex_num + 1; ++i) {
        cout << g.vertex[i];
        for (int j = 1; j < g.vex_num + 1; ++j) {
            cout << ' ' << g.arcs[i][j];
        }
        cout << endl;
    }
}

void addVertex(Graph &g, int v) {
    g.vex_num++;
    g.vertex[g.vex_num] = v;
}

int main() {
    Graph g;
    while (initGraph(g)) {
        int v;
        cin >> v;
        addVertex(g, v);
        showGraph(g);
    }
    return 0;
}