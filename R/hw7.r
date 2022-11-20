rng.geom <- function(n = 1, p = 0.5) {
    ceiling(log(runif(n)) / log(1 - p))
}
x <- rng.geom(1000, p = 0.1)
mean(x)
rbernoulli.geom <- function(size = 1, prob = 0.1) {
    x <- numeric(size)
    k <- 0
    while (k <= size) {
        T <- rgeom(1, prob = prob)
        if (T > 1) {
            x[(k + 1):(min(c(k + T - 1, size)))] <- 0
        }
        if (k + T <= size) x[k + T] <- 1
        k <- k + T
    }
    x
}
x <- rbernoulli.geom(size = 1000, prob = 0.1)
prop.table(table(x)) * 100

rnbinom.v1 <- function(n, size = 1, prob = 0.5) {
    x <- numeric(n)
    for (i in 1:n)
    {
        U <- runif(1)
        k <- 0
        cc <- prob
        a <- (1 - prob)^size
        F <- a
        while (U > F) {
            a <- a * cc * (size + k) / (k + 1)
            F <- F * a
            k <- k + 1
        }
        x[i] <- k
    }
    x
}
x <- rnbinom.v1(n = 10000, size = 10, prob = 0.3)
x
round(prop.table(table(x)) * 100)
round(dnbiom(0:10, size = 10, prob = 0.3) * 100)

rng.rtri <- function(n) {
    sqrt(runif(n))
}
x <- rng.rtri(1000)
hist(x, freq = FALSE)
curve(1 / 2 * x^(1 / 2 - 1), 0, 1, col = "red", add = TRUE)

rng.rtri <- function(n) {
    sqrt(runif(n))
}
x <- rng.rtri(1000)
hist(x, freq = FALSE)
curve(1 / 2 * x^(1 / 2 - 1), 0, 1, col = "red", add = TRUE)

rng.rtri <- function(n) {
    sqrt(runif(n))
}
x <- rng.rtri(1000)
hist(x, freq = FALSE)
curve(2 / (pi * sqrt(1 - x^2)), 0, 1, col = "red", add = TRUE)
