#include <iostream>
using namespace std;

#define n 4
int queue[n];
int f=-1;
int r=-1;

void enqueue (int x) {
    if ((r+1)%n==f) {
        cout<<"Overflow"<<endl;
    }
    else if (f==-1 && r==-1) {
        f=r=0;
        cout<<"Entered at "<<r<<endl;
        queue[r]=x;
    }
    else {
        r=(r+1)%n;
        queue[r]=x;
        cout<<"Entered at "<<r<<endl;
    }
}

int dequeue () {
    if (f==-1 && r==-1) {
        cout<<"Underflow"<<endl;
        return -1;
    }
    else if (f==r) {
        int x = queue[f];
        f=r=-1;
        return x;
    }
    else {
        int x = queue[f];
        f=(f+1)%n;
        return x;
    }
}

void display() {
    if (f == -1 && r == -1) {
        cout << "Queue Empty" << endl;
    } else {
        int i = f;
        while (true) {
            cout << queue[i] << " ";
            if (i == r) break;
            i = (i + 1) % n;
        }
        cout << endl;
    }
}


int main () {
    cin.clear();
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