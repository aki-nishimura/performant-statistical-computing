
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

simulate_sparse_binary_design <- function(n_obs, n_pred, density, seed = NULL) {
  if (!is.null(seed)) {
    set.seed(seed)
  }
  n_nonzero <- as.integer(n_obs * n_pred * density)
  row_index <- sample.int(n_obs, n_nonzero, replace = TRUE)
  col_index <- sample.int(n_pred, n_nonzero, replace = TRUE)
  design_mat <- sparseMatrix(i = row_index, j = col_index, x = 1)
  return(design_mat)
}

