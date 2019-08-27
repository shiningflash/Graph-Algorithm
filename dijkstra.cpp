// complexity: O(V*logV+E)
// nodes can be maximum 10000

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair <int, int>
#define inf 1<<30
#define mx 10005

int nodes, edges, dis[mx];
vector <pii> g[mx];

struct node {
    int u, w;
    node(int u, int w) { this->u = u, this->w = w; }
    bool operator < (const node& p) const { return w < p.w; }
};

void dijkstra(int src) {
    for (int i = 1; i <= nodes; i++) dis[i] = inf;
    priority_queue <node> q;
    q.push(node(src, 0));
    dis[src] = 0;

    while (!q.empty()) {
        node top = q.top(); q.pop();
        int u = top.u;
        for (int i = 0; i < (int) g[u].size(); i++) {
            int v = g[u][i].first;
            int w = g[u][i].second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push(node(v, dis[v]));
            }
        }
    }
}

void print_dis(int src) {
    printf("u - v = w\n-----------\n");
    for (int i = 1; i <= nodes; i++) {
        printf("%d - %d = %d\n", src, i, dis[i]);
    }
}

int main() {
    freopen("in", "r", stdin);
    scanf("%d %d", &nodes, &edges);
    int u, v, w, src;
    while (edges--) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    scanf("%d", &src);
    dijkstra(src);
    print_dis(src);
}

/*
Input:
5 7
1 4 35
1 2 40
1 5 5
5 3 10
1 3 25
3 2 10
2 4 2
1

Output:
u - v = w
-----------
1 - 1 = 0
1 - 2 = 25
1 - 3 = 15
1 - 4 = 27
1 - 5 = 5
*/
