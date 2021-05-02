#include <Rcpp.h>
using Rcpp::NumericVector;
using Rcpp::NumericMatrix;

// [[Rcpp::export]]
NumericVector ar_precision_matvec(const NumericVector& v, double auto_corr) {
	int n = v.size();
	NumericVector result(n); // Allocate return vector
	double auto_corr_sq = pow(auto_corr, 2.); // '^' operator would not work
  // Fill in; remember that C array index starts from *0 instead of 1*
	return result;
}

// [[Rcpp::export]]
NumericVector sym_banded_matvec(
    const NumericVector& v, const NumericMatrix& banded_mat) {
  int n_col = banded_mat.ncol();
  int n_row = banded_mat.nrow();
  if (n_row != v.size()) {
    Rcpp::stop("Incompatible dimensions");
  }
  NumericVector result(n_row);
  // Multiplication by the diagonal
  for (int i = 0; i < n_row; ++i) {
    result[i] = banded_mat(i, 0) * v[i]; // Use (,) to access matrix elements
  }
  // Multiplication by the off-diagonals
  for (int diag_offset = 1; diag_offset < n_col; ++diag_offset) {
    for (int i = 0; i < n_row - diag_offset; ++i) {
      // Fill in
    }
  }
  return result;
}
