#pragma once

#include <iostream>
#include "Nodo.h"
using namespace std;

template <typename T>
class SplayTree{
private:

    Node<T>* root; // Nodo raíz del SplayTree

    T findDeleteMinimum(T key, Node<T>* tree) { // funcion que busca el menor valor de un arbol, lo devuelve y borra el nodo
        Node<T>* x = tree;
        while (x->left != nullptr || x->right != nullptr) {
            if (x->left) {
                x = x->left;
            }
            else {
                swap(x->key, x->right->key);
                x = x->right;
            }
        } 
        T ret = x->key;
        if(x == x->parent->left)
            x->parent->left = nullptr;
        else 
            x->parent->right = nullptr;
        delete(x);
        return ret;
    }

    T findDeleteMaximum(T key, Node<T>* tree) { // funcion que busca el mayor valor de un arbol, lo devuelve y borra el nodo
        Node<T>* x = tree;
        while (x->left != nullptr || x->right != nullptr) {
            if (x->right) {
                x = x->right;
            }
            else {
                swap(x->key, x->left->key);
                x = x->left;
            }
        }
        T ret = x->key;

        if (x == x->parent->left)
            x->parent->left = nullptr;
        else
            x->parent->right = nullptr;
        delete(x);
        return ret;
    }

    // Las rotaciones se han implementado siguiendo los apuntes de la asignatura

    void rightRotate(Node<T>* node) {
        if (node == nullptr) 
            return;
        else {
            Node<T>* aux = node->right;
            node->right = aux->left;
            if (aux->left) 
                aux->left->parent = node;
            
            aux->parent = node->parent;
            if (node->parent == nullptr) 
                this->root = aux;
            
            else if (node == node->parent->left) 
                node->parent->left = aux;
            
            else if (node == node->parent->right) 
                node->parent->right = aux;
            
            aux->left = node;
            node->parent = aux;
        }
    }

    void leftRotate(Node<T>* node) {
        Node<T>* aux = node->left;
        node->left = aux->right;
        if (aux->right) 
            aux->right->parent = node;
        
        aux->parent = node->parent;
        if (node->parent == nullptr) 
            this->root = aux;
        
        else if (node == node->parent->left) 
            node->parent->left = aux;
        
        else if (node == node->parent->right) 
            node->parent->right = aux;
        
        aux->right = node;
        node->parent = aux;
    }
    

    void splay(Node<T>* node) {

        while (node && node->parent) { 
            if (!node->parent->parent) {// Si el nodo no tiene "abuelo" entonces se le realizarán rotaciónes "simples"
                if (node == node->parent->left) {
                    leftRotate(node->parent);
                }
                else if (node == node->parent->right) {
                    rightRotate(node->parent);
                }
            }

            // Si tiene "abuelo" se le realizará la rotación correspondiente a la situación del nodo

            else if (node == node->parent->left && node->parent == node->parent->parent->left) {
                leftRotate(node->parent->parent);
                leftRotate(node->parent);
            }
            else if (node == node->parent->right && node->parent == node->parent->parent->right) {
                rightRotate(node->parent->parent);
                rightRotate(node->parent);
            }
            else if (node == node->parent->left && node->parent == node->parent->parent->right) {
                leftRotate(node->parent);
                rightRotate(node->parent);
            }
            else if (node == node->parent->right && node->parent == node->parent->parent->left) {
                rightRotate(node->parent);
                leftRotate(node->parent);
            }
        }
    }

public:

    SplayTree() { // Constructor 
        this->root = nullptr;
    }
 
    void insert(T key) {  

        Node<T>* newN = new Node<T>(key);
        Node<T>* par = nullptr;
        Node<T>* ch = this->root;

        if (ch == nullptr) {
            ch = newN;  
        }
        while (ch != nullptr && ch->key != key) {
            par = ch;
            key < ch->key? ch = ch->left: ch = ch->right; // Nos movemos a la izquierda o derecha dependiendo de donde debamos 
        }

        newN->parent = par;
        if (par == nullptr)
            this->root = newN; // primer nodo insertado en el arbol
        else if (key < par->key)
            par->left = newN;
        else
            par->right = newN;

        // Todo el rato guardamos el nodo par porque el nuevo nodo se incluye en el arbol desde el padre

         splay(newN);
    }

    bool find(T key) {

        Node<T> *node = this->root;

        if (this->root == nullptr) // Si no habia nodos en el arbol no se hace nada
            return false;

        while (node->key != key) { // Se busca el nodo hasta encontrarlo o llegar a un punto en el que sabemos que no va a estar
            if (node->left && key < node->key) 
                node = node->left;
            else if (node->right && key > node->key)
                node = node->right;
            else
                break;
        }
        splay(node); // Flotamos el nodo
            
        return (node->key == key);
    }
    
    void erase(T key) {
        
        Node<T>* node = this->root;
        Node<T>*parent = nullptr;
        
        if (this->root == nullptr)
            return;

        else if (this->root->key == key) {
            this->root = nullptr;
        }
            
        while (node->key != key) { // Buscamos el nodo...
            if (node->left && key < node->key)
                node = node->left;
            else if (node->right && key > node->key)
                node = node->right;
            else
                break;
        }
        parent = node->parent;
		
		if(node->key != key){ // Si el nodo que queremos borrar no esta en el arbol, entonces lo que hacemos es flotar el nodo mas cercano
			splay(node);
			return;
		}
		
        if (node->left == nullptr && node->right == nullptr) {  // Si el nodo es una hoja lo borramos 
            if (parent->left == node) parent->left = nullptr;
            else parent->right = nullptr;
            delete(node);
        }
        else if (node->right != nullptr)  // Si el nodo tiene hijo derecho, cambiamos su valor por el menor hijo derecho y borramos
            node->key = findDeleteMinimum(key, node->right);
        
        else // Si el nodo tiene hijo izquierdo, cambiamos su valor por el mayor hijo izquierdo y borramos
            node->key = findDeleteMaximum(key, node->left); 

        if (this->root == nullptr)
            this->root = node;

        splay(parent); // Flotamos el padre del nodo
    } 
};
