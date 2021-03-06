/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIte.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:59:17 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/19 11:59:23 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTORITE_HPP__
# define __VECTORITE_HPP__

namespace ft
{
	template < class Category,		//iterator::iterator_category
			   class T,				//iterator::value_type
			   class Distance,		//iterator::difference_type
			   class Pointer,		//iterator::pointer
			   class Reference		//iterator::reference
			   > struct iterator;

	template < class Category, class T, class Distance = std::ptrdiff_t,
			   class Pointer = T*, class Reference = T& >
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <bool is_integral, typename T>
	struct is_integral_base {
		typedef T type;
		static const bool value = is_integral;
	};

	template<typename> struct is_integral_t : public is_integral_base<false, bool> {};

	template<> struct is_integral_t<bool> : public is_integral_base<true, bool> {};
	template<> struct is_integral_t<char> : public is_integral_base<true, char> {};
	template<> struct is_integral_t<wchar_t> : public is_integral_base<true, wchar_t> {};
	template<> struct is_integral_t<short> : public is_integral_base<true, short> {};
	template<> struct is_integral_t<int> : public is_integral_base<true, int> {};
	template<> struct is_integral_t<long> : public is_integral_base<true, long> {};
	template<> struct is_integral_t<long long> : public is_integral_base<true, long long> {};

	template<typename T> struct is_integral: is_integral_t<T> {};

	template < class Iterator >
	struct iterator_traits {
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	template < class T >
	struct iterator_traits<T*> {
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef random_access_iterator_tag		iterator_category;
	};

	template < class T >
	struct iterator_traits<const T*> {
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef random_access_iterator_tag		iterator_category;
	};

	template <class T>
	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
		
		/********* COPLIEN *********/
		// copy-constructible, copy-assignable and destructible (Forward : default-constructible)
		random_access_iterator() : _nodePtr(0) { };
		random_access_iterator(pointer nodePtr) : _nodePtr(nodePtr) { };
		random_access_iterator<T> & operator=(random_access_iterator<T> const & other)
			{ _nodePtr = other._nodePtr; return *this; };
		random_access_iterator(random_access_iterator<T> const & other)
			{ *this = other; };
		~random_access_iterator() {};
	
		/********* ITERATORS *********/
		// can be incremented
		random_access_iterator	operator++(int) //i++
			{ random_access_iterator tmp(*this); operator++(); return tmp; };
		random_access_iterator &operator++() //++i
			{ this->_nodePtr++; return *this; }

		/********* INPUT ITERATORS *********/
		// Supports equality/inequality comparisons
		bool operator==(random_access_iterator const & other) const
			{ return this->_nodePtr == other._nodePtr; };
		bool operator!=(random_access_iterator const & other) const
			{ return this->_nodePtr != other._nodePtr; };
		// Can be dereferenced as an rvalue
		reference operator*() const
			{ return *this->_nodePtr; };
		pointer operator->() const
			{ return *this->_nodePtr; };
		pointer getNodePtr() const
			{ return this->_nodePtr; };

		/********* OUTPUT ITERATORS *********/
		// Can be dereferenced as an lvalue (only mutable iterator types)
		//*a = t
		//*a++ = t

		/********* FORWARD ITERATORS *********/
		// Multipass: neither dereferencing nor incrementing affects dereferenceability 
		//b=; *a++; *b

		/********* BIDIRECTIONAL ITERATORS *********/
		// Can be decremented
		random_access_iterator &	operator--()
			{ this->_nodePtr--; return *this; }
		random_access_iterator	operator--(int)
			{ random_access_iterator tmp(*this); operator--(); return tmp; };
		//*a--

		/********* RANDOM ACCESS ITERATORS *********/
		// Supports arithmetic operators + and -
		difference_type operator +(random_access_iterator other)
			{ return (this->_nodePtr + other._nodePtr); };
		difference_type operator -(random_access_iterator other)
			{ return (this->_nodePtr - other._nodePtr); };
		friend random_access_iterator operator+(random_access_iterator const & other, int n)
			{ return (other._nodePtr + n); };
		friend random_access_iterator operator+(int n, random_access_iterator const & other)
			{ return (other._nodePtr + n); };
		friend random_access_iterator operator-(random_access_iterator const & other, int n)
			{ return (other._nodePtr - n); };
		friend random_access_iterator operator-(int n, random_access_iterator const & other)
			{ return (other._nodePtr - n); };

