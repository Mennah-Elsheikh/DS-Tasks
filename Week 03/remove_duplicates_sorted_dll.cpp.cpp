using namespace std;
#include <iostream>
// Definition of doubly linked list:
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {

        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

//*************************************************************************/
// Node *removeDuplicates(Node *head)
// {
//     if (head == nullptr)
//         return nullptr;

//     Node *current = head;
//     while (current != nullptr)
//     {
//         Node *temp = current->next;
//         while (temp != nullptr && temp->data == current->data)
//         {
//             Node *duplicate = temp;
//             temp = temp->next;
//             if (temp != nullptr)
//                 temp->prev = current;
//             delete duplicate;
//         }
//         current->next = temp;
//         if (temp != nullptr)
//             temp->prev = current;
//         current = temp;
//     }
//     return head;
// }
Node *removeDuplicates(Node *head)
{
    // Write your code here
    Node *prev = head;

    while (prev != NULL && prev->next != NULL)
    {
        Node *temp = prev->next;
        while (temp != NULL && temp->data == prev->data)
        {
            temp = temp->next;
        }
        prev->next = temp;
        if (temp)
            temp->prev = prev;
        prev = prev->next;
    }
    return head;
}
