#ifndef LISTNODE_H
#define LISTNODE_H
template <typename T>
struct ListNode {
    T val;
    ListNode<T>* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(T x) : val(x), next(nullptr) {}
    ListNode(T x, ListNode<T>* next) : val(x), next(next) {}
};
#endif
