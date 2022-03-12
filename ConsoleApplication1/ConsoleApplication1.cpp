// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>

#pragma warning(disable: 6031)

bool EventHappens(double a, int R)
{
    //if (!(a > 0.0) && !(a < 0.0))
    if (a > 100.0 || a < 0.0)
        throw "Invalid probability";
    if(R > 100 || R < 1)
        throw "Invalid input number";
    if (a == 100.0)
        return true;
    if (a == 0.0)
        return false;

    return true;
}

int main()
{
    srand(time(NULL));
    int R = 1 + rand() % 100;
    double a = 13.0;
    try
    {
        bool res = EventHappens(a, R);
    }
    catch (const char* msg)
    {
        std::cout << std::string(msg) << std::endl;
        _getch();
        return 1;
    }
    return 0;
}
