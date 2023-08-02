a=600851475143
b=2
while a!=1
    if a%b==0
        a/=b
    else
        b+=1
    end
end
p b