//
//  main.cpp
//  assignment-1
//
//  Created by DONIYORBEK IBROKHIMOV on 03/12/22.
//

#include <iostream>

using namespace std;

struct Node{
    Node *next, *prev;
    int age;
    string name;

    Node() {
        next = nullptr;
        prev = nullptr;
        age = 0;
    }
};

class Child {
private:
    int age = 0;
    string name;
    
    Node *childHead;
    
public:
    
    Child () {
        childHead = nullptr;
    }
    
    void setAge(const int &child_age) {
        age = child_age;
    }
    
    const int &getAge() const {
        return age;
    }
    
    void setName(const string &child_name) {
        name = child_name;
    }
    
    const string &getName() const {
        return name;
    }
    
};

class Wife {
private:
    Node *wifeHead;
    int age = 0;
    string name;
    
    Child *childLink;
    
    void childDetails() {
        cout << "Enter the child's name->";
        string child_name;
        cin >> child_name;
        
        cout << "Enter the child's age->";
        int child_age = 0;
        cin >> child_age;
        
        childLink->setName(child_name);
        childLink->setAge(child_age);
    }
    
public:
    Wife() {
        wifeHead = nullptr;
        wifeLast = nullptr;
        childLink = nullptr;
        
        bool isChildAvailable;
        cout << "Enter 1 if you have a child and 0 otherwise";
        cin >> isChildAvailable;
        
        if(isChildAvailable) {
            childLink = new Child;
            childDetails();
        }
    }
    
    void setAge(const int &wife_age) {
        age = wife_age;
    }
    
    const int &getAge() const {
        return age;
    }
    
    void setName(const string &wife_name) {
        name = wife_name;
    }
    
    const string &getName () const {
        return name;
    }

//    void insertWifeAtLast(const string &wife_name, const int wife_age) {
//        Node *newWife = new Node;
//        newWife->name = wife_name;
//        newWife->age = wife_age;
//
//        if (!wifeHead) {
//            newWife->next = wifeHead;
//            wifeHead = newWife;
//            wifeLast = newWife;
//        } else {
//            newWife->next = wifeLast->next;
//            wifeLast->next = newWife;
//            wifeLast = newWife;
//        }
//    }

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


class Husband {
private:
    Node *husbandHead, *husbandLast;
    Wife *wifeLink;
    Husband *nextHusband;
    
    int age = 0;
    string name;
    
    void wifeDetails() {
        cout << "Enter the wife's name->";
        string wife_name;
        cin >> wife_name;
        
        cout << "Enter the wife's age->";
        int wife_age = 0;
        cin >> wife_age;
        
        wifeLink->setName(wife_name);
        wifeLink->setAge(wife_age);
    }

public:
    Husband() {
        husbandHead = nullptr;
        husbandLast = nullptr;
        wifeLink = nullptr;
        
        cout << "Enter 1 if you are married or 0 otherwise\n";
        bool isMarried;
        cin >> isMarried;
        
        if(isMarried) {
            wifeLink = new Wife;
            wifeDetails();
            
        }
    }
    
    void setHusbandAge(const int &husband_age) {
        age = husband_age;
    }
    
    const int &getHusbandAge() const {
        return age;
    }
    
    void setHusbandName (const string &husband_name) {
        name = husband_name;
    }
    
    const string &getHusbandName () const {
        return name;
    }

    void insertHusbandAtLast(const string &husband_name, const int husband_age) {
        Husband *newHusband = new Husband;
        newHusband->setHusbandName(husband_name);
        newHusband->setHusbandAge(husband_age);

        if (!husbandHead) {
            newHusband->nextHusband = husbandHead;
            //newHusband->prev = husbandHead;
            husbandHead = newHusband;
            husbandLast = newHusband;
        } else {
            newHusband->nextHusband = husbandLast->ne;
            husbandLast->n = newHusband;
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


int main() {
    // testing insertion at last in Husband class
    Husband husband1;
    husband1.insertHusbandAtLast("h1", 34);
    husband1.insertHusbandAtLast("h1", 34);
    husband1.insertHusbandAtLast("h1", 34);
    
    cout << endl;
    return 0;
}
