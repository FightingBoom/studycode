#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
    std::string str;
public:
    Report(const std::string s) : str(s)
    {
        std::cout << "Object created!\n";
    }

    ~Report()
    {
        std::cout << "Object deleted!\n";
    }

    void comment() const
    {
        std::cout << str << "\n";
    }
};

int main()
{
    {
        // vscode提示找不到头文件，但可以编译通过
        std::auto_ptr<Report>
            ps (new Report("using auto_ptr"));

        ps->comment();
    }

    {
        std::shared_ptr<Report>
            ps (new Report("using shared_ptr"));

        ps->comment();
    }

    {
        std::unique_ptr<Report>
            ps (new Report("using unique_ptr"));

        ps->comment();
    }

    return 0;
}

/*
zhaochen@zhaochendeAir code_16.05 % ./a.out 
Object created!
using auto_ptr
Object deleted!
Object created!
using shared_ptr
Object deleted!
Object created!
using unique_ptr
Object deleted!
*/

