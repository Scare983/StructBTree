#include "ItemType.h"
struct Node {
	ItemType key;
	Node *left;
	Node *right;
	Node getNextNode(Node* aNode);
};
	
class BinaryTree {

	public:
	
	BinaryTree();
	~BinaryTree();
	void nullifyBinaryTree(Node*& tree);
	void insert(ItemType &key);
	void recursiveInsert(Node*& tree, ItemType &key);
	void deleteItem(ItemType &key);
	void recursiveFindItemToDelete(Node*& tree, ItemType &key);
	void deleteNode(Node*& tree);
	void getNextNode(Node *tree, ItemType& newKey);
	void retrieve(ItemType &item, bool &found);
	void recursiveRetrieve(Node* tree, ItemType &item, bool &found);
	void preOrder() const;
	void recursivePreOrder(Node* tree) const;
	void inOrder() const;
	void recursiveInOrder(Node* tree) const;
	void postOrder() const;
	void recursivePostOrder(Node* tree) const;
	int getLength() const;
	int recursiveGetLength(Node* tree) const;
	void getSameLevelNonsiblings(ItemType &key);
	int getLevelOfNode(Node* tree, ItemType &key);
	
	private: 

	Node *root;
	int length;
	
	
};