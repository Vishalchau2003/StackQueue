#include<iostream>
using namespace std;

class Queue {
private:
    int start;      // Points to the front element
    int end;        // Points to the last element
    int size;       // Maximum size of the queue
    int currsize;   // Current number of elements
    int *arr;       // Dynamic array for queue storage

public:
    // Constructor to initialize queue with default size 16
    Queue() {
        start = -1;
        end = -1;
        currsize = 0;
        size = 16;
        arr = new int[size];  // Dynamically allocating memory for queue
    }

    // Push function (enqueue operation)
    void push(int x) {
        if (currsize == size) {  // If queue is full
            cout << "Overflow\n";
            return;
        }
        if (start == -1 && end == -1) {  // If queue is initially empty
            start = 0;
            end = 0;
        } 
        else {
            end = (end + 1) % size;  // Move end pointer circularly
        }
        arr[end] = x;  // Store the new element
        currsize++;    // Increase queue size
    }

    // Pop function (dequeue operation)
    int pop() {
        if (start == -1) {  // If queue is empty
            cout << "Underflow\n";
            return -1;  // Return -1 to indicate failure
        }
        int x = arr[start];  // Store the element to return

        if (currsize == 1) {  // If only one element was present
            start = -1;
            end = -1;
            currsize = 0;
        } else {
            start = (start + 1) % size;  // Move start pointer circularly
            currsize--;  // Decrease queue size
        }
        return x;  // Return the removed element
    }

    // Function to get the front element
    int top() {
        if (start == -1) {  // If queue is empty
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[start];  // Return front element
    }

    // Function to return the current size of the queue
    int getSize() {
        return currsize;
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q;  // Create a queue

    q.push(8);
    q.push(7);
    q.push(5);

    cout << "Popped element: " << q.pop() << endl;  // Should print 8
    cout << "Front element: " << q.top() << endl;   // Should print 7
    cout << "Queue size: " << q.getSize() << endl;  // Should print 2

    return 0;
}
