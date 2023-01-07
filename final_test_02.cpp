/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

//�Ч�����ӹB��l�и�,err_detection�Mfind_intersection�禡
#include <iostream>
#include <cmath>
using namespace std;
const double TOL = 1.e-13;
//���`�B�z���O
class Err
{
private:
    int kind; //�i�ΨӧP�_���`�������A�p���I���|(�ثe�]�w���Ȭ�1)�B�S�����I�B��u���|
public:
    Err(int i) : kind(i) {}
    //�����B��l�и��\��A�z�Lkind���ȱN���P���������`���A�^��
    friend ostream &operator<<(ostream &out, const Err &foo);
};
//�ͦ��I�y�Ъ����O
class Point
{
private:
    double x, y;

public:
    Point(double a = 0., double b = 0.) : x(a), y(b) {}
    //�N���@�I�����I�ھ��D�N��X
    friend ostream &operator<<(ostream &out, const Point &pt)
    {
        return out << "(" << (abs(pt.x) < TOL ? 0. : pt.x)
                   << "," << (abs(pt.y) < TOL ? 0. : pt.y)
                   << ")";
    }

    friend istream &operator>>(istream &in, Point &pt)
    {
        return in >> pt.x >> pt.y;
    }
    //�����B��l�и��\��A�z�L�Ө禡������I�y�ЬO�_�۵��A�۵��^��true
    friend bool operator==(const Point &a, const Point &b);
    friend class Line;
};
//�z�L���I(Point����)�c���@�u
class Line
{
private:
    Point pt1, pt2;
    double a, b, c; //���u��{����ax+by=c

public:
    Line(const Point &m, const Point &n) : pt1(m), pt2(n)
    {
        if (m == n)
        {                  //�z�L�B��l�и��\�������I�y��
            throw(Err(1)); //�Y�L�k�c���u(���I���|)�����p�A�Y�XErr����
        }
        if (pt1.x == pt2.x)
        {
            a = 1;
            b = 0;
            c = pt1.x;
        }
        else
        {
            a = (pt2.y - pt1.y) / (pt2.x - pt1.x);
            b = -1;
            c = a * pt1.x - pt1.y;
        }
    }

    friend Point intersection(const Line &line1, const Line &line2);

    //�ݧ������禡�A�\��D�n�O�^�ǲ��`������("�S�����I"��"��u���|")�A�S�����`�^��0
    friend int err_detection(const Line &line1, const Line &line2);
    //�ݧ������禡�A�p��X��u���@�I���I�y�СA�i�z�Lx,y�x�s�p��X��xy�y��
    friend void find_intersection(const Line &line1, const Line &line2, double *x, double *y);
};
//���z�Lerr_detection()�P�_line1, line2�O�_�����`�A����A�z�Lfind_intersection()��X���@�I���I�y��
Point intersection(const Line &line1, const Line &line2)
{
    double point_x, point_y;                  //���I���I�y��
    int errlog = err_detection(line1, line2); //����X�O�_�����`
    if (errlog != 0)
        throw(Err(errlog));
    else
    {
        find_intersection(line1, line2, &point_x, &point_y); //�p��X���@�I���I�y��
        return Point(point_x, point_y);
    }
}

int main()
{
    Point pt1, pt2, pt3, pt4;
    while (cin >> pt1 >> pt2 >> pt3 >> pt4)
    {
        try
        {
            Line line1(pt1, pt2);
            Line line2(pt3, pt4);
            cout << intersection(line1, line2) << endl;
        }
        catch (const Err &err)
        {
            cout << err << endl;
        }
    }
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE*/

int err_detection(const Line &line1, const Line &line2)
{
    if (((line1.b == 0) && (line2.b == 0) && (line1.c == line2.c)))
    {
        return 2;
    }
    else if (((line1.b == 0) && (line2.b == 0) && (line1.c != line2.c)))
    {
        return 3;
    }

    double deltax1 = line1.c * line2.b - line1.b * line2.c;
    double dletax2 = line1.a * line2.c - line1.c * line2.a;
    double delta = line1.a * line2.b - line2.a * line1.b;
    if (delta != 0)
    {
        return 0; //�S���D
    }
    else if (deltax1 == 0 && dletax2 == 0)
    {
        return 2; //��u���|
    }
    else
    {
        return 3; //�S�����I
    }
};

void find_intersection(const Line &line1, const Line &line2, double *x, double *y)
{
    double deltax1 = line1.c * line2.b - line1.b * line2.c;
    double dletax2 = line1.a * line2.c - line1.c * line2.a;
    double delta = line1.a * line2.b - line2.a * line1.b;
    *x = deltax1 / delta;
    *y = dletax2 / delta;
}

ostream &operator<<(ostream &out, const Err &foo)
{
    if (foo.kind == 1)
    {
        out << "���I���|";
    }
    else if (foo.kind == 2)
    {
        out << "��u���|";
    }
    else if (foo.kind == 3)
    {
        out << "�S�����I";
    }
    return out;
}

bool operator==(const Point &a, const Point &b)
{
    if ((a.x == b.x) && (a.y == b.y))
    {
        return true;
    }
    else
    {
        return false;
    }
};