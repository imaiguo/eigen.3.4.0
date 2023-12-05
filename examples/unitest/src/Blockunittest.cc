
#include <Eigen/Dense>

#include <gtest/gtest.h>

TEST(Block, print){

    Eigen::MatrixXf m(4,4);
    m <<  1, 2, 3, 4,
          5, 6, 7, 8,
          9,10,11,12,
          13,14,15,16;

    std::cout << "Block in the middle" << std::endl;
    std::cout << m.block<2,2>(1,1) << std::endl << std::endl;

    for (int i = 1; i <= 4; ++i){
        std::cout << "Block of size " << i << "x" << i << std::endl;
        std::cout << m.block(0,0,i,i) << std::endl << std::endl;
    }
}

TEST(Block, lvalues){
    Eigen::Array22f m;
    m << 1,2,
         3,4;

    Eigen::Array44f a = Eigen::Array44f::Constant(0.6);
    std::cout << "Here is the array a:\n" << a << "\n\n";

    a.block<2,2>(1,1) = m;
    std::cout << "Here is now a with m copied into its central 2x2 block:\n" << a << "\n\n";

    a.block(0,0,2,3) = a.block(2,1,2,3);
    std::cout << "Here is now a with bottom-right 2x3 block copied into top-left 2x3 block:\n" << a << "\n\n";
}

TEST(Block, Columns){

    Eigen::MatrixXf m(3,3);
    m << 1,2,3,
         4,5,6,
         7,8,9;

    std::cout << "Here is the matrix m:" << std::endl << m << std::endl;

    std::cout << "2nd Row: " << m.row(1) << std::endl;

    m.col(2) += 3 * m.col(0);
    std::cout << "After adding 3 times the first column into the third column, the matrix m is:\n";

    std::cout << m << std::endl;
}
 
TEST(Block, Corner){

    Eigen::Matrix4f m;
    m << 1, 2, 3, 4,
         5, 6, 7, 8,
         9, 10,11,12,
         13,14,15,16;

    std::cout << "m.leftCols(2) =" << std::endl << m.leftCols(2) << std::endl << std::endl;

    std::cout << "m.bottomRows<2>() =" << std::endl << m.bottomRows<2>() << std::endl << std::endl;

    m.topLeftCorner(1,3) = m.bottomRightCorner(3,1).transpose();
    std::cout << "After assignment, m = " << std::endl << m << std::endl;
}

TEST(Block, Vector){

    Eigen::ArrayXf v(6);
    v << 1, 2, 3, 4, 5, 6;

    std::cout << "v.head(3) =" << std::endl << v.head(3) << std::endl << std::endl;

    std::cout << "v.tail<3>() = " << std::endl << v.tail<3>() << std::endl << std::endl;

    v.segment(1,4) *= 2;
    std::cout << "after 'v.segment(1,4) *= 2', v =" << std::endl << v << std::endl;
}
