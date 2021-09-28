//8->4->1->3->0

//Sort it using merge sort

#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x) : data{x}, next{nullptr} {}
};

node *middle(node *head)
{ // 4 (2), 5 (3)
    node *slow = head;
    node *fast = head;
    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *merge(node *first, node *second)
{ 
    node *itr = nullptr;
    node *head = itr;

    while (first && second)
    {
        if (first->data <= second->data)
        {
            if (itr)
            {   
                itr->next = first;
                itr = itr->next;
            }
            else
            {
                itr = first;
                head = itr;
            }
            first = first->next;
        }
        else
        {
            if (itr)
            {
                itr->next = second;
                itr = itr->next;
            }
            else
            {
                itr = second;
                head = itr;
            }
            second = second->next;
        }
    }
    while (first)
    {
        if (itr)
        {
            itr->next = first;
            itr = itr->next;
        }
        else
        {
            itr = first;
            head = itr;
        }
        first = first->next;
    }

    while (second)
    {
        if (itr)
        {
            itr->next = second;
            itr = itr->next;
        }
        else
        {
            itr = second;
            head = itr;
        }
        second = second->next;
    }

    return head;
}

node *mergeSort(node *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    node *mid = middle(head); //8 -
    //cout << mid->data << "mid\n";
    node *other = mid->next;       // 1
    mid->next = nullptr;           // 8 -> null; 1->null
    node *first = mergeSort(head); //8
    node *sec = mergeSort(other);  //3
    return merge(first, sec);
}

int main()
{
    vector<int> v = {8, 4, 1, 3 ,0};
    node *head = new node(v.front());

    node *itr = head;
    for (int i = 1; i < v.size(); i++)
    {
        itr->next = new node(v[i]);
        itr = itr->next;
    }
    node *sortedhead = mergeSort(head);
    itr = sortedhead;

    while (itr)
    {
        cout << itr->data << " ";
        itr = itr->next;
    }
    
    return 0;
}