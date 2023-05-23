import Data.Char (toLower)
import Data.List (intersperse)

main = interact $ ('.' :) . intersperse '.' . filter (not . (`elem` "aoyeui")) . map toLower . head . lines
