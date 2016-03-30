/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorders(node *head, int *x)
{
	if (head != NULL)
	{
		inorders(head->left, x);
		(*x) = (*x) + head->data;
		inorders(head->right, x);
	}
}
int height(node* head)
{
	if (head == NULL)
		return 0;
	else
	{
		int left = height(head->left);
		int right = height(head->right);
		if (left > right)
			return(left + 1);
		else return(right + 1);
	}
}
int get_height(struct node *root){
	int x = 0;
	x=height(root);
	return x;
}

int get_left_subtree_sum(struct node *root){
	int x = 0;
	if (root != NULL)
	{
		node *p = root->left;
		inorders(p, &x);
		return x;
	}
	else
		return 0;
}
int get_right_subtree_sum(struct node *root){
	int x = 0;
	if (root != NULL)
	{
		node *p = root->right;
		inorders(p, &x);
		return x;
	}
	else
		return 0;
}

