#include <iostream>
#include <algorithm>
using namespace std;

#define N 2

// In-place rotate it by 90 degrees in clockwise direction
void rotate(int mat[N][N])
{
    // Transpose the matrix
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            swap(mat[i][j], mat[j][i]);

    // swap columns
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N/2; j++)
            swap(mat[i][j], mat[i][N - j - 1]);
}

int main()
{
    int mat[N][N] =
    {
        { 1, 2},
        { 3, 4}
    };

    rotate(mat);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";

        cout << '\n';
    }
    return 0;
}
