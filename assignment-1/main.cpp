//
//  main.cpp
//  assignment-1
//
//  Created by DONIYORBEK IBROKHIMOV on 03/12/22.
//

#include <iostream>

using namespace std;

struct Node {
    Node *next, *prev;
    int age;
    string name;

    Node() {
        next = nullptr;
        prev = nullptr;
        age = 0;
    }
};

class Husband {
private:
    Node *husbandHead, *husbandLast;

public:
    Husband() {
        husbandHead = nullptr;
        husbandLast = nullptr;
    }

    void insertHusbandAtLast(string husband_name, int husband_age) {
        Node *newHusband = new Node;
        newHusband->age = husband_age;
        newHusband->name = husband_name;

        if (husbandHead) {
            newHusband->next = husbandHead;
            newHusband->prev = husbandHead;
            husbandHead = newHusband;
            husbandLast = newHusband;
        } else {
            newHusband->next = husbandLast->next;
            husbandLast->next = newHusband;
            newHusband->prev = husbandLast;
            husbandLast = newHusband;
        }
    }

    void printAll() {
        Node *temp = husbandHead;
        int i = 1;
        while (temp) {
            cout << "Name " << i << " " << temp->name
                 << "\nAge " << i << " " << temp->age << endl;
            temp = temp->next;
            i++;
        }
    }

};

int main() {
    Husband husband1;
    husband1.insertHusbandAtLast("h1", 34);
    husband1.printAll();

    return 0;
}
