#include<iostream>
using namespace std;
#define MAX 8
int size[MAX];

struct bstnode
{
	bstnode* lchild;
	int data;
	bstnode* rchild;
};
bstnode* root = 0;

void insert(int x);
void insert(int x)
{
	bstnode* p, * t;
	int done;
	p = new bstnode;
	p->data = x;
	p->lchild = NULL;
	p->rchild = NULL;
	if (root == NULL)
	{
		root = p;
	}
	else
	{
		t = root;
		done = 0;
		while (done == 0)
		{
			if (x < t->data)
			{
				if (t->lchild == NULL)
				{
					t->lchild = p;
					done = 1;
				}
				else
					t = t->lchild;
			}
			else
			{
				if (t->rchild == NULL)
				{
					t->rchild = p;
					done = 1;
				}
				else
					t = t->rchild;
			}
		}
	}
}

void inorder(bstnode* t)
{
	if (t != NULL)
	{
		inorder(t->lchild);
		cout << t->data<<endl;
		inorder(t->rchild);
	}
}

void preorder(bstnode* t)
{
	if (t != NULL)
	{
		cout << t->data << endl;
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void postorder(bstnode* t)
{
	if (t != NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		cout << t->data<<endl;
	}
}

int main()
{
	int choice, data;
	do
	{
		cout << "Enter 1.Insert 2.Inorder 3.PreOrder 4.PostOrder 5.Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "Enter the value to insert" << endl;
			cin >> data;
			insert(data);
			break;
		case 2:cout << "The tree in Inorder" << endl;
			inorder(root);
			break;
		case 3:cout << "The Tree in Preorder" << endl;
			preorder(root);
			break;
		case 4:cout << "The Tree in PostOrder" << endl;
			postorder(root);
			break;
		default:cout << "Exiting" << endl;
			choice = 5;
		}
	} while (choice != 5);
}