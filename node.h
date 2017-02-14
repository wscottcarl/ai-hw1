
#ifndef NODE_H
#define NODE_H
// node class for a* search tree solving 8 tile puzzle

class Node {
	private:
		Node* frst;
		Node* scnd;
		Node* thrd;
		Node* frth;
		Node* prnt;
		int cost;
		int depth;
		Problem* state;
		int heuristic;
	public:
		bool isNull();
		bool operator<(const Node& n) { return this->heuristic < n.heuristic; };
		Node* expand();
		Node* getParent();
		Problem* getState();
		Node();
		Node(Problem*, int, int, Node*, int);
		int getDepth();
		bool hasUp();
		bool hasDown();
		Node* getUp();
		Node* getDown();
};

#endif
