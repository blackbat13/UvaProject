def combine_genes(gene1: str, gene2: str) -> str:
    if (gene1 == "non-existent" and gene2 != "dominant") or (
        gene1 != "dominant" and gene2 == "non-existent"
    ):
        return "non-existent"

    if (gene1 == "dominant" and gene2 != "non-existent") or (
        gene1 != "non-existent" and gene2 == "dominant"
    ):
        return "dominant"

    return "recessive"


def compute_gene(name: str, genes: dict, parents: dict):
    if name in genes:
        return

    compute_gene(parents[name][0], genes, parents)
    compute_gene(parents[name][1], genes, parents)
    genes[name] = combine_genes(genes[parents[name][0]], genes[parents[name][1]])


genes = dict()
parents = dict()
n = int(input())

for _ in range(n):
    name, value = input().split()

    if value in ["dominant", "recessive", "non-existent"]:
        genes[name] = value
    else:
        if value not in parents:
            parents[value] = [name, ""]
        else:
            parents[value][1] = name

for el in parents:
    compute_gene(el, genes, parents)

for el in sorted(genes):
    print(el, genes[el])
