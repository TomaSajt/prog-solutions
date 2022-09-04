const ids = [
    "A2A2Y4",
    "P19835_BAL_HUMAN",
    "P10761_ZP3_MOUSE",
    "P05231_IL6_HUMAN",
    "A8GP89",
    "Q58CQ5",
    "Q0U2C0",
    "P22891_PRTZ_HUMAN",
    "O14977",
    "P01008_ANT3_HUMAN",
    "Q3ATP6",
    "Q0IBF4",
];

(async () => {
    let out = "";
    const regex = /(?=(N[^P][ST][^P]))/g;
    for (let id of ids) {
        let ind = id.indexOf("_");
        let shortID = ind >= 0 ? id.substring(0, ind) : id;
        let link = `http://www.uniprot.org/uniprot/${shortID}.fasta`;
        let res = await fetch(link);
        let text = await res.text();
        let str = text.split("\n").slice(1).join("");
        let arr = [];
        for (let match of str.matchAll(regex)) {
            arr.push(match.index + 1);
        }
        if (arr.length != 0) {
            out += id + "\n" + arr.join(" ") + "\n";
        }
        await new Promise((res) => setTimeout(res, 200));
    }
    console.log(out);
})();
