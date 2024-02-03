
#include "ListNode.h"
#include <iostream>
using namespace std;
template <typename T>
class circular_linked_list {
private:
    int length;
    ListNode<T>* head;
    ListNode<T>* tail;

public:
    circular_linked_list() : length(0), head(nullptr), tail(nullptr) {}
    void append(T value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
            newNode->next = newNode;  // Make it point to itself for circularity
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
        length++;
    }
	void remove(int index) {
	    if (length == 0) {
	        std::cout << "Circular linked list is empty." << std::endl;
	        return;
	    }
	    if (index < 0 || index >= length) {
	        std::cout << "Invalid index." << std::endl;
	        return;
	    }
	    ListNode<T>* current = head;
	    ListNode<T>* prev = nullptr;
	    // Traverse to the node at the given index
	    for (int i = 0; i < index; i++) {
	        prev = current;
	        current = current->next;
	    }
	    // Remove the node from the list
	    if (length == 1) {
	        // Only one node in the list, remove it
	        head = nullptr;
	    } else if (current == head) {
	        // Node to be removed is the head node
	        prev->next = current->next;
	        head = current->next;
	    } else {
	        // Node to be removed is in the middle or at the end
	        prev->next = current->next;
	        if (current == tail)
	            tail = prev;
	    }
	    delete current;
	    length--;
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
};

