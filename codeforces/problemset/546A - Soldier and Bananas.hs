main = interact $ show . (\[k, n, w] -> max 0 $ ((k * w * (w + 1)) `div` 2) - n) . map read . words
