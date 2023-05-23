ceilDiv n d = (n + d - 1) `div` d

main = interact $ show . (\[n, m, a] -> ceilDiv n a * ceilDiv m a) . map read . words
