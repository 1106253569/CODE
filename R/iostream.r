mydate <- data.frame(
    age = numeric(3),
    gender = character(3),
    weight = numeric(3)
)
mydateTxt <- "  # nolint
age gender weight,
25  m   166,
30  f   115,
18  f   120
"
mydate <- read.table(header = TRUE, text = mydateTxt)
