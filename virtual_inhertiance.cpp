#include <iostream>

using namespace std;

struct Person {
    Person() {
        cout << "\nConstructing Person";
    }
    virtual ~Person() = default;
    virtual void speak() {}
    private:
    int a;
};

struct Student: virtual Person {
    Student() {
        cout << "\nConstructing Student";
    }
    virtual void learn() {}
};

struct Worker: virtual Person {
    Worker() {
        cout << "\nConstructing Worker";
    }
    virtual void work() {}
};

struct TeachingAssistant: Student, Worker {
    TeachingAssistant() {
        cout << "\nConstructing TeachingAssistant";
    }
};

int main() {
    TeachingAssistant ta;
    cout << "\nSize of Person : " << sizeof(Person); 
    cout << "\nSize of Student : " << sizeof(Student); 
    cout << "\nSize of Teacher : " << sizeof(Worker); 
    cout << "\nSize of Teaching Assistant : " << sizeof(TeachingAssistant); 
    return  0;
}