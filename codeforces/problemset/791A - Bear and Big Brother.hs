import Data.List (findIndex)
import Data.Maybe (fromJust)

iterMult [a, b] = (a, b) : iterMult [3 * a, 2 * b]

main = interact $ show . fromJust . findIndex (uncurry (>)) . iterMult . map read . words
