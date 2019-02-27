#include <stdio.h>
int start, end;

struct Info
{
    int temp;
    int cnt;

    Info(){}
    Info(int x, int c):temp(x), cnt(c){}
};

template <typename T>
class Queue
{
    public:
        Queue():head(0), tail(0){}

        bool empty()
        {
            return head == tail;
        }

        T& pop()
        {
            if ( head >= tail )
            {
                printf("pop error\n");
            }
            return data[head++];
        }

        void push(const T& a)
        {
            if ( tail == 10000 )
            {
                printf("maximum error\n");
            }
            data[tail++] = a;
        }

    private:
        int head, tail;
        T data[10000];
};

int f(Queue<Info>& Q, int temp, int count)
{
    Q.push(Info(temp, count));

    while ( !Q.empty() )
    {
        Info info = Q.pop();

        int temp = info.temp;
        if (temp == end)
            return info.cnt;
        else if (temp < end)
        {
            Q.push(Info(temp+10, info.cnt+1));
            Q.push(Info(temp+5, info.cnt+1));
            Q.push(Info(temp+1, info.cnt+1));
        }
        else
        {
            Q.push(Info(temp-10, info.cnt+1));
            Q.push(Info(temp-5, info.cnt+1));
            Q.push(Info(temp-1, info.cnt+1));
        }
    }
}

int main()
{
    scanf("%d %d\n", &start, &end);
    Queue<Info> Q;

    int res = f(Q, start, 0);
    printf("%d\n", res);

    return 0;
}
