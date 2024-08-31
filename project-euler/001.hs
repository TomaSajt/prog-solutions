main = print $ sum $ filter (\x -> any ((== 0) . mod x) [3, 5]) [1 .. 1000]
