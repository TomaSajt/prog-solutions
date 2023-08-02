n=1000000
$mem={1=>1}
def f(i)
    return $mem[i] if $mem[i]
    $mem[i] = f(i%2==0 ? i/2 : i*3+1)+1
end
p (1..n-1).max_by{f(_1)}