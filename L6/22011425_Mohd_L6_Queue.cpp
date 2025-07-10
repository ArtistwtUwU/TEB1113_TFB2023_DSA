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

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string name){
        Node* new_Node = new Node(name);

        if (front == nullptr) {
            front = new_Node;
            rear = new_Node;
        }else {
            rear->next_ptr = new_Node;
            rear = new_Node;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
            Node* temp = front;
            front = front->next_ptr;
            cout << temp->name << endl;
            delete temp;
    }

    void display_queue(){
        Node* current = front;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alice");

    cout << "Queue: ";
    queue.display_queue();

    cout << "Dequeued: ";
    queue.dequeue();

    cout << "Queue: ";
    queue.display_queue();

    return 0;
}