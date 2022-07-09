#include <iostream>
using namespace std;

struct Node
{

    int data;
    Node *next;
};

struct List
{

    Node *head = nullptr;
    Node *tail = nullptr;

    void insertNode(int data);
    void removeNode(int data);
    void display();
};

void List::insertNode(int data)
{

    Node *aux = new Node;
    aux->data = data;
    aux->next = nullptr;

    if (head == nullptr)
    {
        head = aux;
        tail = aux;
    }
    else
    {
        tail->next = aux;
        tail = aux;
    }
}

void List::removeNode(int data)
{

    Node *current = head;
    Node *previous = nullptr;

    while (current != nullptr)
    {
        if (current->data == data)
        {
            if (previous == nullptr)
            { // HEAD
                head = current->next;
            }
            else if (current->next == nullptr)
            { //TAIL
                previous->next = nullptr;
                tail = previous;
            }
            else
            {
                previous->next = current->next;
            }
            delete current;
            return;
        }

        previous = current;
        current = current->next;
    }
}

void List::display()
{

    Node *aux = head;
    while (aux != nullptr)
    {
        cout << aux->data << "\t";
        aux = aux->next;
    }
    cout << endl;
}

int main()
{
    List lista;

    lista.insertNode(111);
    lista.insertNode(222);
    lista.display();

    return 0;
}