#ifndef LIST_H
#define LIST_H

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(const T& data) : data(data), next(nullptr) {}
};

#endif // LIST_H
