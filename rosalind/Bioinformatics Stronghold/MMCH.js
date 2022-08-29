let str =
    "GUUGAUCGAGUUCCAUAACUAGAUGGUUAGCCGUAAGGGGUUGAAGUGCCUCCCCAUCGUAGGGGCCUGCAAAGGUUGUAGCACUUU";
let [a, u, c, g] = [/A/g, /U/g, /C/g, /G/g].map((r) =>
    BigInt((str.match(r) || []).length)
);
const solve = (a, b) => {
    if (a < b) [a, b] = [b, a];
    let res = 1n;
    for (let i = a; i > a - b; i--) res *= i;
    return res;
};
let res = 1n;
console.log(solve(a, u) * solve(c, g));
