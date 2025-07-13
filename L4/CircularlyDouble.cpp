/**Name: Mohd Adrian Firdaus bin Mohd Rosli
Student ID: 22011425**/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;
    Node* prev_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
        this->prev_ptr = nullptr;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add(string name){
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            head->next_ptr = head;
            head->prev_ptr = head;
        }else {
            tail->next_ptr = newNode;
            newNode->prev_ptr = tail;
            newNode->next_ptr = head;
            head->prev_ptr = newNode;
            tail = newNode;
        }
    }

    void displayforward(){
        Node* current = head;
        if (head == nullptr) {
            cout << "Empty List" << endl;
            return;
        }
        do {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }while (current != head);
        cout << head->name << endl;
    }

    void displaybackward(){
        Node* current = tail;
        if (tail == nullptr) {
            cout << "Empty List" << endl;
            return;
        }
        do {
            cout << current->name << " -> ";
            current = current->prev_ptr;
        }while (current != tail);
        cout << tail->name << endl;
    }

    void deleteNode(string name){
        Node* current = head;
        Node* previous = tail;

        if (head == nullptr) {
            return;
        }

        do {
            if (current->name == name) {
                if (current == head && current == tail) {
                    delete current;
                    head = tail = nullptr;
                    return;
                }

                if (current == head) {
                    head = head->next_ptr;
                    tail->next_ptr = head;
                    head->prev_ptr = tail;
                }

                else if (current == tail) {
                    tail = tail->prev_ptr;
                    tail->next_ptr = head;
                    head->prev_ptr = tail;
                }
                else {
                    current->prev_ptr->next_ptr = current->next_ptr;
                    current->next_ptr->prev_ptr = current->prev_ptr;
                }
                delete current;
                return;
            }
            current = current->next_ptr;
        }while (current != head);
    }
};

int main() {
    LinkedList list;

    list.add("Ali");
    list.add("Ahmed");
    list.add("Alice");
    list.add("Ariana");

    cout << "Display forward:" << endl;
    list.displayforward();

    cout << "Display backward:" << endl;
    list.displaybackward();

    cout << "\nAfter ahmed is deleted:" <<endl;
    list.deleteNode("Ahmed");

    cout << "Display forward:" << endl;
    list.displayforward();

    cout << "Display backward:" << endl;
    list.displaybackward();


}