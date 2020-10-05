#include "Colorsk.h"


//use color definitions 
void Colorsk::sclr(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

//user color definition back and text
void Colorsk::sclr(int bg, int fg)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(bg + fg));
}
