https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

#include <bits/stdc++.h>

using namespace std;

class BST{ 
  
  public:
     int val;
     BST *left, *right;
     BST()
     {
         val=0;
         left=NULL;  
         right=NULL;   
     }
     BST(int x)
     {
         val=x;
         left =NULL;
         right = NULL; 
     }
};

// Time complexity:- O(n)

BST* insert(BST* root, int val)
{
  if(root==NULL)
  {
      return new BST(val);
  }
  if(root->val<val)
  {
      root->right = insert(root->right,val);
  }
  else
  {
      root->left = insert(root->left,val);
  }
   return root;
}

void inorder(BST* root)
{
   if(root==NULL)
     return;
   inorder(root->left);
   cout<<root->val<<", ";
   inorder(root->right);
}

// Time complexity:- O(n)

BST* search(BST* root, int val)
{
    if(root==NULL || root->val==val)
    {
         return root;
    }
    else if(root->val<val)
    {
         return search(root->right, val);
    }    
    else
    {
         return search(root->left, val);
    }
}

// Time complexity:- O(n)

BST* deleteNode(BST* root, int val)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->val>val)
    {
        root->left = deleteNode(root->left,val);
        return root;
    }
    else if(root->val<val)
    {
        root->right = deleteNode(root->right,val);
        return root;
    }
    else
    {
        if((root->left==NULL) && (root->right==NULL))
        {
              delete root;
              return NULL;
        }
        else if (root->left==NULL)
	{
	     BST* temp = root->right; 
            delete root;
            return temp;
        }    
        else if(root->right==NULL)
        {
             BST* temp = root->left;
             delete root;
             return temp;
        }
        else
	{
	     BST* succPar=root; 
             BST* succ=root->right;
             while(succ->left!=NULL)
             {
                  succPar = succ;
                  succ = succ->left;
             }
             if(succPar==root)
             {
                  succ->left = root->right;
                  delete root;
                  return succ;
             }
             else
	     {
                  root->val = succ->val;
                  delete succ;
                  return root;		
             }
        }

    }
}

int main()
{
    BST* root = NULL;
    root= insert(root,2);
    root= insert(root,4);
    root= insert(root,1);
    root= insert(root,10);
    root= insert(root,12);
    inorder(root);
     
    cout<<endl;
        cout<<endl;

    BST* temp = search(root,4);

    if(temp==NULL)
       cout<<"NO"<<endl;
    else
       cout<<"YES"<<endl;

    deleteNode(root, 4);
    deleteNode(root, 3);

    temp = search(root,4);

    if(temp==NULL)
       cout<<"NO"<<endl;
    else
       cout<<"YES"<<endl;
    inorder(root);
     
    cout<<endl;
        cout<<endl;	
    return 0;
}