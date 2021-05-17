#include <Rcpp.h>
using Rcpp::NumericMatrix;
using Rcpp::NumericVector;

// [[Rcpp::export]]
NumericVector row_oriented_matvec_c(
    const NumericMatrix& A, const NumericVector& v
  ) {
  int n_row = A.nrow();
  int n_col = A.ncol();
  if (n_col != v.size()) {
    Rcpp::stop("Incompatible dimensions");
  }
  NumericVector result(n_row);
  for (int i = 0; i < n_row; ++i) {
    for (int j = 0; j < n_col; ++j) {
      result[i] += A(i, j) * v[j];
    }
  }
  return result;
}

// [[Rcpp::export]]
NumericVector col_oriented_matvec_c(
    const NumericMatrix& A, const NumericVector& v
  ) {
  int n_row = A.nrow();
  int n_col = A.ncol();
  if (n_col != v.size()) {
    Rcpp::stop("Incompatible dimensions");
  }
  NumericVector result(n_row);
  for (int j = 0; j < n_col; ++j) {
    for (int i = 0; i < n_row; ++i) {
      result[i] += A(i, j) * v[j];
    }
  }
  return result;
}