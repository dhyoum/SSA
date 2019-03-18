#include <stdio.h>

#define MAX_H (10)
#define MAX_W (25)

int H = 0, W = 0;
int wayper[MAX_H][MAX_W];
int visit[MAX_W][(1 << MAX_H)+1][(1 << MAX_H)+1];

void pr()
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            printf("%d ", wayper[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isChip(int h, int w)
{
    return !(wayper[h][w] || wayper[h + 1][w] || wayper[h][w + 1] || wayper[h + 1][w + 1]);
}

void setChip(int h, int w, int val)
{
    wayper[h][w] = val;
    wayper[h+1][w] = val;
    wayper[h][w+1] = val;
    wayper[h+1][w+1] = val;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int order(int w)
{
    int val = 0;
    for (int i = 0; i < H; i++)
    {
        if (wayper[i][w]) val |= (1 << i);
    }
    return val;
}

int dfs(int h, int w)
{
    int m = 0;
    if (w == (W - 1)) return 0;

    int orderH = order(w);
    int orderH_1 = order(w+1);
    if (visit[w][orderH][orderH_1]) return visit[w][orderH][orderH_1];

    for (int i = h; i < (H - 1); i++)
    {
        if (isChip(i, w))
        {
            setChip(i, w, 2);
            m = max(m, dfs(i, w)+1);
            setChip(i, w, 0);
        }
    }

    m = max(m, dfs(0, w+1));
    visit[w][orderH][orderH_1] = m;
    return visit[w][orderH][orderH_1];
}

int main()
{
    int T = 0;
//  freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d", &H, &W);
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                scanf("%d", &wayper[i][j]);
            }
        }
        printf("#%d %d\n", test_case, dfs(0, 0));
        for (int i = 0; i < W; i++)
        {
            for (int j = 0; j < (1 << H) + 1; j++)
            {
                for (int k = 0; k < (1 << H) + 1; k++)
                {
                    visit[i][j][k] = 0;
                }
            }
        }
    }
    return 0;
}

