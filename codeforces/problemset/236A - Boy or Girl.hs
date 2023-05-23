import Data.List (nub)

main = interact $ (\n -> if even n then "CHAT WITH HER!" else "IGNORE HIM!") . length . nub . head . lines
