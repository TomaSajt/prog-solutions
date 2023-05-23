main = interact $ show . sum . map (\l -> if l !! 1 == '+' then 1 else -1) . tail . lines
