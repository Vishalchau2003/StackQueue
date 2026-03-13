#include<iostream>
using namespace std;

// Class to implement stack
class Stack {
    int size;  // Maximum size of the stack
    int *arr;  // Dynamic array for stack storage
    int topIndex; // Tracks the top element's index

public:
    // Constructor to initialize stack
    Stack() {
        topIndex = -1;  // Stack is empty initially
        size = 1000;  // Default stack size
        arr = new int[size];  // Allocate memory for stack
    }

    // Push function to insert an element into the stack
    void push(int x) {
        if (topIndex == size - 1) {  // Check for stack overflow
            cout << "Stack Overflow\n";
            return;
        }
        topIndex++;  // Move top index up
        arr[topIndex] = x;  // Insert element
    }

    // Pop function to remove the top element from the stack
    int pop() {
        if (topIndex == -1) {  // Check for stack underflow
            cout << "Stack Underflow\n";
            return -1; // Return invalid value if stack is empty
        }
        int x = arr[topIndex];  // Store the top element
        topIndex--;  // Move top index down
        return x;  // Return popped element
    }

    // Function to return the top element without removing it
    int top() {
        if (topIndex == -1) {  // Check if stack is empty
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[topIndex];  // Return the top element
    }

    // Function to return the current size of the stack
    int Size() {
        return topIndex + 1;
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }
};

// Main function
int main() {
    Stack s;  // Create a stack

    s.push(3);
    s.push(6);
    s.push(9);

    cout << "Popped element is " << s.pop() << endl;  // Should print 9
    cout << "Top element is " << s.top() << endl;     // Should print 6
    cout << "Stack size is " << s.Size() << endl;     // Should print 2

    return 0;
}




