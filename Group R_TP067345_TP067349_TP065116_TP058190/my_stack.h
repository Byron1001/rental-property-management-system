#include <iostream>
#include "ListNode.h" 
using namespace std;
template <typename T>
class stack {
private:
    int length;
    ListNode<T>* top;
public:
    stack() : length(0), top(nullptr) {}
    void push(const T& n) {
        ListNode<T>* newNode = new ListNode<T>(n);
        newNode->next = top;
        top = newNode;
        length++;
    }
	void remove(int index) {
	    if (index < 0 || index >= length) {
	        cout << "Invalid index." << endl;
	        return;
	    }
	    if (index == 0) {
	         // Remove the element from the top of the stack
	        return;
	    }
	    ListNode<T>* current = top;
	    ListNode<T>* prev = nullptr;
	    int currentIndex = 0;
	    while (currentIndex < index) {
	        prev = current;
	        current = current->next;
	        currentIndex++;
	    }
	    prev->next = current->next;
	    delete current;
	    length--;
	}
    void pop() {
        if (length == 0)
            return;
        ListNode<T>* temp = top;
        top = top->next;
        delete temp;
        length--;
    }
    T peek() const {
        if (length == 0)
            cout << "Stack is empty" << endl;
        return top->val;
    }
    int len() const {
        return length;
    }
	T get(int n){
    	ListNode<T>* temp = top;
    	for (int i = 0; i < n; i++) 
            temp = temp->next;
        return temp->val;
	}
    void display_all() const {
        ListNode<T>* temp = top;
        while (temp != nullptr) {
            std::cout << temp->val << std::endl;
            temp = temp->next;
        }
    }
};
template <typename T>
void stack_remove(stack<T>& temp1, int index){
	if (index < 0 || index >= temp1.len()) {
        cout << "Invalid index" << endl;
        return;
    }
    stack<T> temp2; // Create a temporary stack to hold elements
    // Pop elements from the original stack and push them into the temporary stack
    // until we reach the element to be removed
    for (int i = 0; i < index; i++) {
        T element = temp1.peek();
        temp1.pop();
        temp2.push(element);
    }
    // Remove the element at the specified index by popping it from the original stack
    temp1.pop();
    // Pop the remaining elements from the temporary stack and push them back into the original stack
    while (temp2.len() > 0) {
        T element = temp2.peek();
        temp2.pop();
        temp1.push(element);
    }
}
template <typename T>
T stack_get(stack<T>& temp, int index) {
    if (index < 0 || index >= temp.len()) {
        cout << "Invalid index" << endl;
        return T(); // Return a default-constructed T if the index is out of range
    }
    stack<T> temp2; // Create a temporary stack to hold elements
    // Pop elements from the original stack and push them into the temporary stack
    // until we reach the element to be retrieved
    for (int i = 0; i < index; i++) {
        T element = temp.peek();
        temp.pop();
        temp2.push(element);
    }
    // Retrieve the element at the specified index
    T element = temp.peek();
    // Pop the remaining elements from the temporary stack and push them back into the original stack
    while (temp2.len() > 0) {
        T el = temp2.peek();
        temp2.pop();
        temp.push(el);
    }
    return element;
}