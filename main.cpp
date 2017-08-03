#include <iostream>

void Exercise1()
{
    // вывести все числа из диапазона 100...2000 в обратном порядке, у которых последняя цифра равна 2 3 4

    for (int i = 2000; i >= 100; --i)
    {
        int iRestNum = i % 10;
        if (iRestNum == 2 || iRestNum == 3 || iRestNum == 4)
        {
            std::cout << i << std::endl;
        }
    }
}

void Exercise2()
{
    // ввести N чисел (N вводится пользователем) с клавиатуры и найти сумму всех чисел

    int iNumbers (0);
    int iSum (0);

    std::cout << "Enter how many numbers you want to sum" << std::endl;

    std::cin >> iNumbers;

    if (iNumbers <= 0)
    {
        std::cout << "Amount of numbers can`t be null or negative number. Only unsigned integer" << std::endl;
        return;
    }
    std::cout << "Enter numbers:" << std::endl;

    for (int i = 0; i < iNumbers; i++)
    {
        int iInput(0);
        std::cin >> iInput;

        iSum += iInput;
    }

    std::cout << "Sum of entered numbers = " << iSum << std::endl;
}

void Exercise3()
{
    // ввести N чисел и среди всех чисел найти минимальное

    int iNumbers (0);
    int iMinimumNumber(0);
    std::cout << "Enter how many numbers you want to enter (find minimum input)" << std::endl;

    std::cin >> iNumbers;
    if (iNumbers <= 0)
    {
        std::cout << "Amount of numbers can`t be null or negative number. Only unsigned integer" << std::endl;
        return;
    }
    std::cout << "Enter numbers:" << std::endl;

    for (int i = 0; i < iNumbers; i++)
    {
        int iInput(0);
        std::cin >> iInput;

        if (i == 0)
        {
            iMinimumNumber = iInput;
        }
        else
        {
            if (iInput < iMinimumNumber)
                iMinimumNumber = iInput;
        }
    }

    std::cout << std::endl << "Minimum is :" << iMinimumNumber << std::endl;
}


void Exercise4()
{
    // найти все делители заданного числа N
    int iInput = 0;

    std::cout << "Enter signed number (find all dividers): " << std::endl;

    std::cin >> iInput;

    if (iInput == 0)
    {
        std::cout << "You can`t use null input" << std::endl;
        return;
    }

    std::cout << std::endl;

    if (iInput < 0)
        iInput *= -1;

    int iLastNum = iInput/2;

    for (int i = 1; i <= iLastNum; i++)
    {
        if (!(iInput%i))
            std::cout << i << std::endl;
    }

    std::cout << iInput << std::endl;
}

void Exercise5()
{
    // введите три значения (a, b, c) с клавиатуры и найдите максимальное из них

    int iMaximum = 0;
    std::cout << "Enter three signed numbers (find maximum)" << std::endl << std::endl;

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
            std::cin >> iMaximum;
        else
        {
            int iCurrentNum = 0;
            std::cin >> iCurrentNum;

            if (iCurrentNum > iMaximum)
                iMaximum = iCurrentNum;
        }
    }

    std::cout << std::endl << "Maximum is: " << iMaximum <<  std::endl;
}

void Exercise6()
{
    //вывести введённое число N в обратном порядке (N: 12345 -> 54321). Число N типа int. Доп. бонус,
    //если не просто распечатать цифры, а получить новое число M

    int iInput = 0;
    int iDigitsNumber = 0;
    int iOutputNumber = 0;
    std::cout << "Enter signed number (reverse)" << std::endl;

    std::cin >> iInput;

    int iDivider = 1;
    for (int i = 1; i < 10; i++)
    {
        iDivider *= 10;

        if ((iInput%iDivider) == iInput)
        {
            iDigitsNumber = i;
            break;
        }
    }

    int iCurrentDigit = iDigitsNumber;
    for (int i = 1; i <= iDigitsNumber; i++)
    {
        int iCurrentExp = 1;

        for (int j = 1; j < iCurrentDigit; j++)
            iCurrentExp *= 10;

        iOutputNumber += iInput%10 * iCurrentExp;
        iInput /= 10;

        iCurrentDigit--;
    }

    std::cout << std::endl << iOutputNumber << std::endl;
}

void Exercise7()
{
    // найти два максимальных элемента в введённой пользователем последовательности
    // т.е. вводится набор значений, как в прошлых задачах, только находим два максимальных
    // пример: ввод 4 2 1 8 5 2 9 4 12 6 7     вывод: 9 12

    int iNumbers (0);
    int iBiggestMaximum(0);
    int iSmallerMaximum(0);

    bool isSmallerNotExists = true;
    std::cout << "Enter how many numbers you want to enter (find 2 maximums in input)" << std::endl;

    std::cin >> iNumbers;
    if (iNumbers <= 0)
    {
        std::cout << "Amount of numbers can`t be null or negative number. Only unsigned integer" << std::endl;
        return;
    }
    std::cout << "Enter numbers:" << std::endl;

    for (int i = 0; i < iNumbers; i++)
    {
        int iInput(0);
        std::cin >> iInput;
        if (!i)
        {
            iBiggestMaximum = iInput;
        }
        else
        {
            if (iInput >= iBiggestMaximum)
            {
                iSmallerMaximum = iBiggestMaximum;
                iBiggestMaximum = iInput;
                isSmallerNotExists = false;
            }
            else if ((iInput < iBiggestMaximum && iInput > iSmallerMaximum) || isSmallerNotExists)
            {
                iSmallerMaximum = iInput;
                isSmallerNotExists = false;
            }
        }
    }

    if (isSmallerNotExists)
    {
        std::cout << "Only 1 entered, so maximum is: " << iBiggestMaximum << std::endl;
    }
    else
    {
        std::cout << "Maximums: " << iSmallerMaximum << " " << iBiggestMaximum << std::endl;
    }
}

int main()
{
    Exercise1();
    Exercise2();
    Exercise3();
    Exercise4();
    Exercise5();
    Exercise6();
    Exercise7();

    return 0;
}

