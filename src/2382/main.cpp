#include <stdio.h>

int N, M, K;
int visit[101][101];
int collision[101][101];

struct MSang
{
    int x, y, count, dir;

    void step()
    {
        if (dir == 1)
            y--;
        else if (dir == 2)
            y++;
        else if (dir == 3)
            x--;
        else if (dir == 4)
            x++;

        if (!border())
        {
            printf("I'm on the border %d %d\n", x, y);

            if (dir == 1)
                dir = 2;
            else if (dir == 2)
                dir = 1;
            else if (dir == 3)
                dir = 4;
            else if (dir == 4)
                dir = 3;

            count = count/2;
        }

        if ( ++visit[x][y] > 1 )
            collision[x][y] = 1;
    }

    bool border()
    {
        if ( x == 0 || x == N || y == 0 || y == N )
        {
            return false;
        }

        return true;
    }
    void print()
    {
        printf("[%d][%d] cnt=%d dir=%d\n", x, y, count, dir);
    }
};
MSang a[1001];


void checkCollision()
{
    for(int i=0; i<K; i++)
    {
        if (collision[a[i].x][a[i].y]) 
            printf("collision : [%d,%d] -> %d\n", a[i].x, a[i].y, i);
    }
}


int main()
{
    int T;
    scanf("%d", &T);


    T = 1;
    for (int i=1; i<=T; i++)
    {
        scanf("%d %d %d\n", &N, &M, &K);
        for (int k = 0; k < K; ++k) 
        {
            scanf("%d %d %d %d\n", &a[k].y, &a[k].x, &a[k].count, &a[k].dir);
        }


        for(int tt=0; tt<1; tt++)
        {
            for(int k=0; k<K; ++k)
            {
                // a[k].print();
                a[k].step();
            }

            checkCollision();
        }
    }

    return 0;
}

