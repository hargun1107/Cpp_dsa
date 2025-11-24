#include <iostream>
using namespace std;

#define n 4
int queue[n];
int f=-1;
int r=-1;

void enqueue (int x) {
    if (r==n-1) {
        cout<<"Overflow"<<endl;
    }
    else if (f==-1 && r==-1) {
        f=r=0;
        cout<<"Entered at "<<r<<endl;
        queue[r]=x;
    }
    else {
        r++;
        queue[r]=x;
        cout<<"Entered at "<<r<<endl;
    }
}

int dequeue () {
    if (f==-1 && r==-1) {
        cout<<"Underflow"<<endl;
    }
    else if (f==r) {
        int x = queue[f];
        f=r=-1;
        return x;
    }
    else {
        int x = queue[f];
        r--;
        return x;
    }
}

void display () {
    if (f==-1 && r==-1) {
        cout<<"Queue Empty";
    }
    else {
        for (int i=f; i<=r; i++) {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}

int main () {
    cout<<"1. Enqueue 2.Dequeue 3.Display 4.Exit"<<endl;
    int ch;
    do {
        cout<<"Enter choice"<<endl;
        cin>>ch;
        if (ch==1) {
            cout<<"Enter element"<<endl;
            int x;
            cin>>x;
            enqueue(x);
        }
        else if (ch==2) {
            int x = dequeue();
            cout<<"Dequed element "<<x<<endl;
        }
        else if (ch==3) {
            display();
        }
        else if (ch==4){
            break;
        }
        else {
            cout<<"Enter choice again"<<endl;
        }
    }
    while (ch!=4);
}