#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node* prev;

    Node(const string& nameVal) : name(nameVal), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void add(const string& name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = tail = newNode;
        }else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Added successfully" << endl;
    }

    void displayForward() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name;
            if (current->next != nullptr)
                cout << " <-> ";
            current = current->next;
        }
        cout << endl;
    }

    void displayBackward() const {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->name;
            if (current->prev != nullptr)
                cout << " <-> ";
            current = current->prev;
        }
        cout << endl;
    }

    void deleteNode(const string& name) {
        Node* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                if (current == head && current == tail) {
                    head = tail = nullptr;
                } else if (current == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                cout << name << " deleted.\n";
                return;
            }
            current = current->next;
        }
        cout << name << " not found.\n";
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.add("Ali");
    list.add("Ahmed");
    list.add("Alice");

    cout << "Forward: ";
    list.displayForward();   // Ali <-> Ahmed <-> Alice

    cout << "Backward: ";
    list.displayBackward();  // Alice <-> Ahmed <-> Ali

    list.deleteNode("Ahmed");

    cout << "After deletion (forward): ";
    list.displayForward();   // Ali <-> Alice

    return 0;
}
