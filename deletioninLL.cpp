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

Node* deletehead(Node* head) {
    Node* temp = head;
    head=head->next;
    free(temp);
    return head;
}

Node* deletetail(Node* head) {
    if (head==nullptr||head->next==nullptr) {
        return nullptr;
    }
    Node* temp = head;
    while((temp->next)->next!=nullptr){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}

Node* deletek(Node* head, int k) {
    if (head==nullptr) {
        return head;
    }
    if (k==1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int ctr=0;
    Node* temp = head;
    Node* prev = nullptr;
    while (temp!=nullptr) {
        ctr++;
        if (ctr==k) {
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* deleteval(Node* head, int val) {
    if (head==nullptr) {
        return head;
    }
    if (head->data==val) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while (temp!=nullptr) {
        if (temp->data==val) {
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
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
    cout<<"After deleting head"<<endl;
    head = deletehead(head);
    displaylist(head);

    cout<<"After deleting tail"<<endl;
    head = deletetail(head);
    displaylist(head);

    int k;
    cout<<"Enter position k to delete from"<<endl;
    cin>>k;
    cout<<"After deleting from kth position"<<endl;
    head = deletek(head,k);
    displaylist(head);

    int val;
    cout<<"Enter value to delete"<<endl;
    cin>>val;
    cout<<"After deleting value "<<val<<endl;
    head = deleteval(head,val);
    displaylist(head);

    return 0;
}