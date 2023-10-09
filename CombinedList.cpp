#include "CombinedList.h"
#include <iostream>


using namespace std;

void project1();
void project2();
void mainMenu();
void postRunOptions(string projectName);

//Calls Project1 from the MainMenu Function
void project1() {
    NumberList list;

    list.appendNode(22, 3.5);
    list.appendNode(55, 3.7);
    list.appendNode(88, 3.1);
    list.appendNode(111, 3.8);
    list.appendNode(210, 3.3);

    list.displayList();

    list.insertNode(31, 3.4);
    list.insertNode(1, 2.9);

    list.displayList();

    list.deleteNode(111);
    list.deleteNode(22);

    list.displayList();

    postRunOptions("Project 1 - Linked Lists");
}

//Calls Project2 from the MainMenu Function
void project2() {
    DoublyCircularList dcList;

    dcList.appendNode(11);
    dcList.appendNode(22);
    dcList.appendNode(33);
    dcList.appendNode(44);
    dcList.appendNode(55);

    dcList.assign1();
    dcList.assign2();
    dcList.assign3();
    dcList.assign4();
    dcList.assign5();

    dcList.printTable();

    postRunOptions("Project 2 - Double Linked List");
}

//Presents loopable menu to the user to navigate the program
void mainMenu() {
    int choice;
    cout << "************************************************************" << endl;
    cout << "************************************************************" << endl;
    cout << "************************************************************" << endl;
    cout << "This is the main menu for Vincent's CSDP250 Projects." << endl;
    cout << "Please select from the following menu:" << endl;
    cout << "1. Project 1 - Linked Lists" << endl;
    cout << "2. Project 2 - Double Linked List" << endl;
    cout << "3. Exit" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            project1();
            break;
        case 2:
            project2();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Exiting..." << endl;
    }
}

//Provides the looping logic for the main menu and the switch menu code
void postRunOptions(string projectName) {
    char choice;
    do {
        cout << "\nWould you like to: " << endl;
        cout << "1. Rerun " << projectName << "." << endl;
        cout << "2. Go back to the main menu." << endl;
        cout << "3. Exit." << endl;
        cout << "Enter your choice (1/2/3): ";
        cin >> choice;

        switch (choice) {
            case '1':
                if (projectName == "Project 1 - Linked Lists") {
                    project1();
                } else if (projectName == "Project 2 - Double Linked List") {
                    project2();
                }
                break;
            case '2':
                mainMenu(); // Assuming your main menu function is named mainMenu. Adjust if it's different.
                break;
            case '3':
                cout << "Goodbye!" << endl;
                exit(0); // Exit the program.
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    } while (choice != '3');
}

//Main program start
int main() {
    cout << "This is the main menu for Vincent's CSDP250 Projects." << endl;
    cout << "Please select from the following menu:" << endl;
    cout << "1. Project 1 - Linked Lists" << endl;
    cout << "2. Project 2 - Double Linked List" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            project1();
            break;
        case 2:
            project2();
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
