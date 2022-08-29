/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 9 Question 2*/

#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{

public:
	void add(T value);
	bool  search(T value)
	{
		return search(Tree<T>::root, value);
	}
	void remove(T val);
	T successor(T val);
	void deleteDuplicates();
private:
	void add(typename Tree<T>::Node* current, T val);
	bool  search(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* Remove(typename Tree<T>::Node* current, T val);
	T minimumValue(typename Tree<T>::Node* root);//helping find the successor
	T  findSuccessor(typename Tree<T>::Node* root, typename Tree<T>::Node* succ);
	void deleteNode(typename Tree<T>::Node* root);// helping to the remove method
	typename Tree<T>::Node* helpSearch(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* Findfather(typename Tree<T>::Node* current, T val);
};


template <class T>
void SearchTree<T>::add(T val)
{
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}


template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{

	if (current->value < val)

		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);

			return;
		}
		else add(current->right, val);
	else

		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);

			return;
		}
		else add(current->left, val);
}


template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{

	if (!current)
		return false;	// we got to the end of the tree and the val isn't exist
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}


template<class T>
inline void SearchTree<T>::remove(T val)
{

	Tree<T>::root = Remove(Tree<T>::root, val);

}


template<class T>
inline T SearchTree<T>::successor(T val)
{
	typename Tree<T>::Node* current = helpSearch(this->root, val);
	if (current->right != NULL) { 
		return minimumValue(current->right);
	}
	else
	{
		typename Tree<T>::Node* Curentsuccessor = NULL;
		typename Tree<T>::Node* father = this->root;
		while (father != current)
		{
			if (father->value > current->value)
			{
				Curentsuccessor = father;   //if the fathe is bigger so  he is the succsesor and we will continue on left
				father = father->left;
			}
			else
				father = father->right;     //if the father is smaller than current go to right side
		}
		if (Curentsuccessor == NULL)
		{
			throw "no successor";
		}
		else
		{
			return Curentsuccessor->value; 
		}
	}
}


template<class T>
inline void SearchTree<T>::deleteDuplicates()
{
	deleteNode(this->root);
}


template<class T>
inline typename Tree<T>::Node* SearchTree<T>::Remove(typename Tree<T>::Node* current, T val)
{

	if (current == NULL)
		return current;

	if (val < current->value)    //if the val < current root
	{
		current->left = Remove(current->left, val);

	}
	else if (val > current->value)  //if the val > current root
	{
		current->right = Remove(current->right, val);
	}

	else
	{                      
		if (current->left == NULL)
			return current->right;
		else if (current->right == NULL)
			return current->left;

		
		current->value = minimumValue(current->right);

		
		current->right = Remove(current->right, current->value);
	}

	return current;
}


template<class T>
inline T SearchTree<T>::minimumValue(typename Tree<T>::Node* root)
{
	typename Tree<T>::Node* current = root;
	
	while (current->left != NULL) {
		current = current->left;
	}
	return current->value;
}


template<class T>
inline T SearchTree<T>::findSuccessor(typename Tree<T>::Node* root, typename Tree<T>::Node* n)
{
	if (n->right != NULL)   
	{

		return   minimumValue(n->right);
	}

	typename Tree<T>::Node* newSucc = NULL;

	while (root != NULL)
	{
		if (n->value < root->value)
		{
			newSucc = root;
			root = root->left;
		}
		else if (n->value > root->value)
			root = root->right;
		else
			break;
	}

	return newSucc->value;
}


template<class T>
void SearchTree<T>::deleteNode(typename Tree<T>::Node* current)
{
	static QueueVector<T>tempQueue(50);
	if (current) //if current is not null 
	{
		deleteNode(current->left);
		tempQueue.enqueue(current->value);
		deleteNode(current->right);
	}
	if (current == Tree<T>::root)
	{
		T help1, help2;
		if (!tempQueue.isEmpty())
		{
			help1 = tempQueue.dequeue();
		}
		while (!tempQueue.isEmpty())
		{
			help2 = tempQueue.dequeue();
			if (help1 == help2)
			{
				remove(help1);
			}
			help1 = help2;
		}
	}
}


template<class T>
inline typename Tree<T>::Node* SearchTree<T>::helpSearch(typename Tree<T>::Node* current, T val)
{
	if (!current)
		throw"no successor"; // we got to the end of the tree and the val isn't exist
	if (current->value == val)
		return current;
	if (current->value < val)
		return helpSearch(current->right, val);
	else
		return helpSearch(current->left, val);
}

template<class T>
inline typename Tree<T>::Node* SearchTree<T>::Findfather(typename Tree<T>::Node* current, T val)
{
	if (!current)
		return nullptr;	//isn't exist
	else if ((!(current->left) && !(current->right)))
		return nullptr;	//isn't exist
	else if ((current->left && current->left->value == val) || (current->right && current->right->value == val))  //if one of the childrens is the value the current is the father 
		return current;
	else if (current->value <= val)
		return Findfather(current->right, val);
	else
		return Findfather(current->left, val);
}

