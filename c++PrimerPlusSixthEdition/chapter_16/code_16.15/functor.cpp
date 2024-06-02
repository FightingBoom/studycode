#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<class T>
class TooBig
{
private:
    T cutoff;

public:
    TooBig(const T & t) : cutoff(t) {}
    bool operator()(const T & v) { return v > cutoff; }
};

void outint(int n)
{
    std::cout << n << " ";
}

int main()
{
    using std::list;
    using std::cout;
    using std::endl;

    TooBig<int> f100(100);
    int vals[10] =
    {
        50, 100, 90, 180, 60,
        210, 415, 88, 188, 201
    };

    list<int> yadayada(vals, vals + 10);
    list<int> etcetera(vals, vals + 10);

    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    yadayada.remove_if(f100);             // 删除大于100的
    etcetera.remove_if(TooBig<int>(200)); // 删除大于200的
    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    return 0;
}

/*
zhaochen@zhaochendeAir code_16.15 % ./a.out 
Original lists:
50 100 90 180 60 210 415 88 188 201 
50 100 90 180 60 210 415 88 188 201 
Trimmed lists:
50 100 90 60 88 
50 100 90 180 60 88 188
*/
