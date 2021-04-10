#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::colvec& axpy_arma(double a, arma::colvec& x, arma::colvec& y) {
  y += a * x;
  return y;
}
