#include "CombinedList.h"

using namespace std;



NumberList::NumberList() {
    head = nullptr;
}

NumberList::~NumberList() {
    ListNode* nodePtr;
    while (head) {
        nodePtr = head;
        head = head->next;
        delete nodePtr;
    }
}

void NumberList::appendNode(int id, double GPA) {
    ListNode* newNode = new ListNode;
    newNode->id = id;
    newNode->GPA = GPA;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        ListNode* nodePtr = head;
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}
void NumberList::insertNode(int id, double gpa) {
    ListNode* newNode = new ListNode;
    newNode->id = id;
    newNode->GPA = gpa;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        ListNode* nodePtr = head;
        ListNode* prevNode = nullptr;

        while (nodePtr && nodePtr->id < id) {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (!prevNode) {
            newNode->next = head;
            head = newNode;
        } else {
            newNode->next = nodePtr;
            prevNode->next = newNode;
        }
    }
}
void NumberList::deleteNode(int id) {
    ListNode* nodePtr;
    ListNode* prevNode;

    if (!head) {
        return;
    }

    if (head->id == id) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    } else {
        nodePtr = head;

        while (nodePtr != nullptr && nodePtr->id != id) {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr) {
            prevNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

void NumberList::displayList() const {
    ListNode* nodePtr = head;
    while (nodePtr) {
        cout << nodePtr->id << ", " << nodePtr->GPA << endl;
        nodePtr = nodePtr->next;
    }
}

DoublyCircularList::DoublyCircularList() {
    head = nullptr;
}

DoublyCircularList::~DoublyCircularList() {
    if (!head) return;

    ListNode* current = head;
    ListNode* nextNode;

    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
}
void DoublyCircularList::appendNode(int value) {
    ListNode* newNode = new ListNode;
    newNode->value = value;

    if (!head) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        ListNode* last = head->prev;
        last->next = newNode;
        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
    }
}

//Displays DoubleCircular Linked List to user
void DoublyCircularList::displayList() const {
    ListNode* nodePtr = head;
    do {
        cout << nodePtr->value << " <-> ";
        nodePtr = nodePtr->next;
    } while (nodePtr != head);
    cout << "Start" << endl;
}
//Functions assign1-assign5 execute the appropriate operations and displays the final value to the user.
void DoublyCircularList::assign1() {
    if (!head) return;
    head->next->next->next = head->prev;
    cout << "The value of the assignment 1 is: ";
    displayList();
}

void DoublyCircularList::assign2() {
    if (!head) return;
    head->prev->prev->prev = head->next->next->next->prev;
    cout << "The value of the assignment 2 is: ";
    displayList();
}

void DoublyCircularList::assign3() {
    if (!head) return;
    head->next->next->next->prev = head->prev->prev->prev;
    cout << "The value of the assignment 3 is: ";
    displayList();
}
void DoublyCircularList::assign4() {
    if (!head) return;
    head->next = head->next->next;
    cout << "The value of the assignment 4 is: ";
    displayList();
}

void DoublyCircularList::assign5() {
    if (!head) return;
    head->next->prev->next = head->next->next->next;
    cout << "The value of the assignment 5 is: ";
    displayList();
}

//Function to print table with data.
void DoublyCircularList::printTable() {
    if (!head) return;

//Width of each cell (including asterisks)
    const int CELL_WIDTH = 19;

    auto centerFormat = [CELL_WIDTH](int num) -> string {
        string s = to_string(num);
        int padding = (CELL_WIDTH - s.length() - 2) / 2;
        string padStr(padding, ' ');
        return "*" + padStr + s + padStr + (s.length() % 2 == 0 ? " " : "") + "*";
    };

    string emptyCell = string(CELL_WIDTH, '*');

    cout << emptyCell << "******************* ******************* ******************* ******************* *******************" << endl;
    cout << "*" + string(CELL_WIDTH - 2, ' ') + "*" << "*      node 1      *      node 2      *      node 3      *      node 4      *      node 5      *" << endl;
    cout << emptyCell << "******************* ******************* ******************* ******************* *******************" << endl;

    //Node Value
    ListNode* nodePtr = head;
    cout << "*     Node Value   ";
    for (int i = 0; i < 5; i++) {
        cout << centerFormat(nodePtr->value);
        nodePtr = nodePtr->next;
    }
    cout << endl;
    cout << emptyCell << "******************* ******************* ******************* ******************* *******************" << endl;

    //Prev Node
    nodePtr = head;
    cout << "*     Prev Node    ";
    for (int i = 0; i < 5; i++) {
        cout << centerFormat(nodePtr->prev->value);
        nodePtr = nodePtr->next;
    }
    cout << endl;
    cout << emptyCell << "******************* ******************* ******************* ******************* *******************" << endl;

    //Next Node
    nodePtr = head;
    cout << "*     Next Node    ";
    for (int i = 0; i < 5; i++) {
        cout << centerFormat(nodePtr->next->value);
        nodePtr = nodePtr->next;
    }
    cout << endl;
    cout << emptyCell << "******************* ******************* ******************* ******************* *******************" << endl;
}

