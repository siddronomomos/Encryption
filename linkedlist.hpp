#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class CircularDoublyLinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
        Node(const T &data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node *head;

public:
    CircularDoublyLinkedList() : head(nullptr) {}

    ~CircularDoublyLinkedList()
    {
        if (head)
        {
            Node *current = head;
            do
            {
                Node *nextNode = current->next;
                delete current;
                current = nextNode;
            } while (current != head);
        }
    }

    void append(const T &data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    // void display() const
    // {
    //     if (!head)
    //         return;
    //     Node *current = head;
    //     do
    //     {
    //         std::cout << current->data << " ";
    //         current = current->next;
    //     } while (current != head);
    //     std::cout << std::endl;
    // }

    int size() const
    {
        if (!head)
            return 0;
        int count = 0;
        Node *current = head;
        do
        {
            ++count;
            current = current->next;
        } while (current != head);
        return count;
    }

    T &get(int index) const
    {
        Node *current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
        return current->data;
    }

    Node *find(const T &data) const
    {
        if (!head)
            return nullptr;
        Node *current = head;
        do
        {
            if (current->data == data)
                return current;
            current = current->next;
        } while (current != head);
        return nullptr;
    }
};

#endif // LINKEDLIST_H