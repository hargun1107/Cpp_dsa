#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root) return;

    if (!root->left && !root->right)
        cout << root->ch << " : " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    cout<<"Name: Hargun Kaur Kohli"<<endl<<"Regstration Number: 24BCE2198"<<endl;
    string input;
    cout << "Enter string: ";
    cin >> input;

    if (input.length() == 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    unordered_map<char,int> freq;

    for (char c : input) {
        if (!isalpha(c)) {
            cout << "Invalid input: only alphabets allowed" << endl;
            return 0;
        }
        freq[c]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (auto p : freq)
        pq.push(new Node(p.first, p.second));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node* root = pq.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}