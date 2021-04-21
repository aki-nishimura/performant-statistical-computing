#include <Rcpp.h>
using Rcpp::NumericVector;


// [[Rcpp::export]]
NumericVector sign_via_if(NumericVector x) {
  int n = x.size();
  NumericVector x_sign(n);
  for(int i = 0; i < n; ++i) {
    if (x[i] > 0) {
      x_sign[i] = 1;
    } else if (x[i] < 0) {
      x_sign[i] = -1;
    } else {
      x_sign[i] = 0;
    }
  }
  return x_sign;
}


// [[Rcpp::export]]
NumericVector sign_via_diff(NumericVector x) {
  int n = x.size();
  NumericVector x_sign(n);
  for(int i = 0; i < n; ++i) {
    x_sign[i] = (x[i] > 0) - (x[i] < 0);
  }
  return x_sign;
}
