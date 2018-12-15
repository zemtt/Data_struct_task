#include <iostream>

using namespace std;

const int MAXSIZE = 100;

typedef struct Graph {
    int vertex[MAXSIZE];
    int arcs[MAXSIZE][MAXSIZE];
    int arc_num, vertex_num;
} Graph;

bool initGraph(Graph &g) {
    cin >> g.vertex_num >> g.arc_num;
    if (g.arc_num == 0 && g.vertex_num == 0) {
        return false;
    }
    for (int i = 1; i < g.vertex_num + 1; ++i) {
        g.vertex[i] = i;
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
    for (int i = 0; i < g.vertex_num; ++i) {
        if (g.vertex[i + 1] > 0) {
            cout << ' ' << g.vertex[i + 1];
        }
    }
    cout << endl;
    for (int i = 1; i < g.vertex_num + 1; ++i) {
        if (g.vertex[i] > 0) {
            cout << g.vertex[i];
            for (int j = 1; j < g.vertex_num + 1; ++j) {
                if (g.vertex[j] > 0) {
                    cout << ' ' << g.arcs[i][j];
                }
            }
            cout << endl;
        }
    }
};

void deleteVertex(Graph &g, int v) {
    g.vertex[v] = 0;
}

int main() {
    Graph g;
    while (initGraph(g)) {
        int v;
        cin >> v;
        deleteVertex(g, v);
        showGraph(g);
    }
    return 0;
}