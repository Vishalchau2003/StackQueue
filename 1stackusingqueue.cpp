

  #include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue<int> q;  // Using a queue to implement stack

public:
    // Function to push an element into the stack
    void push(int x) {
        int s = q.size(); // Get current size of the queue
        q.push(x); // Insert new element at the end of the queue

        //We are able to use q.push(), q.pop(), and other queue operations inside the class methods because these methods (push(), pop(), top(), etc.) are members of the same class.

        
        // Rotate previous elements to the back of the queue to maintain stack order
        for (int i = 0; i < s; i++) {
            q.push(q.front()); // Move front element to the back
            q.pop(); // Remove the front element
        }
    }

    // Function to remove and return the top element of the stack
    int pop() {
        if (q.empty()) { // Check if the stack is empty
            cout << "Stack is empty! Cannot pop." << endl;
            return -1; // Indicating error
        }
        int x = q.front(); // Get the top element
        q.pop(); // Remove the top element
        return x;
    }

    // Function to return the top element without removing it
    int top() {
        if (q.empty()) { // Check if the stack is empty
            cout << "Stack is empty! No top element." << endl;
            return -1; // Indicating error
        }
        return q.front(); // The top element is at the front of the queue
    }

    // Function to return the size of the stack
    int size() {
        return q.size();
    }
};

int main() {
    Stack s;
    
    // Pushing elements into the stack
    s.push(3);
    s.push(2);
    s.push(4);
    s.push(1);

    // Display the top element of the stack
    cout << "Top of the stack: " << s.top() << endl;

    // Display the size of the stack before removing an element
    cout << "Size of the stack before removing element: " << s.size() << endl;

    // Remove the top element and display it
    cout << "The deleted element is: " << s.pop() << endl;

    // Display the top element after removal
    cout << "Top of the stack after removing element: " << s.top() << endl;

    // Display the size of the stack after removing an element
    cout << "Size of the stack after removing element: " << s.size() << endl;

    return 0;
}
