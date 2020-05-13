#include <iostream>

struct Node {
    int data;
    Node* next;
    Node() : next(NULL) {}
};

Node * copyList(Node * & head1) {
    Node* ptr = new Node;
    if (head1 == NULL)
        return NULL;
    ptr->next = copyList(head1->next);
    ptr->data = head1->data;
    return ptr;
}

void pushBack(Node*& head, int e) {
    Node * n = new Node;
    n->data = e;
    n->next = head;
    head = n;
}

void print(Node * head) {
    if (head == NULL)
        return;
    std::cout << head->data;
    print(head->next);
}

int main() {
    Node * head = NULL;
    pushBack(head, 1);
    pushBack(head, 2);
    pushBack(head, 3);
    pushBack(head, 4);
    print(head);
    std::cout << std::endl;

    Node * head2 = copyList(head);
    print(head2);
    std::cout << std::endl;
}
