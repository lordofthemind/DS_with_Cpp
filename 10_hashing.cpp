#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 100;

struct Node
{
    int key;
    char data[MAX_SIZE];
    Node *next;
};

class HashTable
{
private:
    Node **table;
    int size;

public:
    HashTable(int size)
    {
        this->size = size;
        table = new Node *[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = NULL;
        }
    }

    int hash(int key)
    {
        return key % size;
    }

    void insert(int key, const char data[])
    {
        int index = hash(key);
        Node *newNode = new Node;
        newNode->key = key;
        strcpy(newNode->data, data);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void search(int key)
    {
        int index = hash(key);
        Node *currentNode = table[index];
        bool found = false;
        while (currentNode != NULL)
        {
            if (currentNode->key == key)
            {
                found = true;
                cout << "Data for key " << key << " is: " << currentNode->data << endl;
                break;
            }
            currentNode = currentNode->next;
        }
        if (!found)
        {
            cout << "Data for key " << key << " not found" << endl;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            Node *currentNode = table[i];
            while (currentNode != NULL)
            {
                Node *temp = currentNode;
                currentNode = currentNode->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

int main()
{
    HashTable ht(10);
    ht.insert(1, "John");
    ht.insert(11, "Emily");
    ht.insert(21, "Michael");
    ht.insert(31, "Samantha");

    ht.search(11);
    ht.search(21);
    ht.search(31);
    ht.search(41);

    return 0;
}
