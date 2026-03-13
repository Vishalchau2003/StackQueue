
// #include<iostream>
// #include<stack>
// using namespace std;

// class Queue{
//   stack<int>s1,s2; // Two stacks used for implementing queue
//   public:
  
//   // Function to push an element into the queue
//   void Push(int x){
//     // Move all elements from s1 to s2
//     while(s1.size()){
//         s2.push(s1.top());
//         s1.pop();
//     }
    
//     // Push the new element onto s1
//     s1.push(x);
    
//     // Move elements back from s2 to s1
//     while(s2.size()){
//      s1.push(s2.top());
//      s2.pop();
//     }
//   }
  
//   // Function to pop the front element of the queue
//   int Pop(){
//     if(s1.empty()){
//         cout << "Queue is empty!" << endl;
//         return -1; // Indicating queue underflow
//     }
//     int x = s1.top(); // Store the front element
//     s1.pop(); // Remove the front element
//     return x;
//   }
// };

// int main() {
//     Queue q;
//     q.Push(1);
//     q.Push(2);
//     q.Push(3);
    
//     cout << "Popped: " << q.Pop() << endl; // Output: 1
//     cout << "Popped: " << q.Pop() << endl; // Output: 2
//     cout << "Popped: " << q.Pop() << endl; // Output: 3
//     cout << "Popped: " << q.Pop() << endl; // Output: Queue is empty!
    
//     return 0;
// }


#include<iostream>
#include<stack>
using namespace std;

class Queue{
  stack<int> s1, s2; // Two stacks used for implementing queue
  public:
  
  // Function to push an element into the queue
  void Push(int x){
    s1.push(x); // Push element onto stack s1
  }
  
  // Function to pop the front element of the queue
  int Pop(){
    if(!s2.empty()){ // If s2 has elements, pop from it
        int x = s2.top();
        s2.pop();
        return x;
    }
    else{
        if(s1.empty()){ // If both stacks are empty, queue is empty
            cout << "Queue is empty!" << endl;
            return -1; // Indicating queue underflow
        }
        
        // Move all elements from s1 to s2 to reverse order
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        int x = s2.top(); // Get the front element
        s2.pop(); // Remove the front element
        return x;
    }
  }
  
  // Function to get the front element of the queue
  int Top(){
    if(!s2.empty()){ // If s2 has elements, return the top element
        return s2.top();
    }
    else{
        if(s1.empty()){ // If both stacks are empty, queue is empty
            cout << "Queue is empty!" << endl;
            return -1;
        }
        
        // Move all elements from s1 to s2 to reverse order
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        return s2.top(); // Return the front element
    }
  }
};

int main() {
    Queue q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    
    cout << "Popped: " << q.Pop() << endl; // Output: 1
    cout << "Popped: " << q.Pop() << endl; // Output: 2
    cout << "Popped: " << q.Pop() << endl; // Output: 3
    cout << "Popped: " << q.Pop() << endl; // Output: Queue is empty!
    
    return 0;
}



