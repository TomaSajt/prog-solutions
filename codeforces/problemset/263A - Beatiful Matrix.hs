import Data.List (elemIndex, findIndex)
import Data.Maybe (isJust)

main = interact $ show . pog . map words . lines

pog board = abs (r - 2) + abs (c - 2)
  where
    maybePosList = map (elemIndex "1") board
    (Just r) = findIndex isJust maybePosList
    (Just c) = maybePosList !! r
