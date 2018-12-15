#include <iostream>

using namespace std;

const int MAXSIZE = 150;

typedef struct Graph {
    int vertexs[MAXSIZE];
    int **mat;
    int vertex_num;
} Graph;

typedef struct Node {
    bool flag = true;
    int path[MAXSIZE];
    int node_num = 0;
    int length = 0;
} Node;

void initGraph(Graph &g, int v, int arc) {
    g.vertex_num = v;
    g.mat = new int *[MAXSIZE];
    for (int i = 0; i < MAXSIZE; ++i) {
        g.mat[i] = new int[MAXSIZE];
        for (int j = 0; j < MAXSIZE; ++j) {
            g.mat[i][j] = 1e6;
        }
    }
    for (int i = 0; i < v; ++i) {
        char c;
        cin >> c;
        g.vertexs[i] = c;
    }
    for (int i = 0; i < arc; ++i) {
        char a, b;
        cin >> a >> b;
        int l;
        cin >> l;
        g.mat[a][b] = l;
    }
}


void dijsktra(Graph g, Node *ans, int tar) {              //ans begin from 1
    ans[0].length = 1e6;
    Node cur[MAXSIZE];
    for (int i = 0; i < MAXSIZE; ++i) {
        if (tar == i) {
            cur[i].flag = false;
        }
        cur[i].length = g.mat[tar][i];
        cur[i].path[0] = tar;
        if (g.mat[tar][i] == 1e6) {
            cur[i].node_num = 0;
        } else {
            cur[i].node_num = 1;
            cur[i].path[1] = i;
        }
    }
    for (int i = 0; i < g.vertex_num - 1; ++i) {
        if (i > 0) {
            for (int j = 0; j < MAXSIZE; ++j) {
                if (!cur[j].flag) {
                    continue;
                }
                int t = ans[i].path[ans[i].node_num];
                if (ans[i].length + g.mat[t][j] < cur[j].length) {
                    cur[j] = ans[i];
                    int temp = ++cur[j].node_num;
                    cur[j].path[temp] = j;
                    cur[j].length += g.mat[t][j];
                }
            }
        }
        Node minNode = cur[0];
        int minpos = 0;
        for (int j = 0; j < MAXSIZE; ++j) {
            if (!cur[j].flag) {
                continue;
            }
            if (cur[j].length < minNode.length) {
                minpos = j;
                minNode = cur[j];
            }
        }
        ans[i + 1] = minNode;
        cur[minpos].flag = false;
    }
}

int main() {
    int v, a;
    while (cin >> v >> a) {
        if (v == 0 && a == 0) {
            break;
        }
        Graph g;
        initGraph(g, v, a);
        char be, end;
        cin >> be >> end;
        Node ans[100];
        dijsktra(g, ans, (int) be);
        int end_pos;
        for (int j = 0; j < g.vertex_num; ++j) {
            if (ans[j].path[ans[j].node_num] == end) {
                end_pos = j;
            }
        }
        cout << ans[end_pos].length << endl;
        for (int i = 0; i < ans[end_pos].node_num; ++i) {
            cout << (char) ans[end_pos].path[i] << ' ';
        }
        cout << (char) ans[end_pos].path[ans[end_pos].node_num] << '\n';
    }
    return 0;
}