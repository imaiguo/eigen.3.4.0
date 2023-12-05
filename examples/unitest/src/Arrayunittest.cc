
#include <Eigen/Dense>

#include <gtest/gtest.h>

// Array<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>

// Array<float,Dynamic,1> ArrayXf 
// Array<float,3,1> Array3f 
// Array<double,Dynamic,Dynamic> ArrayXXd 
// Array<double,3,3> Array33d


TEST(Array, Accessing){
    Eigen::ArrayXXf  m(2,2);

    // assign some values coefficient by coefficient
    m(0,0) = 1.0; m(0,1) = 2.0;
    m(1,0) = 3.0; m(1,1) = m(0,1) + m(1,0);

    // print values to standard output
    std::cout << m << std::endl << std::endl;

    // using the comma-initializer is also allowed
    m << 1.0,2.0,
        3.0,4.0;
        
    // print values to standard output
    std::cout << m << std::endl;
}

TEST(Array, Addition){

    Eigen::ArrayXXf a(3,3);
    Eigen::ArrayXXf b(3,3);

    a << 1,2,3,
         4,5,6,
         7,8,9;

    b << 1,2,3,
         1,2,3,
         1,2,3;
        
    // Adding two arrays
    std::cout << "a + b = " << std::endl << a + b << std::endl << std::endl;

    // Subtracting a scalar from an array
    std::cout << "a - 2 = " << std::endl << a - 2 << std::endl;
}

TEST(Array, multiplication){

    Eigen::ArrayXXf a(2,2);
    Eigen::ArrayXXf b(2,2);

    a << 1,2,
         3,4;

    b << 5,6,
         7,8;

    std::cout << "a * b = " << std::endl << a * b << std::endl;
}

TEST(Array, abs){

    Eigen::ArrayXf a = Eigen::ArrayXf::Random(5);

    a *= 2;
    std::cout << "a =" << std::endl << a << std::endl;
    std::cout << "a.abs() =" << std::endl << a.abs() << std::endl;
    std::cout << "a.abs().sqrt() =" << std::endl << a.abs().sqrt() << std::endl;
    std::cout << "a.min(a.abs().sqrt()) =" << std::endl << a.min(a.abs().sqrt()) << std::endl;
}

TEST(Array, array){

    Eigen::MatrixXf m(2,2);
    Eigen::MatrixXf n(2,2);
    Eigen::MatrixXf result(2,2);

    m << 1,2,
         3,4;

    n << 5,6,
         7,8;

    result = m * n;
    std::cout << "-- Matrix m*n: --\n" << result << "\n\n";

    result = m.array() * n.array();
    std::cout << "-- Array m*n: --\n" << result << "\n\n";

    result = m.cwiseProduct(n);
    std::cout << "-- With cwiseProduct: --\n" << result << "\n\n";

    result = m.array() + 4;
    std::cout << "-- Array m + 4: --\n" << result << "\n\n";
}

TEST(Array, matrix){

    Eigen::MatrixXf m(2,2);
    Eigen::MatrixXf n(2,2);
    Eigen::MatrixXf result(2,2);

    m << 1,2,
         3,4;

    n << 5,6,
         7,8;

    result = (m.array() + 4).matrix() * m;
    std::cout << "-- Combination 1: --\n" << result << "\n\n";

    result = (m.array() * n.array()).matrix() * m;
    std::cout << "-- Combination 2: --\n" << result << "\n\n";
}
