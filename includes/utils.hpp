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
	const class nullptr_t
	{
		public:
			template<class T>          
			operator T*() const        
			{	return 0;	};

			template<class C, class T> 
			operator T C::*() const 
			{	return 0;	};   

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

	template <class T>
	struct tree_node
	{
		tree_node<T>*	left;
		tree_node<T>*	right;
		T				data;
		tree_node<T>*	parent;
		tree_node<T>*	out;

		tree_node()
		{
			left = NULL;
			right = NULL;
			parent = NULL;
			data = NULL;
		};

		tree_node(tree_node<T>* p, tree_node<T>* r, tree_node<T>* l, const T& d)
		{
			left = l;
			right = r;
			parent = p;
			data = d;
		};
	};

	template <class T,
			  class Node = ft::tree_node<T>,
			  class Allocator = std::allocator<Node> >
	class BinarySearchTree
	{
		public:
			typedef Allocator		allocator_type;
			typedef T				value_type;
			typedef Node			node;
			typedef node*			nodePtr;

			nodePtr					_root;
			nodePtr					_smallestNode;
			nodePtr					_biggestNode;
			nodePtr					_lastNode;
			nodePtr					_rendNode;
			size_t					_number;
			allocator_type			_allocator;
		
			/********* CONSTRUCTEURS *********/
			BinarySearchTree(const allocator_type& alloc = allocator_type())
			{
				this->_root = NULL;
				this->_smallestNode = NULL;
				this->_biggestNode = NULL;
				this->_number = 0;
				this->_allocator = alloc;
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
			nodePtr	minValue(nodePtr node)
			{
				nodePtr temp = node;

				while (temp->left != NULL)
					temp = temp->left;
				return temp;
			};

			nodePtr	inorderSuccessor(nodePtr node)
			{
				if (node->right != NULL)
					return minValue(node->right);

				nodePtr parent = node->parent;
				while (parent != NULL && node == parent->right)
				{
					node = parent;
					parent = parent->parent;
				}
				return parent;
			};

			nodePtr	maxValue(nodePtr node)
			{
				nodePtr temp = node;

				while (temp->right != NULL)
					temp = temp->right;
				return temp;
			};

			nodePtr	inorderPredecessor(nodePtr node)
			{
				if (node == this->_smallestNode)
					return this->_smallestNode;
				if (node->left != NULL)
					return maxValue(node->left);

				nodePtr parent = node->parent;
				while (parent != NULL && node == parent->left)
				{
					node = parent;
					parent = parent->parent;
				}
				return parent;
			};

			bool	search(const value_type& k)
			{
				nodePtr temp = _root;
				while (temp != NULL)
				{
					if (temp->data.first == k.first)
						return true;
					else
					{
						if (k.first > temp->data.first)
							temp = temp->right;
						else
							temp = temp->left;
					}
				}
				return false;
			};

			nodePtr	findNode(const value_type& k) const
			{
				nodePtr temp = _root;

				while (temp != NULL)
				{
					if (temp->data.first == k.first)
						return temp;
					else
					{
						if (k.first > temp->data.first)
						{
							if (temp->data.first == _lastNode->parent->data.first)
								break;
							temp = temp->right;
						}
						else if (k.first < temp->data.first)
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

			void	inorder(nodePtr t)
			{
				if (t != NULL)
				{
					if (t->left)
						inorder(t->left);
					if (t->right)
						inorder(t->right);
				}
			};

			void	smallestNode(nodePtr t)
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

			void	biggestNode(nodePtr t)
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
				nodePtr set = this->_root;
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

			value_type			insert(value_type data)
			{
				nodePtr temp = this->_allocator.allocate(1);
				
				if (this->isEmpty())
				{
					this->_root = temp;
					this->_allocator.construct(temp, node(_root, NULL, NULL, data));

					this->_lastNode = this->_allocator.allocate(1);
					this->_allocator.construct(this->_lastNode, node(_root, NULL, NULL, value_type()));
					_lastNode->data = value_type();

					this->_rendNode = this->_allocator.allocate(1);
					this->_allocator.construct(this->_rendNode, node(_root, NULL, NULL, value_type()));
					_rendNode->data = value_type();
				}
				else
				{
					this->_allocator.construct(temp, node(temp->parent, NULL, NULL, data));
					nodePtr curr;
					curr = _root;
					while (curr)
					{
						temp->parent = curr;
						if (temp->data == curr->data)
							break;
						else if (temp->data > curr->data)
						{ 
							if (curr->data == _lastNode->parent->data)
								break;
							curr = curr->right;
						}
						else  if (temp->data < curr->data)
						{
							if (curr->data == _rendNode->parent->data)
								break;
							curr = curr->left;
						}
					}
					if (temp->data.first < temp->parent->data.first)
						temp->parent->left = temp;
					else if (temp->data.first > temp->parent->data.first)
						temp->parent->right = temp;
				}
				this->_number++;
				this->resetNode();
				return temp->data;
			};

			void remove(const value_type& k)
			{
				if (this->isEmpty() || this->search(k) == false)
					return ;

				nodePtr curr = _root;
				nodePtr parent;
				while (curr)
				{
					if (curr->data.first == k.first)
						break;
					else
					{
						parent = curr;
						if (k.first > curr->data.first)
							curr = curr->right;
						else
							curr = curr->left;
					}
				}
				if (curr == this->_root && this->_root->right == this->_lastNode && this->_root->left == this->_rendNode)
				{
					this->_number--;
					this->_allocator.deallocate(curr, 1);
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
							this->_allocator.deallocate(curr, 1);
						}
						else if (parent->right && parent->right == curr)
						{
							parent->right = curr->right;
							curr->right->parent = curr->parent;
							this->_allocator.deallocate(curr, 1);
						}
						else
						{
							this->_root = curr->right;
							this->_root->parent = this->_root;
							this->_allocator.deallocate(curr, 1);
						}
					}
					else
					{
						if (parent->left && parent->left == curr)
						{
							parent->left = curr->left;
							curr->left->parent = curr->parent;
							this->_allocator.deallocate(curr, 1);
						}
						else if (parent->right && parent->right == curr)
						{
							parent->right = curr->left;
							curr->left->parent = curr->parent;
							this->_allocator.deallocate(curr, 1);
						}
					}
				}
				else if (curr->left == NULL && curr->right == NULL)
				{
					if (parent->left == curr)
						parent->left = NULL;
					else
						parent->right = NULL;
					this->_allocator.deallocate(curr, 1);
				}
				else if (curr->left != NULL && curr->right != NULL && curr->right != this->_lastNode)
				{
					nodePtr chkr;
					chkr = curr->right;
					if ((chkr->left == NULL) && (chkr->right == NULL))
					{
						curr->data = chkr->data;
						curr->right = NULL;
						this->_allocator.deallocate(chkr, 1);
					}
					else
					{
						if ((curr->right)->left != NULL)
						{
							nodePtr lcurr;
							nodePtr lcurrp;
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
							this->_allocator.deallocate(lcurr, 1);
						}
						else
						{
							nodePtr tmp;
							tmp = curr->right;
							curr->data = tmp->data;
							curr->right = tmp->right;
							tmp->right->parent = curr;
							this->_allocator.deallocate(tmp, 1);
						}
					}
				}
				this->_number--;
				this->resetNode();
			};

			void	removeExtremNodes()
			{
				this->_allocator.destroy(this->_lastNode);
				this->_allocator.deallocate(this->_lastNode, 1);
				this->_allocator.destroy(this->_rendNode);
				this->_allocator.deallocate(this->_rendNode, 1);
			};
	};
};
#endif
