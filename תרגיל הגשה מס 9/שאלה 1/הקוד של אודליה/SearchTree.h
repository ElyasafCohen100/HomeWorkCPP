/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 9          *
*                            *
******************************/
#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;
///--------------------------------------------------- SearchTree קובץ ההדר של -------------------------------------------------------///


//------------------ SearchTree פתיחת מחלקת הבן הגנרית --------------------//
template<class T>
class SearchTree : public Tree<T> { // Tree - יורשת מ SearchTree המחלקה

public:

	void add(T value);
	bool  search(T value) {
		return search(Tree<T>::root, value);
	}
	
	void remove(T val);
	T successor(T val);
	void delete_duplicates();


private:

	void add(typename Tree<T>::Node* current, T val);
	bool search(typename Tree<T>::Node* current, T val);

	typename Tree<T>::Node* Remove(typename Tree<T>::Node* current, T val);
	T min_value(typename Tree<T>::Node* root); //helping find the successor
	T  find_successor(typename Tree<T>::Node* root, typename Tree<T>::Node* succ);

	void delete_node(typename Tree<T>::Node* root); // helping to the remove method
	typename Tree<T>::Node* help_search(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* find_father(typename Tree<T>::Node* current, T val);
};


template <class T>
void SearchTree<T>::add(T val) {

	if (!Tree<T>::root) {
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}

	add(Tree<T>::root, val);
}


template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val) {

	if (current->value < val)
		if (!current->right) {
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else

		if (!current->left) {
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}


template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val) {

	if (!current) {
		return false;	// we got to the end of the tree and the val isn't exist
	}
	if (current->value == val) {
		return true;
	}
	if (current->value < val) {
		return search(current->right, val);
	}
	else {
		return search(current->left, val);
	}
}


template<class T>
inline void SearchTree<T>::remove(T val) {
	Tree<T>::root = Remove(Tree<T>::root, val);
}

//------------- לשנות משתנים -----------//
template<class T>
inline T SearchTree<T>::successor(T val) {
	typename Tree<T>::Node* current = help_search(this->root, val);
	if (current->right != NULL) {
		return min_value(current->right);
	}

	else {
		typename Tree<T>::Node* Curent_successor = NULL;
		typename Tree<T>::Node* father = this->root;

		while (father != current) {
			if (father->value > current->value) {
				Curent_successor = father; 
				father = father->left;
			}
			else {
				father = father->right;    
			}
		}

		if (Curent_successor == NULL) {
			throw "no successor";
		}
		else {
			return Curent_successor->value;
		}
	} 
}


template<class T>
inline void SearchTree<T>::delete_duplicates() {
	delete_node(this->root);
}


template<class T>
inline typename Tree<T>::Node* SearchTree<T>::Remove(typename Tree<T>::Node* current, T val) {

	if (current == NULL) {
		return current;
	}

	if (val < current->value) {  
		current->left = Remove(current->left, val);
	}

	else if (val > current->value) {   
		current->right = Remove(current->right, val);
	}

	else {

		if (current->left == NULL) {
			return current->right;
		}

		else if (current->right == NULL) {
			return current->left;
		}

		current->value = min_value(current->right);
		current->right = Remove(current->right, current->value);
	}

	return current;
}


template<class T>
inline T SearchTree<T>::min_value(typename Tree<T>::Node* root) {

	typename Tree<T>::Node* current = root;
	while (current->left != NULL) {
		current = current->left;
	}
	return current->value;
}


template<class T>
inline T SearchTree<T>::find_successor(typename Tree<T>::Node* root, typename Tree<T>::Node* n) {

	if (n->right != NULL) {
		return   min_value(n->right);
	}

	typename Tree<T>::Node* newSucc = NULL;
	while (root != NULL) {
		if (n->value < root->value) {
			newSucc = root;
			root = root->left;
		}

		else if (n->value > root->value) {
			root = root->right;
		}

		else {
			break;
		}
	}

	return newSucc->value;
}


template <class T>
void SearchTree<T>::delete_node(typename Tree<T>::Node* current) {

	static QueueVector<T>tempQueue(50);

	if (current) { //if current is not null 
		delete_node(current->left);
		tempQueue.enqueue(current->value);
		delete_node(current->right);
	}

	if (current == Tree<T>::root) {
		T help1, help2;

		if (!tempQueue.isEmpty()) {
			help1 = tempQueue.dequeue();
		}

		while (!tempQueue.isEmpty()) {
			help2 = tempQueue.dequeue();
			if (help1 == help2) {
				remove(help1);
			}

			help1 = help2;
		}
	}
}


template<class T>
inline typename Tree<T>::Node* SearchTree<T>::help_search(typename Tree<T>::Node* current, T val) {

	if (!current) {
		throw "no successor";
	}

	if (current->value == val) {
		return current;
	}

	if (current->value < val) {
		return help_search(current->right, val);
	}

	else {
		return help_search(current->left, val);
	}
}


template<class T>
inline typename Tree<T>::Node* SearchTree<T>::find_father(typename Tree<T>::Node* current, T val) {

	if (!current) {
		return nullptr;	
	}

	else if ((!(current->left) && !(current->right))) {
		return nullptr;
	}

	else if ((current->left && current->left->value == val) || (current->right && current->right->value == val)) {
		return current;
	}

	else if (current->value <= val) {
		return find_father(current->right, val);
	}

	else {
		return find_father(current->left, val);
	}
}

