#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int data) : data(data) {}
};
class sll
{
private:
    node *head{};

public:
    // the "data will be reversed"
    // O(1) => insert at the beginning
    void add_item(int value)
    {
        node *new_node = new node(value);
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
        node *current_node = head;
        if (head == NULL)
        {
            cout << "linked list is empty ";
        }
        else
        {
            while (current_node != NULL)
            {
                cout << current_node->data << "\t";
                current_node = current_node->next;
            }
        }
        cout << endl;
    }
    node *get_tail()
    {
        if (head == NULL)
        {
            return nullptr;
        }
        else
        {
            node *tail = head;
            while (tail->next != nullptr)
            {
                tail = tail->next;
            }
            return tail;
        }
    }
};
int main()
{
    sll list;
    list.add_item(7);
    list.add_item(10);
    list.add_item(5);
    list.print();//5 10 7 
    node *res = list.get_tail();
    if (res == nullptr)
        cout << "///";
    else
        cout << "the tail : " << res->data << "\n";
    list.print();
}