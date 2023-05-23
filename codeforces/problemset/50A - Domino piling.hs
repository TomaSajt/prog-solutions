main = interact $ show . (`div` 2) . product . map read . words
