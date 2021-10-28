/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:45:20 by aduchemi          #+#    #+#             */
/*   Updated: 2021/10/27 17:45:24 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <cstdlib>
#include "./Map/pair.hpp"

namespace ft
{
	const                        
	class nullptr_t
	{
		public:
			template<class T>          
			operator T*() const        
			{ return 0; };

			template<class C, class T> 
			operator T C::*() const 
			{ return 0; };   

		private:
			void operator&() const;    
	} nullptr_t = {}; 

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

	template <typename T>
	void	ft_swap(T & a, T & b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <class T1, class T2>
	struct tree_node
	{
		tree_node<T1,T2>*	left;
		tree_node<T1,T2>*	right;
		ft::pair<T1,T2>		data;
		tree_node<T1,T2>*	parent;
		tree_node<T1,T2>*	out;
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
			tree_node<T1,T2>*	_rendNode;
			size_t				_number;
		
			/********* CONSTRUCTEURS *********/
			BinarySearchTree()
			{
				this->_root = NULL;
				this->_smallestNode = NULL;
				this->_biggestNode = NULL;
				this->_lastNode = NULL;
				this->_number = 0;
			};

			BinarySearchTree(BinarySearchTree const & other)
			{	*this = other;	};

			BinarySearchTree & operator=(BinarySearchTree const & other)
			{	
				this->_root = other._root;
				this->_smallestNode = other._smallestNode;
				this->_biggestNode = other._biggestNode;
				this->_lastNode = other._lastNode;
				this->_rendNode = other._rendNode;
				this->_number = other._number;
				return *this;
			};

			~BinarySearchTree() {};

			/********* OTHER *********/
			tree_node<T1,T2>*	minValue(ft::tree_node<T1,T2>* node)
			{
				tree_node<T1, T2>* temp = node;

				while (temp->left != NULL)
					temp = temp->left;
				return temp;
			};

			tree_node<T1,T2>*	inorderSuccessor(ft::tree_node<T1,T2>* node)
			{
				if (node->right != NULL)
					return minValue(node->right);

				tree_node<T1, T2>* parent = node->parent;
				while (parent != NULL && node == parent->right)
				{
					node = parent;
					parent = parent->parent;
				}
				return parent;
			};

			tree_node<T1,T2>*	maxValue(ft::tree_node<T1,T2>* node)
			{
				tree_node<T1, T2>* temp = node;

				while (temp->right != NULL)
					temp = temp->right;
				return temp;
			};

			tree_node<T1,T2>*	inorderPredecessor(ft::tree_node<T1,T2>* node)
			{
				if (node == this->_smallestNode)
					return this->_smallestNode;
				if (node->left != NULL)
					return maxValue(node->left);

				tree_node<T1, T2>* parent = node->parent;
				while (parent != NULL && node == parent->left)
				{
					node = parent;
					parent = parent->parent;
				}
				return parent;
			};

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
			};

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
						{
							if (temp->data.first == _lastNode->parent->data.first)
								break;
							temp = temp->right;
						}
						else if (key < temp->data.first)
						{
							if (temp->data.first == _rendNode->parent->data.first)
								break;
							temp = temp->left;
						}
					}
				}
				return _lastNode;
			};

			bool	isEmpty() const { return _number == 0; };

			void	inorder(tree_node<T1, T2>* t)
			{
				if (t != NULL)
				{
					if (t->left)
						inorder(t->left);
					if (t->right)
						inorder(t->right);
				}
			};

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
			};

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
			};

			void	resetNode()
			{
				tree_node<T1, T2>* set = this->_root;

				this->smallestNode(set);
				if (this->_smallestNode == this->_rendNode)
					this->_smallestNode = this->_smallestNode->parent;
				this->_rendNode->parent = this->_smallestNode;
				this->_smallestNode->left = this->_rendNode;

				set = _root;
				this->biggestNode(set);
				if (this->_biggestNode == this->_lastNode)
					this->_biggestNode = this->_biggestNode->parent;
				this->_lastNode->parent = this->_biggestNode;
				this->_biggestNode->right = this->_lastNode;
			};

			ft::pair<T1,T2>		insert(ft::pair<T1,T2> data)
			{
				tree_node<T1, T2>* temp = new tree_node<T1, T2>;
				temp->data = data;
				temp->left = NULL;
				temp->right = NULL;
				
				if (this->isEmpty())
				{
					_root = temp;
					_root->parent = temp;
					tree_node<T1, T2>* last = new tree_node<T1, T2>;
					_lastNode = last;
					_lastNode->parent = _root;
					_lastNode->left = NULL;
					_lastNode->right = NULL;
					_lastNode->data = ft::make_pair(key_type(), mapped_type());
					tree_node<T1, T2>* rend = new tree_node<T1, T2>;
					_rendNode = rend;
					_rendNode->parent = _root;
					_rendNode->left = NULL;
					_rendNode->right = NULL;
					_rendNode->data = ft::make_pair(key_type(), mapped_type());
				}
				else
				{
					tree_node<T1, T2>* curr;
					curr = _root;
					while (curr)
					{
						temp->parent = curr;
						if (temp->data == curr->data)
							break;
						else if (temp->data > curr->data) { 
							if (curr->data == _lastNode->parent->data)
								break;
							curr = curr->right;}
						else  if (temp->data < curr->data) {
							if (curr->data == _rendNode->parent->data)
								break;
							curr = curr->left;}
					}
					if (temp->data < temp->parent->data)
						temp->parent->left = temp;
					else if (temp->data > temp->parent->data)
						temp->parent->right = temp;
				}
				this->_number++;
				this->resetNode();
				return temp->data;
			};

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
				if (curr == this->_root && this->_root->right == this->_lastNode && this->_root->left == this->_rendNode)
				{
					this->_number--;
					delete curr;
					return ;
				}
				else if ((curr->left == NULL && curr->right != NULL) ||
					(curr->left != NULL && (curr->right == NULL || curr->right == this->_lastNode)))
				{
					if (curr->left == NULL && curr->right != NULL)
					{
						if (parent->left && parent->left == curr)
						{
							parent->left = curr->right;
							curr->right->parent = curr->parent;
							delete curr;
						}
						else if (parent->right && parent->right == curr)
						{
							parent->right = curr->right;
							curr->right->parent = curr->parent;
							delete curr;
						}
						else
						{
							this->_root = curr->right;
							this->_root->parent = this->_root;
							delete curr;
						}
					}
					else
					{
						if (parent->left && parent->left == curr)
						{
							parent->left = curr->left;
							curr->left->parent = curr->parent;
							delete curr;
						}
						else if (parent->right && parent->right == curr)
						{
							parent->right = curr->left;
							curr->left->parent = curr->parent;
							delete curr;
						}
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
				else if (curr->left != NULL && curr->right != NULL && curr->right != this->_lastNode)
				{
					tree_node<T1, T2>* chkr;
					chkr = curr->right;
					if ((chkr->left == NULL) && (chkr->right == NULL))
					{
						curr->data = chkr->data;
						curr->right = NULL;
						delete chkr;
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
							if (lcurr->right)
							{
								lcurrp->left = lcurr->right;
								lcurrp->left->parent = lcurrp;
							}
							else
								lcurrp->left = NULL;
							curr->data = lcurr->data;
							delete lcurr;
						}
						else
						{
							tree_node<T1, T2>* tmp;
							tmp = curr->right;
							curr->data = tmp->data;
							curr->right = tmp->right;
							tmp->right->parent = curr;
							delete tmp;
						}
					}
				}
				this->_number--;
				this->resetNode();
			};

			void	removeExtremNodes()
			{
				delete this->_lastNode;
				delete this->_rendNode;
			};
	};
};
#endif
