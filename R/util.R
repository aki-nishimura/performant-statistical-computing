
are_all_close <- function(vector1, vector2, rel_tol = 1e-3) {
  ave_magnitude <- (abs(vector1) + abs(vector2)) / 2
  coord_rel_err <- abs(vector1 - vector2) / ave_magnitude
  return(all(coord_rel_err < rel_tol))
}

install_and_load_packages <- function(package_names) {
  for (pkg in required_packages) {
    if (!(pkg %in% rownames(installed.packages()))) {
      install.packages(pkg)
    }
    library(pkg, character.only = TRUE)
  }
}

summarize_benchmark <- function(bench_output, include_expression = FALSE) {
  col_to_print <- c("min", "median", "mem_alloc", "n_itr")
  if (include_expression) {
    col_to_print <- c("expression", col_to_print)
  }
  print_output <- capture.output(print(bench_output[col_to_print]))
  row_to_print <- c(2, 4)
  for (i in row_to_print) {
    cat(paste0(print_output[i], '\n'))
  }
}

simulate_sparse_binary_design <- function(n_obs, n_pred, density, seed = NULL) {
  if (!is.null(seed)) {
    set.seed(seed)
  }
  if (density < 0 || density > 1) {
    stop("Density must be between 0 and 1")
  }
  if (n_obs < 1 || n_pred < 1) {
    stop("Number of observations and predictors must be larger than 1")
  }
  n_obs <- floor(n_obs)
  n_pred <- floor(n_pred)
  n_nonzero <- as.integer(n_obs * n_pred * density)
  nnz_linear_index <- sample(n_obs * n_pred, n_nonzero, replace = FALSE)
  row_index <- nnz_linear_index %% n_obs + 1
  col_index <- (nnz_linear_index - 1) %/% n_obs + 1
  design_mat <- sparseMatrix(
    i = row_index, j = col_index, x = 1, dims = c(n_obs, n_pred)
  )
  return(design_mat)
}

