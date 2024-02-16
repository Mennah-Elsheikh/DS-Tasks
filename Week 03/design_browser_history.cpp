using namespace std;
#include <iostream>
struct Node
{
    string val;
    Node *prev = NULL;
    Node *next = NULL;
};
class BrowserHistory
{
public:
    Node *curr = NULL; // null pointer
    BrowserHistory(string homepage)
    {
        curr = new Node();    // create a new node
        curr->val = homepage; // as the first node of the list and the value of it the homepage url
    }

    void visit(string url)
    {                            // as the insert function in dll
        Node *temp = new Node(); // create a new node that we will be inserte
        temp->val = url;         // the value of it
        curr->next = temp;       // the next steps to link the node to the list
        temp->prev = curr;
        curr = temp;
    }

    string back(int steps)
    { // as the delete node frome the end function but we back only not delete
        while (curr->prev && steps > 0)
        {
            curr = curr->prev;
            steps--;
        }
        return curr->val; // the last node i will point to it
    }

    string forward(int steps)
    { // to iterate on linkd list number of steps from the actual location
        while (curr->next && steps > 0)
        {
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */