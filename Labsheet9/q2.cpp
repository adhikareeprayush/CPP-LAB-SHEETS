#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    static const int MAX_SIZE = 100; // Define a maximum size for the queue
    T arr[MAX_SIZE];
    int front;
    int rear;
    int size;

public:
    Queue() : front(0), rear(-1), size(0) {}

    // Add an element to the end of the queue
    void enqueue(const T& item) {
        if (size < MAX_SIZE) {
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = item;
            ++size;
        } else {
            cout << "Queue is full. Cannot enqueue." << endl;
        }
    }

    // Remove an element from the front of the queue
    T dequeue() {
        if (size > 0) {
            T item = arr[front];
            front = (front + 1) % MAX_SIZE;
            --size;
            return item;
        } else {
            cout << "Queue is empty. Cannot dequeue." << endl;
            // Return a default-constructed object of type T
            return T();
        }
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Display the contents of the queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue contents: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[(front + i) % MAX_SIZE] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Create and use a queue of integers
    Queue<int> intQueue;
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);
    intQueue.display(); // Output: Queue contents: 1 2 3
    cout << "Dequeued: " << intQueue.dequeue() << endl; // Output: Dequeued: 1
    intQueue.display(); // Output: Queue contents: 2 3

    // Create and use a queue of doubles
    Queue<double> doubleQueue;
    doubleQueue.enqueue(1.1);
    doubleQueue.enqueue(2.2);
    doubleQueue.enqueue(3.3);
    doubleQueue.display(); // Output: Queue contents: 1.1 2.2 3.3
    cout << "Dequeued: " << doubleQueue.dequeue() << endl; // Output: Dequeued: 1.1
    doubleQueue.display(); // Output: Queue contents: 2.2 3.3

    // Create and use a queue of strings
    Queue<string> stringQueue;
    stringQueue.enqueue("Hello");
    stringQueue.enqueue("World");
    stringQueue.enqueue("Queue");
    stringQueue.display(); // Output: Queue contents: Hello World Queue
    cout << "Dequeued: " << stringQueue.dequeue() << endl; // Output: Dequeued: Hello
    stringQueue.display(); // Output: Queue contents: World Queue

    return 0;
}
