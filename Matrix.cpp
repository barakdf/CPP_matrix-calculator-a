//
// Created by barak on 04/04/2022.
//

#include "Matrix.hpp"

using namespace zich;

/* Constructor */
Matrix::Matrix(const std::vector<double> &mat, int row, int col) : r(row), c(col) { this->matrix = mat; };


Matrix Matrix::operator-(const Matrix& other){
    Matrix ans({1},1,1);
    return ans;
}

Matrix Matrix::operator+(const Matrix &other){
    Matrix ans({1},1,1);
    return ans;
}

Matrix Matrix::operator*(const Matrix &other){
    Matrix ans({1},1,1);
    return ans;
}

/* mat = mat- {1,1,1,1,1,1...}  ---->  [mat(x)-1,......,mat(x+z)-1,..]*/

void Matrix::operator--() {
    Matrix ans({1},1,1);
}
/* mat = mat + {1,1,1,1,1,1...}  |---->  [mat(x)+1,......,mat(x+z)+1,..]*/
void Matrix::operator++() {
    Matrix ans({1},1,1);
}

/* mat = mat - (other matrix)*/
void Matrix::operator-=(const Matrix &other) {
    Matrix ans({1},1,1);
}
/* mat = mat + (other matrix)*/
void Matrix::operator+=(const Matrix &other) {
    Matrix ans({1},1,1);
}
/* mat = mat * (other matrix)*/
void Matrix::operator*=(const Matrix &other) {
    Matrix ans({1},1,1);
}

/*Boolean Expressions */
bool Matrix::operator==(const Matrix &other) {
    return true;
}

bool Matrix::operator!=(const Matrix &other) {
    return true;
}

bool Matrix::operator<=(const Matrix &other) {
    return true;
}

bool Matrix::operator>=(const Matrix &other) {
    return true;
}

bool Matrix::operator<(const Matrix &other) {
    return true;
}

bool Matrix::operator>(const Matrix &other) {
    return true;
}

/*end boolean expressions*/

//Matrix operator*(const Matrix &other) {
//    Matrix ans({1},1,1);
//    return ans;
//}

/* multiply matrix with scalar */
Matrix zich::operator*(double scalar, const Matrix &other) {
    Matrix ans({1},1,1);
    return ans;
}

Matrix zich::operator*=( const Matrix &other,double scalar) {
    Matrix ans({1},1,1);
    return ans;
}


Matrix zich::operator-(Matrix &matrix1) {
    Matrix ans({1},1,1);
    return ans;
}

Matrix zich::operator+(Matrix &matrix1) {
    Matrix ans({1},1,1);
    return ans;
}


/* cout << operator overload */
std::ostream& zich::operator<<(std::ostream &ostream, const Matrix &other) {
    ostream << "OK";
    return ostream;
}

/* cin >> operator overload */
std::ostream& zich::operator>>(std::ostream &ostream, const Matrix &other) {
    return ostream;
}



