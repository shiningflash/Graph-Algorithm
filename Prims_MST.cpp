// Prim’s Minimum Spanning Tree (MST)
// using Adj. List, TC - O(ElogV)
 
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
#include <limits>
 
#define mem(x, y) memset(x,y,sizeof(x))
#define CLEAR(x) memset(x,0,sizeof(x))
 
#define pb push_back
#define Sort(v) sort(v.begin(),v.end())
#define _sort(s, n) sort(s, s+n)
#define sqr(x) ((x)*(x))
 
#define le 5001
#define ERR 1e-9
#define pi (2*acos(0))
#define PI 3.141592653589793
#define INT_MAX 2147483647
 
#define scanint(a) scanf("%d",&a)
#define scanLLD(a) scanf("%lld",&a)
 
typedef long long ll;
using namespace std;
 
////////////////////////////////////////
 
const int MX = 10000;
typedef pair <int, int> dual;
 
int nodes, edges;
vector <dual> g[MX];
 
inline void Prim_MST() {
	vector <int> dis(nodes, INT_MAX);
	vector <bool> vis(nodes, false);
	vector <int> parent(nodes, -1);
	int source = 0;
	dis[0] = 0;
 
	priority_queue <dual, vector <dual>, greater <dual> > q;
	q.push(make_pair(0, source));
 
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		vis[u] = true;
		for (int x = 0; x < (int) g[u].size(); x++) {
			int v = g[u][x].first;
			int w = g[u][x].second;
			if (!vis[v] && dis[v] > w) {
				dis[v] = w;
				q.push(make_pair(dis[v], v));
				parent[v] = u;
			}
		}
	}
	for (int i = 1; i < nodes; i++)
		printf("%d - %d \t%d\n", parent[i], i, dis[i]);
}
 
int main() {
    scanf("%d %d", &nodes, &edges);
    for (int i = 0; i <= nodes; i++)
        g[i].clear();
    for (int i = 0, u, v, w; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
    }
    Prim_MST();
    return 0;
}

/********
 stdin 
4 5
0 1 2
0 2 3
0 3 1
2 1 2
3 2 2
 stdout 
0 - 1 	2
3 - 2 	2
0 - 3 	1
 *******/
