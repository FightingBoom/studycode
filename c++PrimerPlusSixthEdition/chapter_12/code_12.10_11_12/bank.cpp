#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    std::srand(std::time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (line.isfull())
            {
                turnaways++;
            }
            else{
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }

        if (wait_time <= 0 && !line.isempty())
        {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }

        if (wait_time > 0)
        {
            wait_time--;
        }

        sum_line += line.queuecount();
    }

    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: " << (double) line_wait / served << " minutes\n";
    }
    else
    {
        cout << "No customers!\n";
    }

    cout << "Done!\n";

    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}


/* 队列最大人数不同，平均等候时间不同
PS E:\91-GitRepository\studycode\c++PrimerPlusSixthEdition\chapter_12\code_12.10_11_12> .\a.exe
Case Study: Bank of Heather Automatic Teller
Enter maximum size of queue: 10
Enter the number of simulation hours: 100
Enter the average number of customers per hour: 15
customers accepted: 1468
         turnaways: 0
average queue size: 0.20
 average wait time: 0.80 minutes
Done!
PS E:\91-GitRepository\studycode\c++PrimerPlusSixthEdition\chapter_12\code_12.10_11_12> .\a.exe
Case Study: Bank of Heather Automatic Teller
Enter maximum size of queue: 10
Enter the number of simulation hours: 100
Enter the average number of customers per hour: 30
customers accepted: 2891
  customers served: 2891
         turnaways: 80
average queue size: 4.50
 average wait time: 9.35 minutes
Done!
PS E:\91-GitRepository\studycode\c++PrimerPlusSixthEdition\chapter_12\code_12.10_11_12> .\a.exe
Case Study: Bank of Heather Automatic Teller
Enter maximum size of queue: 20
Enter the number of simulation hours: 100
Enter the average number of customers per hour: 30
customers accepted: 2952
  customers served: 2942
         turnaways: 54
average queue size: 9.98
 average wait time: 20.32 minutes
Done!
*/

/* 队列最大人数固定，平均等候时间也不同
PS E:\91-GitRepository\studycode\c++PrimerPlusSixthEdition\chapter_12\code_12.10_11_12> .\a.exe
Case Study: Bank of Heather Automatic Teller
Enter maximum size of queue: 10
Enter the number of simulation hours: 4
Enter the average number of customers per hour: 30
customers accepted: 120
         turnaways: 0
average queue size: 1.90
 average wait time: 3.83 minutes
Done!
PS E:\91-GitRepository\studycode\c++PrimerPlusSixthEdition\chapter_12\code_12.10_11_12> .\a.exe
Case Study: Bank of Heather Automatic Teller
Enter maximum size of queue: 10
Enter the number of simulation hours: 4
Enter the average number of customers per hour: 30
customers accepted: 117
  customers served: 109
         turnaways: 5
average queue size: 4.89
 average wait time: 10.04 minutes
Done!
PS E:\91-GitRepository\studycode\c++PrimerPlusSixthEdition\chapter_12\code_12.10_11_12> .\a.exe
Case Study: Bank of Heather Automatic Teller
Enter maximum size of queue: 10
Enter the number of simulation hours: 4
Enter the average number of customers per hour: 30
customers accepted: 113
  customers served: 111
         turnaways: 0
average queue size: 1.90
 average wait time: 4.07 minutes
Done!
*/
