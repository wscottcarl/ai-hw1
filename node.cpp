#include <iostream>
#include "problem.h"
#include "node.h"
#include <cstddef>

int h1(Node*);

Node::Node()
{
	this->frst = NULL;
	this->scnd = NULL;
	this->thrd = NULL;
	this->frth = NULL;
	this->prnt = NULL;
	this->state = NULL;
	this->cost = 0;
	this->depth = 0;
	this->heuristic = 0;
}

Node::Node(Problem* prob, int cst, int dpth, Node *parent, int hstc)
{
	this->state = prob;
	this->cost = cst;
	this->depth = dpth;
	this->prnt = parent;
	this->heuristic = hstc;
	this->frst = NULL;
	this->scnd = NULL;
	this->thrd = NULL;
	this->frth = NULL;
}

bool Node::isNull()
{
	if(this->state == NULL) return true;
	return false;
}

Node* Node::expand()
{
// to expand, use front of queue
	
//	if(state->up() != NULL) 
//	{
//		frst = new Node(state->up(), cost+1, depth+1, this, h1(state->up()));
//	}
	if(state->down() != NULL) 
	{
		std::cout << "Debugging\n";
		state->showBoard();
		std::cout << scnd << std::endl;
//		Node* tmp = new Node(this->state, cost+1, depth+1, NULL, 0);
		this->scnd = new Node();
		std::cout << "Debugging\n";
	}
/*	if(state->left() != NULL) 
	{
		
	}
	if(state->right() != NULL) 
	{
		
	}*/
	return NULL;
}

Node* Node::getParent()
{
	return this->prnt;
}

Problem* Node::getState()
{
	return this->state;
}

int Node::getDepth()
{ 	return this->depth; 	}

int h1(Node* n) 
{ 
// Tiles out of row and column heuristic
	
	return n->getState()->outOfRow() + n->getState()->outOfCol();
}

bool Node::hasUp()
{
	if(frst == NULL) return false;
	else return true;
}

Node *Node::getUp()
{ return frst; }

bool Node::hasDown()
{
	if(scnd == NULL) return false;
	else return true;
}

Node *Node::getDown()
{ return scnd; }
