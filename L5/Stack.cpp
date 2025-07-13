/**Name: Mohd Adrian Firdaus bin Mohd Rosli
Student ID: 22011425**/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name){
        this->name = name;
        this->next_ptr = nullptr;
    }
};

class Stack{
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(string name){
        Node* newNode = new Node(name);
        newNode->next_ptr = top;
        top = newNode;
        cout << "Pushed:" << name << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        cout << "Popped:" << temp->name << endl;
        top = top->next_ptr;
        delete temp;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* current = top;
        while (current != nullptr) {
            cout << current->name << "->";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }
};


int main() {
    Stack stack;

    stack.push("Ali");
    stack.push("Ahmed");
    stack.push("Alice");

    cout << "\nStack:" << endl;
    stack.display();

    cout << "\nStack after pop:" << endl;
    stack.pop();
    stack.display();
}

