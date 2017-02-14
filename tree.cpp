#include <iostream>
#include <queue>
#include "problem.h"
#include "node.h"
#include "tree.h"
#include <typeinfo>


Tree::Tree()
{
}

Tree::Tree(Node* node)
{
	head = node;
	nodes.push(*node);
	expansions = 0;
}

void Tree::solve()
{
//	this->head->getState()->showBoard();
//	this->nodes.front().getState()->showBoard();
//	nodes.pop();
	Node curr = nodes.front();
	nodes.pop();
	depth = curr.getDepth();
	while(not curr.getState()->isSolved())
	{
		curr.getState()->showBoard();
		curr.expand();
		curr.getState()->showBoard();
		nq(curr);
		expansions++;
		if(nodes.empty() and not curr.getState()->isSolved()) finish(1);
//		curr = nodes.front();
		depth = curr.getDepth();
//		nodes.pop();
	}
	finish();
}

void Tree::finish()
{
	std::cout << "Found solution with " << expansions << " node expansions\n";
	std::cout << "Found solution at " << depth << " depth\n";
}

void Tree::finish(int fail)
{
	std::cout << "Failed to find expand solution.\n";
}

void Tree::nq(Node n)
{
//	if(n.hasUp()) 
//	{
//		nodes.push(*n.getUp());
//	}
	if(n.hasDown()) 
	{
		nodes.push(*n.getDown());
	}
}
