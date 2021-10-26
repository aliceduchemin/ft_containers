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
			{ return 0; }           
		template<class C, class T> 
			operator T C::*() const 
			{ return 0; }   

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
			BinarySearchTree() { _root = NULL; _smallestNode = NULL; _biggestNode = NULL; _lastNode = NULL; _number = 0; };
			BinarySearchTree(BinarySearchTree const & other)
				{	*this = other;	};
			BinarySearchTree & operator=(BinarySearchTree const & other)
				{	this->_root = other._root;
					this->_smallestNode = other._smallestNode;
					this->_biggestNode = other._biggestNode;
					this->_lastNode = other._lastNode;
					this->_rendNode = other._rendNode;
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
			/*	
				std::cout << "parent node = " << node->parent->data.first<<std::endl;
				if (node->left)
					std::cout << "left node = " << node->left->data.first<<std::endl;
				if (node->right)
					std::cout << "right node = " << node->right->data.first<<std::endl;
			*/
				if (node == this->_smallestNode)
					return this->_smallestNode;
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
						else if (key < temp->data.first)
						{
					//	std::cout << "left"<<std::endl;
							if (temp->data.first == _rendNode->parent->data.first)
							{
					//	std::cout << "last"<<std::endl;
								//return _lastNode;
								break;
							}
							temp = temp->left;
						}
					}
				}
				return _lastNode;
			}

			bool	isEmpty() const { return _number == 0; }
			void	print_inorder() { inorder(_root); };
			void	inorder(tree_node<T1, T2>* t)
			{
				if (t != NULL)
				{
					if (t->left)
						inorder(t->left);
				//	std::cout << "key: " << t->data.first << " value: " << t->data.second << " --- ";
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
			//		std::cout << "t = " << _smallestNode->data.first<<std::endl;
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
				//	std::cout << "t = " << _biggestNode->data.first<<std::endl;
					if (t->right)
						biggestNode(t->right);
				}
			}

			void				resetNode()
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
			}

			ft::pair<T1,T2>		insert(ft::pair<T1,T2> data)
			{
				tree_node<T1, T2>* temp = new tree_node<T1, T2>;
				temp->data = data;
				temp->left = NULL;
				temp->right = NULL;
				
			//	std::cout << "\nTREE insert " << data.first << std::endl;
			//	std::cout << "tree number ? " << this->_number << std::endl;
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
					//	std::cout << "boucle, parent = " << temp->parent->data.first<<std::endl;
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
				this->_number++;
				this->resetNode();
			//	this->_biggestNode->right = this->_lastNode;
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
			/*	std::cout << "\ncurr = " << curr->data.first << std::endl;
				if (curr != _root)
					std::cout << "curr parent = " << parent->data.first << std::endl;
				std::cout << "_root = " << _root->data.first << std::endl;
			
				if (curr->left)
					std::cout << "curr->left = "<<curr->left->data.first<<std::endl;				
				if (curr->right)
					std::cout << "curr->right = "<<curr->right->data.first<<std::endl;				
			*/
				if (curr == this->_root && this->_root->right == this->_lastNode && this->_root->left == this->_rendNode)
				{
			//		std::cout << "free 0 : " << curr->data.first<<std::endl;
					this->_number--;
					delete curr;
					return ;
				}
				else if ((curr->left == NULL && curr->right != NULL) ||
					(curr->left != NULL && (curr->right == NULL || curr->right == this->_lastNode)))
				{
			//		std::cout << "node with single child" << std::endl;
					if (curr->left == NULL && curr->right != NULL)
					{
				//	std::cout << "single child is at right" << std::endl;
						if (parent->left && parent->left == curr)
						{
				//			std::cout << "child is at left, curr = " <<curr->data.first<< std::endl;
				//			std::cout << "parent curr = " <<curr->parent->data.first<< std::endl;
				//			std::cout << "curr right= " <<curr->right->data.first<< std::endl;
							parent->left = curr->right;
							curr->right->parent = curr->parent;
				//			std::cout<< "free 1: "<< curr->data.first<<std::endl;
							delete curr;
						}
						else if (parent->right && parent->right == curr)
						{
					/*		if (curr->right == _lastNode)
								std::cout << "lastnode\n";
							std::cout << "child is at right" << std::endl;
					*/		parent->right = curr->right;
							curr->right->parent = curr->parent;
				//			std::cout<< "free 2: "<< curr->data.first<<std::endl;
							delete curr;
						}
						else
						{
			//				std::cout<<"root\n";
							this->_root = curr->right;
							this->_root->parent = this->_root;
				//			std::cout<< "free 3: "<< curr->data.first<<std::endl;
							delete curr;
						}
					}
					else
					{
				//		std::cout << "single child is at left" << std::endl;
						if (parent->left && parent->left == curr)
						{
							parent->left = curr->left;
				//			std::cout << "new parent left = "<< parent->left->data.first<<std::endl;
							curr->left->parent = curr->parent;
				//			std::cout<< "free 4: "<< curr->data.first<<std::endl;
							delete curr;
						}
						else if (parent->right && parent->right == curr)
						{
							parent->right = curr->left;
					//		std::cout << "new parent right = "<< parent->right->data.first<<std::endl;
							curr->left->parent = curr->parent;
				//			std::cout<< "free 5: "<< curr->data.first<<std::endl;
							delete curr;
						}
					}
				}
				else if (curr->left == NULL && curr->right == NULL)
				{
			//		std::cout << "leaf node" << std::endl;
					if (parent->left == curr)
						parent->left = NULL;
					else
						parent->right = NULL;
			//		std::cout<< "free 6: "<< curr->data.first<<std::endl;
					delete curr;					
				}
				//else if (curr->left != NULL && curr->left != this->_rendNode && curr->right != NULL && curr->right != this->_lastNode)
				else if (curr->left != NULL && curr->right != NULL && curr->right != this->_lastNode)
				{
			//		std::cout << "node with 2 children\n";
			//		std::cout << "replace node with smallest value in right subtree\n";
					tree_node<T1, T2>* chkr;
					chkr = curr->right;
					if ((chkr->left == NULL) && (chkr->right == NULL))
					{
			//			std::cout<< "free 7: "<< curr->data.first<<std::endl;
						curr->data = chkr->data;
						curr->right = NULL;
						delete chkr;
					}
					else
					{
				//		std::cout << "right child has children\n";
						if ((curr->right)->left != NULL)
						{
			//				std::cout << "if node's right child has a left child, move all the way down to locate smallest element\n";
							tree_node<T1, T2>* lcurr;
							tree_node<T1, T2>* lcurrp;
							lcurrp = curr->right;
							lcurr = (curr->right)->left;
							while (lcurr->left != NULL)
							{
								lcurrp = lcurr;
								lcurr = lcurr->left;
							}
				//			std::cout<< "lcurrp   : "<< lcurrp->data.first<<std::endl;
				//			std::cout<< "lcurr   : "<< lcurr->data.first<<std::endl<<std::endl;
							if (lcurr->right)
							{
								lcurrp->left = lcurr->right;
								lcurrp->left->parent = lcurrp;
				//				std::cout<< "lcurrp "<< lcurrp->left->data.first<<" left parent : "<< lcurrp->left->parent->data.first<<std::endl;
							}
							else
								lcurrp->left = NULL;
					//		std::cout<< "free 8: "<< curr->data.first<<std::endl;
							curr->data = lcurr->data;
							delete lcurr;
					/*		std::cout<< "curr   : "<< curr->data.first<<std::endl;
							std::cout<< "curr right  : "<< curr->right->data.first<<std::endl;
							std::cout<< "curr right right : "<< curr->right->right->data.first<<std::endl;
							if (curr->right->left)
							{
								std::cout<< "curr right left : "<< curr->right->left->data.first<<std::endl;
								std::cout<< "curr right left parent : "<< curr->right->left->parent->data.first<<std::endl;
							}*/
						}
						else
						{
				//			std::cout <<"else\n";
							tree_node<T1, T2>* tmp;
							tmp = curr->right;
				//			std::cout<< "free 9: "<< curr->data.first<<std::endl;
				//			std::cout <<"tmp right = "<<tmp->right->data.first<< std::endl;
				//			std::cout <<"tmp right parent = "<<tmp->right->parent->data.first<< " curr = " <<curr->data.first<<std::endl;
							curr->data = tmp->data;
							curr->right = tmp->right;
							tmp->right->parent = curr;
							delete tmp;
						}
					}
				}
				
				this->_number--;
				this->resetNode();
		//		std::cout<< "end remove, _root = " << _root->data.first << " smallest node = " << _smallestNode->data.first << " biggest node = " << _biggestNode->data.first<< "\n";
		//		std::cout<< "smallest node left = " << _smallestNode->left->data.first << " biggest node right = " << _biggestNode->right->data.first<< "\n";
		//		this->print_inorder();
			}

			void	removeExtremNodes()
			{
				delete this->_lastNode;
				delete this->_rendNode;
			}

		/*	void	clear(tree_node<T1, T2>* t)
			{
				if (t != NULL)
				{
					if (t->left)
						clear(t->left);
					if (t->right)
						clear(t->right);
							std::cout<< "free 10: "<< t->data.first<<std::endl;
					delete t;
				}
			}*/
	};
};

#endif