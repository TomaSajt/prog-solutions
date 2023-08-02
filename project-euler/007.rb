n=10001
max=n*(Math.log(n)+2)
primes=(0..max).to_a
primes[0]=primes[1]=nil
primes.each{|p|
    next if !p
    break if p*p > max
    (p*p).step(max,p){primes[_1]=nil}
}
p primes.compact[n-1]