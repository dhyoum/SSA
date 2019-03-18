#include <stdio.h>

#define Q_MAX (10000000)
int N = 0, O = 0, M = 0;
int nums[10];
int oper[4];
int magicNum = 0;
int min = Q_MAX;
int visit[1000][1000][5];

typedef struct NodeT {
    int opNum;
    int num;
    int op;
    int tch;
    int isOp;
}NodeT;

NodeT queue[Q_MAX];

int front = 0, rear = 0;
int isQueueEmpty()
{
    return front == rear;
}

void enQueue(NodeT node)
{
    queue[rear++] = node;
    if (Q_MAX <= rear) rear = rear % Q_MAX;
}

NodeT deQueue()
{
    if (Q_MAX <= front) front = front % Q_MAX;
    return queue[front++];
}

void bfs()
{
    NodeT tmp;
    tmp.opNum = 0; tmp.op = 0; tmp.tch = 0; tmp.num = 0; tmp.isOp = 0;
    enQueue(tmp);
    while (!isQueueEmpty())
    {
        NodeT data = deQueue();
        if (!visit[data.num][data.opNum][data.op])
        {
            visit[data.num][data.opNum][data.op] = data.tch;
        }
        else
        {
            if (visit[data.num][data.opNum][data.op] <= data.tch) continue;
        }

        for (int i = 0; i < N; i++)
        {
            NodeT tmp2 = data;
            if (tmp2.op)
            {
                tmp2.opNum *= 10;
                tmp2.opNum += nums[i];
                tmp2.tch++;
                if (tmp2.tch > M) break;
                if (tmp2.opNum > 999 || tmp2.opNum < 0) continue;
            }
            else
            {
               tmp2.num *= 10;
                tmp2.num += nums[i];
                tmp2.tch++;
                if (tmp2.tch > M) break;
                if (tmp2.num > 999 || tmp2.num < 0) continue;
            }
            enQueue(tmp2);
        }

        NodeT tmp3 = data;
        if (tmp3.opNum != 0)
        {
            if (tmp3.op) tmp3.isOp = 1;
            if (tmp3.op == 1) tmp3.num += tmp3.opNum;
            else if (tmp3.op == 2) tmp3.num -= tmp3.opNum;
            else if (tmp3.op == 3) tmp3.num *= tmp3.opNum;
            else if (tmp3.op == 4) tmp3.num /= tmp3.opNum;
        }
        if (tmp3.num > 999 || tmp3.num < 0) continue;
        if (tmp3.num == magicNum)
        {
            if (tmp3.isOp) tmp3.tch++;
            if (min > tmp3.tch) min = tmp3.tch;
            continue;
        }
        for (int i = 0; i < O; i++)
        {
            NodeT tmp4 = data;
            if (tmp4.op && tmp4.opNum)
            {
                if (tmp4.op == 1) tmp4.num += tmp4.opNum;
                else if (tmp4.op == 2) tmp4.num -= tmp4.opNum;
                else if (tmp4.op == 3) tmp4.num *= tmp4.opNum;
                else if (tmp4.op == 4) tmp4.num /= tmp4.opNum;
                tmp4.opNum = 0;
            }
            tmp4.op = oper[i];
            tmp4.tch++;
            if (tmp4.tch > M) break;
            if (tmp4.num > 999 || tmp4.num < 0) continue;
            enQueue(tmp4);
        }
    }
}

int main()
{
    int T = 0;
    //freopen("test.txt", "r", stdin);

    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++)
    {
        int isExist = 0, isMinus = 0;
        scanf("%d %d %d", &N, &O, &M);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &nums[i]);
        }
        for (int i = 0; i < O; i++)
        {
            scanf("%d", &oper[i]);
            if (oper[i] == 2) isMinus = 1;
        }
        scanf("%d", &magicNum);
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                for (int m = 0; m < 5; m++)
                {
                    visit[i][j][m] = 0;
                }
            }
        }
         
        for (int i = 0; i < N; i++)
        {
            if (magicNum == nums[i]) isExist = 1;
        }
        if (!isExist)
        {
            bfs();
        }
        else
        {
            min = 1;
        }
        if (min == Q_MAX) min = -1;
        if (!isExist && magicNum == 0)
        {
            if (isMinus)
            {
                min = 4;
            }
            else
            {
                min = -1;
            }
        }
        if (min > M) min = -1;
        printf("#%d %d\n", test_case, min ? min : -1);
        rear = front = 0;
        min = Q_MAX;
    }

    return 0;
}

