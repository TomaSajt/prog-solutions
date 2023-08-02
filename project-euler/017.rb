$a=[nil,"one","two","three","four","five","six","seven","eight","nine",
    "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
$b=[nil,nil,"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]
def english n
    return "onethousand" if n==1000
    return "zero" if n==0
    s=""
    hundreds=n/100
    rest=n%100
    s+=$a[hundreds]+"hundred" if hundreds!=0
    s+="and" if hundreds!=0 && rest!=0
    s+=other(rest) if rest!=0
    return s
end
def other n
    return $a[n] if n < 20
    return $b[n/10]+(n%10==0 ? "" : $a[n%10])
end

p (1..1000).sum{english(_1).size}