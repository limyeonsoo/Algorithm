const reverse = (u) = > {
    let result = "";
    for (let i = 0; i < u.length; i++) result += (u[i] == '(' ? ')' : '(');
    return result;
}
const split = (w) = > {
    let leftCnt = 0;
    let rightCnt = 0;
    let u = "";
    let v = "";
    for (let i = 0; i < w.length; i++) {
        if (w[i] == = '(') leftCnt += 1;
        else rightCnt += 1;
        if (leftCnt == = rightCnt) {
            u = w.substring(0, leftCnt + rightCnt);
            v = w.substring(leftCnt + rightCnt, w.length);
            return[u, v];
        }
    }
}

const checkCorrect = (w) = > {
    //rightCnt 가 큰 순간 올바르지 않지 않나?
    let leftCnt = 0;
    let rightCnt = 0;

    for (let i = 0; i < w.length; i++) {
        if (w[i] == = '(') leftCnt += 1;
        else rightCnt += 1;
        if (rightCnt > leftCnt) {
            return false;
        }
    }
    return true;
}
const process3 = (w) = > {
    if (checkCorrect(w)) return w;
    let[u, v] = split(w);
    if (checkCorrect(u)) w = u + process3(v);
    else w = process4(u, v);
    return w;
}

const process4 = (u, v) = > {
    let temp = "(";
    temp += process3(v);
    temp += ")"
        temp += reverse(uFirstLast(u));
    return temp;
}
const uFirstLast = (u) = > {
    // u가 작으면 ?  => 빈 문자열이 반환되네
    let newU = u.substring(1, u.length - 1);
    return newU;
}
function solution(p) {
    var answer = '';

    p = process3(p);


    return p;
}