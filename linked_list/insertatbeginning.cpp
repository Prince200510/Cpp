#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtBeginning(Node* &head, int val){
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}