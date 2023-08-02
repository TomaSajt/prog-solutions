a,b,s=0,1,0
while a<=4000000
    s+=a
    3.times{x=a+b;a=b;b=x}
end
p s