#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::VectorXd;

// [[Rcpp::export]]
void axpy_eigen(double a, VectorXd& x, VectorXd& y) {
	y += a * x;
}
