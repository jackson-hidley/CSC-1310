/*
NAME: Jackson Hidley
DATE: 2/12/2020
TITLE: BinaryTree.h
*/

#include <iostream>
using namespace std;

#ifndef BinaryTree_H
#define BinaryTree_H

	template<class T>
	class BinaryTree
	{
		private:
			struct treeNode
			{
				treeNode* left;
				treeNode* right;
				T data;
			};
			treeNode* root;
			bool isEmpty() const { return root == NULL; }
			void insert( T d )
			{
				treeNode* t = new treeNode;
				treeNode* parent;
				t->data = d;
				t->left = NULL;
				t->right = NULL;
				parent = NULL;
				// is this a new tree?
				if(isEmpty()) root = t;
				else
				{
					//Note: ALL insertions are as leaf nodes
					treeNode* curr;
					curr = root;
					// Find the Node's parent
					while(curr)
					{
						parent = curr;
						if(t->data > curr->data) curr = curr->right;
						else curr = curr->left;
					}

					if(t->data < parent->data)
						parent->left = t;
					else
						parent->right = t;
				}
			}
			
			void destroySubTree()
			{
			//	delete BinaryTree;
			}
			
			void inOrder(treeNode* p)
			{
				if(p != NULL)
				{
					if(p->left) inOrder(p->left);
					cout << " " << p->data << " ";
					if(p->right) inOrder(p->right);
				}
				else return;
			}
			
			void preOrder( treeNode* p )
			{
				if(p != NULL)
				{
					cout << " " << p->data << " ";
					if(p->left) preOrder(p->left);
					if(p->right) preOrder(p->right);
				}
				else return;
			}
			
			void postOrder( treeNode* p )
			{
				if(p != NULL)
				{
					if(p->left) postOrder(p->left);
					if(p->right) postOrder(p->right);
					cout << " " << p->data << " ";
				}
				else return;
			}
			
		public:
			BinaryTree()
			{
				root = NULL;
			}
			~BinaryTree()
			{
				destroySubTree();
			}
			void insertNode( T hold )
			{
				insert( hold );
			}
			void displayInOrder()
			{
				inOrder(root);
			}
			void displayPreOrder()
			{
				preOrder(root);
			}
			void displayPostOrder()
			{
				postOrder(root);
			}
	};
	
#endif
