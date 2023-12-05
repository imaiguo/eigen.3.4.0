
#include <Eigen/Dense>

#include <gtest/gtest.h>

// Vectors are just a special case of matrices, with either 1 row or 1 column.

TEST(VectorXd, assign){

    Eigen::VectorXd v(3);
    v << 1, 2, 3;
    std::cout << "v :" << std::endl << v << std::endl;
}

TEST(VectorXd, multiply){

    Eigen::MatrixXd m = Eigen::MatrixXd::Random(3,3);
    m = (m + Eigen::MatrixXd::Constant(3,3,1.2)) * 50;
    std::cout << "m =" << std::endl << m << std::endl;

    Eigen::VectorXd v(3);
    v << 1, 2, 3;
    std::cout << "m * v =" << std::endl << m * v << std::endl;
}

TEST(VectorXd, Constructors){

    Eigen::VectorXd a {{1.5, 2.5, 3.5}};             // A column-vector with 3 coefficients
    Eigen::RowVectorXd b {{1.0, 2.0, 3.0, 4.0}};     // A row-vector with 4 coefficients

    std::cout << "a =" << std::endl << a << std::endl;
    std::cout << "b =" << std::endl << b << std::endl;

    {
        Eigen::Vector2d a(5.0, 6.0);
        Eigen::Vector3d b(5.0, 6.0, 7.0);
        Eigen::Vector4d c(5.0, 6.0, 7.0, 8.0);
        std::cout << "a =" << std::endl << a << std::endl;
        std::cout << "b =" << std::endl << b << std::endl;
        std::cout << "c =" << std::endl << c << std::endl;
    }
}

TEST(VectorXd, Accessors){
    Eigen::VectorXd v(2);
    v(0) = 4;
    v(1) = v(0) - 1;
    std::cout << "Here is the vector v:\n" << v << std::endl;
}
