#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node* left;
    int key;
    struct node* right;
}nodetype;
nodetype* newNode(int item){
    nodetype* temp=(nodetype*)malloc(sizeof(nodetype));
    temp->key=item;
    temp->left=temp->right=NULL;
    return temp;
}
void inorder(nodetype* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\n",root->key);
        inorder(root->right);
    }
}
void postorder(nodetype* root){
    if(root!=NULL){
        inorder(root->left);
        inorder(root->right);
        printf("%d\n",root->key);
    }
}
void preorder(nodetype* root){
    if(root!=NULL){
        printf("%d\n",root->key);
        inorder(root->left);
        inorder(root->right);
    }
}
nodetype* insert(nodetype* node,int key){
    if(node==NULL){
        return newNode(key);
    }
    if(key<node->key){
        node->left=insert(node->left,key);
    }
    else if(key>node->key){
        node->right=insert(node->right,key);
    }
    return node;
}
nodetype* minValueNode(nodetype* node)
{
    nodetype* current = node;  
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
} 
nodetype* deleteNode(nodetype* root, int key)
{   
    if (root == NULL)
        return root; 
        // SEARCHING
    if (key < root->key)
        root->left = deleteNode(root->left, key); 
    else if (key > root->key)
        root->right = deleteNode(root->right, key); 
    // DELETION        
    else { 
        if (root->left == NULL) {
            nodetype* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            nodetype* temp = root->left;
            free(root);
            return temp;
        } 
        nodetype* temp = minValueNode(root->right); 
        root->key = temp->key; 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
 int count(nodetype *root)
{ 
    if (root ==NULL)
        return 0;

    else
    {
        return 1 + count(root->left) + count(root->right);
    }
}
int countLeafNode(struct node *root){ 
    if(root == NULL)
        return 0; 
    if(root->left == NULL && root->right == NULL)
        return 1; 
    else
        return countLeafNode(root->left) + countLeafNode(root->right);
}
int main(){
    nodetype* root=NULL; 
    root = insert(root, 1);
    // insert(root, 30);
    // insert(root, 20);
    // insert(root, 40);
    // insert(root, 70);
    // insert(root, 60);
    while(1){
        int key,ch;
        printf("enter 1 for insertion anything 2 for inorder 3 for reorder 4 for postorder 5 for deletion other to exit");
        scanf("%d",&ch);
        if(ch==1){
            printf("enter data\n");
        scanf("%d",&key);
            insert(root,key);
        }
        else if(ch==2){
            printf("inorder display\n");
            inorder(root);
        }
        else if(ch==3){
            printf("preorder display\n");
             preorder(root);
        }
        else if(ch==4){
            printf("postorder display\n");
            postorder(root);
        } 
        else if(ch==5){
            int delnode;
            printf("enter node to be deleted \n");
            scanf("%d",&delnode);
            root=deleteNode(root,delnode);
        }
        else if(ch==6){
            // int countnode=count(root);
            printf("number of nodes %d\n",count(root)); 
        }
        else if(ch==7){
            // int countnode=count(root);
            printf("number of leafnodes %d\n",countLeafNode(root)); 
        }
        else{
            break;
        }

    }
    
    
   
    return 0;
}