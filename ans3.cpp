#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
Node* middleelement(Node* head){
  int count =0;
  Node* temp = head;
  while (temp -> next != NULL){
    temp = temp -> next;
    count++;
  }
  int midelement = ((count/2) + 1);
 Node* temp = head;
 while(temp <= midelement){
   temp = temp -> next;
   
};
