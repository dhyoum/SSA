#include <stdio.h>
int start, end;
int res = 40;

void solve(int temp, int count)
{
    if ( count > res ) return;

    if (temp == end)
    {
        if (count< res)
            res = count;
        return;
    }

    if (temp<end)
    {
        solve(temp+10, count+1); 
        solve(temp+5, count+1); 
        solve(temp+1, count+1); 
    }
    else
    {
        solve(temp-10, count+1); 
        solve(temp-5, count+1); 
        solve(temp-1, count+1); 
    }
}


int main()
{
    scanf("%d %d\n", &start, &end);
    solve(start, 0);
    printf("%d\n", res);

    return 0;
}
