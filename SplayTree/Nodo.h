#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:

	T key;
	Node<T>* parent;
	Node<T>* right;
	Node<T>* left;
	
	Node(T key) {
		this->key = key;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
};