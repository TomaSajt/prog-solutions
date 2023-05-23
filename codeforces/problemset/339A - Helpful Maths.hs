import Data.List (intersperse, sort)

main = interact $ intersperse '+' . sort . filter (/= '+') . head . lines
