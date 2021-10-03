#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        data = data;
        left = right = NULL;
    }
};

Node *buildTree(){
    int data;
    cin>>data;
    if(data == -1)
        return NULL;
    Node *root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printTree(Node *root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

int main(int argc, char const *argv[])
{
    Node *root = buildTree();
    printTree(root);
    return 0;
}
