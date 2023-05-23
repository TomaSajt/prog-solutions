solve _ [] = 0
solve c (x : xs) = (if x == c then 1 else 0) + solve x xs

main = interact $ show . solve '@' . last . lines
