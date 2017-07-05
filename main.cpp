#include <iostream>

using namespace std;

typedef struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void add(int value) {

    Node *tmpNode = new Node;
    tmpNode->next = NULL;
    tmpNode->value = value;

    if (head == NULL) {
        head = tmpNode;
        return;
    }

    Node *currentNode = head;

    while (currentNode) {
        if (currentNode->next == NULL) {
            currentNode->next = tmpNode;
            return;
        }
        currentNode = currentNode->next;
    }
}

bool remove(int position) {
    if (position == -1) {
        return false;
    }

    int counter = 1;

    Node *currentNode = head;
    Node *previousNode = head;

    while (currentNode) {

        if (position == counter) {
            previousNode->next = currentNode->next;
            break;
        }
        counter++;
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    return true;
}

int getIndex(int value) {
    int position = -1;
    int counter = 0;
    while (head) {
        if (head->value == value) {
            position = counter;
        }
        head = head->next;
        ++counter;
    }
    cout << "Found item at index " << position << endl;
    return position;
}

void list() {

    Node *tmpHead = head;

    while (tmpHead) {
        int tmpValue = tmpHead->value;
        cout << "Listing item " << tmpValue << endl;
        tmpHead = tmpHead->next;
    }
}

int main() {

    add(1);
    add(2);
    add(3);
    add(4);
    list();
    remove(3);
    list();
    getIndex(4);
    getIndex(5);

    return 0;
}