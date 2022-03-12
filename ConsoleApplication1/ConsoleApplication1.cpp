// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <math.h>

#pragma warning(disable: 6031)

bool EventHappens(double prob)
{
    size_t range = 100;
    if (prob > 100.0 || prob < 0.0)
        throw "Invalid probability";
    if (prob == 100.0)
        return true;
    if (prob == 0.0)
        return false;
    while (prob - floor(prob) != 0.0)
    {
        range *= 10;
        prob *= 10.0;
    }
    prob *= prob;
    return !((int)prob % (1 + rand() % range));
}

bool E(double prob)
{
    size_t range = 100;
    if (prob > 100.0 || prob < 0.0)
        throw "Invalid probability";
    if (prob == 100.0)
        return true;
    if (prob == 0.0)
        return false;
    while (prob - floor(prob) != 0.0)
    {
        range *= 10;
        prob *= 10.0;
    }
    return ((double)(1 + rand() % range)) <= prob;
}

int main()
{
    srand(time(NULL));
    bool res1, res2;
    double a = 50.0;
    for (size_t i = 0; i < 10; i++)
    {
        try
        {
            res1 = EventHappens(a);
            res2 = E(a);
        }
        catch (const char* msg)
        {
            std::cout << std::string(msg) << std::endl;
            _getch();
            return 1;
        }
        std::cout << (res1 ? "Event 1 happened" : "Event 1 didn't happen") << ' ' << (res2 ? "Event 2 happened" : "Event 2 didn't happen") << std::endl;
    }
    _getch();
    return 0;
}
