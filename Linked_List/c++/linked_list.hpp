#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory>
#include <iostream>
#include <vector>

struct Node {
    int data;
    std::unique_ptr<Node> next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    std::unique_ptr<Node> head;
    Node* tail; // Add this line

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void append(int data);
    void prepend(int data);
    void insert_after(const Node* node, int data);
    Node* find(int data) const;
    bool contains(int data) const;
    int length() const;
    void reverse();

    // New methods
    template<typename Func>
    void traverse(Func f) const {
        Node* current = head.get();
        while (current) {
            f(current);
            current = current->next.get();
        }
    }

    void print_list() const {
        traverse([](const Node* node) {
            std::cout << node->data << " -> ";
        });
        std::cout << "nullptr" << std::endl;
    }

    // Add this method declaration
    void delete_value(int value);

    // Add this method declaration
    void delete_at_position(int position);

    // Add this method to the LinkedList class
    std::vector<int> to_vector() const {
        std::vector<int> result;
        traverse([&result](const Node* node) {
            result.push_back(node->data);
        });
        return result;
    }
};

#endif // LINKED_LIST_HPP
