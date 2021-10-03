#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *createNode(int data){
    node *root = new node();
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void preOrder(node * root){
    if (root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node * root){
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void inOrder(node * root){
    if (root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int countNode(node *temp){
    if(temp){
        return (1 + countNode(temp->left) + countNode(temp->right));
    }
    else
        return 0;
}

int countLeaveNode(node *temp){
    if(temp == NULL)
        return 0;
    if(temp->left == NULL && temp->right == NULL)
        return 1;
    else
        return(countLeaveNode(temp->left) + countLeaveNode(temp->right));
}

int heigth(node *temp){
    if(temp == NULL)
        return 0;
    int lt = heigth(temp->left);
    int gt = heigth(temp->right);
    return max(lt, gt) + 1;
}

int countFullNode(node *temp){
    if(temp ==NULL)
        return 0;
    if(temp->left == NULL && temp->right == NULL)
        return 0;
    else
        return(countFullNode(temp->left) + countFullNode(temp->right) + (temp->left != NULL && temp->right != NULL)?1:0);
}

void leveOrder(node *root){
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

void printKthLevel(node *root, int k){
    if(root == NULL)
        return;
    if(k==1)
        cout<<root->data<<" ";
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

class HBPair{
public:
    int height;
    bool balance;
};
/*

HBPair isHeightBalanced(node *root){
    HBPair p;
    if(root == NULL){
        p.heigth = 0;
        p.balance = true;
        return p;
    }
    HBPair left = isHeightBalanced(root->left);
    HBpair right = isHeightBalanced(root->rigth);
    p.heigth = max(left.heigth, right.heigth) + 1;
    if(abs(left.heigth - right.heigth)<= 1 && left.balance && right.balance){
        p.balance = false;
    }
    return p;
}
*/

int PrintAtDistanceK(node *root, node *target, int k){
    // base case
    if(root == NULL)
        return -1;
    // reach the target node
    if(root == target){
        printKthLevel(target, k);
        return 0;
    }
    // back to the ansector
    int dl = PrintAtDistanceK(root->left, target, k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }else{
            printKthLevel(root->right, k-2-dl);
        }

        return 1+dl;
    }

    int dr = PrintAtDistanceK(root->right, target, k);
    if(dr!=-1){
    if(dr+1==k){
        cout<<root->data<<" ";
    }
    else{
        printKthLevel(root->left, k-2-dr);
    }
    return 1+dr;
 }
return -1;
}


int main(int argc, char const *argv[])
{
    node *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);
   //  cout<<root->data;
   //  cout<<endl;
   //  cout<<root->left->left->data;
   //  cout<<endl;
    cout<<"In-order traversal: ";
    inOrder(root);
    cout<<endl;
    cout<<"Pre-order traversal: ";
    preOrder(root);
    cout<<endl;
    cout<<"Post-Order traversal: ";
    postOrder(root);
    cout<<endl;
    cout<<"Level Order Traversal: ";
    leveOrder(root);
    cout<<endl;
    /* int res = countNode(root);
    cout<<"No.of Nodes in the Binary tree is: "<<res;
    int leave = countLeaveNode(root);
    cout<<endl;
    cout<<"No.of Leave Node in the Binary Tree is: "<<leave;
    cout<<endl;
    int full = countFullNode(root->right);
    cout<<"No.of Full Node: "<<full;
    cout<<endl; */
    int h = heigth(root);
    cout<<"Heigth of the Tree is: "<<h;
    cout<<endl;
    printKthLevel(root, 3);
    cout<<endl;
    /*
    if(isHeightBalanced(root).balance){
        cout<<" Heigth Balanced";
    }
    else
        cout<<" Not Heigth Balanced"; */
    return 0;
}
