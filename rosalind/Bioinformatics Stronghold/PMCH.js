let str = "CGCUUAGGUUUUAUCGAAGGGACUAAAAGCCGUCUUUUGCCGCGCACGAUUUACGACCGACUAAGGAGCUAUACGUCAGC";
let a = (str.match(/A/g) || []).length;
let g = (str.match(/G/g) || []).length;
let res = 1n;
for (let i = 2n; i <= a; i++) res *= i;
for (let i = 2n; i <= g; i++) res *= i;
console.log(res);
