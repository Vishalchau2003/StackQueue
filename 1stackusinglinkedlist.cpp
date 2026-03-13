
  #include <iostream>
using namespace std;

// Structure for a stack node
struct stacknode {
    int data;          // Data stored in the node
    stacknode* next;   // Pointer to the next node in the stack

    // Constructor to initialize a new node
    stacknode(int x) {
        data = x;
        next = NULL;
    }
};

// Stack class implementation using linked list
class stack {
private:
    stacknode* top;  // Pointer to the top element of the stack
    int size;        // Variable to store the size of the stack

public:
    // Constructor to initialize stack
    stack() {//when we will initialise an new object
        top = NULL;  // Initially, the stack is empty
        size = 0;    // Stack size is 0 at the beginning
    }

    // Function to push an element onto the stack
    void push(int x) {
        stacknode* temp = new stacknode(x); // Create a new node

        if (temp == nullptr) {  // Check for memory allocation failure
            cout << "Stack Overflow" << endl;
            return;
        }

        temp->next = top; // Link the new node to the top
        top = temp;       // Update top to the new node
        size++;           // Increase stack size
    }

    // Function to pop the top element from the stack
    int pop() {
        if (top == NULL) {  // Check if stack is empty
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int x = top->data;     // Store the data to return
        stacknode* temp = top; // Store the current top
        top = top->next;       // Move top to the next node
        delete temp;           // Free the memory of the popped node
        size--;                // Decrease stack size
        return x;
    }

    // Function to get the current size of the stack
    int getSize() {
        return size;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Function to get the top element of the stack without removing it
    int peek() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
};

// Main function to test the stack implementation
int main() {
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl; // Should print 30
    cout << "Popped element: " << s.pop() << endl; // Should print 30
    cout << "Current size: " << s.getSize() << endl; // Should print 2

    return 0;
}
