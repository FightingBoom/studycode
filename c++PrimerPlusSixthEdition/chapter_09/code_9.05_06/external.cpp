#include <iostream>

using namespace std;

double warming = 0.3;

void update(double dt);
void local();

int main()
{
    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);
    cout << "Global warming is " << warming << " degrees.\n";
    local();
    cout << "Global warming is " << warming << " degrees.\n";

    return 0;
}

/*
PS E:\91-GitRepository\studycode\c++PrimerPlusSixthEdition\chapter_09\code_9.05_06> g++ .\external.cpp .\support.cpp
PS E:\91-GitRepository\studycode\c++PrimerPlusSixthEdition\chapter_09\code_9.05_06>
PS E:\91-GitRepository\studycode\c++PrimerPlusSixthEdition\chapter_09\code_9.05_06> .\a.exe
Global warming is 0.3 degrees.
Updating global warming to 0.4 degrees.
Global warming is 0.4 degrees.
Local warming = 0.8 degrees.
But global warming = 0.4 degrees.
Global warming is 0.4 degrees.
*/
