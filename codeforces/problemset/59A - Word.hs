import Data.Char (isUpper, toLower, toUpper)

main = interact $ (\s -> map (if 2 * length (filter isUpper s) > length s then toUpper else toLower) s) . head . lines
