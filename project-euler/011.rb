x=File.read("./input/011.txt").split(/\n/).map{_1.split.map(&:to_i)}
n,m,k=x.size,x[0].size,4
a=(k-1..n-k).map{|i|(k-1..m-k).map{|j|[i,j]}}.flatten(1)
d=[[1,0],[1,1],[0,1],[-1,1],[-1,0],[-1,-1],[0,-1],[1,-1]]
p a.map{|i,j|d.map{|u,v|(0..k-1).map{|s|x[i+s*u][j+s*v]}.reduce(:*)}}.flatten.max