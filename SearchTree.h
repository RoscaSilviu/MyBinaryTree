#pragma once
#include <iostream>
#include <vector>
struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;
    Node(int key) : key(key), parent(nullptr), left(nullptr), right(nullptr) {}
};


class BSearchTree
{
private:
    Node* root;

public:
    BSearchTree();
    Node* getRoot();
    void insert(int key);
    Node* maxim(Node* current);
    Node* minim(Node* current);
    Node* succesor(Node* x);
    Node* predecesor(Node* x);
    Node* find(int key);
    void transplant(Node* z, Node* y);
    void del(int key);
    void erase(Node* x);
    void print_tree(int opt);
    void preordine(Node* root);
    void inordine(Node* root);
    void postordine(Node* root);
    void niveluri();
    void construct(std::vector<int> constrVect);
    bool empty();
    void clear();

};

