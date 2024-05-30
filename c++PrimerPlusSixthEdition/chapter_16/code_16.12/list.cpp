#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

void outint(int n)
{
    std::cout << n << " ";
}

int main()
{
    using namespace std;

    list<int> one(5, 2);
    int stuff[5] = {1, 2, 4, 8, 6};

    list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);

    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int> three(two);
    three.insert(three.end(), more, more + 6);

    cout << "List one: ";
    for_each(one.begin(), one.end(), outint);
    cout << endl << "List two: ";

    for_each(two.begin(), two.end(), outint);
    cout << endl << "List three: ";

    for_each(three.begin(), three.end(), outint);
    three.remove(2);
    cout << endl << "List three minus 2s: ";

    for_each(three.begin(), three.end(), outint);
    three.splice(three.begin(), one); // 将one插入到three前
    cout << endl << "List three after splice: ";
    for_each(three.begin(), three.end(), outint);

    cout << endl << "List one: "; // one被使用后会清空
    for_each(one.begin(), one.end(), outint);
    three.unique(); // 将连续的相同元素压缩为单个元素
    cout << endl << "List three after unique: ";
    for_each(three.begin(), three.end(), outint);
    three.sort();   // 按递增顺序排列
    three.unique();
    cout << endl << "List three after sort & unique: ";
    for_each(three.begin(), three.end(), outint);

    two.sort();
    three.merge(two); // 合并排序后的两个链表
    cout << endl << "Sorted two merged into three: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    return 0;
}

/*
zhaochen@zhaochendeAir code_16.12 % clang++ list.cpp 
zhaochen@zhaochendeAir code_16.12 % ./a.out 
List one: 2 2 2 2 2 
List two: 1 2 4 8 6 
List three: 1 2 4 8 6 6 4 2 4 6 5 
List three minus 2s: 1 4 8 6 6 4 4 6 5 
List three after splice: 2 2 2 2 2 1 4 8 6 6 4 4 6 5 
List one: 
List three after unique: 2 1 4 8 6 4 6 5 
List three after sort & unique: 1 2 4 5 6 8 
Sorted two merged into three: 1 1 2 2 4 4 5 6 6 8 8
*/
