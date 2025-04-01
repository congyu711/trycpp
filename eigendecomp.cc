#include </opt/homebrew/Cellar/eigen/3.4.0_1/include/eigen3/Eigen/eigenvalues>
#include <iostream>
using namespace Eigen;
using namespace std;

int main() {
  MatrixXd A(3,3);
  A << 1.0/2,1.0/2,0,1.0/2,1.0/4,1.0/4,0,1.0/3,2.0/3;
  cout << "Here is a matrix, A:" << endl << A << endl << endl;

  EigenSolver<MatrixXd> es(A);
  cout << "The eigenvalues of A are:" << endl << es.eigenvalues() << endl;
  cout << "The matrix of eigenvectors, V, is:" << endl
       << es.eigenvectors() << endl
       << endl;

  complex<double> lambda = es.eigenvalues()[0];
  cout << "Consider the first eigenvalue, lambda = " << lambda << endl;
  VectorXcd v = es.eigenvectors().col(0);
  cout << "If v is the corresponding eigenvector, then lambda * v = " << endl
       << lambda * v << endl;
  cout << "... and A * v = " << endl
       << A.cast<complex<double>>() * v << endl
       << endl;

  MatrixXcd D = es.eigenvalues().asDiagonal();
  MatrixXcd V = es.eigenvectors();
  cout << "Finally, V * D * V^(-1) = " << endl << V * D * V.inverse() << endl;
}