using namespace std;
#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

class Queue
{
private:
    int size;
    int added_elements;
    stack<int> s1, s2;

public:
    Queue(int size) : size(size){};
    // s1 : 1 2 3 4 , we need to add 5 we use another stack s2 : 1 2 3 4 qnd add the element 5 => then push to the s1 : 5 4 3 2 1
    //  here we deQueue (pop) the last in => 1
    void enQueue(int x) // O(n)
    {
        assert(!isFull());
        // Move all elements from s1 to s2
        // Move all elements from s1 to s2
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // Push item into s1
        s1.push(x);
        added_elements++;
        // Push everything back to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // deQueue an item from the queue
    int deQueue() // big O(1)
    {
        assert(!isEmpty());
        // if first stack is empty
        if (s1.empty())
        {
            return -1;
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        --added_elements;
        return x;
    }
    bool isEmpty()
    {
        return added_elements == 0;
    }
    bool isFull()
    {
        return added_elements == size;
    }
};

int main()
{
    Queue qu(6);

    for (int i = 1; i <= 3; ++i)
        qu.enQueue(i);

    cout << qu.deQueue() << " ";

    for (int i = 4; i <= 5; ++i)
        qu.enQueue(i);

    while (!qu.isEmpty())
        cout << qu.deQueue() << " ";

    return 0;
}
