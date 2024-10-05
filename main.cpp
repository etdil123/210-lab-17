// Ethan Dilk | Lab 17 | COMSC 210
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void addNodeFront(Node * &head, Node * newVal, int tmp_val);
void addNodeEnd(Node * &head);
void deleteNode(Node * &head);
void insertNode(Node * &head);
void deleteList(Node * &head);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        addNodeFront(head, newVal, tmp_val);
    }
    output(head);

    deleteNode(head);
    
    insertNode(head);

    addNodeEnd(head);

    deleteList(head);
    

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addNodeFront(Node * &head, Node * newVal, int tmp_val){
     // adds node at head
    if (!head) { // if this is the first node, it's the new head
        head = newVal;
        newVal->next = nullptr;
        newVal->value = tmp_val;
    }
    else { // its a second or subsequent node; place at the head
        newVal->next = head;
        newVal->value = tmp_val;
        head = newVal;
    }
}

void addNodeEnd(Node * &head){
    // insert node at the end
    Node * current = head;

    int entry;
    cout << "Enter value to insert at the end: " << endl;
    cin >> entry;

    Node * prev = head;
    // Traverse to end of linked list
    for (int i = 0; i < (SIZE); i++){
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    }

    // At the end, insert a new node
    Node * newnode = new Node;
    newnode->value = entry;
    newnode->next = nullptr;
    prev->next = newnode;
    output(head);
    
}

void deleteNode(Node * &head){

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);
}

void insertNode(Node * &head){
    // insert a nodee
    Node * current = head;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    int entry;
    cin >> entry;

    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);
}

void deleteList(Node * &head){
    // deleting the linked list
    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
}
    



