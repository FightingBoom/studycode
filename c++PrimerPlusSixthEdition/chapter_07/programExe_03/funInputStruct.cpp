#include <iostream>

using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void showBuffer(box buffer);
void ProcessVolume(box * buffer);

int main()
{
    box makerBuffer;
    
    cout << "Please input maker: ";
    cin.getline(makerBuffer.maker, 40);

    cout << "Please input height: ";
    cin >> makerBuffer.height;

    cout << "Please input width: ";
    cin >> makerBuffer.width;

    cout << "Please input length: ";
    cin >> makerBuffer.length;

    ProcessVolume(&makerBuffer);
    showBuffer(makerBuffer);

    return 0;
}

void showBuffer(box buffer)
{
    cout << "buffer.maker: " << buffer.maker << endl;
    cout << "buffer.height: " << buffer.height << endl;
    cout << "buffer.width: " << buffer.width << endl;
    cout << "buffer.length: " << buffer.length << endl;
    cout << "buffer.volume: " << buffer.volume << endl;
}

void ProcessVolume(box * buffer)
{
    buffer->volume = buffer->height * buffer->length * buffer->width;
}

/*
Please input maker: hello word
Please input height: 180
Please input width: 30
Please input length: 50
buffer.maker: hello word
buffer.height: 180
buffer.width: 30
buffer.length: 50
buffer.volume: 270000
*/
