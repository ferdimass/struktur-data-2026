#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();

    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    node1->prev = NULL;
    node2->prev = node1;
    node3->prev = node2;

    cout << "Kanan  : ";
    Node* current = node1;
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;

    cout << "Kiri: ";
    current = node3;
    while (current != NULL) {
        cout << current->data << " <- ";
        current = current->prev;
    }
    cout << "NULL" << endl;

    return 0;
}