#include "SearchTree.h"
#include <queue>
#include<vector>

BSearchTree::BSearchTree():root(nullptr)
{
}

Node* BSearchTree::getRoot()
{
	return root;
}

void BSearchTree::insert(int key)
{
	
		Node* newNode = new Node(key);
		Node* currentx = root;
		Node* currenty = nullptr;

		while (currentx != nullptr) {
			currenty = currentx;
			if (newNode->key < currentx->key)
				currentx = currentx->left;
			else
				currentx = currentx->right;
		}

		newNode->parent = currenty;
		if (currenty == nullptr)
			root = newNode;
		else if (newNode->key < currenty->key)
			currenty->left = newNode;
		else
			currenty->right = newNode;
	}

void BSearchTree::construct(std::vector<int> constrVect) {
	for (int i = 0; i < constrVect.size(); i++)
		insert(constrVect[i]);
}

Node* BSearchTree::maxim(Node* current)
{
	while (current->right != nullptr)
		current = current->right;

	return current;
}

Node* BSearchTree::minim(Node* current)
{
	while (current->left != nullptr)
		current = current->left;

	return current;
}

Node* BSearchTree::succesor(Node* x)
{
	Node* current = root;
	if (current->right != nullptr)
		current = minim(x->right);
	else {
		current = x->parent;
		while (current != nullptr && x == current->right) {
			x = current;
			current = current->parent;
		}
	}
	return current;
}

Node* BSearchTree::predecesor(Node* x)
{
	Node* current = root;
	if (current->left != nullptr)
		current = maxim(x->left);
	else {
		current = x->parent;
		while (current != nullptr && x == current->left) {
			x = current;
			current = current->parent;
		}
	}
	return current;
}

Node* BSearchTree::find(int key)
{
	Node* current = root;
	while (current != nullptr && current->key != key) {
		if (key < current->key)
			current = current->left;
		else
			current = current->right;
	}
	return current;
}
void BSearchTree::transplant(Node* z, Node* y)
{
	if (z->parent == nullptr)
		root = y;
	else if (z == z->parent->left)
		z->parent->left = y;
	else
		z->parent->right = y;

	if (y != nullptr)
		y->parent = z->parent;
}

void BSearchTree::del(int key) {
	Node* z = find(key);
	if (z == nullptr)
		return;

	if (z->left == nullptr)
		transplant(z, z->right);
	else if (z->right == nullptr)
		transplant(z, z->left);
	else
	{
		Node* y = succesor(z);
		if (y->parent != z)
		{
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
	}

	delete z;
}
void BSearchTree::preordine(Node* root) {
	if (root == nullptr) return;
	std::cout << root->key << " ";
	preordine(root->left);
	preordine(root->right);
}
void BSearchTree::inordine(Node* root) {
	if (root == nullptr) return;
	inordine(root->left);
	std::cout << root->key << " ";
	inordine(root->right);
}
void BSearchTree::postordine(Node* root) {
	if (root == nullptr) return;
	postordine(root->left);
	postordine(root->right);
	std::cout << root->key << " ";
}

void BSearchTree::niveluri() {
	if (root == nullptr) {
		return;
	}

	std::queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* current = q.front();
		q.pop();

		std::cout << current->key << " ";

		if (current->left != nullptr) {
			q.push(current->left);
		}

		if (current->right != nullptr) {
			q.push(current->right);
		}
	}
}
void BSearchTree::print_tree(int opt)
{
	switch (opt) {
	case 1:
		preordine(root);
		break;
	case 2:
		inordine(root);
		break;
	case 3:
		postordine(root);
		break;
	case 4:
		niveluri();
		break;
	default:
		std::cout << "Cazul nu exista\n";
		break;
	}
}

bool BSearchTree::empty() {
	if (root == nullptr)
		return true;
	return false;
}

void BSearchTree::clear()
{
	erase(root);
	root = nullptr;
}

void BSearchTree::erase(Node* x)
{
	if (x == nullptr)
		return;

	erase(x->left);
	erase(x->right);
	delete x;
}
