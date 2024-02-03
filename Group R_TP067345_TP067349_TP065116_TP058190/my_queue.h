#include <iostream>
#include "ListNode.h"
using namespace std;
template <typename T>
class queue {
private:
    int length;
    ListNode<T>* head;
    ListNode<T>* tail;
public:
    queue() : length(0), head(nullptr), tail(nullptr) {}
    void push(const T& n) {
        ListNode<T>* newNode = new ListNode<T>(n);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    void remove(int index) {
	    if (index < 0 || index >= length) {
	        cout << "Invalid index." << endl;
	        return;
	    }
	    if (index == 0)
	         // Remove the element at the front of the queue
	        return;
	    ListNode<T>* current = head;
	    ListNode<T>* prev = nullptr;
	    int currentIndex = 0;
	    while (currentIndex < index) {
	        prev = current;
	        current = current->next;
	        currentIndex++;
	    }
	    prev->next = current->next;
	    if (current == tail)
	        tail = prev;
	    delete current;
	    length--;
	}
    T front(){
        if (length == 0) {
            cout << "Queue is empty" << endl;
            return nullptr;
        }
        return head->val;
    }

    T back() const{
        if (length == 0)
            cout << "Queue is empty" << endl;
        return back->val;
    }
    T get(int n){
    	ListNode<T>* temp = head;
    	for (int i = 0; i < n; i++)
            temp = temp->next;
        return temp->val;
	}
    void pop() {
        if (length == 0)
            return;
        ListNode<T>* temp = head;
        head = head->next;
        if (head == nullptr)
            tail = nullptr;
        delete temp;
        length--;
    }
    T top() const {
        if (length == 0)
            cout << "Queue is empty" << endl;
        return head->val;
    }
    bool empty(){
    	return length==0;
	}
    int len() const {
        return length;
    }
    void display_all() const {
        ListNode<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->val << std::endl;
            temp = temp->next;
        }
    }
};
template <typename T>
void queue_remove(queue<T>& temp1, int index) {
    if (index < 0 || index >= temp1.len()) {
        cout << "Invalid index" << endl;
        return;
    }
    queue<T> temp2; // Create a temporary queue to hold elements before the index
    // Dequeue elements from the original queue and enqueue them into the temporary queue
    // until we reach the element to be removed
    for (int i = 0; i < index; i++) {
        T element = temp1.front();
        temp1.pop();
        temp2.push(element);
    }
    // Skip the element at the specified index (effectively removing it from the queue)
    temp1.pop();
    // Dequeue the remaining elements from the original queue and enqueue them back into the temporary queue
    while (!temp1.empty()) {
        T element = temp1.front();
        temp1.pop();
        temp2.push(element);
    }
    // Move all elements back from the temporary queue to the original queue
    while (!temp2.empty()) {
        T element = temp2.front();
        temp2.pop();
        temp1.push(element);
    }
}

template <typename T>
T queue_get(queue<T>& temp, int index) {
    if (index < 0 || index >= temp.len()) {
        cout << "Invalid index" << endl;
        return T(); // Return a default-constructed T if the index is out of range
    }

    int originalSize = temp.len();

    // Move elements from the original queue to a temporary queue
    queue<T> temp2;
    while (temp.len() > originalSize - index) {
        temp2.push(temp.front());
        temp.pop();
    }

    // Retrieve the element at the specified index
    T element = temp.front();
    
	while (!temp.empty()) {
        temp2.push(temp.front());
        temp.pop();
    }
    // Move elements back from the temporary queue to the original queue
    while (!temp2.empty()) {
        temp.push(temp2.front());
        temp2.pop();
    }

    return element;
}


