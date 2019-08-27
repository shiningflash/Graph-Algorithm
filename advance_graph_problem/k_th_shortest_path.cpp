#include <bits/stdc++.h>
using namespace std;
#define mx 105
#define inf 1<<30
#define pb push_back
#define pii pair <int, int>

struct node {
    int u, w;
    node(int u, int w) {
        this->u = u;
        this->w = w;
    };
    bool operator < (const node& p) const {
        return w > p.w;
    };
};

int t, nodes, edges, vis[mx];
vector <pii> g[mx];

int dijkstra(int x, int y, int k) {
    memset(vis, 0, sizeof(vis));
    priority_queue <node> q;
    q.push(node(x, 0));

    while (!q.empty()) {
        node top = q.top();
        q.pop();
        int u = top.u;
        int w = top.w;
        if (vis[u] == k) continue;
        vis[u]++;
        if (vis[u] == k && u == y) return w;
        
        for (int i = 0; i < (int) g[u].size(); i++) {
            int v = g[u][i].first;
            int nw = g[u][i].second;
            if (vis[v] < k) q.push(node(v, w+nw));
        }
    }
    return -1;
}

int main() {
    //freopen("in", "r", stdin);
    int u, v, w, t, cas(0), x, y, k;
    while ((scanf("%d %d", &nodes, &edges) && (nodes+edges))) {
        // x = source, y = destination, k = k'th shortest path
        scanf("%d %d %d", &x, &y, &k);
        for (int i = 1; i <= nodes; i++) g[i].clear();
        while (edges--) {
            scanf("%d %d %d", &u, &v, &w);
            g[u].pb({v, w});
        }
        printf("%d\n", dijkstra(x, y, k));
    }
}