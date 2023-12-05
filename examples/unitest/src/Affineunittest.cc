
#include <Eigen/Dense>

#include <gtest/gtest.h>


// If you are working with OpenGL 4x4 matrices then Affine3f and Affine3d are what you want.
// Since Eigen defaults to column-major storage, you can directly use the Transform::data() method to pass your transformation matrix to OpenGL.

TEST(Affine, Constructors){
    Eigen::Rotation2Df r;  // r  = Matrix2f(..);       // assumes a pure rotation matrix
    Eigen::AngleAxisf aa1;  // aa = Quaternionf(..);
    Eigen::AngleAxisf aa2;  // aa = Matrix3f(..);       // assumes a pure rotation matrix
    Eigen::Matrix2f m1;     // m  = Rotation2Df(..);
    Eigen::Matrix3f m2;     // m  = Quaternionf(..);       Matrix3f m;   m = Scaling(..);
    Eigen::Affine3f m3;     // m  = AngleAxis3f(..);       Affine3f m;   m = Scaling(..);
    Eigen::Affine3f m4;     // m  = Translation3f(..);     Affine3f m;   m = Matrix3f(..)
}

// aux=
// 1 0 0 0
// 0 1 0 0
// 0 0 1 0
// 0 0 0 1
TEST(Affine, init){
    Eigen::Affine3f aux(Eigen::Affine3f::Identity());
    aux.isApprox(Eigen::Affine3f::Identity());
    std::cout << "aux=" << std::endl << aux.matrix() << std::endl;

    std::cout << "aux isApprox: [" << aux.isApprox(Eigen::Affine3f::Identity()) << "]." << std::endl;

    Eigen::Affine3f m2 = aux.inverse();
    std::cout << "aux.inverse():" << std::endl << m2.matrix() << std::endl;
}
