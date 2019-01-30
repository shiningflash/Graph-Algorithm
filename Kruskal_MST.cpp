/**********************************
 kruskal’s Minimum Spanning Tree (MST)
 using Adj. List, TC - O(ElogE)
 @author Amirul Islam (shiningflash)
 **********************************/

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

struct edge {
	int u, v, w;
	bool operator < (const edge& p) const {
		return w < p.w;
	}
};

vector <edge> g;
int parent[MX];
int nodes, edges;

inline int find(int r) {
	return (parent[r] == r) ? r : find(parent[r]);
}

inline void kruskal_mst() {
	sort(g.begin(), g.end());
	for (int i = 0; i < nodes; i++) parent[i] = i;
	int cnt = 0, tcost = 0, u, v, w;
	for (int i = 0; i < edges; i++) { // edges = g.size()
		u = find(g[i].u);
		v = find(g[i].v);
		if (u != v) {
			cout << g[i].u << " - " << g[i].v << " " << g[i].w << "\n";
			parent[u] = v;
			cnt++;
			tcost += g[i].w;
			if (cnt == nodes-1) break;
		}
	}
	printf("\nminimum cost: %d\n", tcost);
}

int main() {
	scanf("%d %d", &nodes, &edges);
	for (int i = 0; i < edges; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edge eg;
		eg.u = u;
		eg.v = v;
		eg.w = w;
		g.pb(eg);
	}
	kruskal_mst();
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
0 - 3 	1
0 - 1 	2
2 - 1 	2

minimum cost: 5
 *******/
