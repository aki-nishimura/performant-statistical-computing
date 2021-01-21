---
permalink: /syllabus/
title: "Syllabus"
---

## Prerequisite
R or Python programing, Linear algebra

Basic knowledge of C language (or interfaces to it, such as Rcpp and Cython) is useful, but easy enough to pick up as needed.

## Grading
Class participation, Homework, and (potentially) Project

## Course topics (tentative)

#### Numerical stability & finite precision arithmetic through examples
  <!-- likelihood vs log-likelihood -->
  * Finite difference approximation of gradient
    - Example: unit-test your log-likelihood and gradient derivation --- how close the numerical gradient can be to the exact one?
  * Dealing with ill-conditioned matrices
    - Example: Gaussian process regression, sparse regression, etc --- what to do when Cholesky fails (SVD, preconditioning, or what?).
  * Failure of Gram-Schmidt orthogonalization
    - Example: principal component analysis using inverse covariance matrix --- re-orthogonalized Lanczos algorithm for finding the smallest eigenvalue / eigenvector.
    <!--
    Algorithm 7.2 in Demmel
    Related example:
      Gram–Schmidt with double orthogonalization
      Naive algorithm for computing the smallest eigenvalue
    -->

#### Algorithm performance on modern hardware
  * Cost of arithmetic operations vs data access: why a count of floating point operations may be irrelevant
  * A bit of assembly code
  * Multi-tiered memory caches
  * Vectorization & data locality
  * Examples:
    - Performance comparison between different linear algebra libraries
    - Sparse vs dense matrix operations
    - Masking to avoid branching in for-loop
  * Parallel computing:
    * Shared memory vs. embarassing parallelism
    * Instruction-level parallelism
    * Example: tale of laptop beating a cluster with 128 CPUs
    <!--
    http://www.frankmcsherry.org/graph/scalability/cost/2015/01/15/COST.html
    https://www.usenix.org/system/files/conference/hotos15/hotos15-paper-mcsherry.pdf
    -->
  * Other issues: low precision computing, branch prediction, overheating, etc

#### Data structures in statistical computing
  * Sparse matrices: storage formats and their computational properties
    * Example: coordinate descent
  * Preprocessing design matrices
    * Example: Cox model, propensity score matched / stratified regression

#### Algorithms for large scale data:
  * Stochastic gradient descent
    * Robbins-Monro algorithm
    * Momentum acceleration
  * Hamiltonian Monte Carlo
  <!--
  Sketched Newton's method, Ref: https://arxiv.org/pdf/1505.02250.pdf
  -->

#### Statistical software designs (Time allowing)
  * General purpose vs focused
    * Example: Stan vs glmnet (or BayesBridge)
  * Start small and keep it extensible / maintainable
    * Example: building Bayesian hierarchical model and Gibbs sampler one step at a time
  * Tuning algorithm parameters
    <!--
    Do users a favor and provide defaults
    Empirical calibration
    -->
      * Example: stochastic optimization of Metropolis acceptance rate
  * Cross-platform portability
  * User-friendly features
    <!--
    (Discussion based lectures?)
    Allow specifying a max number of iterations
    Through useful warnings and errors
    Report progress
    -->

#### Essentials for statistical software developer / contributor (Maybe)
  * Software licensing
    * Permissive vs copy left / viral
    <!--
    Different conditions in a nutshell:
      Give me credits
      You can't sue me
      State changes. (This sounds reasonable, but gets rather annoying quickly, so don't ask this if possible.)
      You are stuck with the same license if you wanna use me
    -->
  * Tools of the trade:
    * Visual diff
    * Navigating codebase: find and grep (in addition to good IDE)
    * Git with its full capability unleashed: rebase, log --follow, blame, tag, etc
