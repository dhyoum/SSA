#include <stdio.h>

#define MAX_N (52)
int pipe[MAX_N][MAX_N];
int visit[MAX_N][MAX_N];
int N = 0;
int min = 99999;

#define LEFT  (1)
#define RIGHT (2)
#define UP    (3)
#define DOWN  (4)

int fromWhere(int pX, int pY, int x, int y)
{
    int from = 0;
    ((pX == x) && ((pY + 1) == y)) ? (from = LEFT) :
        ((pX == x) && ((pY - 1) == y)) ? (from = RIGHT) :
        ((pY == y) && ((pX + 1) == x)) ? (from = UP) : (from = DOWN);
    return from;
}

void dfs(int pX, int pY, int x, int y, int c)
{
    if (c + x + y >= min) return;
    if (pX == 1 && pY == 1 && x == 1 && y == 0)
    {
        if (min > c) min = c;
        return;
    }
    if (N < x || N < y || 0 >= x || 0 >= y || visit[x][y]) return;
    if (pipe[x][y] == 0) return;

    int from = fromWhere(pX, pY, x, y);
    if (pipe[x][y] == 1 || pipe[x][y] == 2)
    {
        int nextX = 0, nextY = 0;
        if (from == LEFT)
        {
            nextX = x; nextY = y + 1;
        }
        else if (from == RIGHT)
        {
            nextX = x; nextY = y - 1;
        }
        else if (from == UP)
        {
            nextX = x + 1; nextY = y;
        }
        else
        {
            nextX = x - 1; nextY = y;
        }
        visit[x][y] = 1;
        dfs(x, y, nextX, nextY, c+1);
        visit[x][y] = 0;
    }
    else
    {
        int nextX[2] = { 0, 0 }, nextY[2] = { 0, 0 };
        if (from == LEFT || from == RIGHT)
        {
            nextX[0] = x - 1; nextY[0] = y;
            nextX[1] = x + 1; nextY[1] = y;
        }
        else
        {
            nextX[0] = x; nextY[0] = y - 1;
            nextX[1] = x; nextY[1] = y + 1;
        }
        visit[x][y] = 1;
        dfs(x, y, nextX[0], nextY[0], c + 1);
        dfs(x, y, nextX[1], nextY[1], c + 1);
        visit[x][y] = 0;
    }
}

int main()
{
    int T = 0;
    //freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                scanf("%d", &pipe[i][j]);
            }
        }
        visit[1][0] = 1;
        dfs(N, N+1, N, N, 0);
        printf("#%d %d\n", test_case, min);
        for (int i = 0; i <= MAX_N; i++)
        {
            for (int j = 0; j <= MAX_N; j++)
            {
                visit[i][j] = 0;
            }
        }
        min = 99999;
    }
    return 0;
}

