#include <Rcpp.h>
using Rcpp::NumericMatrix;
using Rcpp::NumericVector;

// [[Rcpp::export]]
NumericVector row_oriented_matvec_c(
    const NumericMatrix& A, const NumericVector& v
  ) {
  int n = v.size();
  NumericVector result(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      result[i] += A[i, j] * v[j];
    }
  }
  return result;
}

// [[Rcpp::export]]
NumericVector col_oriented_matvec_c(
    const NumericMatrix& A, const NumericVector& v
  ) {
  int n = v.size();
  NumericVector result(n);
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      result[i] += A[i, j] * v[j];
    }
  }
  return result;
}