/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:05:58 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/10 15:05:59 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

#include <memory>
#include "vectorNode.hpp"
#include "vectorIte.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class	vector
	{
		public:
			typedef Allocator 							allocator_type;
			typedef typename Allocator::size_type 		size_type;
			typedef typename Allocator::difference_type difference_type;
			typedef typename Allocator::reference 		reference;
			typedef typename Allocator::const_reference const_reference;
			typedef ft::VectorIterator<T>				iterator;
		
			/********* COPLIEN *********/
			vector();
			vector(vector & other);
			vector &	operator=(vector & other);
			~vector();

			/********* ITERATION *********/
			iterator begin() { return VectorIterator<T>(_headNode); };
			iterator end() { 
				VectorIterator<T> tmp = VectorIterator<T>(_headNode);
				int count = 1;
				tmp = _headNode;
				while (count < _number)
				{
					tmp = tmp.getNodePtr()->getNxt();
					count++;
				}
				tmp = tmp.getNodePtr()->getNxt();
				tmp = NULL;
				return tmp; };
			iterator rbegin() { return this->end(); };
			iterator rend() { return VectorIterator<T>(_headNode); };

			/********* FUNCTIONS *********/
			T*		clone() const;
			void	clear();
			bool	empty();
			int		size() const; //size
			T&		front();
			T&		back();
			int		push_back(T newNode);
			void	pop_back();

		/********* GET SET *********/
	/*	vectorNode<T>	*getHeadNode() const { return _headNode; };
		int			*getNumber() const { return _number; };
		void		setHeadNode(vectorNode<T> *headNode) { _headNode = headNode; };
		void		setNumber(int number) { _number = number; };*/

		private:
			vectorNode<T>	*_headNode;
			int			_number;
	};

	template< typename T, typename Allocator >
	vector<T, Allocator>::vector()
	{
	//	std::cout << "vector default constructor" << std::endl;
		_number = 0;
	}
	
	template< typename T, typename Allocator >
	void	vector<T, Allocator>::clear()
	{
		int			count;
		int			total;

		total = _number;
		count = 1;
		while (count <= total)
		{
			this->pop_back();
			count++;
		}
	}

	template< typename T, typename Allocator >
	bool	vector<T, Allocator>::empty()
	{
		if (_number == 0)
			return true;
		return false;
	}
	
	template< typename T, typename Allocator >
	vector<T, Allocator>::~vector()
	{
	//	std::cout << "vector destructor, number = " << _number << std::endl;
		if (_headNode)
			this->clear();
	}


	template< typename T, typename Allocator >
	vector<T, Allocator>::vector(vector<T, Allocator> & other)
	{
		_number = 0;
		*this = other;
	}

	template< typename T, typename Allocator >
	vector<T, Allocator> &	vector<T, Allocator>::operator=(vector<T, Allocator> & other)
	{
		int		i;
		iterator it = other.begin();

		if (_headNode)
			this->clear();

		i = 0;
		while (i < other.size())
		{
			this->push_back(*it);
			it++;
			i++;
		}
		_number = other.size();
		return *this;
	}

	template< typename T, typename Allocator >
	int	vector<T, Allocator>::size() const
	{
		return _number;
	}

	template< typename T, typename Allocator >
	int		vector<T, Allocator>::push_back(T newNode)
	{
		vectorNode<T>	*tmp;

		if (_number == 0)
		{
			_headNode = new vectorNode<T>;
			_headNode->setNode(newNode);
			_headNode->setPrv(_headNode);
			_headNode->setNxt(NULL);
		
		//	std::cout << "FIRST node = " << _headNode->getNode() << std::endl;
		//	std::cout << "FIRST nxt = " << _headNode->getNxt() << std::endl;
		//	std::cout << "FIRST prv = " << _headNode->getPrv()->getNode() << std::endl;
		}
		else
		{
			tmp = _headNode;
			while (tmp->getNxt())
				tmp = tmp->getNxt();
			tmp->setPrv(tmp);
			tmp->setNxt(new vectorNode<T>);
			tmp->getNxt()->setNode(newNode);
			tmp->getNxt()->setNxt(NULL);
			
		//	std::cout << "\nELSE node = " << tmp->getNxt()->getNode() << std::endl;
		//	std::cout << "ELSE nxt = " << tmp->getNxt()->getNxt() << std::endl;
		//	std::cout << "ELSE prv = " << tmp->getPrv()->getNode() << std::endl;
		}
		_number++;
		return _number;
	}

	template< typename T, typename Allocator >
	void	vector<T, Allocator>::pop_back()
	{
		vectorNode<T>	*tmp;
		int				count;

		count = 1;
		if (_number == 1)
			delete _headNode;
		else
		{
			tmp = _headNode;
			while (count < _number - 2)
			{
				_headNode = _headNode->getNxt();
				count++;
			}
			_headNode->setPrv(_headNode);
			_headNode = _headNode->getNxt();
			_headNode->setNxt(NULL);

			std::cout << "POP node = " << _headNode->getNxt()->getNode() << std::endl;
			std::cout << "POP nxt = " << _headNode->getNxt()->getNxt() << std::endl;
			std::cout << "POP prv = " << _headNode->getPrv()->getNode() << std::endl;
			_headNode = tmp;
		}
		_number--;
	}

	//std::ostream & operator<<(std::ostream & o, typename ft::list<int>::t_list const & to_print)
/*	std::ostream & operator<<(std::ostream & o, typename ft::list<int>::iterator const & to_print)
	{
		return o << to_print._node;
	}*/
}

#endif
