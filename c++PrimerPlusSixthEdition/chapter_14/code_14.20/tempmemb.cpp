#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class beta
{
private:
    template <typename V>
    class hold
    {
    private:
        V val;
    public:
        hold(V v = 0) : val(v) {}
        void show() const { cout << val << endl; }
        V Value() const { return val; }
    };

    hold<T> q;      // 模板变量
    hold<int> n;    // 模板变量

public:
    beta(T t, int i) : q(t), n(i) {}

    // 模板方法
    template<typename U>
    U blab(U u, T t)
    {
        return (n.Value() + q.Value()) * u / t;
    }

    void Show() const
    {
        q.show();
        n.show();
    }
};


// 测试代码
int main()
{
    // 使用beta(T t, int i)构造，T为double类型
    beta<double> guy(3.5, 3);
    cout << "T was set to double\n";
    guy.Show();

    cout << "V was set to T, which is double, "
        << "then V was set to int\n";

    // inline int beta<double>::blab<int>(int u, double t)
    cout << guy.blab(10, 2.3) << endl;
    cout << "U was set to int\n";

    // inline double beta<double>::blab<double>
    //      (double u, double t)
    cout << guy.blab(10.0, 2.3) << endl;
    cout << "U was set to double\n";

    cout << "Done\n";
    return 0;
}

/*
zhaochen@zhaochendeAir code_14.20 % ./a.out 
T was set to double
3.5
3
V was set to T, which is double, then V was set to int
28
U was set to int
28.2609
U was set to double
Done
*/
