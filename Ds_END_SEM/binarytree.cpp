#include "iostream"


using namespace std;

class Tree{
  public:
   int data;

   Tree* right;
   Tree * left;
};

void preorder(Tree * n){
  if(!n) return;
  cout<<n->data<<" "; 
  preorder(n->left);
  preorder(n->right);
}

Tree* createTree(){
  int x ;
  Tree *n = new Tree();
  cout<<"Enter data -1 for NULL : ";
  cin>>x;
  if(x == -1){
    return NULL;
  }
  n->data = x;
  cout<<"Left chilf of "<<x<<": \n";
  n->left = createTree();
  cout<<"RIght child of "<<x<<" : \n";
  n->right = createTree();
  return n;
}


int main(){
  Tree* root = createTree();
  preorder(root);
}