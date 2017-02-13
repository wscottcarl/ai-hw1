

// node class for a* search tree solving 8 tile puzzle

Class Node {
	private:
		Node* one;
		Node* two;
		Node* three;
		Node* four;
		Node* parent;
		int cost;
		int index;
		int distance;
		
	public:
		isNull();
		Node* getNext();
		Node* getParent();
	
};
