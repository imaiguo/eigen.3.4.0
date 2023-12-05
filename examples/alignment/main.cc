
#include <iostream>

#include <Eigen/Dense>


// 格式化打印输出
//precision 精度：主要包括StreamPrecision与FullPrecision，默认为0
//flags 设置标号，默认为0
//coeffSeparator 同一行两个数的分隔符
//rowSeparator  两行之间的分隔符
//rowPrefix 每一行开头符号
//rowSuffix 每一行结束符号
//matPrefix 矩阵开始时符号
//matSuffix 矩阵结束时符号

Eigen::IOFormat CommaInitFmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", ", ", "", "", " << ", ";");
Eigen::IOFormat CleanFmt(4, 0, ", ", "\n", "[", "]");
Eigen::IOFormat OctaveFmt(Eigen::StreamPrecision, 0, ", ", ";\n", "", "", "[", "]");
Eigen::IOFormat HeavyFmt(Eigen::FullPrecision, 0, ", ", ";\n", "[", "]", "[", "]");

class Foo_d
{
public:
  // Eigen::Vector4d v;
  Eigen::Affine3f transform = Eigen::Affine3f::Identity();
};
 
 
struct Foo {
  Foo() { init_d(); }
  ~Foo() { delete d; }
  void bar()
  {
    // use d->v instead of v
  }
private:
  void init_d() { d = new Foo_d; }
  int i = 0;
  double b = 0.1;
  Foo_d* d;
};


void alignfunc(){
  std::cout << alignof(Eigen::Vector2d) << std::endl; // 16
  std::cout << alignof(Eigen::Vector3d) << std::endl; // 8
  std::cout << alignof(Eigen::Vector4d) << std::endl; // 16
  std::cout << alignof(Eigen::Vector2f) << std::endl; // 4
  std::cout << alignof(Eigen::Vector3f) << std::endl; // 4
  std::cout << alignof(Eigen::Vector4f) << std::endl; // 16
  std::cout << alignof(Eigen::Matrix2d) << std::endl; // 16
  std::cout << alignof(Eigen::Matrix3d) << std::endl; // 8
  std::cout << alignof(Eigen::Matrix2f) << std::endl; // 16
  std::cout << alignof(Eigen::Matrix3f) << std::endl; // 4
  std::cout << alignof(Eigen::Matrix4d) << std::endl; // 16
  std::cout << alignof(Eigen::Matrix4f) << std::endl; // 16
  std::cout << alignof(Eigen::Affine3d) << std::endl; // 16
  std::cout << alignof(Eigen::Affine3f) << std::endl; // 16
  std::cout << alignof(Eigen::Quaterniond) << std::endl; // 16
  std::cout << alignof(Eigen::Quaternionf) << std::endl; // 16
}

int main(){

  alignfunc();

  Foo_d * foo = new Foo_d();
  Eigen::Affine3f f = foo->transform;

  f.isApprox(Eigen::Affine3f::Identity());
  std::cout << "isApprox:" << f.isApprox(Eigen::Affine3f::Identity()) << std::endl;
  std::cout << sizeof(Foo_d) <<std::endl;
  std::cout << f.matrix() <<std::endl;
  std::cout << sizeof(Eigen::Affine3f) << std::endl;



  Eigen::Affine3f *t =  new Eigen::Affine3f;
  *t = Eigen::Affine3f::Identity();
  
  std::cout << t->matrix() <<std::endl;

  std::cout << "sizeof(float):" <<  sizeof(float) << std::endl;
  return 0;
}

