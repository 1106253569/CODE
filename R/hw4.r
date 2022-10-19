N <- 100
A <- 3.5
B <- 3.5
d <- 0.8
K <- 6
r <- d / 2
d2 <- d^2
sigma <- 0.5
oldpar <- par(pty = "s", bty = "n", mar = c(0, 0, 1, 0))

circ <- function(x, y, r, ...) {
    n <- 30
    theta <- seq(0, 2 * pi, length = n)
    xx <- x + r * cos(theta)
    lines(xx, yy, color = red)
}


