#include <stdio.h>

#define MAX 10000

class LinkedList
{
private:
    class Node
    {
    public:
        Node(int _x, int _y) : x(_x), y(_y), next(NULL)
        {}
        Node* next;

        void print()
        {
            printf("%2d %2d\n", x, y);
        }

        int x, y;
    };

public:
    LinkedList() : head(NULL), tail(NULL) {}
    ~LinkedList()
    {
        Node* p = head;
        while(p)
        {
            Node* old = p;
            p = p->next;
            delete old;
        }
    }
    void display()
    {
        Node* p = head;
        while(p)
        {
            p->print();
            p = p->next;
        }
    }
    void push_back(int x, int y)
    {
        Node* node = new Node(x, y);
        if (!head)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    Node* getNode(int index)
    {
        int pos=0;
        Node* p = head;
        while ( p && (pos++)!=index )
        {
            p = p->next;
        }
        return p;
    }

private:
    Node* head;
    Node* tail;
};

int main()
{
    int N;
    scanf("%d", &N);

    int x, y;
    LinkedList list;
    for(int i=0; i<N; i++)
    {
        scanf("%d %d\n", &x, &y);
        list.push_back(x, y);
    }

    list.display();

    return 0;
}
