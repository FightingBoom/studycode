#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
    using namespace std;

    const int N = 6;
    string s1[N] =
    {
        "buffoon", "thinkers",
        "for", "heavy",
        "can", "for"
    };
    string s2[N] =
    {
        "metal", "any",
        "food", "elegant",
        "deliver", "for"
    };

    set<string> A(s1, s1 + N);
    set<string> B(s2, s2 + N);

    ostream_iterator<string, char> out(cout, " ");
    cout << "Set A: ";
    copy(A.begin(), A.end(), out);
    cout << endl;

    cout << "Set B: ";
    copy(B.begin(), B.end(), out);
    cout << endl;

    // 并集
    cout << "Union of A and B:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    // 交集
    cout << "Intersection of A and B:\n";
    set_intersection(A.begin(), A.end(),
        B.begin(), B.end(), out);
    cout << endl;

    // A和B的区别
    cout << "Difference of A and B:\n";
    set_difference(A.begin(), A.end(),
        B.begin(), B.end(), out);
    cout << endl;

    set<string> C;
    cout << "Set C:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(),
        insert_iterator<set<string> >(C, C.begin()));
    copy(C.begin(), C.end(), out);
    cout << endl;

    string s3("grungy");
    C.insert(s3);
    cout << "Set C after insertion:\n";
    copy(C.begin(), C.end(), out);
    cout << endl;

    cout << "Showing a range:\n";
    copy(C.lower_bound("ghost"),
        C.upper_bound("spook"), out);
    cout << endl;

    return 0;
}

/*
zhaochen@zhaochendeAir code_16.13 % clang++ setops.cpp 
zhaochen@zhaochendeAir code_16.13 % ./a.out 
Set A: buffoon can for heavy thinkers 
Set B: any deliver elegant food for metal 
Union of A and B:
any buffoon can deliver elegant food for heavy metal thinkers 
Intersection of A and B:
for 
Difference of A and B:
buffoon can heavy thinkers 
Set C:
any buffoon can deliver elegant food for heavy metal thinkers 
Set C after insertion:
any buffoon can deliver elegant food for grungy heavy metal thinkers 
Showing a range:
grungy heavy metal
*/
