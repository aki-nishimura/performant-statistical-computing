#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::VectorXd;

// [[Rcpp::export]]
VectorXd axpy_eigen(double a, VectorXd& x, VectorXd& y) {
	y += a * x;
	return(y);
}
