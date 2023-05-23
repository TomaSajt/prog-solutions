import Data.Char (toLower)

ordToInt EQ = 0
ordToInt LT = -1
ordToInt GT = 1

main = interact $ show . ordToInt . (\[a, b] -> compare a b) . lines . map toLower
