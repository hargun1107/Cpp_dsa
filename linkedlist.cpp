#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void displaylist (Node* head) {
    Node* temp = head;
    while (temp!=nullptr) {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null";
}

Node* convertarr2LL (int arr[], int n) {
    Node* head = new Node();
    head->data=arr[0];
    head->next=nullptr;
    Node* mover = head;
    for (int i=1; i<n; i++) {
        Node* newnode = new Node();
        newnode->data=arr[i];
        newnode->next=nullptr;
        mover->next=newnode;
        mover=newnode;
    }
    return head;
}

int search (Node* head, int val) {
    Node* temp = head;
    while (temp!=nullptr) {
        if (temp->data==val) {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

int main() {
    int n;
    cout<<"Enter number of nodes";
    cin>>n;
    if (n<=0) {
        cout<<"Linked list cannot be created";
        return 0;
    }
    Node* head = new Node();
    cout<<"Enter data for node 1";
    cin>>head->data;
    head->next=nullptr;
    Node* current = head;
    for (int i=2; i<=n; i++) {
        Node* newnode = new Node();
        cout<<"Enter data for node "<<i;
        cin>>newnode->data;
        newnode->next = nullptr;
        current->next = newnode;
        current = newnode;
    }
    displaylist(head);

    int arr[] = {12,9,123,90};
    int s = sizeof(arr) / sizeof(arr[0]);
    Node* newhead = convertarr2LL(arr,s);
    displaylist (newhead);

    int val;
    cout<<"Enter value to search in linked list"<<endl;
    cin>>val;
    int ans = search(head,val);
    if (ans==1) {
        cout<<"Value is present";
    }
    else {
        cout<<"Value is not present";
    }
    return 0;
}