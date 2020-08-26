#include "BinaryTree.h"
#include <iostream>	

using namespace std;
int counter;
	BinaryTree::BinaryTree() {
		root = NULL;
		counter = 0;
	}
	BinaryTree::~BinaryTree() {
		nullifyBinaryTree(root);
		
	}
	void BinaryTree::nullifyBinaryTree(Node*& tree) {
		if(tree != NULL) {
			 nullifyBinaryTree(tree->left);
			 nullifyBinaryTree(tree->right);
			 delete tree;
		}
	}
	
	void BinaryTree::insert(ItemType &key) {
		recursiveInsert(root, key);
		
	}
	void BinaryTree::recursiveInsert(Node*& tree, ItemType &key) {
			if(tree == NULL) {
				tree = new Node();
				tree->right = NULL;
				tree->left = NULL;
				tree->key = key;
		}
		else if(key.getValue() < tree->key.getValue()) {
			recursiveInsert(tree->left, key);
		}
		else {
			recursiveInsert(tree->right, key);
		}
	}
	void BinaryTree::deleteItem(ItemType &key) {
		
		recursiveFindItemToDelete(root, key);
}
	
	void BinaryTree::recursiveFindItemToDelete(Node*& tree, ItemType &key) { //cannot use retrieve method b/c need to use the found node
		if(tree == NULL) {
			cout << "Item not in tree" << endl;
		}
		else if(key.getValue() < tree->key.getValue()) {
			recursiveFindItemToDelete(tree->left, key);
		}
		else if(key.getValue() > tree->key.getValue()) {
			recursiveFindItemToDelete(tree->right, key);
		}
		else {
			if(key.getValue() == tree->key.getValue()) {
				deleteNode(tree);
			}
			else {
				cout << "Item not in tree" << endl;
			}
	
	}
	}
	void BinaryTree::deleteNode(Node*& tree) {
		ItemType newKey;
		Node* temp = tree;
		if(tree->left == NULL) {
			tree = tree->right;
			delete temp;
	}
		else if(tree->right == NULL) {
			tree = tree->left;
			delete temp;
		}
		else {
			getNextNode(tree->right, newKey);
			tree->key = newKey;
			recursiveFindItemToDelete(tree->right, newKey);
		}
	}
		void BinaryTree::getNextNode(Node *tree, ItemType& newKey) {
    while (tree->left != NULL) {
        tree = tree->left;
	}
	newKey = tree->key;
   
		}
	void BinaryTree::retrieve(ItemType &item, bool &found) {
		recursiveRetrieve(root, item, found);
	}
	void BinaryTree::recursiveRetrieve(Node* tree, ItemType &item, bool &found) {
		if(tree == NULL) {
			
		}
		else if(item.getValue() < tree->key.getValue()) {
			recursiveRetrieve(tree->left, item, found);
		}
		else if(item.getValue() > tree->key.getValue()) {
			recursiveRetrieve(tree->right, item, found);
		}
		else {
			if(item.getValue() == tree->key.getValue()) {
				found = true;
			}
			else {
				
			}
		}
		
	}
	void BinaryTree::preOrder() const {
		recursivePreOrder(root);
	}
	void BinaryTree::recursivePreOrder(Node* tree) const{
		if(tree != NULL) {
			cout << tree->key.getValue() << " ";
			recursivePreOrder(tree->left);
			recursivePreOrder(tree->right);
		}
	}
	void BinaryTree::inOrder() const {
		recursiveInOrder(root);
		
	}
	void BinaryTree::recursiveInOrder(Node* tree) const{
		if(tree != NULL) {
			recursiveInOrder(tree->left);
			cout << tree->key.getValue() << " ";
			recursiveInOrder(tree->right);
		}
	}
	void BinaryTree::postOrder() const {
		recursivePostOrder(root);
	}
	void BinaryTree::recursivePostOrder(Node* tree) const{
		if(tree != NULL) {
			recursivePostOrder(tree->left);
			recursivePostOrder(tree->right);
			cout << tree->key.getValue() << " ";
		}
	}
	int BinaryTree::getLength() const {
		
		return recursiveGetLength(root);
		
	}
	int BinaryTree::recursiveGetLength(Node* tree) const {
		if(tree == NULL) {
			return 0;
		}
		else {
			return recursiveGetLength(tree->left) + recursiveGetLength(tree->right) + 1;
			
		}
	}
	void BinaryTree::getSameLevelNonsiblings(ItemType &key) {
		int level = getLevelOfNode(root, key);
	}
	int BinaryTree::getLevelOfNode(Node *tree, ItemType &key) {

	}