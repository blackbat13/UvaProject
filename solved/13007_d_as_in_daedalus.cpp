#include <cstdio>

using namespace std;

int main () {
    int n, m, result, budget, daedalus, card_sum, card, best_card;
    while(scanf("%d %d", &n, &m) != EOF) {
        result = 0;
        for(int i = 0; i < m; ++i) {
            card_sum = 0;
            scanf("%d %d", &budget, &daedalus);
            for(int j = 1; j < n; ++j) {
                scanf("%d", &card);
                card_sum += card;
            }

            best_card = 10000;
            if(card_sum + daedalus > budget) {
                daedalus = 0;
            }
            
            while(card_sum + best_card > budget && best_card > daedalus) {
                best_card /= 10;
            }

            result += best_card - daedalus;
        }

        printf("%d\n", result);
    }

    return 0;
}