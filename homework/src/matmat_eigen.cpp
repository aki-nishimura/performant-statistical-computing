#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map; // 'Map' (i.e. reference without making copies) R matrices
using Eigen::MatrixXd;  

// [[Rcpp::export]]
MatrixXd matmat_via_eigen(const Map<MatrixXd> A, const Map<MatrixXd> B) {
  return A * B;
}