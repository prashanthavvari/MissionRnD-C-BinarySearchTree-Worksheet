/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
void inorderfun(struct node *root,int *ind, int *arr)
{

	if (!root)
	{
		return;
	}
	else
	{
		inorderfun(root->left, arr, ind);
		arr[*ind] = root->data;
		(*ind)++;
		inorderfun(root->right, arr, ind);
	}
}

void inorder(struct node *root, int *arr){
	int ind = 0;
	if (root != NULL && arr != NULL)
		inorderfun(root, arr, &ind);
	else
		return;
}
void preorderfun(struct node *root, int *ind, int *arr)
{
	if (!root)
	{
		return;
	}
	else
	{
		arr[*ind] = root->data;
		(*ind)++;
		preorderfun(root->left, arr, ind);
		preorderfun(root->right, arr, ind);
	}
}
void preorder(struct node *root, int *arr){
	int ind = 0;
	if (root != NULL && arr != NULL)
		preorderfun(root, arr, &ind);
	else
		return;
}
void postorderfun(struct node *root, int *ind, int *arr)
{

	if (!root)
		return;
	else
	{
		postorderfun(root->left, arr, ind);
		postorderfun(root->right, arr, ind);
		arr[*ind] = root->data;
		(*ind)++;
	}
}
void postorder(struct node *root, int *arr){
	int ind = 0;
	if (root != NULL && arr != NULL)
		postorderfun(root, arr, &ind);
	else
		return;
}