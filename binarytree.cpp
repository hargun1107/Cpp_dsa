#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node (int val) {
        data = val;
        left = right = nullptr;
    }
};

void preorder (Node* root) {
    if (root==nullptr) {
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder (root->right);
} 

void inorder (Node* root) {
    if (root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder (root->right);
}

void postorder (Node* root) {
    if (root==nullptr){
        return;
    }
    postorder(root->left);
    postorder (root->right);
    cout<<root->data;
}

int main () {
    struct Node* root = new Node (1);
    root->left = new Node (2);
    root ->right = new Node(3);
    root->left->right = new Node (5);
    preorder (root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
}