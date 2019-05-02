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

int n, e, u, v;
vector <vector <int> > g;
vector <bool> vis;

void BFS(int u) {
    queue <int> q;
    q.push(u);
    vis[u] = 1;
    while (!q.empty()) {
        u = q.front(); q.pop();
        printf("%d ", u);
        for (int v = 0; v < g[u].size(); v++)
            if (!vis[g[u][v]]) q.push(g[u][v]), vis[g[u][v]] = 1; 
    }
}

int main() {
    scanf("%d %d", &n, &e);
    vis.assign(n, 0);
    g.assign(n, vector<int>());
    while (e--) scanf("%d %d", &u, &v), g[u].push_back(v);
    for (int i = 0; i < n; i++) if (!vis[i]) BFS(i); 
    puts("");
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
