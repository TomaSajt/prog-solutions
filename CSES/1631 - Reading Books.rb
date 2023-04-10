a=`sed 1d`.split.map &:to_i
p [2*a.max,a.sum].max
