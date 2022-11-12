x <- c(20, 29, 30, 40, 60, 120)
y <- c(4.35, 4.18, 4.17, 4.08, 4.00, 3.92)
print(approx(x, y, 43.2))

fx <- function(x) {
    (x + 2) / sqrt(1 + 2 * x)
}
a <- 0
b <- 4
n <- 1
h<-(b-a)/n
xi <- seq(from = a, to = b, by = h)
xis <- xi[-c(1, length(xi))]
Tn<--h/2*(fx(a)+2*(sum(fx(xis)))+fx(b))
print(Tn)
n <- 4
h <- (b - a) / n
xi <- seq(from = a, to = b, by = h)
xis <- xi[-c(1, length(xi))]
mid <- xi[-length(xi)] + h / 2
Sn <- h / 6 * (fx(a) + 4 * (sum(fx(mid))) + 2 * (sum(fx(xis))) + fx(b))
Sn