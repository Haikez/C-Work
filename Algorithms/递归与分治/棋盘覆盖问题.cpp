#include <iostream>
using namespace std;
int t = 1;
int Board[100][100] = {0};
void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
    if (size == 1)
        return;
    int tail = t++;
    size /= 2;
    //特殊方格在左上角
    if (tr + size > dr && tc + size > dc)
    {
        ChessBoard(tr, tc, dr, dc, size);
    }
    else
    {
        Board[tr + size - 1][tc + size - 1] = tail;
        ChessBoard(tr, tc, tr + size - 1, tc + size - 1, size);
    }
    //特殊方格在右上角
    if (tr + size > dr && tc + size <= dc)
    {
        ChessBoard(tr, tc + size, dr, dc, size);
    }
    else
    {
        Board[tr + size - 1][tc + size] = tail;
        ChessBoard(tr, tc + size, tr + size - 1, tc + size, size);
    }
    //特殊方格在左下角
    if (tr + size <= dr && tc + size > dc)
    {
        ChessBoard(tr + size, tc, dr, dc, size);
    }
    else
    {
        Board[tr + size][tc + size - 1] = tail;
        ChessBoard(tr + size, tc, tr + size, tc + size - 1, size);
    }

    //特殊方格在右下角
    if (tr + size <= dr && tc + size <= dc)
    {
        ChessBoard(tr + size, tc + size, dr, dc, size);
    }
    else
    {
        Board[tr + size][tc + size] = tail;
        ChessBoard(tr + size, tc + size, tr + size, tc + size, size);
    }
}
int main()
{
    int size;
    cout << "请输入棋盘规格:";
    cin >> size;
    ChessBoard(0, 0, 3, 4, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << Board[i][j] << " ";
        }
        cout << endl;
    }
}