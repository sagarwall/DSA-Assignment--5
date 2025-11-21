#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to count and delete occurrences of a key
int deleteKeyOccurrences(Node* &head, int key) {
    int count = 0;

    // Delete nodes from the beginning if they match key
    while (head != nullptr && head->data == key) {
        count++;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Now delete occurrences in the rest of the list
    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->next->data == key) {
            count++;
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }

    return count;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked list: 1->2->1->2->1->3->1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);

    int key = 1;

    cout << "Original List: ";
    printList(head);

    int count = deleteKeyOccurrences(head, key);

    cout << "Count: " << count << endl;

    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}
