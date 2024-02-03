#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include<string>
#include "ListNode.h"
using namespace std;
template <typename T>
class vector {
private:
    int length;
    ListNode<T>* head;
    ListNode<T>* tail;

public:
    vector() : length(0), head(nullptr), tail(nullptr) {}
    void push_back(const T& n) {
        ListNode<T>* newNode = new ListNode<T>(n);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    void pop_back() {
        if (length == 0) 
            return;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
            length = 0;
            return;
        }
        ListNode<T>* temp = head;
        for (int i = 0; i < length - 2; i++) 
            temp = temp->next;
        temp->next = nullptr;
        delete tail;
        tail = temp;
        length--;
    }
	void remove(int index) {
	    if (index < 0 || index >= length) {
	        cout << "it has ran out of range" << endl;
	        return;
	    }
	    if (index == 0) {
	        ListNode<T>* temp = head;
	        head = head->next;
	        delete temp;
	        if (head == nullptr) {
	            tail = nullptr;
	        }
	    } else {
	        ListNode<T>* current = head;
	        ListNode<T>* previous = nullptr;
	        for (int i = 0; i < index; i++) {
	            previous = current;
	            current = current->next;
	        }
	        previous->next = current->next;
	        if (current == tail) {
	            tail = previous;
	        }
	        delete current;
	    }
	    length--;
	}
	void set(int index, const T& value) {
        if (index < 0 || index >= length) {
            cout << "Index out of range" << endl;
            return;
        }
        ListNode<T>* current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        current->val = value;
    }
	void change_to(int index, int new_number){
		ListNode<T>* temp1 = head;
		for(int i=0 ; i<index ; i++)
			temp1 = temp1->next;
		temp1->val = new_number;
	}
	void swap(int index1, int index2) {
	    if (index1 < 0 || index1 >= length || index2 < 0 || index2 >= length) {
	        cout << "Indices are out of range." << endl;
	        return;
	    }
	    if (index1 == index2)
	        return;
	    ListNode<T>* node1 = head;
	    ListNode<T>* node2 = head;
	    ListNode<T>* prev1 = nullptr;
	    ListNode<T>* prev2 = nullptr;
	    // Traverse to the nodes at the given indices
	    for (int i = 0; i < index1; i++) {
	        prev1 = node1;
	        node1 = node1->next;
	    }
	    for (int i = 0; i < index2; i++) {
	        prev2 = node2;
	        node2 = node2->next;
	    }
	    // Swap the node addresses
	    if (prev1 != nullptr)
	        prev1->next = node2;
	    else 
	        head = node2;
	    if (prev2 != nullptr)
	        prev2->next = node1;
	    else
	        head = node1;
	    ListNode<T>* temp = node1->next;
	    node1->next = node2->next;
	    node2->next = temp;
	}
	T get(int n){
    	ListNode<T>* temp = head;
    	for (int i = 0; i < n; i++)
            temp = temp->next;
        return temp->val;
	}
	int len(){
		return length;
	}
	void display_all() {
        ListNode<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->val << std::endl;
            temp = temp->next;
        }
    }
};
#endif


