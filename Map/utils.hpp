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
		tree_node<T1,T2>*	left;
		tree_node<T1,T2>*	right;
		ft::pair<T1,T2>		data;
		tree_node<T1,T2>*	parent;
	};

	template <class T1, class T2>
	class BinarySearchTree
	{
		public:
			tree_node<T1,T2>*	_root;
			tree_node<T1,T2>*	_smallestNode;
			tree_node<T1,T2>*	_biggestNode;
			size_t				_number;
		
			BinarySearchTree() { _root = NULL; _smallestNode = NULL; _biggestNode = NULL; _number = 0; };
			/*
			tree_node<T1,T2>*	advance(ft::pair<T1,T2>	data)
			{
			//	if (this->isEmpty() || this->search(node) == false)
			//		return ;
				bool found = false;
				tree_node<T1, T2>* temp = _root;
				tree_node<T1, T2>* parent;
				while (temp != NULL)
				{
					if (temp->data.first == data.first)
					{
						found = true;
						break;
					}
					else
					{
						parent = temp;
						if (data.first > temp->data.first)
							temp = temp->right;
						else
							temp = temp->left;
					}
				}
			//	temp = temp->right;
				return temp;
			};*/

			tree_node<T1,T2>*	minValue(ft::tree_node<T1,T2>* node)
			{
				tree_node<T1, T2>* temp = node;
				while (temp->left != NULL)
					temp = temp->left;
			//	std::cout <<"min value return = " <<temp->data.first<<std::endl;
				return temp;
			}

			tree_node<T1,T2>*	inorderSuccessor(ft::tree_node<T1,T2>* node)
			{
			//	std::cout <<"\ninorder successr node = " << node->data.first<<std::endl;
			//	tree_node<T1, T2>* temp = _root;

				if (node->right != NULL)
					return minValue(node->right);
				tree_node<T1, T2>* parent = node->parent;
				while (parent != NULL && node == parent->right)
				{
					node = parent;
					parent = parent->parent;
			//	std::cout <<"boucle parent !=null, return = " <<parent->data.first<<std::endl;
				}
				return parent;
			}

			tree_node<T1,T2>*	maxValue(ft::tree_node<T1,T2>* node)
			{
			//	std::cout << "max value node : " <<node->data.first<<std::endl;
				tree_node<T1, T2>* temp = node;
				while (temp->right != NULL)
					temp = temp->right;
			//	std::cout << "return max value : " <<temp->data.first<<std::endl;
				return temp;
			}

			tree_node<T1,T2>*	inorderPredecessor(ft::tree_node<T1,T2>* node)
			{
			//	std::cout <<"\ninorder predecessor node = " << node->data.first<<std::endl;
				
			//	std::cout << "parent node = " << node->parent->data.first<<std::endl;
				if (node->left)
			//		std::cout << "left node = " << node->left->data.first<<std::endl;
				if (node->right)
			//		std::cout << "right node = " << node->right->data.first<<std::endl;
			
				if (node->left != NULL)
					return maxValue(node->left);
				tree_node<T1, T2>* parent = node->parent;
				while (parent != NULL && node == parent->left)//right
				{
					node = parent;
					parent = parent->parent;
			//	std::cout <<"boucle parent !=null, return = " <<node->data.first<<std::endl;
				}
				return parent;
			}

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

			ft::tree_node<T1,T2>*	findNode(ft::tree_node<T1,T2>* node)
			{
				tree_node<T1, T2>* temp = _root;
				while (temp != NULL)
				{
					if (temp->data == node->data)
					{
					//	std::cout << "find node = " <<temp->data.first<<std::endl;
						return temp;
					}
					else
					{
						if (node->data > temp->data)
						{
					//	std::cout << "node > temp"<<std::endl;
							temp = temp->right;
						}
						else
						{
					//	std::cout << "else"<<std::endl;
							temp = temp->left;
						}
					}
				}
				return _root;
			}

			ft::tree_node<T1,T2>*	findNode(T1 const & key)
			{
				tree_node<T1, T2>* temp = _root;
				while (temp != NULL)
				{
					if (temp->data.first == key)
						return temp;
					else
					{
						if (key > temp->data.first)
							temp = temp->right;
						else
							temp = temp->left;
					}
				}
				return this->_biggestNode;
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

			void	smallestNode(tree_node<T1, T2>* t)
			{
				if (t != NULL)
				{
					if (t->right)
						smallestNode(t->right);
					this->_smallestNode = t;
					if (t->left)
						smallestNode(t->left);
				}
			}

			void	biggestNode(tree_node<T1, T2>* t)
			{
				if (t != NULL)
				{
					if (t->left)
						biggestNode(t->left);
					this->_biggestNode = t;
					if (t->right)
						biggestNode(t->right);
				}
			}

			void	insert(ft::pair<T1,T2> data)
			{
				tree_node<T1, T2>* temp = new tree_node<T1, T2>;
			//	tree_node<T1, T2>* parent = NULL;
				temp->data = data;
				temp->left = NULL;
				temp->right = NULL;
				
				if (this->isEmpty())
				{
					_root = temp;
					_root->parent = temp;
				}
				else
				{
					tree_node<T1, T2>* curr;
					curr = _root;
					while (curr)
					{
						temp->parent = curr;
					//	std::cout << "parent = " << temp->parent->data.first<<std::endl;
						if (temp->data == curr->data)
							break;
						else if (temp->data > curr->data)
							curr = curr->right;
						else
							curr = curr->left;
					}
					if (temp->data < temp->parent->data)
					{
					//	std::cout << "left\n";
						temp->parent->left = temp;
					}
					else if (temp->data > temp->parent->data)
					{
					//	std::cout << "right\n";
						temp->parent->right = temp;
					}
				}
				tree_node<T1, T2>* set = NULL;
				this->_number++;
				set = _root;
				this->smallestNode(set);
				set = _root;
				this->biggestNode(set);
				std::cout<< "end insert of value " << data.first<< ", _root = " << _root->data.first << " smallest node = " << _smallestNode->data.first << " biggest node = " << _biggestNode->data.first<<std::endl;
				std::cout<< "parent = "<< temp->parent->data.first<<std::endl;
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