		// Supports inequality comparisons (<, >, <= and >=?? between iterators)
		bool operator<(random_access_iterator const & other) const
			{ return this->_nodePtr < other._nodePtr; };
		bool operator<=(random_access_iterator const & other) const
			{ return this->_nodePtr <= other._nodePtr; };
		bool operator>(random_access_iterator const & other) const
			{ return this->_nodePtr > other._nodePtr; };
		bool operator>=(random_access_iterator const & other) const
			{ return this->_nodePtr >= other._nodePtr; };
		
		// Supports compound assignment operations += and -=
		random_access_iterator	&operator+=(int n)
			{	int i = 0;
				while (i < n) {	operator++(); i++; }
				return *this; };
		random_access_iterator	&operator-=(int n)
			{	int i = 0;
				while (i < n) {	operator--(); i++; }
				return *this; };

		// Supports offset dereference operator ([])
		reference operator[](int n)	{ return (*(*this + n)); }

		private:
			pointer	_nodePtr;
	};

	/*********** CONST ITERATOR ***********/
	template <class T>
	class const_random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
		
		/********* COPLIEN *********/
		const_random_access_iterator() : _nodePtr(0) { };
		const_random_access_iterator(pointer nodePtr) : _nodePtr(nodePtr) { };
		const_random_access_iterator<T> & operator=(const_random_access_iterator<T> const & other)
			{ _nodePtr = other._nodePtr; return *this; };
		const_random_access_iterator<T> & operator=(random_access_iterator<T> const & other)
			{ _nodePtr = other.getNodePtr(); return *this; };
		const_random_access_iterator(const_random_access_iterator<T> const & other)
			{ *this = other; };
		const_random_access_iterator(random_access_iterator<T> const & other)
			{ *this = other; };
		~const_random_access_iterator() {};

		/********* ITERATORS *********/
		const_random_access_iterator	operator++(int) //i++
			{ const_random_access_iterator tmp(*this); operator++(); return tmp; };
		const_random_access_iterator &	operator++() //++i
			{ this->_nodePtr++; return *this; }
		const_random_access_iterator	operator--(int)
			{ const_random_access_iterator tmp(*this); operator--(); return tmp; };
		const_random_access_iterator &	operator--()
			{ this->_nodePtr--; return *this; }

		bool operator==(const_random_access_iterator const & other) const
			{ return this->_nodePtr == other._nodePtr; };
		bool operator!=(const_random_access_iterator const & other) const
			{ return this->_nodePtr != other._nodePtr; };
		reference operator*() const
			{ return *this->_nodePtr; };
		pointer operator->() const
			{ return *this->_nodePtr; };
		pointer getNodePtr() const
			{ return this->_nodePtr; };
		
		difference_type operator +(const_random_access_iterator other)
			{ return (this->_nodePtr + other._nodePtr); };
		difference_type operator -(const_random_access_iterator other)
			{ return (this->_nodePtr - other._nodePtr); };
		friend const_random_access_iterator operator+(const_random_access_iterator const & other, int n)
			{ return (other._nodePtr + n); };
		friend const_random_access_iterator operator+(int n, const_random_access_iterator const & other)
			{ return (n + other._nodePtr); };
		friend const_random_access_iterator operator-(const_random_access_iterator const & other, int n)
			{ return (other._nodePtr - n); };
		friend const_random_access_iterator operator-(int n, const_random_access_iterator const & other)
			{ return (other._nodePtr - n); };

		/********* RANDOM ACCESS ITERATORS *********/
		bool operator<(const_random_access_iterator const & other) const
			{ return this->_nodePtr < other._nodePtr; };
		bool operator<=(const_random_access_iterator const & other) const
			{ return this->_nodePtr <= other._nodePtr; };
		bool operator>(const_random_access_iterator const & other) const
			{ return this->_nodePtr > other._nodePtr; };
		bool operator>=(const_random_access_iterator const & other) const
			{ return this->_nodePtr >= other._nodePtr; };

