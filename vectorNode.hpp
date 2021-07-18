/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorNode.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:25:54 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/19 12:25:55 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTORNODE_HPP__
# define __VECTORNODE_HPP__

namespace ft
{
	template <class T>
	class vectorNode
	{
		private:
			T			_node;
			vectorNode	*_nxtNode;
			vectorNode	*_prvNode;
		public:
			vectorNode() {};
			vectorNode(T& node, vectorNode *nxtNode) : _node(node), _nxtNode(nxtNode) {};
			
			vectorNode	*getNxt() const { return _nxtNode; };
			vectorNode	*getPrv() const { return _prvNode; };
			T 			getNode() const { return _node; };
	
			void		setNxt(vectorNode *nxtNode) { _nxtNode = nxtNode; };
			void		setPrv(vectorNode *prvNode) { _prvNode = prvNode; };
			void		setNode(T node) { _node = node; };
	
		//	vectorNode	*operator++(int)
		//		{ return this->getNxt(); };
		//		{ return _nxtNode->_node; };
			//	{ this = this->_nxtNode; std::cout << this->_node << std::endl; return *this; };
	};
}

#endif