#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map; // 'Map' (i.e. reference without making copies) R matrices
using Eigen::VectorXd;
using Eigen::SparseMatrix;
typedef Map<SparseMatrix<double, Eigen::ColMajor>> MappedCsc;
typedef Map<SparseMatrix<double, Eigen::RowMajor>> MappedCsr;

template <typename MappedSparseMatrix>
bool check_dim_compatible(
    const MappedSparseMatrix A, const Map<VectorXd> v, bool transposed
  ) {
  bool is_incompatible;
  if (transposed) {
    is_incompatible = (A.rows() != v.size());
  } else {
    is_incompatible = (A.cols() != v.size());
  }
  if (is_incompatible) Rcpp::stop("Incompatible dimensions");
  return is_incompatible;
}

// [[Rcpp::export]]
VectorXd csc_eigen_matvec(
    const MappedCsc A, const Map<VectorXd> v, bool transposed = false
  ) {
  check_dim_compatible(A, v, transposed);
  if (transposed) {
    return A.transpose() * v;
  } else {
    return A * v;
  }
}

// [[Rcpp::export]]
VectorXd csr_eigen_matvec(
    const MappedCsr A, const Map<VectorXd> v, bool transposed = false
  ) {
  check_dim_compatible(A, v, transposed);
  if (transposed) {
    return A.transpose() * v;
  } else {
    return A * v;
  }
}
