

#include "doctest.h"
#include "Matrix.hpp"
#include <iostream>

//#define TEST_CASE DOCTEST_TEST_CASE

using namespace zich;


/** Operators :
 *  Arithmetics --> (a+a/a-a/a*a), (a+=a / a-=a / a*=a / a*=~Num~), (+a/-a), (++,--)
 *  Boolean --> (==,!=), (<,>), (<=,>=)
 *  iostream --> (<<), (>>)*/

TEST_CASE ("Good Input") {

            SUBCASE("Arithmetics") {
        Matrix mat1({1, 0, 0, 0, 1, 0, 0, 0, 1}, 3, 3);
        Matrix mat2({1, 0, 0, 0, 1, 0, 0, 0, 1}, 3, 3);
        Matrix mat_sum({2, 0, 0, 0, 2, 0, 0, 0, 2}, 3, 3);

        Matrix mul1({1, 2, 3, 4, 5, 6}, 2, 3);
        Matrix mul2({10, 11, 20, 21, 30, 31}, 3, 2);
        Matrix mul3({140, 146, 320, 335}, 2, 2);

                SUBCASE("(a+a/a-a/a*a)") {
            /* adding mat2 to mat1, return a new matrix and do not affect any of mat1/mat2
             * the new matrix should be equal to mat_sum*/
                    CHECK(((mat1 + mat2) == mat_sum) == true);
            /* sub mat1 from mat_sum, return a new matrix and do not affect any of mat1/mat2
             * the new matrix should be equal to mat2 and to mat1 since they are both equal and their sum equal to mat_sum
             * in addition, from the last check we know each mat didn't change values*/
                    CHECK(((mat_sum - mat1) == mat2) == true);
            /*multiplication of mul1 and mul2, should return mul3 */
                    CHECK(((mul1 * mul2) == mul3) == true);
            /*try again the check above, if the matrices value did not change should return true*/
                    CHECK(((mul1 * mul2) == mul3) == true);
        }
                SUBCASE("(a+=a,a-=a, a*=a, a*=~Num~)") {

            /* adding mat2 to mat1, and save the result in mat1, mat1 should be as same as mat_sum*/
            mat1 += mat2;
                    CHECK((mat1 == mat_sum) == true);
            /* sub mat2 from mat1, and save the result in mat1, mat1 should be same as before, and equal to mat2*/
            mat1 -= mat2;
                    CHECK((mat1 == mat2) == true);
                    CHECK((mat1 == mat_sum) == false);
            /* multiply mat1 -1, should change all the values to negative and store in mat1
             * adding mat1 to mat_sum, should make affect as -= to the original mat1, and equal to mat2*/
            double scalar = -1;
            mat1 *= scalar;
            mat_sum += mat1;
                    CHECK((mat_sum == mat2) == true);
            /* adding mat1 to mat2, adding mat_sum(should be same as math2 from last CHECK)
             * mat2 and mat1 should be equal in all values (zero matrix)*/
            mat2 += mat1;
            mat1 += mat_sum;
                    CHECK((mat1 == mat2) == true);

            /*multiply mul1 and mul2,by the law of multiplication of matrices should mul1 should turn to mul3
             * meaning change the size too*/
            mul1 *= mul2;
                    CHECK((mul1 == mul3) == true);
        }
    }

            SUBCASE("Boolean Expressions") {
                SUBCASE("Equal matrix") {
            Matrix mat({1, 0, 0, 0, 1, 0, 0, 0, 1}, 3, 3);
            Matrix mat2({1, 0, 0, 0, 1, 0, 0, 0, 1}, 3, 3);

                    CHECK((mat == mat2) == true);
                    CHECK((mat != mat2) != false);
        }

                SUBCASE("Not Equal matrix") {
            Matrix mat({1, 0, 0, 0, 1, 0, 0, 0, 0}, 3, 3);
            Matrix mat2({1, 0, 0, 0, 1, 0, 0, 0, 1}, 3, 3);
                    CHECK((mat == mat2) == false);
                    CHECK((mat != mat2) != true);
        }
                SUBCASE("Less then || Greater then") {
            Matrix mat({1, 0, 0, 0, 0, 0, 0, 0, 0}, 3, 3);
            Matrix mat2({0, 0, 0, 0, 0, 0, 0, 1, 1}, 3, 3);
                    CHECK((mat < mat2) == true);
            Matrix mat_double({0, 0, 0, 0, 0.0000001, 0.5, 0.5, 0.5, 0.5}, 3, 3);
                    CHECK((mat2 < mat_double) == true);
            Matrix mat_double_bigger({0, 0, 0, 0, 0, 0, 0, 0, 2.1}, 3, 3);
                    CHECK((mat_double_bigger > mat_double) == true);
        }
                SUBCASE("Less|Equal then || Greater|Equal then") {
            Matrix mat({1, 0, 0, 0, 0, 0, 0, 0, 0}, 3, 3);
            Matrix mat2({0, 0, 0, 0, 0, 0, 0, 0, 1}, 3, 3);
                    CHECK((mat < mat2) == false);
                    CHECK((mat == mat2) == true);
                    CHECK((mat <= mat2) == true);
                    CHECK((mat >= mat2) == true);

        }
    }


}

TEST_CASE ("Bad Inputs") {

            SUBCASE("Size doesn't match the matrix length") {
                CHECK_THROWS(Matrix matrix({0, 0, 1, 1}, 2, 3));
                CHECK_THROWS(Matrix matrix({0}, 1, 2));
                CHECK_THROWS(Matrix matrix({100000000000000}, 2, 1));
                CHECK_THROWS(Matrix matrix({0}, 0, 0));

    }

            SUBCASE("Negative size") {
                CHECK_THROWS(Matrix matrix({0}, -1, 0));
    }
}

TEST_CASE ("Invalid Arithmetic operations") {

    /* multiplication methods */
    Matrix matrix2_2({0, 0, 1, 1}, 2, 2);
    Matrix matrix3_2({0, 0, 1, 1}, 3, 2);
            CHECK_THROWS(matrix2_2 * matrix3_2);
            CHECK_NOTHROW(matrix3_2 * matrix2_2);
    Matrix matrix3_3({0, 0, 1, 1}, 3, 3);
            CHECK_THROWS(matrix3_2 * matrix3_3);
            CHECK_NOTHROW(matrix3_3 * matrix3_2);
    /* Addition and subtraction */
            CHECK_THROWS(matrix3_2 + matrix3_3);
            CHECK_THROWS(matrix3_2 - matrix3_3);
            CHECK_THROWS(matrix3_3 + matrix3_2);
            CHECK_THROWS(matrix3_3 - matrix3_2);
    /* when the matrices have the same row and col --> OK*/
            CHECK_NOTHROW(matrix3_3 + matrix3_3);
            CHECK_NOTHROW(matrix3_2 += matrix3_2);
            CHECK_NOTHROW(matrix3_3 - matrix3_3);
            CHECK_NOTHROW(matrix3_2 -= matrix3_2);
}
TEST_CASE("COUT") {
    
}