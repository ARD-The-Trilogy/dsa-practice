#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
};

void insertAtTail(node* &head, int val) {
    node* n = new node(val);
    if(head == NULL) {
        head=n;
        return;
    };

    node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
};

void display(node* head) {
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
};

int length(node* head) {
    node* temp = head;
    int count = 0;
    while(temp!=NULL) {
        temp = temp->next;
        count++;
    }
    return count;
};

node* kappend(node* &head, int k) {
    int l = length(head);
    k=k%l;
    node* tail = head;
    node* newhead;
    node* newtail;
    int pos = l-k;
    int count =1;

    while(tail->next!=NULL) {
        if(count == pos) {
            newtail = tail;
            newhead = newtail->next;
        }
        tail = tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;

    return newhead;
};

int main() {
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    node* newhead = kappend(head, 3);
    display(newhead);

    return 0;
}
