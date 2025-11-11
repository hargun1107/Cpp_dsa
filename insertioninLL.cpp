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
    cout<<"Null"<<endl;
}

Node* inserthead(Node* head, int val) {
    Node* temp = new Node();
    temp->data=val;
    temp->next=head;
    return temp;
}

Node* inserttail(Node* head, int val) {
    if (head==nullptr) {
        Node* newnode = new Node();
        newnode->data=val;
        newnode->next=nullptr;
        return newnode;
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* newnode = new Node();
    newnode->data=val;
    newnode->next=nullptr;
    temp->next=newnode;
    return head;
}

Node* insertk(Node* head, int val, int k) {
    if (head==nullptr) {
        if (k==1) {
            Node* nn = new Node();
            nn->data=val;
            nn->next=nullptr;
            return nn;
        }
    }
    int c=0;
    Node* temp = head;
    while (temp!=nullptr) {
        c++;
        if(c==k-1){
            Node* nn = new Node();
            nn->data=val;
            nn->next=temp->next;
            temp->next=nn;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertbeforeval(Node* head, int val, int el) {
    if (head==nullptr) {
        return nullptr;
    }
    if (head->data==val) {
        Node* nn = new Node();
        nn->data=el;
        nn->next=head;
        return nn;
    }
    Node* temp = head;
    while (temp->next!=nullptr) {
        if(temp->next->data==val){
            Node* nn = new Node();
            nn->data=el;
            nn->next=temp->next;
            temp->next=nn;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main() {
    int n;
    cout<<"Enter number of nodes"<<endl;
    cin>>n;
    if (n<=0) {
        cout<<"Linked list cannot be created";
        return 0;
    }
    Node* head = new Node();
    cout<<"Enter data for node 1"<<endl;
    cin>>head->data;
    head->next=nullptr;
    Node* current = head;
    for (int i=2; i<=n; i++) {
        Node* newnode = new Node();
        cout<<"Enter data for node "<<i<<endl;
        cin>>newnode->data;
        newnode->next = nullptr;
        current->next = newnode;
        current = newnode;
    }

    displaylist(head);

    int val;
    cout<<"Enter value to add at head"<<endl;
    cin>>val;
    cout<<"After inserting at head"<<endl;
    head = inserthead(head,val);
    displaylist(head);

    int m;
    cout<<"Enter value to add at tail"<<endl;
    cin>>m;
    cout<<"After inserting at tail"<<endl;
    head = inserttail(head,m);
    displaylist(head);

    int k;
    int value;
    cout<<"Enter k position"<<endl;
    cin>>k;
    cout<<"Enter value "<<endl;
    cin>>value;
    head = insertk(head,value,k);
    displaylist(head);

    int val1;
    int el;
    cout<<"Enter value to insert before"<<endl;
    cin>>val1;
    cout<<"Enter element to insert"<<endl;
    cin>>el;
    head = insertbeforeval(head, val1, el);
    displaylist(head);
}