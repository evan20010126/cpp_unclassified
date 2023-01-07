#include <iostream>
using namespace std;

struct my_struct
{
    int numerator;
    int denominator;
};

int main()
{
    while (true)
    {
        my_struct F;
        cin >> F.numerator;
        cin >> F.denominator;
        if (F.numerator == 1 && F.denominator == 1)
        {
            break;
        }
        my_struct L;
        my_struct M;
        my_struct R;
        L.numerator = 0;
        L.denominator = 1;
        M.numerator = 1;
        M.denominator = 1;
        R.numerator = 1;
        R.denominator = 0;
        long double Fd = F.numerator / (long double)F.denominator;
        long double Md = M.numerator / (long double)M.denominator;
        while (!(M.denominator == F.denominator && M.numerator == F.numerator))
        {
            if (Fd > Md)
            {
                L.numerator = M.numerator;
                L.denominator = M.denominator;
                M.numerator = M.numerator + R.numerator;
                M.denominator = M.denominator + R.denominator;
                cout << "R";
            }
            else
            {
                R.numerator = M.numerator;
                R.denominator = M.denominator;
                M.numerator = M.numerator + L.numerator;
                M.denominator = M.denominator + L.denominator;
                cout << "L";
            }
            Md = M.numerator / (long double)M.denominator;
        }
        cout << endl;
    }

    return 0;
}