-- https://www.twanvl.nl/blog/haskell/Knuth-Morris-Pratt-in-Haskell

data KMP a = KMP
  { done :: Bool,
    next :: a -> KMP a
  }

makeTable' [] failure = KMP True failure
makeTable' (x : xs) failure = KMP False test
  where
    test c = if c == x then success else failure c
    success = makeTable' xs $ next $ failure x

makeTable xs = table
  where
    table = makeTable' xs (const table)

numMatches [haystack, needle] = length . filter done $ scanl next (makeTable needle) haystack

main = interact $ show . numMatches . map ((\l -> zipWith (-) l $ tail l) . map read . words) . tail . lines
