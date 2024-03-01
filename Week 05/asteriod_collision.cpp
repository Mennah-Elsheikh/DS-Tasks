#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Stack
{
private:
    int size{};   // the size of the stack
    int top{};    // point to the last element of the stack
    int *array{}; // the dynamic array
public:
    Stack(int size) : size(size), top(-1)
    {
        array = new int[size];
    }

    ~Stack()
    {
        delete[] array;
    }

    void push(int x)
    {
        assert(!isFull());
        array[++top] = x;
    }

    int pop()
    {
        assert(!isEmpty());
        return array[top--];
    }

    int peek()
    {
        assert(!isEmpty());
        return array[top];
    }

    bool isFull()
    {
        return top == size - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void display_reversed()
    {
        for (int i = top; i >= 0; i--)
            cout << array[i] << " ";
        cout << "\n";
    }
};

void asteroid_Collision(vector<int> &asteroids)
{
    Stack st(asteroids.size());

    for (int asteroid : asteroids)
    {
        bool destroyed = false;

        while (!st.isEmpty() && asteroid < 0 && st.peek() > 0)
        {
            if (abs(asteroid) > st.peek())
            {
                st.pop();
            }
            else if (abs(asteroid) == st.peek())
            {
                st.pop();
                destroyed = true;
                break;
            }
            else
            {
                destroyed = true;
                break;
            }
        }

        if (!destroyed)
        {
            st.push(asteroid);
        }
    }
    st.display_reversed();
}

int main()
{
    vector<int> arr{10, 5, -2};
    asteroid_Collision(arr);

    return 0;
}
