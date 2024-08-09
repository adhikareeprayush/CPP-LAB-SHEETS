#include <iostream>
#include <stdexcept> // For std::runtime_error
using namespace std;

// Exception class for stack overflow
class StackOverflowException : public runtime_error {
public:
    StackOverflowException() : runtime_error("Stack overflow: Cannot push to a full stack.") {}
};

// Exception class for stack underflow
class StackUnderflowException : public runtime_error {
public:
    StackUnderflowException() : runtime_error("Stack underflow: Cannot pop from an empty stack.") {}
};


template <typename T>
class Stack {
private:
    static const int MAX_SIZE = 100; // Define a maximum size for the stack
    T arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    // Add an element to the stack
    void push(const T& item) {
        if (top >= MAX_SIZE - 1) {
            throw StackOverflowException(); // Throw exception if stack is full
        }
        arr[++top] = item;
    }

    // Remove an element from the stack
    T pop() {
        if (top < 0) {
            throw StackUnderflowException(); // Throw exception if stack is empty
        }
        return arr[top--];
    }

    // Peek at the top element of the stack
    T peek() const {
        if (top < 0) {
            throw StackUnderflowException(); // Throw exception if stack is empty
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top < 0;
    }

    // Display the contents of the stack
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack contents: ";
        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Stack<int> intStack;

    try {
        // Push elements onto the stack
        for (int i = 0; i < 105; ++i) { // Attempt to exceed stack capacity
            intStack.push(i);
        }
    } catch (const StackOverflowException& e) {
        cout << e.what() << endl;
    }

    try {
        // Pop elements from the stack
        for (int i = 0; i < 105; ++i) { // Attempt to pop more elements than present
            cout << "Popped: " << intStack.pop() << endl;
        }
    } catch (const StackUnderflowException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
