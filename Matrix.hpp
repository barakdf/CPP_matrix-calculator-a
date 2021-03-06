//
// Created by barak on 04/04/2022.
//
#include <iostream>
#include <vector>

#ifndef CPP_MATRIX_CALCULATOR_A_MATRIX_HPP
#define CPP_MATRIX_CALCULATOR_A_MATRIX_HPP
namespace zich {
    class Matrix {
    private:
        std::vector<double> matrix;
        int r;
        int c;
    public:
        Matrix(const std::vector<double> &mat, int row, int col );



        /* Arithmetic Operators */
        Matrix operator-(const Matrix &other);
        Matrix operator+(const Matrix &other);
        Matrix operator*(const Matrix &other);

        void operator--();
        void operator++();


        /* self-object arithmetic operators */
        void operator-=(const Matrix &other);
        void operator+=(const Matrix &other);
        void operator*=(const Matrix &other);

        /*Boolean Expressions */
        bool operator==(const Matrix &other);
        bool operator!=(const Matrix &other);

        bool operator<=(const Matrix &other);
        bool operator>=(const Matrix &other);

        bool operator<(const Matrix &other);
        bool operator>(const Matrix &other);

        /*end boolean expressions*/


        friend Matrix operator*(double scalar, const Matrix &other);
        friend Matrix operator*=( const Matrix &other,double scalar);
        friend Matrix operator+(Matrix &matrix);
        friend Matrix operator-(Matrix &matrix);



        /* IO Operators*/
        friend std::ostream& operator<<(std::ostream& ostream, const Matrix& other);
        friend std::ostream& operator>>(std::ostream& ostream, const Matrix& other);



    };
}
#endif //CPP_MATRIX_CALCULATOR_A_MATRIX_HPP
