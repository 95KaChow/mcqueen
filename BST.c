#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
   struct Node *lchild;
   int data;
   struct Node *rchild;	
};
struct Node *root = NULL;

struct Node* insertR(struct Node *p , int key)
     {
     	struct Node *newNode;
     	
     	 if(p == NULL)
     	 {
     	newNode=(struct Node*)malloc(sizeof(struct Node));
     	newNode->data = key;
     	newNode->lchild = newNode->rchild = NULL;
     	 return newNode;
		  }
		  
		  if(key > p->data)
		  {
		  	p->rchild = insertR(p->rchild,key);
		  }
		  else if( key < p->data)
		  {
		  	p->lchild = insertR(p->lchild,key);
		  }
		  return p;
	 }
void insert(int key)
{
	struct Node *c,*p,*newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = key;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	
	if(root == NULL)
	{
		root = newNode;
		return;
	}
	
	c = root;
	p = NULL;
	while(c != NULL)
	{
		p = c;
		if(key > c->data)
		   c=c->rchild;
		else if(key < c->data)
		   c=c->lchild;
		else
		   return;
	}
	
	if(key > p->data)
	{
		p->rchild = newNode;
	}
	else
	{
		p->lchild = newNode;
	}
}
void inorder(struct Node *p)
{
	if(p)
	{
		inorder(p->lchild);
		printf("%d   ",p->data);
		inorder(p->rchild);
	}
}
void preorder(struct Node *p)
{
	if(p)
	{
		printf("%d   ",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void postorder(struct Node *p)
{
	if(p)
	{
		
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d   ",p->data);
	}
}

struct Node* searchRecur(struct Node *p , int key)
{
	if(p == NULL)
	 return NULL;
	else if(p->data == key)
	   return p;
	else if(key > p->data)
	      return searchRecur(p->rchild,key);
	else
	      return searchRecur(p->lchild,key); 
}
struct Node* searchIter(struct Node *p , int key)
{
	while(p != NULL)
	{
		 if(key > p->data)
		 {
		 	p=p->rchild;
		 }
		 else if(key < p->data)
		 {
		 	p=p->lchild;
		 }
		 else
		 {
		 	return p;
		 }
	}
	
	return NULL;
}
int main()
{
	root=insertR(root,50);
	insertR(root,40);
	insertR(root,60);
	insertR(root,70);
	insertR(root,55);
	insertR(root,30);
	insertR(root,45);
	
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	struct Node *r = searchRecur(root,70);
	if(r!=NULL)
	{
		printf("\n%d found by recursion ",r->data);
	}
	else
	{
		printf("\n data is not found !!");
	}
	return 0;
}