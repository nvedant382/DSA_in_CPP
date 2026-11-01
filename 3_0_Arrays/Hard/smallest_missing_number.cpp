/*

function missingNumber(arr, n) {
    let present = new Array(n + 2).fill(false);

    for (let i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] <= n + 1) {
            present[arr[i]] = true;
        }
    }

    for (let i = 1; i <= n + 1; i++) {
        if (!present[i]) return i;
    }
}


*/

/*

function missingNumber(arr, n) {
    for (let i = 1; i <= n + 1; i++) {
        let found = false;
        for (let j = 0; j < n; j++) {
            if (arr[j] === i) {
                found = true;
                break;
            }
        }
        if (!found) return i;
    }
}


*/

/*
*/