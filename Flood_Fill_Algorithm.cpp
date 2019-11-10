/*
    @algorithm  : flood fill algorithm
    @author     : Amirul Islam
    @complexity : O(N*M)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mx = 1e3;

char grid[mx][mx];
bool vis[mx][mx];
int row, column;

int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

void floodfill(int i, int j) {
    if (i < 0 || j < 0 || i >= row || j >= column) return; // base case

    if (grid[i][j] == '.' && !vis[i][j]) {
        vis[i][j] = true;

        for (int m = 0; m < 8; m++) {
            int x = i + dx[m];
            int y = j + dy[m];
            floodfill(x, y);
        }        
    }
}

int main() {
    // freopen("in", "r", stdin);

    scanf("%d %d", &row, &column);
    getchar();

    // input 2D grid array
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            scanf("%c", &grid[i][j]);
        }
        getchar();
    }

    // traverse 2D array
    // find dotted region
    int cnt(0);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                cnt++;
                floodfill(i, j);
            }
        }
    }
    printf("Number of dotted region: %d\n", cnt);
}

/*
Input:
12 25
@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@*************@@@@@@
@@@@@@*....*     ..@@@@@@
@@@@@@*....*   ....@@@@@@
@.@@@@*....*      .@@@@@@
@@@@@@*....********@@..@@
@@@@@@*...........*@@@...
@@@@@@*...........*@@@..@
@@@@@@*************@@@@.@
@@@@@@@@@.....@@@@@@@@@@@
@@@@@@@@@.....@@@@@@@@@@@

Output:
Number of dotted region: 5
*/
