#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next;

    Node(const string& nameVal, Node* nextPtr = nullptr)
        : name(nameVal), next(nextPtr) {}
};

class LinkedList{
    Node* head;

    public:
    LinkedList() : head(nullptr) {}

    void add(const string& name){
        Node* newNode = new Node{name, nullptr};
        if (head == nullptr) {
            head = newNode;
        }else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Added successfully" << endl;
    }

    void display()const{
        Node* current = head;
        while (current != nullptr) {
            cout << current->name;
            if (current->next != nullptr) {
                cout<< " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    void deleteNode(string name){
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->name == name) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                cout << name << " deleted.\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        cout << name << " not found.\n";
    }
};

int main() {
    LinkedList list;

    list.add("Ali");
    list.add("Ahmed");
    list.add("Alice");

    list.display();
    list.deleteNode("Ahmed");
    list.display();


}

