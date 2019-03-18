#include <stdio.h>

struct Point
{
    int x, y;
    bool forward;

    void where()
    {
        printf("  [%d,%d]\n", x, y);
    }

    void moveZigZag(int N)
    {
        int cnt = 2;
        while (cnt--)
        {
            for (int i = 1; i <= 2*N-1; ++i) 
            {
                int loop = i<N?i:2*N-i;
                while (loop--)
                {
                    where();
                    int isDown = (x+y)%2;
                    if (loop)
                    {
                        if ( forward )
                        {
                            if (isDown) x++, y--;
                            else x--, y++;
                        }
                        else
                        {
                            if (isDown) x--, y++;
                            else x++, y--;
                        }
                    }
                    else
                    {
                        isDown = i<N ? isDown:!isDown;
                        if (forward)
                        {
                            if (isDown) x++;
                            else y++;
                        }
                        else
                        {
                            if (isDown) x--;
                            else y--;
                        }
                    }

                    if (x>N-1) x = N-1;
                    if (y>N-1) y = N-1;
                }
            }
            forward = false;
        }
    }
};

int main(void)
{
    Point p = {0,0, true};

    p.moveZigZag(3);

    return 0;
}
