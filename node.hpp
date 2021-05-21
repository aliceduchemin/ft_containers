/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:25:54 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/19 12:25:55 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __NODE_HPP__
# define __NODE_HPP__

namespace ft
{
	template <class T>
	class listNode
	{
		private:
			T			_node;
			listNode	*_nxtNode;
		public:
			listNode() {};
			listNode(T& node, listNode *nxtNode) : _node(node), _nxtNode(nxtNode) {};
			
			listNode	*getNxt() const { /*std::cout << "get nxt\n"; */return _nxtNode; };
			T 			getNode() const { /*std::cout << "get node\n";*/ return _node; };
	
			void		setNxt(listNode *nxtNode) {/* std::cout << "set nxt\n";*/ _nxtNode = nxtNode; };
			void		setNode(T node) { /*std::cout << "set node\n"; */_node = node; };
	};
}

#endif