#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <cstdlib>
#include "pair.hpp"

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	};

	template <class T1, class T2>
	struct tree_node
	{
		tree_node<T1,T2>* left;
		tree_node<T1,T2>* right;
		ft::pair<T1,T2>	data;
	};

	template <class T1, class T2>
	class BinarySearchTree
	{
		public:
			tree_node<T1,T2>* _root;
		
			BinarySearchTree() { _root = NULL; };
			
			tree_node<T1,T2> &advance(tree_node<T1,T2> data)
			{
			//	if (this->isEmpty() || this->search(data) == false)
			//		return ;
				bool found = false;
				tree_node<T1, T2>* curr = _root;
				tree_node<T1, T2>* parent;
				while (curr != NULL)
				{
					if (curr->data == data)
					{
						found = true;
						break;
					}
					else
					{
						parent = curr;
						if (data > curr->data)
							curr = curr->right;
						else
							curr = curr->left;
					}
				}
				curr = curr->right;
				return curr;
			};

			bool	search(ft::pair<T1,T2> data)
			{
				tree_node<T1, T2>* temp = _root;
				while (temp != NULL)
				{
					if (temp->data == data)
						return true;
					else
					{
						if (data > temp->data)
							temp = temp->right;
						else
							temp = temp->left;
					}
				}
				return false;
			}

			bool	isEmpty() const { return _root==NULL; }
			void	print_inorder() { inorder(_root); };
			void	inorder(tree_node<T1, T2>* t)
			{
				if (t != NULL)
				{
					if (t->left)
						inorder(t->left);
					std::cout << "key: " << t->data.first << " value: " << t->data.second << " --- ";
					if (t->right)
						inorder(t->right);
				}
			}

			void	insert(ft::pair<T1,T2> data)
			{
				tree_node<T1, T2>* temp = new tree_node<T1, T2>;
				tree_node<T1, T2>* parent;
				temp->data = data;
				temp->left = NULL;
				temp->right = NULL;
				parent = NULL;
				
				if (this->isEmpty())
					_root = temp;
				else
				{
					tree_node<T1, T2>* curr;
					curr = _root;
					while (curr)
					{
						parent = curr;
						if (temp->data == curr->data)
							break;
						else if (temp->data > curr->data)
							curr = curr->right;
						else
							curr = curr->left;
					}
					if (temp->data < parent->data)
						parent->left = temp;
					else if (temp->data > parent->data)
						parent->right = temp;
				}
			}

			void remove(ft::pair<T1,T2> data)
			{
				if (this->isEmpty() || this->search(data) == false)
					return ;
				bool found = false;
				tree_node<T1, T2>* curr = _root;
				tree_node<T1, T2>* parent;
				while (curr != NULL)
				{
					if (curr->data == data)
					{
						found = true;
						break;
					}
					else
					{
						parent = curr;
						if (data > curr->data)
							curr = curr->right;
						else
							curr = curr->left;
					}
				}
				if ((curr->left == NULL && curr->right != NULL) ||
					(curr->left != NULL && curr->right == NULL))
				{
					if (curr->left == NULL && curr->right != NULL)
					{
						if (parent->left == curr)
							parent->left = curr->right;
						else if (parent->right == curr)
							parent->right = curr->right;
						delete curr;
					}
					else
					{
						if (parent->left == curr)
							parent->left = curr->left;
						else if (parent->right == curr)
							parent->right = curr->left;
					}
				}
				else if (curr->left == NULL && curr->right == NULL)
				{
					if (parent->left == curr)
						parent->left = NULL;
					else
						parent->right = NULL;
					delete curr;					
				}
				else if (curr->left != NULL && curr->right != NULL)
				{
					tree_node<T1, T2>* chkr;
					chkr = curr->right;
					if ((chkr->left == NULL) && (chkr->right = NULL))
					{
						curr = chkr;
						delete chkr;
						curr->right = NULL;
					}
					else
					{
						if ((curr->right)->left != NULL)
						{
							tree_node<T1, T2>* lcurr;
							tree_node<T1, T2>* lcurrp;
							lcurrp = curr->right;
							lcurr = (curr->right)->left;
							while (lcurr->left != NULL)
							{
								lcurrp = lcurr;
								lcurr = lcurr->left;
							}
							curr->data = lcurr->data;
							delete lcurr;
							lcurrp->left = NULL;
						}
						else
						{
							tree_node<T1, T2>* tmp;
							tmp = curr->right;
							curr->data = tmp->data;
							curr->right = tmp->right;
							delete tmp;
						}
					}
				}
			}
	};
};

#endif