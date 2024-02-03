
#include <iostream>
using namespace std;
template <typename T>
struct Doubly_ListNode {
    T val;
    Doubly_ListNode<T>* prev;
    Doubly_ListNode<T>* next;

    Doubly_ListNode() : val(T()), prev(nullptr), next(nullptr) {}
    explicit Doubly_ListNode(T value) : val(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class doubly_circular_linked_list {
private:
    int length;
    Doubly_ListNode<T>* head;
    Doubly_ListNode<T>* tail;
public:
    doubly_circular_linked_list() : length(0), head(nullptr), tail(nullptr) {}
    // Append a new node to the end of the doubly circular linked list
    void append(T value) {
        Doubly_ListNode<T>* newNode = new Doubly_ListNode<T>(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode; // Make it point to itself for circularity
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
        length++;
    }
	void remove(int index) {
	    if (length == 0) {
	        std::cout << "Doubly circular linked list is empty." << std::endl;
	        return;
	    }
	    if (index < 0 || index >= length) {
	        std::cout << "Invalid index." << std::endl;
	        return;
	    }
	    Doubly_ListNode<T>* current = head;
	    // Traverse to the node at the given index
	    for (int i = 0; i < index; i++)
	        current = current->next;
	    // Remove the node from the list
	    if (length == 1) {
	        // Only one node in the list, remove it
	        head = nullptr;
	        tail = nullptr;
	    } else if (current == head) {
	        // Node to be removed is the head node
	        head = current->next;
	        head->prev = tail;
	        tail->next = head;
	    } else if (current == tail) {
	        // Node to be removed is the tail node
	        tail = current->prev;
	        tail->next = head;
	        head->prev = tail;
	    } else {
	        // Node to be removed is in the middle
	        current->prev->next = current->next;
	        current->next->prev = current->prev;
	    }
	    delete current;
	    length--;
	}
    T get(int n){
    	Doubly_ListNode<T>* temp = head;
    	for (int i = 0; i < n; i++)
            temp = temp->next;
        return temp->val;
	}
	int len(){
		return length;
	}
};

