import Data.List (foldl')
import qualified Data.Set as S

data Command = Add String | Remove String | Send Int

readCommand ('+' : name) = Add name
readCommand ('-' : name) = Remove name
readCommand s = Send . length . tail . dropWhile (/= ':') $ s

processCommand (set, acc) (Add name) = (S.insert name set, acc)
processCommand (set, acc) (Remove name) = (S.delete name set, acc)
processCommand (set, acc) (Send len) = (set, acc + S.size set * len)

main = interact $ show . snd . foldl' processCommand (S.empty, 0) . map readCommand . lines
