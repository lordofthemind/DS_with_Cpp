#include <iostream>
using namespace std;

struct Node {
    int pid;
    string prod_name;
    double price;
    Node* left;
    Node* right;

    Node(int pid, string prod_name, double price) {
        this->pid = pid;
        this->prod_name = prod_name;
        this->price = price;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insert(Node* root, int pid, string prod_name, double price) {
    if (root == nullptr) {
        return new Node(pid, prod_name, price);
    }

    if (price < root->price) {
        root->left = insert(root->left, pid, prod_name, price);
    } else {
        root->right = insert(root->right, pid, prod_name, price);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << "PID: " << root->pid << ", PROD_NAME: " << root->prod_name << ", PRICE: " << root->price << endl;
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 1, "Maggi", 20.00);
    root = insert(root, 2, "Kurkure", 10.00);
    root = insert(root, 3, "Strawberry", 99.99);

    cout << "Inorder Traversal:" << endl;
    inorderTraversal(root);

    return 0;
}