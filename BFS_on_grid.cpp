/*
  implementation of BFS on 2D grid
  @author Amirul islam :: Nov 1, 2019
                   _
   _|_ o._ o._  __|_| _. _|_
  _>| ||| ||| |(_|| |(_|_>| |
                _|
*/

#include <bits/stdc++.h>
using namespace std;
#define pii pair <int, int>
#define mp make_pair
#define isInside(x, y, row, col) (x >= 0 && x < row && y >= 0 && y < col)

const int mx = 1e3;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

char cell[mx][mx];
bool vis[mx][mx];
int dis[mx][mx];

void bfs(int sx, int sy, int row, int col) {
    vis[sx][sy] = 1;
    queue <pii> q;
    q.push(mp(sx, sy));
    while (!q.empty()) {
        pii top = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = top.first + dx[k];
            int ny = top.second + dy[k];
            if (isInside(nx, ny, row, col) && cell[nx][ny] != '#' && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                dis[nx][ny] = dis[top.first][top.second] + 1;
                q.push(mp(nx, ny));
            }
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    
    int row, col, sx, sy, cnt(0);
    scanf("%d %d", &row, &col);
    swap(row, col);
    for (int i = 0; i < row; i++) {
        scanf("%s", cell[i]);
    }
    bfs(0, 0, row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) printf("%d ", dis[i][j]);
        printf("\n");
    }
    return 0;
}

/*

Input:

3 3
...
#.#
...

Output:

0 1 2 
0 2 0 
4 3 4

 */
