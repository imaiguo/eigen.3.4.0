
#include <Eigen/Dense>

#include <gtest/gtest.h>

// Compile-time error: YOU_MIXED_MATRICES_OF_DIFFERENT_SIZES

// TEST(Validity, CompileTime){

//     Eigen::Matrix3f m;
//     Eigen::Vector4f v;
//     v = m*v;
// }

// Run-time assertion failure here: "invalid matrix product"
// TEST(Validity, RunTime){
//     Eigen::MatrixXf m(3,3);
//     Eigen::VectorXf v(4);
//     v = m * v;
// }
