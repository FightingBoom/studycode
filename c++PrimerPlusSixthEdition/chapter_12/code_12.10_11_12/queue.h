#ifndef QUEUE_H_
#define QUEUE_H_

class Customer
{
private:
    long arrive;
    int processtime;

public:
    Customer()
    {
        arrive = processtime = 0;
    }

    void set(long when);

    long when() const
    {
        return arrive;
    }

    int ptime() const
    {
        return processtime;
    }
};

typedef Customer Item;

class Queue
{
private:
    struct Node
    {
        Item item;
        struct Node * next; // 竟然可以嵌套使用自身的结构体定义
    };

    enum
    {
        Q_SIZE = 10
    };

    Node * front; // 链表第一个元素
    Node * rear;  // 链表最后一个元素
    int items;
    const int qsize;

    Queue(const Queue & q) : qsize(0) {}
    Queue & operator=(const Queue & q) { return *this; }

public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item);
    bool dequeue(Item &item);
};

#endif // !QUEUE_H_