#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
struct bud {
    int l, h, p;
};

bool operator<(bud a, bud b) {
    if (a.l == b.l)
        return a.p > b.p;
    else
        return a.l > b.l;
}

int main() {
    bud b;
    priority_queue<bud> kol;
    int mxp, mnl;
    scanf("%d %d %d", &b.l, &b.h, &b.p);
    kol.push(b);
    mxp = b.p;
    mnl = b.l;
    while (scanf("%d %d %d", &b.l, &b.h, &b.p) != EOF) {
        kol.push(b);
        mxp = max(mxp, b.p);
    }

    b.l = mnl;
    b.p = mxp;
    b.h = 0;
    kol.push(b);
    b = kol.top();
    kol.pop();
    int g = b.l, w = b.h, k = b.p;
    printf("%d ", g);
    while (!kol.empty()) {
        b = kol.top();
        kol.pop();
        if (b.l >= k && b.h != w) {
            printf("%d %d ", w, k);
            k = b.p;
            g = b.l;
            w = b.h;
        } else if (b.h == w && b.l == k) {
            k = b.p;
        } else if (b.h > w) {
            if (b.l == g) {
                if (k > b.p) {
                    bud tmp;
                    tmp.l = b.p;
                    tmp.h = w;
                    tmp.p = k;
                    kol.push(tmp);
                }
                w = b.h;
                k = b.p;
            } else {
                printf("%d %d ", w, b.l);
                if (k > b.p) {
                    bud tmp;
                    tmp.l = b.p;
                    tmp.h = w;
                    tmp.p = k;
                    kol.push(tmp);
                }
                w = b.h;
                k = b.p;
            }
        } else if (b.p > k) {
            bud tmp;
            tmp.l = k;
            tmp.p = b.p;
            tmp.h = b.h;
            kol.push(tmp);
        }
    }

    printf("%d %d 0\n", w, k);
    return 0;
}
