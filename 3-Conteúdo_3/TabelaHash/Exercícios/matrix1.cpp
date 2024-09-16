#include <iostream>
#include <exception>
using namespace std;

class Matrix{
    int num_lin;
    int num_col;
    double **M;

public:
    Matrix(int lines, int collums){
        num_lin = lines;
        num_col = collums;
        M = new double *[lines];
        if(M == nullptr){
            cerr << "Memory Error" << endl;
            exit(EXIT_FAILURE);
        }
        for(int l=0; l < lines; l++){
            M[l] = new double [collums];
            if(M[l] == nullptr){
                cerr << "Memory Error" << endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    ~Matrix(){
        for(int l = 0; l < num_lin; l ++){
            delete[] M[l];
        }
        delete[] M;
    }

    void assign(int l, int c, double newvalue){
        M[l][c] = newvalue;
    }

    void assign_all(){
        cout << "Matrix: " << endl;
        for(int l = 0; l < num_lin; l++){
            for(int c = 0; c < num_col; c++){
                cout << l << ", " << c << ": ";
                cin >> M[l][c];
            }
        }
    }

    double acess(int l, int c){
        return M[l][c];
    }

    double* acess_pointer(int l, int c){
        return &M[l][c];
    }

    double& acess_reference(int l, int c){
        return M[l][c];
    }

    double& operator() (int l, int c){
        return M[l][c];
    }

    Matrix operator+ (const Matrix &m1) const{
        if(num_lin != m1.num_lin || num_col != m1.num_col){
            throw invalid_argument("Matrix dimensions don't match for addition");
        }
        Matrix result(num_lin, num_col);
        for(int l = 0; l < num_lin; l++){
            for(int c = 0; c < num_col; c++){
                result(l, c) = M[l][c] + m1.M[l][c];
            }
        }
        return result;
    }

    Matrix operator- (const Matrix &m1) const{
        if(num_lin != m1.num_lin || num_col != m1.num_col){
            throw invalid_argument("Matrix dimensions don't match for addition");
        }
        Matrix result(num_lin, num_col);
        for(int l = 0; l < num_lin; l++){
            for(int c = 0; c < num_col; c++){
                result(l, c) = M[l][c] - m1.M[l][c];
            }
        }
        return result;
    }

    Matrix operator* (const Matrix &m1) const{
        if(num_col != m1.num_lin){
            throw invalid_argument("Matrix dimensions don't match for Multiplication");
        }
        Matrix result(num_lin, m1.num_col);
        for(int i=0; i< num_lin; i++){
            for(int j=0; j < num_col; j++){
                result.M[i][j] = 0;
                for(int k1 = 0; k1 < num_col; k1++){
                    result.M[i][j] += M[i][k1] * m1.M[k1][j];
                }
            }
        }
        return result;
    }

    Matrix T (){
        Matrix result(num_col, num_lin);
        for(int i = 0; i < num_col; i++){
            for(int j = 0; j < num_lin; j++){
                result.M[i][j] = M[j][i];
            }
        }
        return result;
    }

    void display() const {
        for (int l = 0; l < num_lin; l++) {
            for (int c = 0; c < num_col; c++) {
                cout << M[l][c] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    try{
        int l; cout << "Lines: "; cin >> l;
        int c; cout << "Collums: "; cin >> c;

        Matrix M1(l,c);
        Matrix M2(l,c);

        cout << "Enter values for Matrix 1:" << endl;
        M1.assign_all();

        cout << "Enter values for Matrix 2:" << endl;
        M2.assign_all();

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