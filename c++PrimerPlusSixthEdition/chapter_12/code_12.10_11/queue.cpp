#include "queue.h"
#include <cstdlib>

Queue::Queue(int qs) : qsize(qs)
{
    front = rear = NULL;
    items = 0;
}

Queue::~Queue()
{
    Node * temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

bool Queue::enqueue(const Item & item)
{
    if (isfull())
    {
        return false;
    }

    Node * add = new Node;  // 申请一块新的内存区域
    add->item = item;       // 存储实际数据
    add->next = NULL;       // 将下一个指针置空，表示当前为最后一个元素
    items++;                // 总的元素计数+1

    if (front == NULL)      // 判断当前链表是否只有这一个元素
    {
        front = add;
    }
    else
    {
        rear->next = add;
    }

    rear = add; // 将最后一个元素指向add；不管列表中是否为0个元素，都需要将新添加的指向最后一个元素；
    return true;
}

bool Queue::dequeue(Item & item)
{
    if (front == NULL)
    {
        return false;
    }

    item = front->item;     // 获取新的front元素地址
    items--;                // 总计数-1
    Node * temp = front;    // 使用临时指针获取上一个front的地址
    front = front->next;    // 更改front为最新的首元素地址
    delete temp;            // 删除上一个元素地址

    if (items == 0)         // 判断数组总元素是否为0，是的话应该将rear尾元素指针也置空
    {
        rear = NULL;
    }

    return true;
}

void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}


