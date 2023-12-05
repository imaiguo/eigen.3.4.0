
#include <Eigen/Dense>

#include <gtest/gtest.h>

// MatrixXd = Matrix + X + d ; X = n, d = double

TEST(MatrixXd, assign){

  Eigen::MatrixXd m(2,2);

  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;

  m(1,1) = m(1,0) + m(0,1);

  std::cout << m << std::endl;
}

TEST(MatrixXd, Random){

  Eigen::MatrixXd m = Eigen::MatrixXd::Random(3,3);
  std::cout << "m =" << std::endl << m << std::endl;
  m = (m + Eigen::MatrixXd::Constant(3,3,1.2)) * 50;
  std::cout << "m =" << std::endl << m << std::endl;
}

TEST(MatrixXd, 3dRandom){
  Eigen::Matrix3d m = Eigen::Matrix3d::Random();
  std::cout << "m =" << std::endl << m << std::endl;
  m = (m + Eigen::Matrix3d::Constant(1.2)) * 50;
  std::cout << "m =" << std::endl << m << std::endl;

  Eigen::Vector3d v(1,2,3);
  std::cout << "m * v =" << std::endl << m * v << std::endl;
}

TEST(MatrixXd, Resize){

  Eigen::MatrixXd m(2,5);
  m.resize(4,3);
  std::cout << "The matrix m is of size " << m.rows() << "x" << m.cols() << ", It has " << m.size() << " coefficients" << std::endl;

  Eigen::VectorXd v(2);
  v.resize(5);
  std::cout << "The vector v is of size " << v.size() << ", As a matrix, v is of size " << v.rows() << "x" << v.cols() << std::endl;
}

TEST(MatrixXd, Assignment){

  Eigen::MatrixXf a(2,2);
  std::cout << "a is of size " << a.rows() << "x" << a.cols() << std::endl;

  Eigen::MatrixXf b(3,3);
  a = b;

  std::cout << "a is now of size " << a.rows() << "x" << a.cols() << std::endl;
}
