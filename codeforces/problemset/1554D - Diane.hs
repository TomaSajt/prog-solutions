solve 1 = "a"
solve n = replicate l 'a' ++ "b" ++ replicate (l - 1) 'a' ++ replicate r 'c'
  where
    (l, r) = divMod n 2

main = interact $ unlines . map (solve . read) . tail . lines
