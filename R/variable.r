# 向量
x <- c(1:20, nrow = 5, ncol = 4)
print(x)
# 矩阵
y <- matrix(1:10, nrow = 2)
print(y)
# 数组
dim1 <- c("A1", "A2")
dim2 <- c("B1", "B2", "B3")
dim3 <- c("C1", "C2", "C3", "C4")
z <- array(1:24, c(2, 3, 4), dimnames = list(dim1, dim2, dim3))
print(z)
# 数据框
pid <- c(1, 2, 3, 4)
age <- c(12, 34, 28, 52)
diabetes <- c("Type1", "Type2", "Type3", "Type4")
status <- c("Poor", "Improved", "Excellent", "Poor")
patientdata <- data.frame(pid, age, diabetes, status)
print(patientdata)
print(patientdata[1:2])
print(patientdata[c("diabetes", "status")])
print(patientdata$pid)
a <- table(patientdata$diabetes, patientdata$status)
print(summary(patientdata$age))
status <- factor(
    x = status, order = TRUE,
    levels = c("Poor", "Improved", "Excellent")
)
demo <- summary(patientdata)
print(demo)
print(str(patientdata))
g <- list(x, y, z, patientdata)
print(g)