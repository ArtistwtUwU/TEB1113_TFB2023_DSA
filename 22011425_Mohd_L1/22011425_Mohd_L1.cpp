#include <iostream>
using namespace std;

//Define Structure
struct Student{
    int id;
    string name;
    int contact;
    string email;
};

int main(){
    //Define Array
    Student student[5];

    //Input
    for(int i = 0; i < 2; i++){
        cout << "Student ID: " ; cin >> student[i].id;
        cout << "Student name: "; cin.ignore() ; getline(cin,student[i].name);
        cout << "Contact Number: "; cin >> student[i].contact;
        cout << "Student Email: "; cin >> student[i].email;
    }

    //Output
    for(int i = 0; i < 2; i++){
        cout << "*****************************************" << endl;
        cout << "Student " << i+1 << endl;
        cout << "Student ID: " << student[i].id << endl;
        cout << "Student Name: " << student[i].name << endl;
        cout << "Contact Number: " << student[i].contact << endl;
        cout << "Student name: " << student[i].email << endl;
    }
}