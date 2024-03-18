#ifndef TVFM_H_
#define TVFM_H_

// 前向声明
class Tv;

// Remote需要用到Tv类做参数，因此需要在前边声明Tv类
class Remote
{
public:
    enum State{Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};

private:
    int mode;

public:
    Remote(int m = TV) : mode(m) {}
    bool volup(Tv & t);
    bool voldown(Tv & t);

    void onoff(Tv & t);

    void chanup(Tv & t);
    void chandown(Tv & t);

    void set_mode(Tv & t);

    void set_input(Tv & t);

    void set_chan(Tv & t, int c);
};

// Tv类内部有Remote友元函数，因此必须在Remote声明之后
class Tv
{
public:
    // 仅声明一个友元函数
    friend void Remote::set_chan(Tv & t, int c);

    enum State{Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};

    Tv(int s = Off, int mc = 125)
        : state(s), volume(5), maxchannel(mc),
        channel(2), mode(Cable), input(TV)
        {}

    void onoff() {state = (state == On) ? Off : On;}

    bool ison() const {return state == On;}

    bool volup();
    bool voldown();

    void chanup();
    void chandown();

    void set_mode()
    {
        mode = (mode == Antenna) ? Cable : Antenna;
    }

    void set_input()
    {
        input = (input == TV) ? DVD : TV;
    }

    void settings() const;

private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
};

// Remote 类方法定义
inline bool Remote::volup(Tv & t)
{
    return t.volup();
}

inline bool Remote::voldown(Tv & t)
{
    return t.voldown();
}

inline void Remote::onoff(Tv & t)
{
    t.onoff();
}

inline void Remote::chanup(Tv & t)
{
    t.chanup();
}

inline void Remote::chandown(Tv & t)
{
    t.chandown();
}

inline void Remote::set_chan(Tv & t, int c)
{
    t.channel = c;
}

inline void Remote::set_mode(Tv & t)
{
    t.set_mode();
}

inline void Remote::set_input(Tv & t)
{
    t.set_input();
}

#endif
