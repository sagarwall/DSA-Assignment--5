#inclde <iostream>
using namespacestd std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
Node* reverseLL(Node* head){
  Node* prev = NULL;
  Node* next = NULL;
  Node* temp = head;
  while(temp !=NULL){
    next = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = next;
  } 
}
};
