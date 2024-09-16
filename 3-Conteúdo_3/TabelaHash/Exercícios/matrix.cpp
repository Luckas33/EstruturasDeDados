#include <iostream>
#include <exception>

using namespace std;

class Matrix
{
private:
    int L;
    int H;
    double **M;

public:
    Matrix(int Linhas, int Colunas)
    {
        M = new double *[Linhas];
        if (M == nullptr)
        {
            cerr << "Bad allocation\n";
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < Linhas; i++)
        {
            M[i] = new double[Colunas];
            if (M[i] == nullptr)
            {
                cerr << "Bad allocation\n";
                exit(EXIT_FAILURE);
            }
        }
    }

    ~Matrix()
    {
        for (int l = 0; l < L; l++)
        {
            delete[] M[l];
        }
        delete[] M;
    };

    void inserir(int l, int c, double e)
    {
        M[l][c] = e;
    }

    void inserir_todos()
    {
        cout << "Matrix: " << endl;
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < H; j++)
            {
                cin >> M[L][H];
            }
        }
    }

    double acess(int l, int c)
    {
        return M[l][c];
    }

    double &operator()(int l, int c)
    {
        return M[l][c];
    }

    Matrix operator+(Matrix &m1)
    {
        if (L != m1.L || H != m1.H)
        {
            throw invalid_argument("erro");
        }
        Matrix result(L, H);
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < H; j++)
            {
                result(i, j) = M[i][j] + m1.M[i][j];
            }
        }
        return result;
    }

    Matrix operator-(Matrix &m1)
    {
        if (L != m1.L || H != m1.H)
        {
            throw invalid_argument("erro");
        }
        Matrix result(L, H);
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < H; j++)
            {
                result(i, j) = M[i][j] - m1.M[i][j];
            }
        }
        return result;
    }

    Matrix operator*(Matrix &m1)
    {
        if (H != m1.L)
        {
            throw invalid_argument("erro");
        }
        Matrix result(L, m1.H);
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < H; j++)
            {
                result.M[i][j] = 0;
                for (int k1 = 0; k1 < H; k1++)
                {
                    result.M[i][j] += M[i][k1] * m1.M[k1][j];
                }
            }
        }
        return result;
    }

    Matrix T()
    {
        Matrix result(H, L);
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < L; j++)
            {
                result.M[i][j] = M[j][i];
            }
        }
        return result;
    }

    void display()
    {
        for (int l = 0; l < L; l++)
        {
            for (int c = 0; c < H; c++)
            {
                cout << M[l][c] << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    try{
        int l; cout << "Lines: "; cin >> l;
        int c; cout << "Collums: "; cin >> c;

        Matrix M1(l,c);
        Matrix M2(l,c);

        cout << "Enter values for Matrix 1:" << endl;
        M1.inserir_todos();

        cout << "Enter values for Matrix 2:" << endl;
        M2.inserir_todos();

        cout << "Matrix 1:" << endl;
        M1.display();

        cout << "Matrix 2:" << endl;
        M2.display();

        Matrix M3 = M1 + M2;
        cout << "Matrix 1 + Matrix 2:" << endl;
        M3.display();

        Matrix M4 = M1 - M2;
        cout << "Matrix 1 - Matrix 2:" << endl;
        M4.display();

        Matrix M5 = M1 * M2;
        cout << "Matrix 1 * Matrix 2:" << endl;
        M5.display();

        Matrix M6 = M1.T();
        cout << "Matrix 1T:" << endl;
        M6.display();
    }

    catch (const exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}