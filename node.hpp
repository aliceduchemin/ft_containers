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
	//	private:
		public:
			T			_node;
			listNode	*_nxtNode;
		public:
			listNode() { std::cout << "node default const\n"; };
			listNode(T& node, listNode *nxtNode) : _node(node), _nxtNode(nxtNode) {};
			listNode *getNxt() const { std::cout << "gtnxt\n"; return _nxtNode; };
	};
}

#endif