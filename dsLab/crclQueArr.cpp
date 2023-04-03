#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;     
    int front;
    int rear;
    int size;

public:
    CircularQueue(int size)
    {
        arr = new int[size];
        front = -1;
        rear = -1;
        this->size = size;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % size == front);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int i;
        for (i = front; i != rear; i = (i + 1) % size)
        {
            cout << arr[i] << " ";
        }
        cout << arr[i] << endl;
    }
};

int main()
{
    CircularQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6); // Should print "Queue is full"
    q.display();  // Should print "1 2 3 4 5"
    q.dequeue();
    q.dequeue();
    q.display();              // Should print "3 4 5"
    cout << q.peek() << endl; // Should print "3"
    return 0;
}
