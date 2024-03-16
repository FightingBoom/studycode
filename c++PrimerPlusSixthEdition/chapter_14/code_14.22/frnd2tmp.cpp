#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
private:
    T item;
    static int ct;

public:
    HasFriend(const T & i) : item(i) {ct++;}
    ~HasFriend() {ct--;}

    friend void counts();

    friend void reports(HasFriend<T> &);
};

template <typename T>
int HasFriend<T>::ct = 0;

void counts()
{
    cout << "int count: " << HasFriend<int>::ct << "; ";
    cout << "double count: "
        << HasFriend<double>::ct << endl;
}

void reports(HasFriend<int> & hf)
{
    cout << "HasFriend<int>: " << hf.item << endl;
}

void reports(HasFriend<double> & hf)
{
    cout << "HasFriend<double>: " << hf.item << endl;
}

int main()
{
    cout << "No objects declared: ";
    counts();

    HasFriend<int> hfi1(10);
    cout << "After hfi1 declared: ";
    counts();

    HasFriend<int> hfi2(20);
    cout << "After hfi2 declared: ";
    counts();

    HasFriend<double> hfdb(10.5);
    cout << "After hfdb declared: ";
    counts();

    reports(hfi1);
    reports(hfi2);
    reports(hfdb);

    return 0;
}

/*
zhaochen@zhaochendeAir code_14.22 % ./a.out 
No objects declared: int count: 0; double count: 0
After hfi1 declared: int count: 1; double count: 0
After hfi2 declared: int count: 2; double count: 0
After hfdb declared: int count: 2; double count: 1
HasFriend<int>: 10
HasFriend<int>: 20
HasFriend<double>: 10.5
*/
