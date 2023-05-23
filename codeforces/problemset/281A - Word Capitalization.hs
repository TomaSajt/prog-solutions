import Data.Char (toUpper)

main = interact (\(x : xs) -> toUpper x : xs)
