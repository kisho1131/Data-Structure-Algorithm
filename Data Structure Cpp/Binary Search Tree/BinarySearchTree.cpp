#include<bits/stdc++.h>
using namespace std;

struct node
{
   int data;
   node *left, *right;
};
node *getNewNode(int data){
    node *root = new node();
    root->data= data;
    root->left = root->right = NULL;
    return root;
}
node* Insert(node *root, int data){
    if(root ==  NULL)
        root = getNewNode(data);
    else if(data <= root->data)
       root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}
node* findMin(node *root){
    if(root == NULL)
        return 0;
    while(root->left!=NULL)
        root = root->left;
    return root;
}
void Inorder(node *root){
    if(root == NULL)
        return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void PreOrder(node *root){
    if(root == NULL)
        return ;
    cout<<root->data<<" ";
    Inorder(root->left);
    // cout<<root->data<<" ";
    Inorder(root->right);
}


int height(node *root){
    if(root == NULL)
        return 0;
    int lt = height(root->left);
    int rt = height(root->right);
    return max(lt, rt) + 1;
}

bool isBinaryTreeUtil(node *root, int min, int max){
    if(root == NULL)
        return true;
    if(root->data > min && root->data < max && isBinaryTreeUtil(root->left, min , root->data) &&
        isBinaryTreeUtil(root->right, root->data, max))
        return true;
    else
        return false;
}
bool isBinaryTree(node *root){
    return isBinaryTreeUtil(root, INT_MIN, INT_MAX);
}

node* Delete(node *root, int data){
    if(root == NULL)
        return root;
    else if(data < root->data) Delete(root->left, data);
    else if(data > root->data) Delete(root->right, data);
    else{
        // Case :1 No Childern
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        // Case:2 One Childern
        else if(root->left == NULL){
            node *temp = root;
            root = root->right;
            delete temp;
        }

        else if(root->right == NULL){
            node *temp = root;
            root = root->left;
            delete temp;
        }
        // Case:3 Two Childern
        else{
            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

node *search(node *root, int data){
    if(root == NULL)
        return root;
    if(root->data == data)
        return root;
    else if(data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

node *GetSuccessor(node *root, int data){
    node *curr = search(root, data);
    if(curr->right!=NULL){
        return findMin(curr->right);
    }
    else{
        node *succ = NULL;
        node *ancs = root;
        while(ancs!= curr){
            if(curr->data < ancs->data){
                succ = ancs;
                ancs = ancs->left;
            }
            else
                ancs = ancs->right;
        }
        return succ;
    }
}

// All the Node is Unique in the Binary tree...
node *findLCA(node *root, int n1, int n2){
    if(root == NULL)
        return NULL;
    if(root->data > n1 && root->data > n2) //  When the LCA Lie in the Left Sub-Tree
        return findLCA(root->left, n1, n2);
    if(root->data < n1 && root->data < n2) // When the LCA Lie in the Right Sub-Tree
        return findLCA(root->right, n1, n2);
    return root;
}
// Function to Print the tree Sum  - O(n) - Traversing the tree in the reverse Order:)
void transformTreeUtil(node *root, int *sum){
    if(root == NULL)
        return;
    transformTreeUtil(root->right, sum);
    *sum = *sum + root->data;
    root->data = *sum - root->data;
    transformTreeUtil(root->left, sum);
}
void transformTree(node *root){
    int sum = 0;
    transformTreeUtil(root, &sum);
}

void SprialPrint(node *root){
    if(root == NULL)
        return;
    stack <node*> s1;
    stack <node*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            node *curr = s1.top();
            s1.pop();
            cout<<curr->data<<" ";
            if(curr->left!=NULL)
                s1.push(curr->left);
            if(curr->right!=NULL)
                s1.push(curr->right);
        }
        while(!s2.empty()){
            node *curr = s2.top();
            s2.pop();
            cout<<curr->data<<" ";
            if(curr->right!=NULL)
                s2.push(curr->right);
            if(curr->left!=NULL)
                s2.push(curr->left);
        }
    }
}

void levelOrder(node *root){
    if(root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
    node *curr = q.front();
    cout<<curr->data<<" ";
    if(curr->left!=NULL)
         q.push(curr->left);
     if(curr->right!=NULL)
        q.push(curr->right);
    q.pop();
    }
}

int main(int argc, char const *argv[])
{
    node *root = NULL;
    root = Insert(root,12);
    root = Insert(root,5);
    root = Insert(root,15);
    root = Insert(root,3);
    root = Insert(root,7);
    root = Insert(root,13);
    root = Insert(root,17);
    root = Insert(root,1);
    root = Insert(root,9);
    Inorder(root);
    cout<<endl;
    //cout<<"Min Element: ";
    //cout<<findMin(root);
    //cout<<endl;
    cout<<"Height is: ";
    cout<<height(root);
    cout<<endl;
    //cout<<isBinaryTree(root);
    //cout<<endl;
    // root = Delete(root, 9);
    // Inorder(root);
    node *succ = GetSuccessor(root, 1);
    cout<<succ->data;
    cout<<endl;
    PreOrder(root);
    cout<<endl;
    cout<<"Lowest Common Ancestor: ";
    node *temp = findLCA(root, 3, 15);
    cout<<temp->data;
    transformTree(root);
    cout<<endl;
    PreOrder(root);
    cout<<endl;
    cout<<"Level Order In Sprial Form: ";
    SprialPrint(root);
    cout<<endl;
    cout<<"Normal Level Order Traversal: ";
    levelOrder(root);
    return 0;
}
