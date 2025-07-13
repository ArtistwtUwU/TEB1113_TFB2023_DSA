/** Name: Mohd Adrian Firdaus bin Mohd Rosli
Student ID: 22011425 **/

#include <iostream>
#include <string>
using namespace std;


class Queue {
    static const int MAX_SIZE = 100;
    string arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    void enqueue(string name){
        if (rear == MAX_SIZE) {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[rear++] = name;
    }

    void dequeue() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << arr[front++] << endl;
    }

    void display_queue(){
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i < rear; i++) {
            cout << arr[i] << "->";
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alice");

    cout << "Queue: " << endl;
    queue.display_queue();

    cout << "Dequeued: " << endl;
    queue.dequeue();

    cout << "Queue: " << endl;
    queue.display_queue();

    return 0;
}