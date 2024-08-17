#include <iostream>
#include <memory>
#include <vector>

struct Node {
    int data;
    std::unique_ptr<Node> next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    std::unique_ptr<Node> head;

public:
    LinkedList() : head(nullptr) {}

    // Append a node to the end of the list
    void append(int data) {
        std::unique_ptr<Node> new_node = std::make_unique<Node>(data);
        if (!head) {
            head = std::move(new_node);
            return;
        }
        Node* last = head.get();
        while (last->next) {
            last = last->next.get();
        }
        last->next = std::move(new_node);
    }

    // Prepend a node to the beginning of the list
    void prepend(int data) {
        std::unique_ptr<Node> new_node = std::make_unique<Node>(data);
        new_node->next = std::move(head);
        head = std::move(new_node);
    }

    // Insert a node after a specific node
    void insert_after(Node* prev_node, int data) {
        if (prev_node == nullptr) {
            std::cerr << "The given previous node cannot be nullptr" << std::endl;
            return;
        }
        std::unique_ptr<Node> new_node = std::make_unique<Node>(data);
        new_node->next = std::move(prev_node->next);
        prev_node->next = std::move(new_node);
    }

    // Delete a node by value
    void delete_value(int data) {
        if (!head) return;

        if (head->data == data) {
            head = std::move(head->next);
            return;
        }

        Node* current = head.get();
        Node* previous = nullptr;

        while (current && current->data != data) {
            previous = current;
            current = current->next.get();
        }

        if (!current) return; // Node with the data not found

        previous->next = std::move(current->next);
    }

    // Delete a node by position (0-indexed)
    void delete_at_position(int position) {
        if (!head) return;

        if (position == 0) {
            head = std::move(head->next);
            return;
        }

        Node* current = head.get();
        Node* previous = nullptr;

        int count = 0;
        while (current && count != position) {
            previous = current;
            current = current->next.get();
            count++;
        }

        if (!current) return; // Position out of range

        previous->next = std::move(current->next);
    }

    // Find a node by value
    Node* find(int data) {
        Node* current = head.get();
        while (current) {
            if (current->data == data) {
                return current;
            }
            current = current->next.get();
        }
        return nullptr;
    }

    // Check if the list contains a node with the given value
    bool contains(int data) {
        return find(data) != nullptr;
    }

    // Get the length of the list
    int length() const {
        int count = 0;
        Node* current = head.get();
        while (current) {
            count++;
            current = current->next.get();
        }
        return count;
    }

    // Check if the list is empty
    bool is_empty() const {
        return head == nullptr;
    }

    // Print the list
    void print_list() const {
        Node* current = head.get();
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next.get();
        }
        std::cout << "nullptr" << std::endl;
    }

    // Reverse the list
    void reverse() {
        Node* prev = nullptr;
        std::unique_ptr<Node> current = std::move(head);
        while (current) {
            std::unique_ptr<Node> next = std::move(current->next);
            current->next.reset(prev);
            prev = current.release();
            current = std::move(next);
        }
        head.reset(prev);
    }

    // Convert the list to a vector (or similar container)
    std::vector<int> to_vector() const {
        std::vector<int> result;
        Node* current = head.get();
        while (current) {
            result.push_back(current->data);
            current = current->next.get();
        }
        return result;
    }
};

int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.prepend(5);
    list.insert_after(list.find(10), 15);

    std::cout << "List: ";
    list.print_list();  // Output: 5 -> 10 -> 15 -> 20 -> nullptr

    list.delete_value(10);
    std::cout << "After deleting 10: ";
    list.print_list();  // Output: 5 -> 15 -> 20 -> nullptr

    list.delete_at_position(1);
    std::cout << "After deleting at position 1: ";
    list.print_list();  // Output: 5 -> 20 -> nullptr

    std::cout << "Contains 20: " << list.contains(20) << std::endl;  // Output: 1 (true)
    std::cout << "List length: " << list.length() << std::endl;  // Output: 2

    list.reverse();
    std::cout << "Reversed list: ";
    list.print_list();  // Output: 20 -> 5 -> nullptr

    return 0;
}
