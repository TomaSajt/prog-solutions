n=13
x=File.read("./input/008.txt").gsub(/\s/,"").chars.map(&:to_i)
p (0..x.size-n-1).map{|i|(i..i+n-1).map{x[_1]}.reduce(:*)}.max