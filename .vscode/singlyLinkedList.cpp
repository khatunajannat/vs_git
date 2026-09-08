#include <bits/stdc++.h>
using namespace std;

struct node
{

    int data;
    node *link;
};

node *head = NULL;

void printing()
{

    node *current = head;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->link;
    }

    cout << endl;
}

void searching(int val)
{

    int f = 0;
    node *current = head;
    while (current != NULL)
    {

        if (current->data == val)
        {
            f = 1;

            cout << " Found " << endl;
        }
        current = current->link;
    }
    if (f == 0)
    {
        cout << "**** NOT FOUND ****" << endl;
    }
}

void printFirst()
{

    cout << head->data << endl;
}

void printLast()
{

    node *current = head;
    while (current->link != NULL)
    {

        current = current->link;
    }
    cout << current->data << endl;
}

void printsecLast()
{

    node *current = head;
    // node *prev = current;
    while (current->link->link != NULL)
    {
        // prev = current;
        // current = prev -> link;
        current = current->link;
    }
    cout << " second last node data : ";
    cout << current->data << endl;
    // cout << prev->data <<endl;
}

void printReversed(node *temp)
{

    if (temp != NULL)
    {

        printReversed(temp->link);

        cout << temp->data << endl;
    }
}

void deleteFirst()
{
    node *ptr = head;
    head = ptr->link;
    free(ptr);
}

void deleteLast()
{
    node *current = head;

    while (current->link->link != NULL)
    {

        current = current->link;
    }

    current->link = NULL;
}

void deleteLast()
{

    node *current = head;
    node *prev = head;

    while (current->link != NULL)
    {

        prev = current;
        current = current->link;
    }
    prev->link = NULL;
    free(current);
}

void insertingFirst(int val)
{

    node *temp = new node();
    temp->data = val;
    temp->link = head;
    head = temp;
}

void insertingLast(int val)
{

    node *temp = new node();
    temp->data = val;
    node *current = head;
    while (current->link != NULL)
    {

        current = current->link;
    }
    current->link = temp;
    temp->link = NULL;
}

void insertingByValue(int val, int key)
{

    node *temp = new node();
    temp->data = val;
    node *current = head;

    while (current->link->data != key && current != NULL)
    {

        current = current->link;
    }

    temp->link = current->link;
    current->link = temp;
}

void insertt(int val, int pos)
{

    if (pos == 1)
    {

        insertingFirst(val);
    }
    else
    {
        node *current = head;
        int i = 1;

        node *temp = new node();
        temp->data = val;
        while (i < pos - 1 && current->link != NULL)
        {
            i++;
            current = current->link;
        }

        temp->link = current->link;
        current->link = temp;
    }
}

void deletingByPos(int pos)
{

    if (pos == 1)
    {
        node *ptr = head;
        head = head->link;
        free(ptr);
    }
    else
    {

        node *current = head;
        node *prev = head;
        int i = 1;
        while (i < pos && current->link != NULL)
        {
            i++;
            prev = current;
            current = current->link;
        }
        prev->link = current->link;
        free(current);
    }
}

void deletingByValue(int key)
{

    node *current = head;
    node *prev = head;

    while (current->data != key && current->link != NULL)
    {

        prev = current;
        current = current->link;
    }
    prev->link = current->link;
    free(current);
}

int main()
{
    node *p, *q, *r;
    p = new node();
    q = new node();
    r = new node();

    p->data = 10;
    q->data = 30;
    r->data = 50;
    p->link = q;
    q->link = r;
    r->link = NULL;

    head = p;
    deletingByValue(30);
    // deletingByPos(2);
    // deleteFirst();
    // deleteLast();
    // insertt(40,3);
    //  insertingByValue(15,30);
    //  insertingFirst(5);
    //  insertingLast(70);

    printing();
    // searching(60);
    // printFirst();
    // printLast();
    // printsecLast();
    // cout<< "Reverse data: "<< endl;
    // printReversed(head);
}
