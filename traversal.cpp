#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BinaryTree {
private:
    Node* root;

    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    pair<Node*, Node*> getDeepestNodeAndParent() {
        if (root == NULL) return {NULL, NULL};
        queue<pair<Node*, Node*>> q;
        q.push({root, NULL});

        pair<Node*, Node*> last;
        while (!q.empty()) {
            last = q.front();
            q.pop();

            if (last.first->left)
                q.push({last.first->left, last.first});
            if (last.first->right)
                q.push({last.first->right, last.first});
        }
        return last;
    }

    void deleteDeepestNode(Node* deepest, Node* parent) {
        if (parent == NULL) {
            delete deepest;
            root = NULL;
            return;
        }
        if (parent->left == deepest)
            parent->left = NULL;
        else if (parent->right == deepest)
            parent->right = NULL;

        delete deepest;
    }

public:
    BinaryTree() : root(NULL) {}

    void insert(int val) {
        Node* newNode = new Node(val);

        if (root == NULL) {
            root = newNode;
            cout << "Inserted " << val << " as root node.\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->left == NULL) {
                curr->left = newNode;
                cout << "Inserted " << val << " to the left of " << curr->data << "\n";
                return;
            } else {
                q.push(curr->left);
            }

            if (curr->right == NULL) {
                curr->right = newNode;
                cout << "Inserted " << val << " to the right of " << curr->data << "\n";
                return;
            } else {
                q.push(curr->right);
            }
        }
    }

    void deleteNode(int val) {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }

        if (root->left == NULL && root->right == NULL) {
            if (root->data == val) {
                delete root;
                root = NULL;
                cout << "Node " << val << " deleted.\n";
            } else {
                cout << "Node not found.\n";
            }
            return;
        }

        queue<Node*> q;
        q.push(root);

        Node* nodeToDelete = NULL;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->data == val) {
                nodeToDelete = curr;
            }
            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
        }

        if (nodeToDelete != NULL) {
            pair<Node*, Node*> deepestPair = getDeepestNodeAndParent();
            Node* deepestNode = deepestPair.first;
            Node* parent = deepestPair.second;
            nodeToDelete->data = deepestNode->data;

            deleteDeepestNode(deepestNode, parent);

            cout << "Node " << val << " deleted.\n";
        } else {
            cout << "Node not found.\n";
        }
    }

    void traverse(int choice) {
        switch (choice) {
            case 1:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 2:
                cout << "Preorder traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Postorder traversal: ";
                postorder(root);
                cout << endl;
                break;
            default:
                cout << "Invalid traversal choice.\n";
        }
    }
};

int main() {
    BinaryTree tree;
    int choice, val;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insert(val);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                tree.deleteNode(val);
                break;

            case 3:
                tree.traverse(1);
                break;

            case 4:
                tree.traverse(2);
                break;

            case 5:
                tree.traverse(3);
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
