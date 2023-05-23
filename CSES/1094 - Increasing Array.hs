main = interact $ show . sum . (\x -> zipWith (-) (scanl1 max x) x) . map read . words . last . lines
