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

    void insertHusbandAtLast(const string &husband_name, const int husband_age) {
        Node *newHusband = new Node;
        newHusband->age = husband_age;
        newHusband->name = husband_name;

        if (!husbandHead) {
            newHusband->next = husbandHead;
            //newHusband->prev = husbandHead;
            husbandHead = newHusband;
            husbandLast = newHusband;
        } else {
            newHusband->next = husbandLast->next;
            husbandLast->next = newHusband;
            //newHusband->prev = husbandLast;
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

class Wife {
private:
    Node *wifeHead, *wifeLast;

public:
    Wife() {
        wifeHead = nullptr;
        wifeLast = nullptr;
    }

    void insertWifeAtLast(const string &wife_name, const int wife_age) {
        Node *newWife = new Node;
        newWife->name = wife_name;
        newWife->age = wife_age;

        if (!wifeHead) {
            newWife->next = wifeHead;
            wifeHead = newWife;
            wifeLast = newWife;
        } else {
            newWife->next = wifeLast->next;
            wifeLast->next = newWife;
            wifeLast = newWife;
        }
    }

    void printAll() {
        Node *temp = wifeHead;
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
    // testing insertion at last in Husband class
    Husband husband1;
    husband1.insertHusbandAtLast("h1", 34);
    husband1.insertHusbandAtLast("h1", 34);
    husband1.insertHusbandAtLast("h1", 34);

    husband1.printAll();
    cout << endl;

    // testing insertion at last in Wife class
    Wife wife1;
    wife1.insertWifeAtLast("h1", 34);
    wife1.insertWifeAtLast("h1", 34);
    wife1.insertWifeAtLast("h1", 34);

    wife1.printAll();

    return 0;
}
