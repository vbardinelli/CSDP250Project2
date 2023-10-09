#ifndef COMBINEDLIST_H
#define COMBINEDLIST_H
#include <iostream>

class NumberList {
private:
    struct ListNode {
        int id;
        double GPA;
        ListNode* next;
    };

    ListNode* head;

public:
    NumberList();
    ~NumberList();

    void appendNode(int, double);
    void deleteNode(int);
    void insertNode(int, double);
    void displayList() const;
};

class DoublyCircularList {
private:
    struct ListNode {
        int value;
        ListNode* next;
        ListNode* prev;
    };

    ListNode* head;

public:
    DoublyCircularList();
    ~DoublyCircularList();

    void appendNode(int value);
    void displayList() const;

    void assign1();
    void assign2();
    void assign3();
    void assign4();
    void assign5();
    void printTable();
};

#endif
