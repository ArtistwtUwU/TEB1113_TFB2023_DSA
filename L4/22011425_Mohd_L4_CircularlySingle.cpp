/**Name: Mohd Adrian Firdaus bin Mohd Rosli
Student ID: 22011425**/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
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
            tail->next_ptr = head;
        }else {
            tail->next_ptr = newNode;
            tail = newNode;
            tail->next_ptr = head;
        }
    }

    void display(){
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

    void deleteNode(string name){
        Node* current = head;
        Node* previous = tail;

        if (head == nullptr) {
            return;
        }

        do {
            if (current->name == name) {
                if (current == head) {
                    if ( head == tail) {
                        delete head;
                        head = tail = nullptr;
                        return;
                    }else {
                        head = head->next_ptr;
                        tail->next_ptr = head;
                        delete current;
                        return;
                    }
                }else {
                        previous->next_ptr = current->next_ptr;
                        if ( current == tail) {
                            tail = previous;
                        }
                        delete current;
                        return;
                    }
                }
                previous = current;
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

    cout << "Linked List:" << endl;
    list.display();
    cout << "After ahmed is deleted:" <<endl;
    list.deleteNode("Ahmed");
    list.display();


}