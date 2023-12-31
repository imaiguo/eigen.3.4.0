#include <iostream>
#include <Eigen/Dense>
 
using Eigen::MatrixXd;
 
int main(){

  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);

  Eigen::Affine3f tran1 = Eigen::Affine3f::Identity();
  Eigen::Affine3f tran2 = tran1;

  std::cout << m << std::endl;
}