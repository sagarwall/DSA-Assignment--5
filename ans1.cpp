#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n; 
    }

    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    void insertBeforeAfter(int key, int val, bool before) {
        Node* n = new Node(val);
        if (!head) return;
        if (before && head->data == key) {
            n->next = head;
            head = n;
            return;
        }
        Node* temp = head, *prev = nullptr;
        while (temp && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) return;
        if (before) {
            n->next = temp;
            prev->next = n;
        } else {
            n->next = temp->next;
            temp->next = n;
        }
    }

    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    } 

    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val) temp = temp->next;
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete
        }
