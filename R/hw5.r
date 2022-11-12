h <- function(x) exp(x)
N <- 10000
set.seed(1)
eta1 <- h(runif(N / 2, 0, 1))
a <- mean(eta1)
eta2 <- h(runif(N / 2, 1, 2))
b <- mean(eta2)
I1 <- a + b
I1

N <- 10000
set.seed(1)
h1 <- function(x) exp(x)
x1 <- h1(runif(N, 0, 1))
a <- mean(x1)
h2 <- function(x) -1.690 * (x - 0.5)
x2 <- h2(runif(N, 0, 1))
b <- mean(x2)
I2 <- a + b
I2

# 例3.3.3
N <- 10000
set.seed(1)
h1 <- function(x) exp(x)
h2 <- function(x) exp(1 - x)
x <- (h1(runif(N, 0, 1)) + h2(runif(N, 0, 1))) / 2
I3 <- mean(x)
I3

N <- 10000
x <- runif(N, -1, 1)
y <- sqrt(1 - x^2)
I4 <- 4 * sum(y) / N
I4

model
{
    p[1] <- 1 / 3
    p[2] <- (1 - b) / 3
    p[3] <- (1 - 2 * b) / 3
    p[4] <- 2 * b / 3
    p[5] <- b / 3
    b <- b2 / 2
    b2 ~ dbeta(1, 1)
    x[1:5] ~ dmulti(p[1:5], N)
}
list(x = c(82, 72, 45, 34, 17), N = 250)
list(M = structure(.Data = c(1, 2, 3, 4, 5, 6), .Dim = c(3, 2)))
list(b2 = 0.2)
list(b2 = 0.8)
library(BRugs)
modelCheck("pf1-model.txt")
modelData("pf1-data.txt")
modelCompile(numChains = 2)
modelInits(c("pf1-inits1.txt", "pf1-inits2.txt"))
modelUpdate(1000)
samplesSet(c("b", "p[1:5]"))
modelUpdate(10000)
b2chains <- samplesHistory("b", plot = FALSE)
samplesHistory("b")
print(samplesStats("*"))
samplesDensity("b", mfrow = c(1, 1))
samplesAutoC("b", 1, mfrow = c(1, 1))
samplesBgr("b", mfrow = c(1, 1))
