$a=[0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8]
$b=[0,0,6,6,5,5,5,7,6,6]
def english n
    return 11 if n==1000
    return 4 if n==0
    s=0
    hundreds=n/100
    rest=n%100
    s+=$a[hundreds]+7 if hundreds!=0
    s+=3 if hundreds!=0 && rest!=0
    s+=other(rest) if rest!=0
    return s
end
def other n
    return $a[n] if n < 20
    return $b[n/10]+(n%10==0 ? 0 : $a[n%10])
end
p (1..1000).sum{english(_1)}