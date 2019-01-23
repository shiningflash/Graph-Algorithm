/*********************************************
 * Topological Sort (bfs approach)
 * @author Amirul Islam (shiningfalsh)
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

/**Define memory set function**/
#define mem(x,y) memset(x,y,sizeof(x))
#define CLEAR(x) memset(x,0,sizeof(x))

/**Define function and object**/
#define pb push_back
#define Sort(v) sort(v.begin(),v.end())
#define _sort(s, n) sort(s, s+n)
#define sqr(x) ((x)*(x))

/**Define constant value**/
#define le 5001
#define ERR 1e-9
#define pi (2*acos(0))
#define PI 3.141592653589793

/**Define input**/
#define scanint(a) scanf("%d",&a)
#define scanLLD(a) scanf("%lld",&a)

typedef unsigned long long ll;
using namespace std;

/********* END **********/

const int MAX = 105;
vector <int> g[MAX];
int vis[MAX];
int t, n, x, y, l, u, v, z, cnt = 0;

inline void bfs() {
    queue <int> q;
    for (int i = 1; i <= x; i++)
        if (!vis[i]) q.push(i);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        printf("%d ", v);
        for (auto i: g[v]) {
            vis[i]--;
            if (!vis[i]) q.push(i);
        }
    }
}

int main() {
    while (scanf("%d %d", &x, &y), (x + y)) {
        CLEAR(vis);
        for (int i = 1; i <= x; g[i].clear(), i++);
        while(y--) {
            scanf("%d %d", &u, &v);
            g[u].pb(v);
            vis[v]++;
        }
        bfs();
        printf("\n");
    }
    return 0;
}

/*
Input:
-----
5 4
1 2
2 3
1 3
1 5
0 0

Output:
------
1 4 2 5 3
*/
