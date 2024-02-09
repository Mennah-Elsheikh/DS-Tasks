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

    void insert_end(int value)
    {
        Node *item = new Node(value);

        if (!head)
            head = tail = item;
        else
        {
            tail->next = item;
            tail = item;
        }
        ++length;
    }
};

int main()
{

    LinkedList list;
    list.insert_end(7);
    list.insert_end(8);

    return 0;
}
