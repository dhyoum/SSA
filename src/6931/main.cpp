#include <stdio.h>

// int data[21][21];

int main()
{
    int T;
    scanf("%d", &T);

    for (int i=1; i<=T; i++)
    {
        int N, M;
        int win_cnt=0, win_pnt=0;
        scanf("%d %d\n", &N, &M);
        for (int y = 0; y < N; ++y) 
        {
            int pnt=0;
            for (int x = 0; x < M; ++x)
            {
                int v; scanf("%d ", &v);

                if (v == 1)
                {
                    pnt++;
                }
            }

            if ( win_pnt < pnt )
            {
                win_pnt = pnt;
                win_cnt = 1;
            }
            else if ( win_pnt == pnt )
            {
                win_cnt++;
            }

        }
        printf("#%d %d %d\n", i, win_cnt, win_pnt);
    }

    return 0;
}

