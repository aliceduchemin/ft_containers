#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <cstdlib>

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

	template <class T>
	struct tree_node
	{
		tree_node<T>* left;
		tree_node<T>* right;
		T data;
	};

	template <class T>
	class BinarySearchTree
	{
		private:
			tree_node<T>* _root;
		
		public:
			BinarySearchTree() { _root = NULL; }

			bool	search(T data)
			{
				tree_node<T>* temp = _root;
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
			void	inorder(tree_node<T>* t)
			{
				if (t != NULL)
				{
					if (t->left)
						inorder(t->left);
					std::cout << " " << t->data << " ";
					if (t->right)
						inorder(t->right);
				}
			}

			void	print_preorder();
			void	preorder(tree_node<T>*);
			void	print_postorder();
			void	postorder(tree_node<T>*);

			void	insert(T data)
			{
				tree_node<T>* temp = new tree_node<T>;
				tree_node<T>* parent;
				temp->data = data;
				temp->left = NULL;
				temp->right = NULL;
				parent = NULL;
				
				if (this->isEmpty())
					_root = temp;
				else
				{
					tree_node<T>* curr;
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

			void remove(T data)
			{
				if (this->isEmpty() || this->search(data) == false)
					return ;
				bool found = false;
				tree_node<T>* curr = _root;
				tree_node<T>* parent;
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
					tree_node<T>* chkr;
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
							tree_node<T>* lcurr;
							tree_node<T>* lcurrp;
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
							tree_node<T>* tmp;
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