		const_random_access_iterator	&operator+=(int n)
			{	int i = 0;
				while (i < n) {	operator++(); i++; }
				return *this; };
		const_random_access_iterator	&operator-=(int n)
			{	int i = 0;
				while (i < n) {	operator--(); i++; }
				return *this; };

		private:
			pointer	_nodePtr;
	};

	/*********** REVERSE ITERATOR ***********/
	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef	Iterator	iterator_type;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		
		/********* COPLIEN *********/
		reverse_iterator() : _it(0) { };
		explicit reverse_iterator (iterator_type other) : _it(other) { };//HERE
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it)
			{	*this = rev_it._it;	};
		template <class Iter>
		reverse_iterator& operator=(const reverse_iterator<Iter>& rev_it)
			{	_it = rev_it._it; return *this;	};
		reverse_iterator(pointer other) : _it(other) { };
		~reverse_iterator() {};
	
		/********* ITERATORS *********/
		iterator_type base() const { return _it; };
		reverse_iterator &	operator++() //++i
			{ this->_it--; return *this; }
		reverse_iterator	operator++(int) //i++
			{ reverse_iterator tmp(*this); operator++(); return tmp; };
		reverse_iterator &	operator--()
			{ this->_it++; return *this; }
		reverse_iterator	operator--(int)
			{ reverse_iterator tmp(*this); operator--(); return tmp; };

		bool operator==(reverse_iterator const & other) const
			{ return this->_it == other._it; };
		bool operator!=(reverse_iterator const & other) const
			{ return this->_it != other._it; };
		reference operator*() const
			{ iterator_type tmp(this->_it); tmp--; return *tmp; };
		pointer operator->() 
			{ iterator_type tmp(this->_it); tmp--; return *tmp; };
		iterator_type getNodePtr() const
			{ iterator_type tmp(this->_it); tmp--; return tmp; };
		
		difference_type operator +(reverse_iterator other)
			{ return (this->_it + other._it); };//HERE
		difference_type operator -(reverse_iterator other)
			{ return (this->_it - other._it); };
		friend reverse_iterator operator+(reverse_iterator const & other, int n)
			{ return reverse_iterator(other._it - n); };
		friend reverse_iterator operator+(int n, reverse_iterator const & other)
			{ return reverse_iterator(other._it - n); };
		friend reverse_iterator operator-(reverse_iterator const & other, int n)
			{ return reverse_iterator(other._it + n); };
		friend reverse_iterator operator-(int n, reverse_iterator const & other)
			{ return reverse_iterator(other._it + n); };

		bool operator<(reverse_iterator const & other) const
			{ return this->_it < other._it; };
		bool operator<=(reverse_iterator const & other) const
			{ return this->_it <= other._it; };
		bool operator>(reverse_iterator const & other) const
			{ return this->_it > other._it; };
		bool operator>=(reverse_iterator const & other) const
			{ return this->_it >= other._it; };

		reverse_iterator	&operator+=(int n)
			{	
				this->_it -= n;
				return *this;
			};
		reverse_iterator	&operator-=(int n)
			{	
				this->_it += n;
				return *this;
			};
		
		reference operator[](int n)	{ return (*(*this + n)); }

		private:
			iterator_type _it;
	};

	/*********** CONST REVERSE ITERATOR ***********/
	template <class Iterator>
	class const_reverse_iterator : ft::reverse_iterator<Iterator>
	{
		public:
			typedef	Iterator	iterator_type;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		
		/********* COPLIEN *********/
		const_reverse_iterator() : _it(0) { };
		explicit const_reverse_iterator (iterator_type other) : _it(other)	{ };//HERE
		template <class Iter>
		const_reverse_iterator(const const_reverse_iterator<Iter>& rev_it)
			{	*this = rev_it._it;	};
		template <class Iter>
		const_reverse_iterator(const reverse_iterator<Iter>& rev_it)
			{	_it = rev_it.getNodePtr();	};
		template <class Iter>
		const_reverse_iterator& operator=(const const_reverse_iterator<Iter>& rev_it)
			{	_it = rev_it._it; return *this;	};
		template <class Iter>
		const_reverse_iterator& operator=(const reverse_iterator<Iter>& rev_it)
			{	_it = rev_it.getNodePtr(); return *this;	};
		const_reverse_iterator(pointer other) : _it(other) { };
		~const_reverse_iterator() {};
	
		/********* ITERATORS *********/
		iterator_type base() const { return _it; };
		const_reverse_iterator &	operator++() //++i
			{ this->_it = this->_it - 1; return *this; }
		const_reverse_iterator	operator++(int) //i++
			{ const_reverse_iterator tmp(*this); operator++(); return tmp; };
		const_reverse_iterator &	operator--()
			{ this->_it = this->_it + 1; return *this; }
		const_reverse_iterator	operator--(int)
			{ const_reverse_iterator tmp(*this); operator--(); return tmp; };

		bool operator==(const_reverse_iterator const & other) const
			{ return this->_it == other._it; };
		bool operator!=(const_reverse_iterator const & other) const
			{ return this->_it != other._it; };
		reference operator*() const
			{ iterator_type tmp(this->_it);/* tmp--; */return *tmp; };
		pointer operator->() 
			{ iterator_type tmp(this->_it);/* tmp--; */return *tmp; };
		
		difference_type operator +(const_reverse_iterator other)
			{ return (this->_it + other._it); };
		difference_type operator -(const_reverse_iterator other)
			{ return (this->_it - other._it); };
		friend const_reverse_iterator operator+(const_reverse_iterator const & other, int n)
			{ return const_reverse_iterator(other._it - n); };
		friend const_reverse_iterator operator+(int n, const_reverse_iterator const & other)
			{ return const_reverse_iterator(other._it - n); };
		friend const_reverse_iterator operator-(const_reverse_iterator const & other, int n)
			{ return const_reverse_iterator(other._it + n); };
		friend const_reverse_iterator operator-(int n, const_reverse_iterator const & other)
			{ return const_reverse_iterator(other._it + n); };

		bool operator<(const_reverse_iterator const & other) const
			{ return this->_it < other._it; };
		bool operator<=(const_reverse_iterator const & other) const
			{ return this->_it <= other._it; };
		bool operator>(const_reverse_iterator const & other) const
			{ return this->_it > other._it; };
		bool operator>=(const_reverse_iterator const & other) const
			{ return this->_it >= other._it; };

		const_reverse_iterator	&operator+=(int n)
			{	
				this->_it -= n;
				return *this;
			};
		const_reverse_iterator	&operator-=(int n)
			{	
				this->_it += n;
				return *this;
			};
		
		reference operator[](int n)	{ return (*(*this + n)); }

		private:
			iterator_type _it;
	};

	/********* COMPARATORS *********/
	template< class T >
	bool	operator==(const ft::random_access_iterator<T>& lhs,
						const ft::const_random_access_iterator<T>& rhs)
	{	return lhs.getNodePtr() == rhs.getNodePtr();	};

	template< class T >
	bool	operator!=(const ft::random_access_iterator<T>& lhs,
						const ft::const_random_access_iterator<T>& rhs)
	{	return (!(lhs == rhs)) ? true : false;	}

	template< class T >
	bool	operator<(const ft::random_access_iterator<T>& lhs,
						const ft::const_random_access_iterator<T>& rhs)
	{	return (lhs.getNodePtr() < rhs.getNodePtr()) ? true : false;	}

	template< class T >
	bool	operator<=(const ft::random_access_iterator<T>& lhs,
						const ft::const_random_access_iterator<T>& rhs)
	{	return (lhs.getNodePtr() <= rhs.getNodePtr()) ? true : false;	}

	template< class T >
	bool	operator>(const ft::random_access_iterator<T>& lhs,
						const ft::const_random_access_iterator<T>& rhs)
	{	return (lhs.getNodePtr() > rhs.getNodePtr()) ? true : false;	}

	template< class T >
	bool	operator>=(const ft::random_access_iterator<T>& lhs,
						const ft::const_random_access_iterator<T>& rhs)
	{	return (lhs.getNodePtr() >= rhs.getNodePtr()) ? true : false;	}
}
#endif