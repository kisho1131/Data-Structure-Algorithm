#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void LevelOrder(node *root){
    if(root ==NULL)
        return;
    queue<node*>q;\
    stack<node*>s;
    q.push(root);
    // int count = 1;
    while(!q.empty()){
        node *curr = q.front();
        s.push(curr);
        if(curr->left!=NULL)
            q.push(curr->left);

        if(curr->right!=NULL)
            q.push(curr->right);
        q.pop();
    }
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
}

void PrintkthLevel(node* root, int k){
    if(root==NULL)
        return;
    if(k==1)
        cout<<root->data<<" ";
    PrintkthLevel(root->left, k-1);
    PrintkthLevel(root->right, k-1);
}

int Height(node *root){
    if(root == NULL)
        return 0;
    int lf = Height(root->left);
    int rt = Height(root->right);
    return max(lf,rt) + 1;
}

void LevelStep(node* root){
    int ht= Height(root);
    for(int i=1;i<=ht; i++){
        PrintkthLevel(root, i);
        cout<<endl;
    }

}

void MorissInorder(node *root){
    while(root){
        if (root->left == NULL){
            cout<<root->data<<" ";
            root = root->right;
        }
        else{
            node *curr = root->left;
            // Find inOrder Predecesor
            while(curr->right && curr->right!=NULL)
                curr = curr->right;
            if(curr->right == root){
                curr->right = NULL;
                root = root->right;
            }
            else{
                cout<<root->data<<" ";
                curr->right = root;
                root = root->left;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(1);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(2);
    root->left->right->left->left = newNode(16);
    root->left->right->left->right = newNode(17);
    root->right->left->right->left = newNode(18);
    root->right->right->left->right = newNode(19);
    cout<<"LevelOrder : ";
    LevelOrder(root);
    cout<<endl;
    cout<<"Print Kth Level: ";
    PrintkthLevel(root, 3);
    cout<<endl;
    cout<<"Height : ";
    cout<<Height(root);
    cout<<endl;
    cout<<"Step Print of Level Order "<<endl;
    LevelStep(root);
    cout<<endl;
    cout<<"Moris Inorder traversal: ";
    MorissInorder(root);
    return 0;
}
