//By Ayush Chauhan Btech CST 21021257
//Question 7
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct bst{
    struct bst* left;
    int data;
    struct bst* right;
}bsttype;

void insert(bsttype **rt, int nm)                      //Function to create nodes
{
    if(*rt==NULL)                                   //Creating Nodes
    {
        *rt=(bsttype *)malloc(sizeof(bsttype));
        (*rt)->left=NULL;
        (*rt)->data=nm;
        (*rt)->right=NULL;
    }
    else if((*rt)->data<nm)                         //if Input is greater than root
    {
        insert(&(*rt)->right, nm);
    }
    else if((*rt)->data>nm)                         //if Input is smaller than root
    {
        insert(&(*rt)->left, nm);
    }
}

void display(bsttype* root)                         //function to display in tree INORDER
{
    if(root==NULL)
        return;
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}
int max(int a, int b)                               //simple math function to return max
{
    return a>=b? a: b;
}

void searchTree(bsttype* root, int target)          //function to search a particular key
{
    if(root==NULL)
        return;
    else if(root->data==target){
        printf("%d was found!\n", target);
        return;
    }
    searchTree(root->left, target);
    searchTree(root->right, target);
}

bsttype* smallest(bsttype* root)                    //function to find minimum in right subtree
{
    if(root->left==NULL)
      	return root;
    return smallest(root->left);
}

bsttype* deleteNode(bsttype* root, int key)         //function to delete a node
{
   	if(root == NULL)
       	return root;
   	else if(key<root->data){
       	root->left = deleteNode(root->left, key);
   	}
   	else if(key>root->data){
       	root->right = deleteNode(root->right, key);
   	}
   	else{
       	if(root->left==NULL && root->right==NULL){
           	return NULL;
       	}
       	else if(root->left==NULL){
           	bsttype* temp = root->right;
           	free(root);
           	return temp;
       	}
       	else if(root->right==NULL){
           	bsttype* temp = root->left;
           	free(root);
           	return temp;
       	}
       	bsttype* temp = smallest(root->right);
       	root->data = temp->data;
       	root->right=deleteNode(root->right, root->data);
    }
    return root;
}
void countLeafNodes(bsttype* root, int* n)          //function to count number of leaf nodes
{
    if(root==NULL)
        return;
    countLeafNodes(root->left, n);
    countLeafNodes(root->right, n);
    if(root->left==NULL && root->right==NULL)
        ++(*n);
}
int findHeightOfBST(bsttype* root)                  //function to find height of a binary tree
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return 0;
    return max(findHeightOfBST(root->left), findHeightOfBST(root->right))+1;
}
int rightCount(bsttype* root)                       //funtion to calculate total number of nodes from right hand side
{
    if(root==NULL)
        return 0;
    return rightCount(root->right)+rightCount(root->left)+1;
}

int main() {
    int ch;
    bsttype* root = NULL;
    printf("By Ayush Chauhan Btech CST 21021257");
    printf("Enter 1 to insert node\n2 to display\n3 to search a key");
    printf("\n4 to delete a Node from the tree\n5 to count leaf nodes");
    printf("\n6 to find height of the tree\n7 to count total nodes in right subtree");
    do{
        printf("\nchoice:");
        scanf("%d", &ch);
        switch(ch){
            case 1: ;
                    int p;
                    printf("Enter Value:");
                    scanf("%d", &p);
                    insert(&root, p);
                    break;
            case 2: 
                    if(root==NULL)
                        printf("Tree is empty\n");
                    else
                        display(root);
                    break;
            case 3:
                    if(root==NULL)
                        printf("Tree is empty\n");
                    else{
                        int x;
                        printf("Enter key to be searched\n");
                        scanf("%d", &x);
                        searchTree(root, x);
                    }
                    break;
            case 4:
                    if(root==NULL)
                        printf("Tree is empty\n");
                    else{
                        int x;
                        printf("Enter key to be deleted\n");
                        scanf("%d", &x);
                        deleteNode(root, x);
                    }
                    break;
            case 5:
                    if(root==NULL)
                        printf("Tree is empty\n");
                    else{
                        int n=0;
                        countLeafNodes(root, &n);
                        printf("%d leaf nodes\n", n);
                    }
                    break;
            case 6:
                    if(root==NULL)
                        printf("Tree is empty\n");
                    else{
                        printf("height: %d\n", findHeightOfBST(root));
                    }
                    break;
            case 7: if(root==NULL)
                        printf("Tree is empty\n");
                    else{
                        printf("num of Nodes in Right subtree: %d\n", rightCount(root->right));
                    }
                    break;
        }
    }while(ch>0 && ch<8);

    return 0;
}
