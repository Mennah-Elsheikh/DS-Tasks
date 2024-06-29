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
    }
    void add_element(int value)
    {
        Node *new_node = new Node(value); // create new node
        if (!head)
        {
            head = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }
    void print()
    {
        // DON'T change head itself
        for (Node *cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    bool is_empty()
    {
        return !head;
    }
    Node *get_tail()
    {
        if (!head)
            return nullptr;
        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }
        return current;
    }
};

int main()
{
    LinkedList list;
    list.add_element(7);
    list.add_element(5);
    list.add_element(1);
    list.print();
    // 1 5 7
    cout << list.get_tail()->data;
    return 0;
}
