#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
void axpy_arma(double a, arma::colvec& x, arma::colvec& y) {
  y += a * x;
}
