main = interact $ show . length . filter (> 1) . map (sum . map read . words) . tail . lines
