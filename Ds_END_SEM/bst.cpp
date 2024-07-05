#include "iostream"

using namespace std;

class Tree{
     public:
      int data;
      Tree *left;
      Tree *right;

      Tree(int val):data(val),left(NULL),right(NULL){}
};


Tree* insert(Tree* root,int data){
        if(root == NULL){
            return new Tree(data);
        } 

         if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void traverse(Tree* root){
    if(!root) return;
    cout<<root->data<<" ";
    traverse(root->left);
    traverse(root->right);

}

Tree* min(Tree* root){
    Tree* curr = root;
    while(curr && curr->left){
        curr = curr->left;
    }
    return curr;
}


Tree* max(Tree* root){
    Tree* curr;
    while(curr && curr->right){
        curr = curr->right;
    }
    return curr;
}

Tree* Delete(Tree* root,int key){
        if(root == NULL){
            return 
            NULL;
        }
        else{
            if(key > root->data){
                root->right = Delete(root->right,key);
            }
            else if (key < root->data){
                root->left = Delete(root->left,key);
            }
            else{
                if(root->right == NULL){
                    return root->left;
                }
                else if(root->left == NULL){
                    return root->right;
                }
                else{
                    Tree* small = min(root->right);
                    root->data = small->data;
                    root->right = Delete(root->right,small->data);
                }
            }
        }
        return root;
}
int main(){
    Tree * root = NULL;
    root = insert(root,13);
     root = insert(root,11);
      root = insert(root,20);
     root = insert(root,23);
      root = insert(root,4);
      root = Delete(root,23);
    traverse(root);
}
