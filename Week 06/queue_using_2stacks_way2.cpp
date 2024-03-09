using namespace std;
#include <iostream>
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
    int deQueue()//O(n)
    {
        assert(!isEmpty()); // Ensure the queue is not empty
        if (s2.empty())
        { // If s2 is empty, move elements from s1 to s2
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int value = s2.top();
        s2.pop(); // Dequeue an item from s2
        added_elements--;
        return value;
    }
    void enQueue(int value) // big O(1)
    {
        assert(!isFull());
        s1.push(value);
        added_elements++;
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