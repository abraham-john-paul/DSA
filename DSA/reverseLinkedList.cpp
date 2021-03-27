#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
    Node(int i) : data{i} {}
};
namespace reverse {
    Node* prev = nullptr;
    Node* next = nullptr;
}
Node* reverseLinkedList(Node* root) {
    if (!root) {
        return root;
    }
    if (!root->next){
        root->next = reverse::prev;
        return root;
    } else {
        reverse::next = root->next;
        root->next = reverse::prev;
        reverse::prev = root;
        return reverseLinkedList(reverse::next);
    }
}

void deleteLinkedList(Node*  head) {
    Node* elem = nullptr;
    while (head) {
        elem = head;
        head = head->next;
        delete head;
    }
}

Node* insertNode(Node* head, int n) {
    if (!head) {
        head = new Node(n);
    } else {
        Node* elem = new Node(n);
        elem->next = head;
        head = elem;
    }
    return head;
}

void printLinkedList(Node* head) {
    cout << "\n";
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node * head = new Node(1);
    head = insertNode(head, 2);
    // head = insertNode(head, 3);
    // head = insertNode(head, 4);
    // head = insertNode(head, 5);
    printLinkedList(head);
    head = reverseLinkedList(head);
    printLinkedList(head);
    deleteLinkedList(head);
}
