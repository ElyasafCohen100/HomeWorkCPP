/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 9 Question 2*/

#pragma once
#include"QueueVector.h"
#include"Queue.h"
#include <iostream>
using namespace std;

//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		int counter = 0;   //
		Node(T val) : value(val), left(NULL), right(NULL) {}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
	};		//end of Node class

	//data member of tree
	Node* root;

public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;

	int height();
	void reflect();
	void breadthScan();
private:
	//private function for not give acsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);

	//help methods
	int Hight(Node* current);
	void Reflect(Node* current);
	void BreadThscan(Node* current);
};

//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}


template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}


template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}


// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}


// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}


// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}


template <class T>
int Tree<T>::height() // deallocate tree
{
	if (isEmpty())
	{
		return -1;
	}
	else
	{
		return Hight(root);
	}

}


template<class T>
inline void Tree<T>::reflect()
{
	if (isEmpty())
	{
		return;
	}
	Reflect(root);
}


template<class T>
inline void Tree<T>::breadthScan()
{
	BreadThscan(Tree<T>::root);
}

template<class T>


inline int Tree<T>::Hight(Node* current)
{
	if (current == NULL)   //empty
		return -1;

	return max(Hight(current->right), Hight(current->left)) + 1;

}


template<class T>
inline void Tree<T>::Reflect(Node* current)
{
	if (current == NULL)
		return;
	else
	{
		Node* temp;
		Reflect(current->left);
		Reflect(current->right);

		//swap
		temp = current->left;
		current->left = current->right;
		current->right = temp;
	}

}


template<class T>
inline void Tree<T>::BreadThscan(Node* current)
{
	if (current == NULL)
		return;
	QueueVector<Node*> qe(50);
	qe.enqueue(root);

	while (!qe.isEmpty())
	{
		Node* node = qe.front();
		cout << node->value << " ";
		qe.dequeue();
		if (node->left != NULL)
			qe.enqueue(node->left);
		if (node->right != NULL)
			qe.enqueue(node->right);
	}
}

