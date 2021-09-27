#include <iostream>
#include <queue>

using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* Insert_recurr(BstNode* root,int data){
    if(root==NULL){
        root = GetNewNode(data);
    }
    else if(data <= root->data){
        root->left = Insert_recurr(root->left, data);
    }
    else{
        root->right = Insert_recurr(root->right, data);
    }
    return root;
}

BstNode* Insert(BstNode* root, int data){
    BstNode* prev = NULL;
    BstNode* temp = root;
    if (root == NULL){
        root = GetNewNode(data);
        return root;
    }
    while(temp != NULL){
        if(data<=temp->data){
            prev = temp;
            temp = temp->left;
        }
        else{
            prev = temp;
            temp = temp->right;
        }
    }
    if(data<=prev->data){
        prev->left = GetNewNode(data);
    }
    else prev->right = GetNewNode(data);
    return root;
}

bool Search(BstNode* root, int data){
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

BstNode* Min(BstNode* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL){
        return root;
    }
    else{
        return Min(root->left);
    }
}

int Max(BstNode* root){
    if(root == NULL){
        return 0;
    }
    else if(root->right == NULL){
        return root->data;
    }
    return Max(root->right);
}

int Height(BstNode* root){
    if(root == NULL){
        return -1;
    }
    int leftH = Height(root->left);
    int rightH = Height(root->right);
    return max(leftH,rightH)+1;
}

void levelOrder(BstNode* root){
    if(root == NULL) return;
    queue<BstNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        BstNode* current = Q.front();
        cout<<current->data<<" ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();
    }
}

void Preorder(BstNode* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(BstNode* root){
    if(root == NULL) return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Postorder(BstNode* root){
    if(root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}


int isBSTUtil(BstNode* node, int min, int max);

int isBST(BstNode* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}
 
/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(BstNode* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return 1;
             
    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;
     
    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values
}

BstNode* Delete(BstNode* root, int data){
    if (root == NULL) return root;
    else if(data < root-> data) root->left = Delete(root->left, data);
    else if(data > root->data) root->right = Delete(root->right, data);
    else{
        // Case 1: No child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        //Case 2: One child
        else if(root->left == NULL){
            BstNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            BstNode* temp = root;
            root = root->left;
            delete temp;
        }
        //case 3: 2 children
        else{
            BstNode* temp = Min(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}
 
int main(){
    BstNode* root = NULL;
    root = Insert(root, 7);
    root = Insert(root, 5);
    root = Insert(root, 1);
    root = Insert(root, 8);
    root = Insert(root, 3);
    root = Insert(root, 6);
    root = Insert(root, 0);
    root = Insert(root, 9);
    root = Insert(root, 4);
    root = Insert(root, 2);

    cout<<endl;
    Inorder(root);

    return 0;
}