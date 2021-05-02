#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::mat matmat_via_arma(const arma::mat& A, const arma::mat& B) {
  return A * B;
}