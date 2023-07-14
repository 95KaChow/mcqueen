#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *left,*right;
}N;

N *root;

N *find_min(N *root){
    if(root==NULL){
        return NULL;
    }
    else if(root->left!=NULL){
        return find_min(root->left);
    }
    return root;
}

void insert(N **r,N **n){
    if(*r == NULL){
        *r = *n;
    }
    else if((*r)->data>(*n)->data){
        insert(&(*r)->left,&(*n));
    }
    else{
        insert(&(*r)->right,&(*n));
    }
}

N  *deltree(N *r,int d){
    if(r == NULL){
        return NULL;
    }
    if(d>r->data){
        r->right = deltree(r->right,d);
    }
    else if(d<r->data){
        r->left = deltree(r->left,d);
    }
    else{
        if(r->left == NULL && r->right== NULL){
            free(r);
            return NULL;
        }
        else if(r->left == NULL || r->right == NULL){
            N *temp_1;
            if(temp_1->left == NULL){
                temp_1=r->right;
            }
            else{
                temp_1=r->left;
            }
            free(r);
            return temp_1;
        }
        else{
            N *temp_2 = find_min(r->right);
            r->data = temp_2->data;
            r->right = deltree(r->right,temp_2->data);
        }
    }
    return r;
}

void preOrder(N *r){
    if(r !=NULL){
        printf("%d ",r->data);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void inOrder(N *r){
    if(r !=NULL){
        inOrder(r->left);
        printf("%d ",r->data);
        inOrder(r->right);
    }
}

void postOrder(N *r){
    if(r !=NULL){
        postOrder(r->left);
        postOrder(r->right);
        printf("%d ",r->data);
    }
}
 
int main(){
    int ch,d;
    N *ptr;
    root = NULL;
    while(1){
        printf("1.Insert 2.PreOrder 3.InOrder 4.PostOrder 5.Delete 6.Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                ptr = (N*)malloc(sizeof(N));
                printf("Enter Data : ");
                scanf("%d",&(ptr)->data);
                ptr->right = NULL;
                ptr->left = NULL;
                insert(&root,&ptr);
                break;
            case 2:
                preOrder(root);
                break;
            case 3:
                inOrder(root);
                break;
            case 4:
                postOrder(root);
                break;
            case 5:
                printf("Enter the data to be deleted : ");
                scanf("%d",&d);
                deltree(root,d);
                printf("\n%d is deleted.",d);
                break;
            case 6:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
}