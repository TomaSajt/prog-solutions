x=File.read("./input/018.txt").split(/\n/).map{_1.split.map &:to_i}
(1..x.size-1).map{|n|
    (0..n).map{|k|
        x[n][k]+=(k==0 ? x[n-1][k] : k==n ? x[n-1][k-1] : [x[n-1][k],x[n-1][k-1]].max)
    }
}
p x[-1].max
#Duplicate of 067