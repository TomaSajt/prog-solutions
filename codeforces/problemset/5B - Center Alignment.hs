import Data.Tuple (swap)

centerLines _ _ [] = []
centerLines l d (x : xs) = x' : centerLines l d' xs
  where
    a = l - length x
    (pl, pr) = (if d then swap else id) $ splitAt (a `div` 2) $ replicate a ' '
    d' = (if odd a then not else id) d
    x' = pl ++ x ++ pr

processLines :: [String] -> [String]
processLines lns = map (\x -> "*" ++ x ++ "*") $ p ++ centerLines l False lns ++ p
  where
    l = maximum . map length $ lns
    p = [replicate l '*']

main = interact $ unlines . processLines . lines
