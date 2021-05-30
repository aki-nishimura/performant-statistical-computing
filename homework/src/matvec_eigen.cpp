#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map; // 'Map' (i.e. reference without making copies) R matrices
using Eigen::MatrixXd;  
using Eigen::VectorXd;


template <typename EigenMatrix>
bool check_dim_compatible(
    const EigenMatrix A, const Map<VectorXd> v, bool transposed
) {
  bool is_compatible;
  if (transposed) {
    is_compatible = (A.rows() == v.size());
  } else {
    is_compatible = (A.cols() == v.size());
  }
  if (!is_compatible) Rcpp::stop("Incompatible dimensions");
  return is_compatible;
}

// [[Rcpp::export]]
VectorXd matvec_via_eigen(
    const Map<MatrixXd> A, const Map<VectorXd> v, bool transposed = false
  ) {
  check_dim_compatible(A, v, transposed);
  if (transposed) {
    return A.transpose() * v;
  } else {
    return A * v;
  }
}