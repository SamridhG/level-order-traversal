#include<iostream>
#include <queue>
using namespace std;
class node{
	public:
		int val;
		node *right,*left;
		node(int val)
		{
			this->val=val;
			right=left=NULL;
		}
};
class tree{
	public:
		node *root;
		tree()
		{
	    root=NULL;
		}
		void insert(int data)
		{
			if(root==NULL)
			{
				root=new node(data);
			}
			else
			{
				node *current=root;
				while(true)
				{
					if(current->val>data)
					{
						if(current->left==NULL)
						{
							current->left=new node(data);
							break;
						}
						else
						{
							current=current->left;
						}
					}
					else
					{
						if(current->right==NULL)
						{
							current->right=new node(data);
							break;
						}
						else
						{
							current=current->right;
						}
					
					}
				}
			}
		}
		void inorder(node *rt)
		{
			if(rt!=NULL)
			{
				inorder(rt->left);
				cout<<rt->val<<" ";
				inorder(rt->right);
			}
		}
		void levelorder(node *rt)
		{
			if(rt!=NULL)
			{
				queue<node*>A;
				A.push(rt);
				while(!A.empty())
				{
					node *out=A.front();
					cout<<out->val<<" ";
					A.pop();
					if(out->left)
					{
						A.push(out->left);
					}
					if(out->right)
					{
						A.push(out->right);
					}
				}
			}
		}
};
int main()
{
	tree A;
	A.insert(13);
	A.insert(5);
	A.insert(15);
	A.insert(3);
	A.insert(4);
	A.insert(12);
	A.insert(0);
	A.inorder(A.root);
	cout<<endl;
	A.levelorder(A.root);
}
