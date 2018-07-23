//
// Created by Damian Kurpiewski on 23.07.2018.
//

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<int> cuts;

int computeCost(int from, int to) {
    double center = (to - from) / 2.0 + from;
    int bestCut = 0;
    double bestCutDist = center;
    double dist;
    for (auto cut : cuts) {
        if(cut <= from || cut >= to) {
            continue;
        }

        dist = fabs(center - cut);
        if(dist < bestCutDist) {
            bestCutDist = dist;
            bestCut = cut;
        }
    }

    if(bestCut == 0) {
        return 0;
    }

    printf("%d\n", bestCut);
    return to - from + computeCost(from, bestCut) + computeCost(bestCut, to);
}

int main() {
    int l, n;

    while (scanf("%d", &l) && l > 0) {
        scanf("%d", &n);
        cuts = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &cuts[i]);
        }

        printf("The minimum cutting is %d.\n", computeCost(0, l));
    }

    return 0;
}