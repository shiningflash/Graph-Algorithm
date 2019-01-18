/*
  implementation of BFS simply
  using vector and queue
  @author Amirul islam
                   _
   _|_ o._ o._  __|_| _. _|_
  _>| ||| ||| |(_|| |(_|_>| |
                _|
*/

#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <list>
#include <iostream>
#include <assert.h>

#define mem(x,y) memset(x,y,sizeof(x))
#define CLEAR(x) memset(x,0,sizeof(x))

#define pb push_back
#define Sort(v) sort(v.begin(),v.end())
#define _sort(s, n) sort(s, s+n)
#define sqr(x) ((x)*(x))

#define le 1000009
#define ERR 1e-9
#define pi (2*acos(0))
#define PI 3.141592653589793

#define scanint(a) scanf("%d", &a)
#define scanLLD(a) scanf("%lld", &a)

typedef long long ll;
using namespace std;

/**********************End*******************/

vector <bool> vis;
vector <vector <int> > g;

void BFS(int u) {
    queue <int> q;
    q.push(u);
    vis[u] = true;

    while (!q.empty()) {
        int f = q.front();
        q.pop();
        printf("%d ", f);

        for (auto i = g[f].begin(); i != g[f].end(); i++)
            if (!vis[*i])
                q.push(*i), vis[*i] = true;
    }
}

int main() {
    int nodes, edges;
    scanf("%d %d", &nodes, &edges);

    vis.assign(nodes, false);
    g.assign(nodes, vector<int>());

    int u, v;
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        // for undirected graph add this line
        // g[v].pb(u);
    }

    // apply BFS on each node that not visited yet
    for (int u = 0; u < nodes; u++)
        if (!vis[u]) BFS(u);

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
