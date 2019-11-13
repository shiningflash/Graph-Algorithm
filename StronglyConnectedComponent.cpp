/*
  @topic      - Strongly Connected Component (SCC)
  @complexity - O(V+E)  -  Kosaraju’s algorithm
  @author     - Amirul islam
                   _
   _|_ o._ o._  __|_| _. _|_
  _>| ||| ||| |(_|| |(_|_>| |
                _|
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4;

vector <int> g1[mx], g2[mx];
bool vis[mx];
stack <int> s1;

void dfs1(int u) {
    vis[u] = true;
    for (int v = 0; v < g1[u].size(); v++) {
        if (!vis[g1[u][v]]) {
            dfs1(g1[u][v]);
        }
    }
    s1.push(u);
}

void dfs2(int u) {
    vis[u] = true;
    cout << u << " ";
    for (int v = 0; v < g2[u].size(); v++) {
        if (!vis[g2[u][v]]) {
            dfs2(g2[u][v]);
        }
    }
}

int main() {
    // freopen("in", "r", stdin);

    int n, u, v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        g1[u].push_back(v);
        g2[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    memset(vis, 0, sizeof(vis));
    while (!s1.empty()) {
        int u = s1.top();
        s1.pop();
        if (!vis[u]) {
            dfs2(u);
            cout << endl;
        }
    }
}
