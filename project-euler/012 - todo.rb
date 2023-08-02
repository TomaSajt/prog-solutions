k=500
i=1
n=1
p (1..k).reduce(:lcm)
loop do
    p n
    break if (1..n).count{|i|n%i==0}>k
    i+=1
    n=n*(i+1)/(i-1)
end