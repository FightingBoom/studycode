#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int LIMIT = 5;

void file_it(ostream & os, double fo, const double fe[], int n);

int main()
{
    ofstream fout;
    const char * fn = "ep-data.txt";
    fout.open(fn);
    if (!fout.is_open())
    {
        cout << "Can't open " << fn << ". Bye.\n";
        exit(EXIT_FAILURE);
    }

    double objective;
    cout << "Enter the focal length of your telescope objective in mm: ";
    cin >> objective;
    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepieces:\n";

    for (int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }

    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);
    cout << "Done\n";

    return 0;
}

void file_it(ostream & os, double fo, const double fe[], int n)
{
    // initial获取setf返回的，调用它之前有效的所有格式化设置；
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed); // 置为使用定点表示法的模式

    os.precision(0); // 指定显示多少位小数
    os << "Focal length of objective: " << fo << " mm\n";
    os.setf(ios::showpoint); // 置为显示小数点的模式
    os.precision(1);
    os.width(12); // 设置下一次输出操作使用的字段宽度，只在显示下一个值时有效，然后将恢复到默认设置0；
    os << "f.1. eyepiece";
    os.width(15);
    os << "magnification" << endl;

    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int (fo/fe[i] + 0.5) << endl;
    }

    os.setf(initial);
}

/*
Enter the focal length of your telescope objective in mm: 1800
Enter the focal lengths, in mm, of 5 eyepieces:
Eyepiece #1: 30
Eyepiece #2: 19
Eyepiece #3: 14
Eyepiece #4: 8.8
Eyepiece #5: 7.5
Focal length of objective: 1800 mm
f.1. eyepiece  magnification
        30.0             60
        19.0             95
        14.0            129
         8.8            205
         7.5            240
Done
*/

/*
文件内容参考：ep-data.txt
*/
