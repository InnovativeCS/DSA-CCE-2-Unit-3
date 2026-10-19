#include <iostream>
#include <string>
using namespace std;

struct Node {
    int rollNo;
    string name;
    Node* left;
    Node* right;

    Node(int r, string n) {
        rollNo = r;
        name = n;
        left = right = NULL;
    }
};

class StudentRecord {
private:
    Node* root;

    Node* insert(Node* node, int roll, string name) {
        if (node == NULL)
            return new Node(roll, name);

        if (roll < node->rollNo)
            node->left = insert(node->left, roll, name);
        else if (roll > node->rollNo)
            node->right = insert(node->right, roll, name);

        return node;
    }

    Node* search(Node* node, int roll) {
        if (node == NULL || node->rollNo == roll)
            return node;

        if (roll < node->rollNo)
            return search(node->left, roll);

        return search(node->right, roll);
    }

    void sortedDisplay(Node* node) {
        if (node == NULL)
            return;

        sortedDisplay(node->left);

        cout << "Roll Number: " << node->rollNo
             << " | Name: " << node->name << "\n";

        sortedDisplay(node->right);
    }

    int countNodes(Node* node) {
        if (node == NULL)
            return 0;

        return 1 + countNodes(node->left)
                 + countNodes(node->right);
    }

    void deleteTree(Node* node) {
        if (node == NULL)
            return;

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    StudentRecord() {
        root = NULL;
    }

    ~StudentRecord() {
        deleteTree(root);
    }

    void insertRecord() {
        int roll;
        string name;

        cout << "Enter Roll Number: ";
        if (!(cin >> roll)) {
            cout << "Invalid roll number!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        }

        if (roll <= 0) {
            cout << "Roll number must be positive!\n";
            return;
        }

        if (search(root, roll) != NULL) {
            cout << "Roll number already exists!\n";
            return;
        }

        cout << "Enter Student Name: ";
        cin >> ws;
        getline(cin, name);

        if (name.empty()) {
            cout << "Name cannot be empty!\n";
            return;
        }

        root = insert(root, roll, name);
        cout << "Student record inserted successfully!\n";
    }

    void searchRecord() {
        int roll;

        cout << "Enter Roll Number to Search: ";
        if (!(cin >> roll)) {
            cout << "Invalid roll number!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        }

        Node* result = search(root, roll);

        if (result == NULL) {
            cout << "Student record not found!\n";
        } else {
            cout << "\nStudent Record Found\n";
            cout << "Roll Number: " << result->rollNo << "\n";
            cout << "Name: " << result->name << "\n";
        }
    }

    void displayRecords() {
        if (root == NULL) {
            cout << "No student records available!\n";
            return;
        }

        cout << "\nStudent Records in Sorted Order\n";
        cout << "--------------------------------\n";
        sortedDisplay(root);
    }

    void countRecords() {
        cout << "Total Student Records: "
             << countNodes(root) << "\n";
    }
};

int main() {
    StudentRecord s;
    int choice;

    do {
        cout << "\n====================================\n";
        cout << " STUDENT RECORD MANAGEMENT SYSTEM\n";
        cout << "       USING BINARY SEARCH TREE\n";
        cout << "====================================\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Search Student Record\n";
        cout << "3. Display Records in Sorted Order\n";
        cout << "4. Count Total Nodes\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                s.insertRecord();
                break;

            case 2:
                s.searchRecord();
                break;

            case 3:
                s.displayRecords();
                break;

            case 4:
                s.countRecords();
                break;

            case 5:
                cout << "Program ended successfully.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
