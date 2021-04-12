#include <Rcpp.h>
using Rcpp::NumericVector;

// [[Rcpp::export]]
double sign_via_if_scalar(double x) {
  if (x > 0) {
    return 1.;
  } else if (x < 0) {
    return -1.;
  } else {
    return 0.;
  }
}

// [[Rcpp::export]]
NumericVector sign_via_if(NumericVector x) {
  int n = x.size();
  NumericVector x_sign(n);
  for(int i = 0; i < n; ++i) {
    x_sign[i] = sign_via_if_scalar(x[i]);
  }
  return x_sign;
}

// [[Rcpp::export]]
double sign_via_subtract_scalar(double x) {
  return (double)(x > 0) - (double)(x < 0);
}

// [[Rcpp::export]]
NumericVector sign_via_subtract(NumericVector x) {
  int n = x.size();
  NumericVector x_sign(n);
  for(int i = 0; i < n; ++i) {
    x_sign[i] = sign_via_subtract_scalar(x[i]);
  }
  return x_sign;
}
