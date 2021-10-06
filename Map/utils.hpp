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
			typedef T1					key_type;
			typedef T2					mapped_type;

			tree_node<T1,T2>*	_root;
			tree_node<T1,T2>*	_smallestNode;
			tree_node<T1,T2>*	_biggestNode;
			tree_node<T1,T2>*	_lastNode;
			size_t				_number;
		
			/********* CONSTRUCTEURS *********/
			BinarySearchTree() { _root = NULL; _smallestNode = NULL; _biggestNode = NULL; _lastNode = NULL; _number = 0; };
			BinarySearchTree(BinarySearchTree const & other)
				{	*this = other;	};
			BinarySearchTree & operator=(BinarySearchTree const & other)
				{	this->_root = other._root;
					this->_smallestNode = other._smallestNode;
					this->_biggestNode = other._biggestNode;
					this->_lastNode = other._lastNode;
					this->_number = other._number;
					return *this;	};
			~BinarySearchTree() {};

			/********* OTHER *********/
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

			bool	search(const key_type& k)
			{
				tree_node<T1, T2>* temp = _root;
				while (temp != NULL)
				{
					if (temp->data.first == k)
						return true;
					else
					{
						if (k > temp->data.first)
							temp = temp->right;
						else
							temp = temp->left;
					}
				}
				return false;
			}

			ft::tree_node<T1,T2>*	findNode(T1 const & key)
			{
			//	std::cout << "\nkey to find : " << key <<std::endl;
				tree_node<T1, T2>* temp = _root;
				while (temp != NULL)
				{
					if (temp->data.first == key)
					{
					//	std::cout << "temp data = key"<<std::endl;
						return temp;
					}
					else
					{
					//	std::cout << "else, temp = "<<temp->data.first<<std::endl;
						if (key > temp->data.first)
						{
					//	std::cout << "right"<<std::endl;
							if (temp->data.first == _lastNode->parent->data.first)
							{
					//	std::cout << "last"<<std::endl;
								//return _lastNode;
								break;
							}
							temp = temp->right;
						}
						else
						{
					//	std::cout << "left"<<std::endl;
							temp = temp->left;
						}
					}
				}
				return _lastNode;
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
					std::cout << "t = " << _biggestNode->data.first<<std::endl;
					if (t->right)
						biggestNode(t->right);
				}
			}

			ft::pair<T1,T2>		insert(ft::pair<T1,T2> data)
			{
				tree_node<T1, T2>* temp = new tree_node<T1, T2>;
				temp->data = data;
				temp->left = NULL;
				temp->right = NULL;
			//	std::cout << "\ninsert " << data.first << std::endl;
				if (this->isEmpty())
				{
				//	std::cout << "empty" << temp->data.first<<std::endl;
					_root = temp;
					_root->parent = temp;
					tree_node<T1, T2>* last = new tree_node<T1, T2>;
					_lastNode = last;
					_lastNode->parent = _root;
					_lastNode->left = NULL;
					_lastNode->right = NULL;
					_lastNode->data = ft::make_pair(key_type(), mapped_type());
				}
				else
				{
					tree_node<T1, T2>* curr;
					curr = _root;
					
					while (curr)
					{
						temp->parent = curr;
					//	std::cout << "boucle, parent = " << temp->parent->data.first<<std::endl;
						if (temp->data == curr->data)
							break;
						else if (temp->data > curr->data) { 
							if (curr->data == _lastNode->parent->data)
								break;
							curr = curr->right;}
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
					//	std::cout <<"parent = " <<temp->parent->data.first<<std::endl;
				}
			//	std::cout<< "end insert\n";
				tree_node<T1, T2>* set = NULL;
				this->_number++;
				set = _root;
				this->smallestNode(set);
				set = _root;
				this->biggestNode(set);
			//	std::cout << "ok1 retour biggest node = " << _biggestNode->data.first <<std::endl;
				if (this->_biggestNode != temp)
					this->_biggestNode = this->_biggestNode->parent;
				this->_biggestNode->right = this->_lastNode;
				this->_lastNode->parent = this->_biggestNode;
			//	std::cout<< "end insert of value " << data.first << " second = " << data.second<< ", _root = " << _root->data.first << " smallest node = " << _smallestNode->data.first << " biggest node = " << _biggestNode->data.first<< "\t";
			//	std::cout<< "parent = "<< temp->parent->data.first<<std::endl;
				return temp->data;
			}

			void remove(const key_type& k)
			{
				if (this->isEmpty() || this->search(k) == false)
					return ;
				tree_node<T1, T2>* curr = _root;
				tree_node<T1, T2>* parent;
				while (curr != NULL)
				{
					if (curr->data.first == k)
						break;
					else
					{
						parent = curr;
						if (k > curr->data.first)
							curr = curr->right;
						else
							curr = curr->left;
					}
				}
				std::cout << "curr = " << curr->data.first << std::endl;
				std::cout << "curr parent = " << parent->data.first << std::endl;
				std::cout << "_root = " << _root->data.first << std::endl;
			
				if (curr->left)
					std::cout << "curr->left = "<<curr->left->data.first<<std::endl;				
				if (curr->right)
					std::cout << "curr->right = "<<curr->right->data.first<<std::endl;				
				
				if ((curr->left == NULL && curr->right != NULL) ||
					(curr->left != NULL && curr->right == NULL))
				{
					std::cout << "node with single child" << std::endl;
					if (curr->left == NULL && curr->right != NULL)
					{
					std::cout << "single child is at right" << std::endl;
						if (parent->left && parent->left == curr)
						{
							std::cout << "child is at left, curr = " <<curr->data.first<< std::endl;
							std::cout << "parent curr = " <<curr->parent->data.first<< std::endl;
							std::cout << "curr right= " <<curr->right->data.first<< std::endl;
							parent->left = curr->right;
							curr->right->parent = curr->parent;
							delete curr;
						}
						else if (parent->right && parent->right == curr)
						{
							std::cout << "child is at right" << std::endl;
							parent->right = curr->right;
							curr->right->parent = curr->parent;
							delete curr;
						}
						else
						{
							std::cout<<"root\n";
							this->_root = curr->right;
							this->_root->parent = this->_root;
							delete curr;
						}
						
					}
					else
					{
					std::cout << "left has a child, not right" << std::endl;
						if (parent->left && parent->left == curr)
						{
							parent->left = curr->left;
							std::cout << "new parent left = "<< parent->left->data.first<<std::endl;
							curr->left->parent = curr->parent;
							delete curr;
						}
						else if (parent->right && parent->right == curr)
						{
							parent->right = curr->left;
							std::cout << "new parent right = "<< parent->right->data.first<<std::endl;
							curr->left->parent = curr->parent;
							delete curr;
						}
					}
				}
				else if (curr->left == NULL && curr->right == NULL)
				{
					std::cout << "leaf node" << std::endl;
					if (parent->left == curr)
						parent->left = NULL;
					else
						parent->right = NULL;
					delete curr;					
				}
				else if (curr->left != NULL && curr->right != NULL && curr->right != this->_lastNode)
				{
					std::cout << "node with 2 children\n";
					std::cout << "replace node with smallest value in right subtree\n";
					tree_node<T1, T2>* chkr;
					chkr = curr->right;
					if ((chkr->left == NULL) && (chkr->right == NULL))
					{
						chkr->parent = curr->parent;//a verif
						curr = chkr;
						delete chkr;
						curr->right = NULL;
					}
					else
					{
						std::cout << "right child has children\n";
						if ((curr->right)->left != NULL)
						{
							std::cout << "if node's right child hast a left child, move all the way down to locate smallest element\n";
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
							std::cout <<"else\n";
							tree_node<T1, T2>* tmp;
							tmp = curr->right;
							curr->data = tmp->data;
							curr->right = tmp->right;
							delete tmp;
						}
					}
				}
				tree_node<T1, T2>* set = NULL;
				this->_number--;
				set = _root;
				this->smallestNode(set);
				set = _root;
				this->biggestNode(set);
				if (this->_biggestNode == this->_lastNode)
					this->_biggestNode = this->_biggestNode->parent;
				std::cout << "biggstnode = " << this->_biggestNode->data.first <<std::endl;
			//	this->_biggestNode->right = this->_lastNode;
				this->_lastNode->parent = this->_biggestNode;
				std::cout<< "end remove, _root = " << _root->data.first << " smallest node = " << _smallestNode->data.first << " biggest node = " << _biggestNode->data.first<< "\n";
				this->print_inorder();
				std::cout<<std::endl;
			}
	};
};

#endif