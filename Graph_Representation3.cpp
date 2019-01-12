/********************************************
 * GRAPH REPRESENTATIONS using STL
 * @author Amirul Islam (shiningflash)
 * *
 * The program basically prints adjacency list
 * of an undirected and weighted graph 
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

void printGraph(vector < pair <int, int> > adj[], int nVertex) {
    int v, w;
    for (int u = 0; u < nVertex; u++) {
        printf("Node %d:\n-------\n", u);
        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            v = it->first;
            w = it->second;
            printf("( %d - %d ) - %d\n", u, v, w);
        }
        printf("\n");
    }
}

int main() {
    //  build graph
    int nVertex, nEdge, u, v, w;
    scanf("%d %d", &nVertex, &nEdge);
    vector < pair <int, int> > adj[nVertex];
    for (int i = 0; i < nEdge; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].pb(make_pair(v, w));
        adj[v].pb(make_pair(u, w));
    }
    printGraph(adj, nVertex);
}

/******************
 INPUT
  ---
  - 1st line, here, 5 nVertex, 7 nEdge
  - after then, u - v - weight
5 7
0 1 10
0 4 20
1 2 30
1 3 40
1 4 50
2 3 60
3 4 70

 OUTPUT:
  -----
Node 0:
-------
( 0 - 1 ) - 10
( 0 - 4 ) - 20

Node 1:
-------
( 1 - 0 ) - 10
( 1 - 2 ) - 30
( 1 - 3 ) - 40
( 1 - 4 ) - 50

Node 2:
-------
( 2 - 1 ) - 30
( 2 - 3 ) - 60

Node 3:
-------
( 3 - 1 ) - 40
( 3 - 2 ) - 60
( 3 - 4 ) - 70

Node 4:
-------
( 4 - 0 ) - 20
( 4 - 1 ) - 50
( 4 - 3 ) - 70
 *****************/
