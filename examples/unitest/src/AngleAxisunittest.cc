
#include <Eigen/Dense>

#include <gtest/gtest.h>


TEST(AngleAxis, Constructors){

    Eigen::Matrix3f m;
    m = Eigen::AngleAxisf(0.25*M_PI, Eigen::Vector3f::UnitX())
        * Eigen::AngleAxisf(0.5*M_PI,  Eigen::Vector3f::UnitY())
        * Eigen::AngleAxisf(0.33*M_PI, Eigen::Vector3f::UnitZ());

    std::cout << m << std::endl << "is unitary: " << m.isUnitary() << std::endl;
}
