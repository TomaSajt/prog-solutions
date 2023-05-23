solve :: [[Int]] -> Int
solve [[_, k], a] = length (filter (>= (a !! (k - 1))) $ filter (> 0) a)

main = interact $ show . solve . map (map read . words) . lines
