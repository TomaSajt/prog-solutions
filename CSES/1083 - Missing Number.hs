main = interact $ show . (\[[n], s] -> ((n * (n + 1)) `div` 2) - sum s) . map (map read . words) . lines
