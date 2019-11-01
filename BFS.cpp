/*
  implementation of BFS
  @author Amirul islam
                   _
   _|_ o._ o._  __|_| _. _|_
  _>| ||| ||| |(_|| |(_|_>| |
                _|
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5;
vector <int> g[mx];
int vis[mx];

void bfs(int u) {
    queue <int> q;
    q.push(u);
    vis[u] = 1;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        printf("%d ", u);
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (!vis[v]) q.push(v), vis[v] = 1;
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    
    int node, edge, u, v;
    scanf("%d %d", &node, &edge);
    while (edge--) scanf("%d %d", &u, &v), g[u].push_back(v);
    for (int i = 0; i < node; i++) if (!vis[i]) bfs(i);
    printf("\n");
    return 0;
}

/*
Input:
8 10
0 1
0 2
0 3
0 4
1 5
2 5
3 6
4 6
5 7
6 7

Output:
0 1 2 3 4 5 6 7
*/
