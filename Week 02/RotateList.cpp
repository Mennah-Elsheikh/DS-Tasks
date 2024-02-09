#include <iostream>
#include <cassert>
using namespace std;

struct Node
{
    int data{};
    Node *next{};
    Node(int data) : data(data) {}
};

class LinkedList
{
private:
    Node *head{};
    Node *tail{};
    int length = 0;

public:
    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *deleted_node = current;
            current = current->next;
            delete deleted_node;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    void print()
    {
        // DON'T change head itself
        for (Node *cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    // using is_empty() function
    void insert_end(int value)
    {
        Node *item = new Node(value);

        if (is_empty()) // if the list is empty
            head = tail = item;
        else
        {
            tail->next = item;
            tail = item;
        }
        ++length;
    }
    bool is_empty()
    {
        return !head;
    }
    void left_rotate(int rotates)
    {
        if (length <= 1 || rotates <= 0)
        {
            return;
        }
        else if (length == 2)
        {
            //just swap !
            tail->next = head;
            head->next = nullptr;
            swap(head, tail);
            return; 
        }
        else
        {
            rotates %= length;
            Node *point = head;
            for (int i = 1; i < rotates && point != nullptr; ++i)
            {
                point = point->next;
            }
            if (point == nullptr || point->next == nullptr)
            {
                return; 
            }

            tail->next = head;
            head = point->next;
            point->next = nullptr;
            tail = point;
        }
    }
};

int main()
{

    LinkedList list;
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);
    list.print();
    // 1 2 3 4 5
    list.left_rotate(1);
    list.print();
    // 2 3 4 1 5
    return 0;
}
