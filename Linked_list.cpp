#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head, * sp, * front, * rear;

void init() {
    head = nullptr;
    front = nullptr;
    rear = nullptr;
    sp = nullptr;
}

// Ham duyet va in danh sach lien ket
void traverselNode() {
    Node* p = head;
    cout << "Danh sach: ";
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Dem so node
int countNodes() {
    int count = 0;
    Node* p = head;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

// Them mot node vao vi tri dau tien
void addHead(Node*& head, int x) {
    Node* newNode = new Node{ x, head };
    head = newNode;
}

// Them 1 node vao vi tri cuoi
void addTail(Node*& head, int x) {
    Node* newNode = new Node{ x, nullptr };
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Xoa node dau
void removeHead(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Xoa node cuoi
void removeTail(Node*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* p = head;
    while (p->next->next != nullptr)
        p = p->next;
    delete p->next;
    p->next = nullptr;
}

// Xoa nodes trung lap
void removeDuplicates(Node* head) {
    Node* q = head;
    while (q != nullptr && q->next != nullptr) {
        Node* runner = q;
        while (runner->next != nullptr) {
            if (runner->next->data == q->data) {
                Node* duplicate = runner->next;
                runner->next = duplicate->next;
                delete duplicate;
            }
            else {
                runner = runner->next;
            }
        }
        q = q->next;
    }
}


// Ham them element vao stack
void push(int x) {
    Node* p = new Node{ x, sp };
    sp = p;
}

// Tra ve element dau tien cua stack
int top() {
    if (sp == nullptr) {
        cout << "Stack rong" << endl;
        return -1;
    }
    return sp->data;
}

// Lay gia tri tu stack
int pop(int& x) {
    if (sp != nullptr) {
        Node* p = sp;
        x = p->data;
        sp = p->next;
        delete p;
        return 1;
    }
    return 0;
}

// Them vao queue
void enqueue(int x) {
    Node* p = new Node{ x, nullptr };
    if (rear == nullptr)
        front = p;
    else
        rear->next = p;
    rear = p;
}

// Xoa khoi queue
int dequeue(int& x) {
    if (front != nullptr) {
        Node* p = front;
        x = p->data;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete p;
        return 1;
    }
    return 0;
}


int frontValue() {
    if (front == nullptr) {
        cout << "Queue rong!\n";
        return -1;
    }
    return front->data;
}

int main() {
    init();

    addTail(head, 2);
    addTail(head, 8);
    addTail(head, 2);
    addTail(head, 9);
    addTail(head, 3);
    addTail(head, 4);
    addTail(head, 5);

    cout << "Danh sach lien ket don ban dau: ";
    traverselNode();

    cout << "So node: " << countNodes() << endl;

    cout << "Them node 8 vao dau: ";
    addHead(head, 8);
    traverselNode();

    cout << "Them node 5 vao cuoi: ";
    addTail(head, 5);
    traverselNode();

    // Xoa node dau
    removeHead(head);
    cout << "Xoa node dau: ";
    traverselNode();

    // Xoa node cuoi
    removeTail(head);
    cout << "Xoa node cuoi: ";
    traverselNode();

    // Xoa elements trung lap
    removeDuplicates(head);
    cout << "Xoa node trung lap: ";
    traverselNode();

    // Stack operations
    cout << "\n--- Stack operations ---\n";

    // Them mot so element vao stack
    push(10);
    push(20);
    push(30);

    cout << "Stack sau khi push: ";
    Node* temp = sp;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    int x;
    if (pop(x)) {
        cout << "Da pop thanh cong! Lay ra " << x << endl;
    }
    else {
        cout << "Stack trong! Pop khong thanh cong!\n";
    }

    cout << "Stack sau khi pop: ";
    temp = sp;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Phan tu tren cung cua stack la: " << top() << endl;

    // Queue
    cout << "\n--- Queue operations ---\n";

    enqueue(100);
    enqueue(200);
    enqueue(300);

    cout << "Front cua Queue la: " << frontValue() << endl;

    if (dequeue(x)) {
        cout << "Da dequeue thanh cong! Lay ra " << x << endl;
    }
    else {
        cout << "Queue rong! Khong dequeue duoc.\n";
    }

    cout << "Queue sau khi dequeue la: " << frontValue() << endl;

    return 0;
}
