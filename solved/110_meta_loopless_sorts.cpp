#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void wypisz(vector<char> tab, int i, int j, map<pair<char, char>, bool> czy, bool nowa) {
    if (j > tab.size() - i - 2) {
        i++;
        j = 0;
    }

    if (i > tab.size() - 2) {
        if (!nowa) {
            printf("\n");
        }

        printf("writeln(%c", tab[0]);
        for (int x = 1; x < tab.size(); ++x) {
            printf(",%c", tab[x]);
        }

        printf(")\n");
        return;
    }

    pair<char, char> t1 = make_pair(tab[j], tab[j + 1]), t2 = make_pair(tab[j + 1], tab[j]);
    if (!czy[t1] && !czy[t2]) {
        czy[t1] = 1;
        czy[t2] = 1;
        printf("if %c < %c then\n", tab[j], tab[j + 1]);
        vector<char> tmp = tab;
        swap(tmp[j], tmp[j + 1]);
        j++;
        wypisz(tab, i, j, czy, 1);
        printf("else ");
        wypisz(tmp, i, j, czy, 0);
    } else {
        czy[t1] = 1;
        czy[t2] = 1;
        j++;
        wypisz(tab, i, j, czy, nowa);
    }
}

int main() {
    int M;
    scanf("%d", &M);
    for (int x = 1; x <= M; ++x) {
        map<pair<char, char>, bool> czy;
        int n;
        scanf("%d", &n);
        vector<char> tab(n, 'a');
        for (int i = 1; i < n; ++i) {
            tab[i] = tab[i - 1] + 1;
        }

        printf("program sort(input,output);\nvar\n");
        printf("a");
        for (int i = 1; i < n; ++i) {
            printf(",%c", tab[i]);
        }

        printf(" : integer;\nbegin\nreadln(a");
        for (int i = 1; i < n; ++i) {
            printf(",%c", tab[i]);
        }

        printf(");\n");
        if (n == 1) {
            printf("writeln(a)\n");
        } else {
            wypisz(tab, 0, 0, czy, 1);
        }

        printf("end.\n");
        if (x != M) {
            printf("\n");
        }
    }

    return 0;
}
