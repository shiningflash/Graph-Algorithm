/********************************************
 * GRAPH REPRESENTATIONS using STL (DFS)
 * @author Amirul Islam (shiningflash)
 * *
 * creates adjacency list first
 * DFS of Unweighted and Undirected
 *********************************************/

#include <bits/stdc++.h>
using namespace std;

int n, e, u, v;
vector <vector<int> > g;
vector <bool> vis;

void dfs_visit(int u) {
    vis[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < g[u].size(); v++)
        if (!vis[g[u][v]]) dfs_visit(g[u][v]);
}

int main() {
    scanf("%d %d", &n, &e);
    vis.assign(n, 0);
    g.assign(n, vector<int>());
    while (e--) scanf("%d %d", &u, &v), g[u].push_back(v), g[v].push_back(u);
    for (int i = 0; i < n; i++) if (!vis[i]) dfs_visit(i);
    puts("");
}

/******************
 INPUT
  ---
  - 1st line, 6 Vertex, 5 Edge
6 5
0 1
1 2
2 4
3 4

 OUTPUT:
  -----
0 1 5 2 4 3
*****************/
