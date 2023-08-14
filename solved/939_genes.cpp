#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

string combineGenes(string gene1, string gene2);

void computeGene(string name, map<string, string> &genes, map<string, pair<string, string>> &parents);

int main()
{
    int n;
    string name, value;
    map<string, string> genes;
    map<string, pair<string, string>> parents;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        cin >> name >> value;
        if (value == "dominant" || value == "recessive" || value == "non-existent")
        {
            genes[name] = value;
        }
        else
        {
            if (parents[value].first == "")
            {
                parents[value].first = name;
            }
            else
            {
                parents[value].second = name;
            }
        }
    }

    for (auto &el : parents)
    {
        computeGene(el.first, genes, parents);
    }

    for (auto &el : genes)
    {
        printf("%s %s\n", el.first.c_str(), el.second.c_str());
    }

    return 0;
}

string combineGenes(string gene1, string gene2)
{
    if ((gene1 == "non-existent" && gene2 != "dominant") || (gene1 != "dominant" && gene2 == "non-existent"))
    {
        return "non-existent";
    }

    if ((gene1 == "dominant" && gene2 != "non-existent") || (gene1 != "non-existent" && gene2 == "dominant"))
    {
        return "dominant";
    }

    return "recessive";
}

void computeGene(string name, map<string, string> &genes, map<string, pair<string, string>> &parents)
{
    if (genes[name] != "")
    {
        return;
    }

    computeGene(parents[name].first, genes, parents);
    computeGene(parents[name].second, genes, parents);
    genes[name] = combineGenes(genes[parents[name].first], genes[parents[name].second]);
}
