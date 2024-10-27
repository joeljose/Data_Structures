#include "linked_list.hpp"

void LinkedList::append(int data) {
    auto new_node = std::make_unique<Node>(data);
    if (!head) {
        head = std::move(new_node);
        tail = head.get();
    } else {
        tail->next = std::move(new_node);
        tail = tail->next.get();
    }
}

void LinkedList::prepend(int data) {
    auto new_node = std::make_unique<Node>(data);
    new_node->next = std::move(head);
    head = std::move(new_node);
    if (!tail) {
        tail = head.get();
    }
}

void LinkedList::insert_after(const Node* prev_node, int data) {
    if (prev_node == nullptr) {
        throw std::invalid_argument("The given previous node cannot be nullptr");
    }
    Node* current = head.get();
    while (current && current != prev_node) {
        current = current->next.get();
    }
    if (!current) {
        throw std::invalid_argument("The given previous node is not in the list");
    }
    auto new_node = std::make_unique<Node>(data);
    new_node->next = std::move(current->next);
    current->next = std::move(new_node);
    if (current == tail) {
        tail = current->next.get();
    }
}

Node* LinkedList::find(int data) const {
    Node* current = head.get();
    while (current) {
        if (current->data == data) {
            return current;
        }
        current = current->next.get();
    }
    return nullptr;
}

bool LinkedList::contains(int data) const {
    return find(data) != nullptr;
}

int LinkedList::length() const {
    int count = 0;
    Node* current = head.get();
    while (current) {
        count++;
        current = current->next.get();
    }
    return count;
}

void LinkedList::reverse() {
    if (!head || !head->next) return;  // Handle empty or single-element list

    Node* prev = nullptr;
    Node* current = head.release();  // Release ownership temporarily to work with raw pointers
    tail = current;  // The current head becomes the new tail

    while (current) {
        Node* next = current->next.release();  // Extract raw pointer from unique_ptr
        current->next.reset(prev);  // Set next to previous
        prev = current;
        current = next;
    }

    head.reset(prev);  // Restore ownership of the new head
    tail->next.reset();  // Ensure the new tail points to nullptr
}


void LinkedList::delete_value(int value) {
    Node* current = head.get();
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == value) {
            if (prev == nullptr) {
                head = std::move(current->next);
                if (!head) {
                    tail = nullptr;
                }
            } else {
                prev->next = std::move(current->next);
                if (prev->next == nullptr) {
                    tail = prev;
                }
            }
            return;
        }
        prev = current;
        current = current->next.get();
    }
}

void LinkedList::delete_at_position(int position) {
    if (position < 0 || head == nullptr) return;

    if (position == 0) {
        head = std::move(head->next);
        if (!head) {
            tail = nullptr;
        }
        return;
    }

    Node* current = head.get();
    Node* prev = nullptr;
    int currentPosition = 0;

    while (current != nullptr && currentPosition < position) {
        prev = current;
        current = current->next.get();
        currentPosition++;
    }

    if (current != nullptr) {
        prev->next = std::move(current->next);
        if (prev->next == nullptr) {
            tail = prev;
        }
    }
}