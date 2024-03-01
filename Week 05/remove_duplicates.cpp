#include <iostream>
#include <cassert>
using namespace std;

class Stack
{
private:
    int size{};
    int top{};
    char *array{};

public:
    Stack(int size) : size(size), top(-1)
    {
        array = new char[size];
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
        assert(!empty());
        return array[top--];
    }

    int peek()
    {
        assert(!empty());
        return array[top];
    }

    int isFull()
    {
        return top == size - 1;
    }

    int empty()
    {
        return top == -1;
    }
    string removeDuplicates(string s)
    {
        Stack st(s.size());
        for (char c : s)
        {
            if (!st.empty() && c == st.peek())
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        string result;
        while (!st.empty())
        {
            result += st.peek();
            st.pop();
        }

        return result;
    }
};

int main()
{
    string s = "abbbcaca";
    Stack stk(s.size());
    cout << stk.removeDuplicates(s) << endl;
    return 0;
}
