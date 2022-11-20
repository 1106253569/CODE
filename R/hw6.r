library(Matrix)
A <- matrix(c(4, 2, 0, 2, 2, 10, 12, 1, 0, 12, 17, 2, 2, 1, 2, 9), nrow = 4)
b <- c(2, -3, 4, 1)
X <- solve(A, b)
X
lu <- expand(lu(A))
lu
chol <- chol(A)
chol

A <- matrix(c(3, 6, 15, 18, 1, 4, 11, 16, 2, 7, 18, 25, 1, 11, 34, 56), nrow = 4)
b <- c(5, 5, 6, -4)
qr <- qr(A)
qr
ei <- eigen(A)
ei
svd <- svd(A)
svd
A1 <- MASS::ginv(A)
A1
