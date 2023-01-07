#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

// �ϥΥ����ܼ�
//queen : �ӦZ��m
class Queens
{
private:
    int counter;      //�p��ŦX�\�k���`��
    bool queen[8][8]; //�x�s�ӦZ��m�A�Y�Ӯy�Ь��ӦZ�]��ture
    // �ˬd�s���ӦZ�Y�\��b (r,c) ��m�O�_�A��
    bool valid_position(int r, int c)
    {
        // �ˬd�O�_�P�w�����ӦZ�b�P�@��, �P�@�C�Φb�﨤�u�W
        //�Y���b�P�@��B�P�@�C�ι﨤�u���ܦ^��false�A�Ϥ��^��true
        /*---------------------------------*/
        for (int i = 0; i < 8; i++)
        {
            if (queen[r][i] == true || queen[i][c] == true)
            {
                return false;
            }
        }

        int k = 1;
        while (r - k >= 0 && c + k <= 7)
        {
            if (queen[r - k][c + k] == true)
            {
                return false;
            }
            k++;
        }

        k = 1;
        while (r - k >= 0 && c - k >= 0)
        {
            if (queen[r - k][c - k] == true)
            {
                return false;
            }
            k++;
        }

        k = 1;
        while (r + k <= 7 && c - k >= 0)
        {
            if (queen[r + k][c - k] == true)
            {
                return false;
            }
            k++;
        }

        k = 1;
        while (r + k <= 7 && c + k <= 7)
        {
            if (queen[r + k][c + k] == true)
            {
                return false;
            }
            k++;
        }
        return true;
        /*---------------------------------*/
    }

public:
    //�إ߫غc�禡�A�Ncounter��ȳ]��0,queen�}�C�Ҧ������]��false
    /*---------------------------------*/
    Queens();

    /*---------------------------------*/

    // int amount = 1;
    // ���j��M�ӦZ��m

    // int stack[8];

    // int stack_ptr = -1;
    void
    locate_queen(int col)
    {
        //�C�@��C�@�C���n���@�ӬӦZ�A�i�q�Ĥ@��Ĥ@�C�}�l��_(queen[0][0])
        //�i�Q�Ϋe��valid_position�P�_�O�_�ŦX
        //���@�ظѪ��ܱNcounter + 1�ç�U�@��
        /*---------------------------------*/
        for (int i = 0; i < 8; i++)
        {
            if (valid_position(i, col))
            {
                if (col == 7)
                {
                    counter++;
                }
                else
                {
                    queen[i][col] = true;
                    locate_queen(col + 1);
                    queen[i][col] = false;
                }
            }
        }
        /*---------------------------------*/
    }
    //��X�ŦX���`��
    void print()
    {
        cout << counter << endl;
    }
};
int main()
{
    Queens game;
    game.locate_queen(0);
    game.print();
}

Queens::Queens()
{
    counter = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            queen[i][j] = false;
        }
    }
    // for (int i = 0; i < 8; i++)
    // {
    //     stack[i] = 0;
    // }
}