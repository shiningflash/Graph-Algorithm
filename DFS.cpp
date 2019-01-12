/********************************************
 * GRAPH REPRESENTATIONS using STL (DFS)
 * @author Amirul Islam (shiningflash)
 * *
 * creates adjacency list first
 * DFS of Unweighted and Undirected
 *********************************************/

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
#include <unordered_set>

#define mem(x,y) memset(x,y,sizeof(x))
#define CLEAR(x) memset(x,0,sizeof(x))

#define pb push_back
#define Sort(v) sort(v.begin(),v.end())
#define _sort(s, n) sort(s, s+n)
#define sqr(x) ((x)*(x))

#define le 50001
#define ERR 1e-9
#define pi (2*acos(0))
#define PI 3.141592653589793
#define MX 1e9

#define scanint(a) scanf("%d", &a)
#define scanLLD(a) scanf("%lld", &a)

typedef long long ll;
using namespace std;

/* -------------------------- */

void dfsVISIT(int u, vector <int> adj[], vector <bool> &visited) {
    visited[u] = true;
    printf("%d ", u);
    for (int v = 0; v < adj[u].size(); v++) {
        int x = adj[u][v];
        if (!visited[x]) dfsVISIT(x, adj, visited);
    }
}

void DFS(vector <int> adj[], int nVertex) {
    vector <bool> visited(nVertex, false);
    for (int u = 0; u < nVertex; u++) {
        if (!visited[u]) dfsVISIT(u, adj, visited);
    }
}

int main() {
    // build graph
    int nVertex, nEdge, u, v;
    scanf("%d %d", &nVertex, &nEdge);
    // vector <int> *adj = new vector <int>[nVertex];
    vector <int> adj[nVertex];
    for (int i = 0; i < nEdge; i++) {
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    DFS(adj, nVertex); // source node - 5
}

/******************
 INPUT
  ---
  - 1st line, 5 nVertex, 7 nEdge
5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4

 OUTPUT:
  -----
0 1 2 3 4
 *****************/
