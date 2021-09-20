#include <iostream>
#include <algorithm>
#include <vector> 
#define _CRT_SECURE_NO_WARNINGS
const double eps = 0.00001;

using namespace std;
class matrix
{
private:
    double** a;
    int n, m;
public:

    // матрица без элементов
    matrix()
    {
        a = 0;
        n = 0;
        m = 0;
    }
    // матрица NxM, если E, то единичная, иначе нулевая
    matrix(int N, int M, bool E = 0)
    {
        n = N;
        m = M;
        a = new double* [n];
        for (int i = 0; i < n; ++i)
        {
            a[i] = new double[m];
            for (int j = 0; j < m; ++j)
                a[i][j] = (i == j) * E;
        }
    }
    
    int N()
    {
        return n;
    }
    int M()
    {
        return m;
    }
    double* operator [] (int index)
    {
        return getRow(index);
    }
    // получить строку матрицы
    double* getRow(int index)
    {
        if (index >= 0 && index < n)
            return a[index];
        return 0;
    }
    // получить столбец матрицы
    double* getColumn(int index)
    {
        if (index < 0 || index >= m)
            return 0;
        double* c = new double[n];
        for (int i = 0; i < n; ++i)
            c[i] = a[i][index];
        return c;
    }
    
    //задать матрицу B
    matrix setMatrixB() {
        matrix B = matrix(n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == j) {
                    B[i][j] = 0;
                }
                else {
                    B[i][j] = -(a[i][j]) / a[i][i];
                }
            }
        }
        return B;
    }
    //задать вектор бета
    matrix setBeta(matrix& b) {
        matrix beta = matrix(n, 1);
        for (int i = 0; i < n; ++i) {
            beta[i][0] = a[i][0]/b[i][i];
        }
        return beta;
    }
    
};

// прочитать матрицу с консоли
matrix scanMatrix()
{
    int n, m;
    scanf_s("%d%d", &n, &m);
    matrix a = matrix(n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf_s("%lf", &a[i][j]);
    return a;
}
matrix scanVector(int n)
{
    matrix a = matrix(n, 1);
    for (int i = 0; i < n; ++i)
        scanf_s("%lf", &a[i][0]);
    return a;
}
// вывести матрицу на консоль
void printMatrix(matrix& a)
{
    for (int i = 0; i < a.N(); ++i)
    {
        for (int j = 0; j < a.M(); ++j)
            printf("%5.3lf ", a[i][j]);
        puts("");
    }
}
void printVector(matrix& a)
{
    for (int i = 0; i < a.N(); ++i)
    {
        cout << "x" << i << ": " << a[i][0] << "\n";
    }
}

// умножение двух матриц
matrix mul(matrix& a, matrix& b)
{
    if (a.M() != b.N())
        return matrix();
    matrix c = matrix(a.N(), b.M());
    for (int i = 0; i < a.N(); ++i)
        for (int j = 0; j < b.M(); ++j)
            for (int k = 0; k < a.M(); ++k)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

matrix solve(matrix& X, matrix& B, matrix& beta)
{
    matrix ans = matrix(X.N(), 1);
    bool check = true;
    while (check) {
        ans = mul(B, X);
        //printMatrix(ans);
        for (int i = 0; i < ans.N(); i++) {
            ans[i][0] = ans[i][0] + beta[i][0];

            if (abs(ans[i][0] - X[i][0]) < eps) {
                check = false;
                continue;
            }
            X[i][0] = ans[i][0];
        }
    }
    return ans;
}
int main()
{
    //matrix* mat1 = new matrix(3, 3, 0);
    cout << "print size and then matrix of coefficients: " << endl;
    matrix* mat1 = &scanMatrix();
    matrix* B = &mat1->setMatrixB();
    printMatrix(*B);
    cout << "print right side vector: " << endl;
    matrix* mat2 = &scanVector(mat1->N());
    matrix* beta = &mat2->setBeta(*mat1);
    printMatrix(*beta);
    cout << "print vector of probable X: " << endl;
    matrix* X = &scanVector(mat1->N());
    
    matrix* ans = &solve(*X, *B, *beta);
    printVector(*ans);
 
}

