series n = n : series (if even n then n `div` 2 else 3 * n + 1)

main = interact $ unwords . map show . (++ [1]) . takeWhile (> 1) . series . read
