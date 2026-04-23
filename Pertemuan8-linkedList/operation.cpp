#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void traversal(Node* head) {
    Node* current = head;
    cout << "Isi List: ";
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void insertion(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << value << " berhasil ditambahkan\n";
}

void deletion(Node*& head) {
    if (head == NULL) {
        cout << "List kosong\n";
        return;
    }
    Node* temp = head;
    cout << temp->data << " berhasil dihapus\n";
    head = head->next;
    delete temp;
}

void searching(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            cout << key << " ditemukan\n";
            return;
        }
        current = current->next;
    }
    cout << key << " tidak ditemukan\n";
}

void updating(Node* head, int oldValue, int newValue) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == oldValue) {
            current->data = newValue;
            cout << oldValue << " berhasil diupdate menjadi " << newValue << "\n";
            return;
        }
        current = current->next;
    }
    cout << oldValue << " tidak ditemukan\n";
}

int main() {
    Node* head = NULL;

    cout << "INSERTION\n";
    insertion(head, 10);
    insertion(head, 20);
    insertion(head, 30);

    cout << "\nTRAVERSAL\n";
    traversal(head);

    cout << "\nSEARCHING\n";
    searching(head, 20);
    searching(head, 99);

    cout << "\nUPDATING\n";
    updating(head, 10, 100);
    traversal(head);

    cout << "\nDELETION\n";
    deletion(head);
    traversal(head);

    return 0;
}