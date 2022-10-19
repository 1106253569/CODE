x <- runif(10000, 0, 2)
I1 <- 2 * mean(exp(x))
x <- runif(20000, 0, 2)
I2 <- 2 * mean(exp(x))
x <- runif(30000, 0, 2)
I3 <- 2 * mean(exp(x))
print(list(I1, I2, I3))

set.seed(1)
I.true <- integrate(function(x) exp(x), 0, 2)
I.true
N <- 10000
yvec <- exp(runif(N, 0, 2))
I.hat1 <- 2 * mean(yvec)
N <- 20000
yvec <- exp(runif(N, 0, 2))
I.hat2 <- 2 * mean(yvec)
N <- 30000
yvec <- exp(runif(N, 0, 2))
I.hat3 <- 2 * mean(yvec)
print(list(I.hat1, I.hat2, I.hat3))

x <- seq(0, 1, length = 100)
h <- exp(-x) / (1 + x^2)
plot(x, h, type = "l")

f1 <- 1
abline(h = 1)
x <- seq(0, 100)
f2 <- exp(-x)
plot(x, f2, type = "l")

x <- seq(-1000, 1000)
f3 <- 1 / (pi * (1 + x^2))
plot(x, f3, type = "l")

x <- seq(0, 1, length = 100)
f4 <- (1 - exp(-1))^(-1) * exp(-x)
plot(x, f4, type = "l")

x <- seq(0, 1, length = 100)
f5 <- 4 / (pi * (1 + x^2))
plot(x, f5, type = "l")

I.true <- integrate(function(x) exp(-x) / (1 + x^2), 0, 1)
set.seed(1)
N <- 10000
Ginv <- function(y) y
x <- Ginv(runif(N))
eta <- exp(-x) / (1 + x^2)
I1 <- mean(eta)
var1 <- var(eta)
print(I.true)
print(list(I1, var1))

set.seed(1)
N <- 10000
Ginv <- function(y) log(1 / (1 - y))
x <- Ginv(runif(N))
eta <- 1 / (1 + x^2)
I2 <- mean(eta)
var2 <- var(eta)
print(list(I2, var2))

set.seed(1)
N <- 10000
Ginv <- function(y) tan(pi * y - pi / 2)
x <- Ginv(runif(N))
eta <- pi * exp(-x)
I3 <- mean(eta)
var3 <- var(eta)
print(list(I3, var3))

set.seed(1)
N <- 10000
Ginv <- function(y) 1 / (log(1 - (1 - exp(1)^-1) * y))
x <- Ginv(runif(N))
eta <- (1 - exp(1)^-1) / (1 + x^2)
I4 <- mean(eta)
var4 <- var(eta)
print(list(I4, var4))

set.seed(1)
N <- 10000
Ginv <- function(y) tan(pi * y / 4)
x <- Ginv(runif(N))
eta <- pi * exp(-x) / 4
I5 <- mean(eta)
var5 <- var(eta)
print(list(I5, var5))

set.seed(1)
I.true <- integrate(function(x) exp(-x) / (1 + x^2), 0, 1)
I.true
N <- 1000
yvec1 <- exp(-runif(N, 0, 0.1)) / (1 + (runif(N, 0, 0.1))^2)
I1.hat <- mean(yvec1) / 10
I1.hat
var1 <- var((yvec1)^2) / 100 - (I1.hat)^2
var1
yvec2 <- exp(-runif(N, 0.1, 0.2)) / (1 + (runif(N, 0.1, 0.2))^2)
I2.hat <- mean(yvec2) / 10
I2.hat
var2 <- var((yvec2)^2) / 100 - (I2.hat)^2
var2
yvec3 <- exp(-runif(N, 0.2, 0.3)) / (1 + (runif(N, 0.2, 0.3))^2)
I3.hat <- mean(yvec3) / 10
I3.hat
var3 <- var((yvec3)^2) / 100 - (I3.hat)^2
var3
yvec4 <- exp(-runif(N, 0.3, 0.4)) / (1 + (runif(N, 0.3, 0.4))^2)
I4.hat <- mean(yvec4) / 10
I4.hat
var4 <- var((yvec4)^2) / 100 - (I4.hat)^2
var4
yvec5 <- exp(-runif(N, 0.4, 0.5)) / (1 + (runif(N, 0.4, 0.5))^2)
I5.hat <- mean(yvec5) / 10
I5.hat
var5 <- var((yvec5)^2) / 100 - (I5.hat)^2
var5
yvec6 <- exp(-runif(N, 0.5, 0.6)) / (1 + (runif(N, 0.5, 0.6))^2)
I6.hat <- mean(yvec6) / 10
I6.hat
var6 <- var((yvec6)^2) / 100 - (I6.hat)^2
var6
yvec7 <- exp(-runif(N, 0.6, 0.7)) / (1 + (runif(N, 0.6, 0.7))^2)
I7.hat <- mean(yvec7) / 10
I7.hat
var7 <- var((yvec7)^2) / 100 - (I7.hat)^2
var7
yvec8 <- exp(-runif(N, 0.7, 0.8)) / (1 + (runif(N, 0.7, 0.8))^2)
I8.hat <- mean(yvec8) / 10
I8.hat
var8 <- var((yvec8)^2) / 100 - (I8.hat)^2
var8
yvec9 <- exp(-runif(N, 0.8, 0.9)) / (1 + (runif(N, 0.8, 0.9))^2)
I9.hat <- mean(yvec9) / 10
I9.hat
var9 <- var((yvec9)^2) / 100 - (I9.hat)^2
var9
yvec10 <- exp(-runif(N, 0.9, 1)) / (1 + (runif(N, 0.9, 1))^2)
I10.hat <- mean(yvec10) / 10
I10.hat
var10 <- var((yvec10)^2) / 100 - (I10.hat)^2
var10
I6 <- (I1.hat + I2.hat + I3.hat + I4.hat + I5.hat + I10.hat + I6.hat + I7.hat + I8.hat + I9.hat)
I6
var6.hat <- (var1 + var2 + var3 + var4 + var5 + var6 + var7 + var8 + var9 + var10)
var6.hat

sum <- 0
for (j in 1:10)
{
    sum <- sum + exp(-(j - 1 + runif(1000, (j - 1) / 10, j / 10)) / 10) / (1 + ((j - 1 + runif(1000, (j - 1) / 10, j / 10)) / 10)^2)
}
I7 <- sum / 10
print(I7)

h <- exp(-(x - 3)^2 / 2) + exp(-(x - 6)^2 / 2)
f <- exp(-x^2 / 2) / sqrt(2 * pi)
I.true <- integrate(function(x) exp(-(x - 3)^2 / 2) + exp(-(x - 6)^2 / 2) * exp(-x^2 / 2) / sqrt(2 * pi), -Inf, Inf)
I.true

set.seed(1)
I.true <- integrate(function(x) exp(-(x - 3)^2 / 2) + exp(-(x - 6)^2 / 2) * exp(-x^2 / 2) / sqrt(2 * pi), -Inf, Inf)
I.true$value
N <- 1000
yvec <- exp(-(rnorm(N) - 3)^2 / 2) + exp(-(rnorm(N) - 6)^2 / 2)
I.hat <- mean(yvec)
I.hat
I.hat - I.true$value

set.seed(1)
N <- 1000
Ginv <- function(y) sqrt(1 + 3 * y) - 1
x <- Ginv(rnorm(N))
eta <- (exp(-(x - 3)^2 / 2) + exp(-(x - 6)^2 / 2)) / (2 * (1 + x) / 3)
I1 <- mean(eta)
I1
var1 <- var(eta)
var1
