import Data.Functor ((<&>))

second (x : y : xs) = y : second xs
second _ = []

op a e = zipWith (||) a [even e, odd e]

check s = all (> 0) s

solve s = if check s then "YES" else "NO"

pog s = show $ zip s $ scanl op [False, False] s

main = interact $ unlines . map (pog . map read . words) . second . tail . lines
