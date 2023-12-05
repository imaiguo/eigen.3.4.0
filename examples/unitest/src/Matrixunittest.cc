#include <Eigen/Dense>

#include <gtest/gtest.h>

// 1. 模板参数
// Matrix 类型模板的三个参数: 矩阵数值类型，行数，列数
// Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>

// 2. 特殊定义类型
// Matrix4f is a 4x4 matrix of floats. Here is how it is defined by Eigen
// typedef Matrix<float, 4, 4> Matrix4f;

// the convenience typedef Vector3f is a (column) vector of 3 floats. It is defined as follows by Eigen:
// typedef Matrix<float, 3, 1> Vector3f;

// We also offer convenience typedefs for row-vectors
// typedef Matrix<int, 1, 2> RowVector2i;

// 3. 特殊定义动态类型
// typedef Matrix<double, Dynamic, Dynamic> MatrixXd;
// typedef Matrix<int, Dynamic, 1> VectorXi;


// 4 . 通用类型模板定义

// Eigen defines the following Matrix typedefs:

// MatrixNt for Matrix<type, N, N>. For example, MatrixXi for Matrix<int, Dynamic, Dynamic>.
// MatrixXNt for Matrix<type, Dynamic, N>. For example, MatrixX3i for Matrix<int, Dynamic, 3>.
// MatrixNXt for Matrix<type, N, Dynamic>. For example, Matrix4Xd for Matrix<d, 4, Dynamic>.
// VectorNt for Matrix<type, N, 1>. For example, Vector2f for Matrix<float, 2, 1>.
// RowVectorNt for Matrix<type, 1, N>. For example, RowVector3d for Matrix<double, 1, 3>.
// Where:

// N can be any one of 2, 3, 4, or X (meaning Dynamic).
// t can be any one of i (meaning int), f (meaning float), d (meaning double), cf (meaning complex<float>), or cd (meaning complex<double>). The fact that typedefs are only defined for these five types doesn't mean that they are the only supported scalar types. For example, all standard integer types are supported, see Scalar types.


TEST(Matrix, assign){
    
}

TEST(Matrix, Constructors){

    Eigen::Matrix3f a;
    Eigen::MatrixXf b;

    {
        Eigen::MatrixXf a(10,15);
        Eigen::VectorXf b(30);
    }


    {
        Eigen::Matrix3f a(3,3);
    }

    {
        Eigen::Vector2i a(1, 2);                      // A column vector containing the elements {1, 2}
        Eigen::Matrix<int, 5, 1> b {1, 2, 3, 4, 5};   // A row-vector containing the elements {1, 2, 3, 4, 5}
        Eigen::Matrix<int, 1, 5> c = {1, 2, 3, 4, 5}; // A column vector containing the elements {1, 2, 3, 4, 5}
    }

    {
        Eigen::MatrixXi a{       // construct a 2x2 matrix
            {1, 2},              // first row
            {3, 4}               // second row
        };

        Eigen::Matrix<double, 2, 3> b {
            {2, 3, 4},
            {5, 6, 7}
        };   
    }
}

TEST(Matrix, Matrix3f){
    Eigen::Matrix3f m;
    m << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;

    std::cout << m << std::endl;
}
