//
// Created by Damian Kurpiewski on 23.07.2018.
//

#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > blocks;
vector<pair<int, int> > positions;

void print() {
    for(auto i = 0; i < blocks.size(); ++i) {
        cout << i << ":";
        for(auto j = 0; j < blocks[i].size(); ++j) {
            cout << " " << blocks[i][j];
        }

        cout << endl;
    }
}

void init(int n) {
    blocks = vector<vector<int> >(n);
    positions = vector<pair<int, int> >(n);
    for (int i = 0; i < n; ++i) {
        positions[i] = make_pair(i, 0);
        blocks[i].push_back(i);
    }
}

void remove(int pos, int to) {
    auto b = blocks;
    for (int i = blocks[pos].size() - 1; i > to; --i) {
        int item = blocks[pos][i];
        blocks[item].push_back(item);
        positions[item] = make_pair(item, blocks[item].size() - 1);
        blocks[pos].pop_back();
    }
}

/// Move a onto b
void moveOnto(int a, int b) {
    if (positions[a].first == positions[b].first) {
        return;
    }

    remove(positions[a].first, positions[a].second);
    remove(positions[b].first, positions[b].second);

    blocks[positions[a].first].pop_back();
    blocks[positions[b].first].push_back(a);

    positions[a] = make_pair(positions[b].first, blocks[positions[b].first].size() - 1);
}

/// Move a over b
void moveOver(int a, int b) {
    if (positions[a].first == positions[b].first) {
        return;
    }

    remove(positions[a].first, positions[a].second);

    blocks[positions[a].first].pop_back();
    blocks[positions[b].first].push_back(a);

    positions[a] = make_pair(positions[b].first, blocks[positions[b].first].size() - 1);
}

/// Pile a onto b
void pileOnto(int a, int b) {
    if (positions[a].first == positions[b].first) {
        return;
    }

    auto curPos = positions[a];
    remove(positions[b].first, positions[b].second);

    for(int i = curPos.second; i < blocks[curPos.first].size(); ++i) {
        blocks[positions[b].first].push_back(blocks[curPos.first][i]);
        positions[blocks[curPos.first][i]] = make_pair(positions[b].first, blocks[positions[b].first].size() - 1);
    }

    for(int i = blocks[curPos.first].size(); i > curPos.second; --i) {
        blocks[curPos.first].pop_back();
    }
}

/// Pile a over b
void pileOver(int a, int b) {
    if (positions[a].first == positions[b].first) {
        return;
    }

    auto curPos = positions[a];

    for(int i = curPos.second; i < blocks[curPos.first].size(); ++i) {
        blocks[positions[b].first].push_back(blocks[curPos.first][i]);
        positions[blocks[curPos.first][i]] = make_pair(positions[b].first, blocks[positions[b].first].size() - 1);
    }

    for(int i = blocks[curPos.first].size(); i > curPos.second; --i) {
        blocks[curPos.first].pop_back();
    }
}

int main() {
    int n, arg1, arg2;
    string command1, command2;
    cin >> n;
    init(n);
    while (true) {
        cin >> command1;
        if (command1 == "quit") {
            break;
        }

        cin >> arg1 >> command2 >> arg2;
        if(command1 == "move") {
            if(command2 == "onto") {
                moveOnto(arg1, arg2);
            } else {
                moveOver(arg1, arg2);
            }
        } else {
            if(command2 == "onto") {
                pileOnto(arg1, arg2);
            } else {
                pileOver(arg1, arg2);
            }
        }
    }

    print();
    return 0;
}