//
//  main.cpp
//  Queue
//
//  Created by Ira Xavier Porchia on 5/22/20.
//  Copyright © 2020 Ira Xavier Porchia. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX = 4;

//class Queue{
//private:
//    int _head;
//    int _tail;
//public:
//    int _data[MAX];
//
//    Queue():
//    _head(0), _tail(0){}
//
//    bool isEmpty(){
//        return _tail == _head;
//    }
//
//    bool isFull(){
//        return (_tail + 1) % MAX == _head;
//    }
//
//    int dequeue(){
//        if (isEmpty()) {
//            cout << "dequeue: Can't dequeue an empty queue.\n " << endl;
//            return 0;
//        }
//        int i = _data[_head];
//        _head = (_head + 1) % MAX;
//        return i;
//    }
//
//    void enqueue(int value){
//        if (isFull()) {
//            cout << "enqueue: Can't enqueue a full queue.\n" << endl;
//            return;
//        }
//        _data[_tail] = value;
//        cout << value << " enqueued onto queue \n" << endl;
//        _tail = (_tail + 1) % MAX;
//    }
//
//    int head(){
//        return _data[_head];
//    }
//
//};

class node{
    friend class LQueue;
private:
    int _data;
    node *_next;
public:
    node(int data):
    _data(data), _next(nullptr){}
};

class LQueue{
private:
    node *_head;
public:
    LQueue():
    _head(nullptr){};
    
    ~LQueue(){
        if(_head == nullptr){
            return;
        }
        node *p;
        while(_head != nullptr){
            p = _head;
            _head = _head->_next;
            p->_next = nullptr;
            delete p;
        }
    }
    
    void enqueue(int data){
        if(_head == nullptr){
            _head = new node(data);
            cout << _head->_data << " enqueued into queue.\n" << endl;
            return;
        }
        node *p = new node(data);
        p->_next = _head;
        _head = p;
        cout << p->_data << " enqueued into queue.\n" << endl;
    }
    
    int dequeue(){
        if(_head == nullptr){
            cout << "Can't dequeue from an empty queue.\n" << endl;
            return 0;
        }
        node *p = _head;
        node *q = _head;
        while(p->_next != nullptr){
            q = p;
            p = p->_next;
        }
        q->_next = nullptr;
        if(q == p){
            _head = nullptr;
        }
        return p->_data;
    }
    
    void traverse(){
        node *p = _head;
        while(p != nullptr){
            cout << p->_data << " ";
            p = p->_next;
        }
        cout << endl;
    }
    
};

int main(int argc, const char * argv[]) {
//    Queue s;
//    s.enqueue(10);
//    s.enqueue(20);
//    s.enqueue(30);
//    cout << s.dequeue() << " Dequeued from queue\n" << endl;
//    cout << s.dequeue() << " Dequeued from queue\n"<< endl;
//    cout << s.dequeue() << " Dequeued from queue\n"<< endl;
//    s.enqueue(40);
//    s.enqueue(50);
//    s.enqueue(60);
//    cout << s.dequeue() << " Dequeued from queue\n" << endl;
//    cout << s.dequeue() << " Dequeued from queue\n"<< endl;
//    cout << s.dequeue() << " Dequeued from queue\n"<< endl;
        LQueue s;
        s.enqueue(10);
        s.enqueue(20);
        s.enqueue(30);
    s.traverse();
        cout << s.dequeue() << " Dequeued from queue\n" << endl;
        cout << s.dequeue() << " Dequeued from queue\n"<< endl;
        cout << s.dequeue() << " Dequeued from queue\n"<< endl;
        s.enqueue(40);
        s.enqueue(50);
        s.enqueue(60);
    s.traverse();
        cout << s.dequeue() << " Dequeued from queue\n" << endl;
        cout << s.dequeue() << " Dequeued from queue\n"<< endl;
        cout << s.dequeue() << " Dequeued from queue\n"<< endl;
    return 0;
}
