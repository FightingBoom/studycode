#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

class Grand
{
private:
    int hold;

public:
    Grand(int h = 0) : hold(h) {}

    virtual void Speak() const
    {
        cout << "I am a grand class!\n";
    }

    virtual int Value() const
    {
        return hold;
    }
};

class Superb : public Grand
{
public:
    Superb(int h = 0) : Grand(h) {}

    void Speak() const
    {
        cout << "I am a superb class!!\n";
    }

    virtual void Say() const
    {
        cout << "I hold the superb value of "
            << Value() << "!\n";
    }
};

class Magnificent : public Superb
{
private:
    char ch;
public:
    Magnificent(int h = 0, char c = 'A')
        : Superb(h), ch(c) {}

    void Speak() const
    {
        cout << "I am a magnificent class!!!\n";
    }

    void Say() const
    {
        cout << "I hold the character " << ch <<
            " and the integer " << Value() << "!\n";
    }
};


Grand * GetOne();

int main()
{
    std::srand(std::time(0));
    Grand * pg;
    Superb * ps;

    for (int i = 0; i < 5; i++)
    {
        pg = GetOne();
        pg->Speak();

        // 赋值结果做判断需要加括号，否则clang++编译有警告
        if ((ps = dynamic_cast<Superb *>(pg)))
        {
            ps->Say();
        }
    }

    return 0;
}

Grand * GetOne()
{
    Grand * p;
    switch (std::rand() % 3)
    {
    case 0:
        p = new Grand(std::rand() % 100);
        break;
    case 1:
        p = new Superb(std::rand() % 100);
        break;
    case 2:
        p = new Magnificent(std::rand() % 100,
            'A' + std::rand() % 26);
        break;
    default:
        break;
    }

    return p;
}

/*
zhaochen@zhaochendeAir code_15.17 % ./a.out
I am a magnificent class!!!
I hold the character P and the integer 98!
I am a magnificent class!!!
I hold the character S and the integer 19!
I am a magnificent class!!!
I hold the character M and the integer 69!
I am a magnificent class!!!
I hold the character H and the integer 71!
I am a grand class!
zhaochen@zhaochendeAir code_15.17 % ./a.out
I am a superb class!!
I hold the superb value of 88!
I am a grand class!
I am a superb class!!
I hold the superb value of 67!
I am a grand class!
I am a superb class!!
I hold the superb value of 66!
zhaochen@zhaochendeAir code_15.17 % ./a.out
I am a superb class!!
I hold the superb value of 76!
I am a magnificent class!!!
I hold the character E and the integer 36!
I am a magnificent class!!!
I hold the character M and the integer 49!
I am a magnificent class!!!
I hold the character T and the integer 15!
I am a magnificent class!!!
I hold the character X and the integer 67!
*/
