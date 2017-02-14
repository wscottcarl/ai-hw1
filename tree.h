

#ifndef TREE_H
#define TREE_H

#include <queue>

class Tree 
{
private:
	Node* head;
	std::queue<Node> nodes;
	int expansions;
	int depth;
	void nq(Node);
public:
	void solve();
	void finish();
	void finish(int);
	Tree();
	Tree(Node*);
};

#endif
