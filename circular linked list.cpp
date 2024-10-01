#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() : tail(NULL) {}


    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (!tail) {
            tail = newNode;
            newNode->next = tail;
        } else {
            Node* temp = tail;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = tail;
            tail = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (!tail) {
            tail = newNode;
            newNode->next = tail;
        } else {
            Node* temp = tail;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = tail;
        }
    }


    void deleteAtBeginning() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        if (tail->next == tail) {
            delete tail;
            tail = NULL;
            return;
        }
        Node* temp = tail;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = tail->next;
        delete tail;
        tail = temp->next;
    }


    void deleteAtEnd() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        if (tail->next == tail) {
            delete tail;
            tail = NULL;
            return;
        }
        Node* temp = tail;
        while (temp->next->next != tail) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = tail;
    }


    bool search(int value) {
        if (!tail) return false;
        Node* temp = tail;
        do {
            if (temp->data == value) return true;
            temp = temp->next;
        } while (temp != tail);
        return false;
    }


    void traverse() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = tail;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail);
        cout << endl;
    }
};


int main() {
    CircularLinkedList cll;
    int choice, value;

    do {
        cout << "\nCircular Linked List Operations:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete at Beginning\n";
        cout << "4. Delete at End\n";
        cout << "5. Search\n";
        cout << "6. Traverse\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                cll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                cll.insertAtEnd(value);
                break;
            case 3:
                cll.deleteAtBeginning();
                break;
            case 4:
                cll.deleteAtEnd();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (cll.search(value)) {
                    cout << value << " found in the list." << endl;
                } else {
                    cout << value << " not found in the list." << endl;
                }
                break;
            case 6:
                cout << "List contents: ";
                cll.traverse();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}

