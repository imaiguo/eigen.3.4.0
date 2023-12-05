
#include <Eigen/Dense>

#include <gtest/gtest.h>

TEST(Arithmetic, add){

    Eigen::Matrix2d a;
    a << 1, 2,
        3, 4;

    Eigen::MatrixXd b(2,2);
    b << 2, 3,
        1, 4;

    std::cout << "a + b =\n" << a + b << std::endl;
    std::cout << "a - b =\n" << a - b << std::endl;
    std::cout << "Doing a += b;" << std::endl;

    a += b;
    std::cout << "Now a =\n" << a << std::endl;

    Eigen::Vector3d v(1,2,3);
    Eigen::Vector3d w(1,0,0);
    std::cout << "-v + w - v =\n" << -v + w - v << std::endl;
}

TEST(Arithmetic, multiplication){

    Eigen::Matrix2d a;
    a << 1, 2,
        3, 4;
    std::cout << "a * 2.5 =\n" << a * 2.5 << std::endl;

    Eigen::Vector3d v(1,2,3);
    std::cout << "0.1 * v =\n" << 0.1 * v << std::endl;

    std::cout << "Doing v *= 2;" << std::endl;
    v *= 2;
    std::cout << "Now v =\n" << v << std::endl;
}

TEST(Arithmetic, transpose){
    {
        Eigen::MatrixXcf a = Eigen::MatrixXcf::Random(2,2);
        std::cout << "Here is the matrix a\n" << a << std::endl;
        std::cout << "Here is the matrix a^T\n" << a.transpose() << std::endl;
        std::cout << "Here is the conjugate of a\n" << a.conjugate() << std::endl;
        std::cout << "Here is the matrix a^*\n" << a.adjoint() << std::endl;
    }

    {
        Eigen::MatrixXf a = Eigen::MatrixXf::Random(2,2);
        std::cout << "Here is the matrix a\n" << a << std::endl;
        std::cout << "Here is the matrix a^T\n" << a.transpose() << std::endl;
        std::cout << "Here is the conjugate of a\n" << a.conjugate() << std::endl;
        std::cout << "Here is the matrix a^*\n" << a.adjoint() << std::endl;
    }
}

TEST(Arithmetic, transposeSelf){

    Eigen::Matrix2i a; a << 1, 2, 3, 4;
    std::cout << "Here is the matrix a:\n" << a << std::endl;
    
    // a = a.transpose(); // !!! do NOT do this !!! use a.transposeInPlace() replease.
    a.transposeInPlace();
    std::cout << "and the result of the aliasing effect:\n" << a << std::endl;
}

// 点乘 和 叉乘
// （点乘 = 长度乘积 * 余弦， 是常量）
// （交叉乘 = 长度乘积 * 正弦，是垂直向量）
TEST(Arithmetic, DotCross){
    Eigen::Vector3d v(1,2,3);
    Eigen::Vector3d w(0,1,2);

    std::cout << "Dot product: " << v.dot(w) << std::endl;
    double dp = v.adjoint()*w; // automatic conversion of the inner product to a scalar
    std::cout << "Dot product via a matrix product: " << dp << std::endl;
    std::cout << "Cross product:\n" << v.cross(w) << std::endl;
}


TEST(Arithmetic, reduction){

    Eigen::Matrix2d mat;
    mat << 1, 2,
           3, 4;

    std::cout << "Here is mat.sum():       " << std::endl << mat<< std::endl;
    std::cout << "Here is mat.sum():       " << mat.sum()       << std::endl;
    std::cout << "Here is mat.prod():      " << mat.prod()      << std::endl;
    std::cout << "Here is mat.mean():      " << mat.mean()      << std::endl;
    std::cout << "Here is mat.minCoeff():  " << mat.minCoeff()  << std::endl;
    std::cout << "Here is mat.maxCoeff():  " << mat.maxCoeff()  << std::endl;
    std::cout << "Here is mat.trace():     " << mat.trace()     << std::endl;
}
