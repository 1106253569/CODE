# qes01
x <- sin(223 / 3)
y <- x^2
z <- y * 10
print(x + 2 * y - 5 * z)


# qes02
vector1 <- seq(from = 2, to = 50, by = 2)
print(vector1)
print(vector1[c(10, 15, 20)])
print(vector1[10:20])
print(vector1[vector1 > 40])


# qes03
cell1 <- c(3, 2, 3, 4, 2, 6, 7, 8, 1)
A <- matrix(cell1, nrow = 3, ncol = 3, byrow = TRUE) # nolint
print(A)
B <- matrix(1:3, nrow = 3, ncol = 3, byrow = FALSE) # nolint
print(B)
print(A %*% B)
print(A * B)


# qes04
A <- matrix(1:16, nrow = 4, ncol = 4, byrow = FALSE) # nolint 
B <- matrix(1:16, nrow = 4, ncol = 4, byrow = TRUE) # nolint
C <- A + B # nolint 
D <- A %*% B # nolint
print(list(A, B, C, D)) # 组合成list输出，使代码更简练

# qes05
x <- 1:10
write(x, file = "R/x.txt")
rm(x)
x <- read.table("R/x.txt")
x <- as.numeric(unlist(x))
str(x)

# qes06
x <- 1:100
for (i in 1:length(x)) { # nolint
    cat(x[i], " ")
}
cat("\n")
i <- 1
while (i <= length(x)) {
    cat(x[i], " ") # nolint
    i <- i + 1
}
i <- 1
cat("\n")
repeat{ # nolint
    if (i > length(x)) {
        cat("\n")
        break
    }

    cat(x[i], " ")
    i <- i + 1
}

# qes07
i <- 1
sum <- 0
while (i <= 100) {
    sum <- sum + i
    i <- i + 1
}
print(sum)

# qes08
i <- 1
sum <- 0
repeat{ # nolint
    if (i > 100) {
        print(sum)
        break
    }
    if (i %% 2 != 0) {
        sum <- sum + i
    }
    i <- i + 1
}

# qes09
myFunction <- function(x) { # nolint
    if (x %% 3 == 0 || x %% 5 == 0) {
        return(TRUE)
    } else {
        return(FALSE)
    }
}
sum <- 0
for (i in 1:100) { # nolint
    if (myFunction(i)) {
        sum <- sum + i
    }
    i <- i + 1
}
print(sum)

# qes10
myData <- rnorm(100, mean = 1, sd = 1) # nolint
str(myData)
cat(min(myData), "\t", which.min(myData))
