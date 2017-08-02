#include <iostream>

void Exercise1()
{
    // ������� ��� ����� �� ��������� 100...2000 � �������� �������, � ������� ��������� ����� ����� 2 3 4

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
    // ������ N ����� (N �������� �������������) � ���������� � ����� ����� ���� �����

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
    // ������ N ����� � ����� ���� ����� ����� �����������

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
    // ����� ��� �������� ��������� ����� N
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

    for (int i = 1; i <= iInput; i++)
    {
        if (!(iInput%i))
            std::cout << i << std::endl;
    }
}

void Exercise5()
{
    // ������� ��� �������� (a, b, c) � ���������� � ������� ������������ �� ���

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
    //������� �������� ����� N � �������� ������� (N: 12345 -> 54321). ����� N ���� int. ���. �����,
    //���� �� ������ ����������� �����, � �������� ����� ����� M

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
    // ����� ��� ������������ �������� � �������� ������������� ������������������
    // �.�. �������� ����� ��������, ��� � ������� �������, ������ ������� ��� ������������
    // ������: ���� 4 2 1 8 5 2 9 4 12 6 7     �����: 9 12

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
        if (!i) //1
        {
            iBiggestMaximum = iInput;
        }
        else    //2+
        {
            if (iInput >= iBiggestMaximum)
            {
                iSmallerMaximum = iBiggestMaximum;
                iBiggestMaximum = iInput;
                isSmallerNotExists = false;
            }
            else if ((iInput < iBiggestMaximum && iInput > iSmallerMaximum) || isSmallerNotExists) //�� ������� ������� ������� = 0 ��� �������
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

