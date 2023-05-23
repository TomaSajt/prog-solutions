main = interact $ unlines . map (\w -> if length w > 10 then head w : show (length w - 2) ++ [last w] else w) . tail . lines
