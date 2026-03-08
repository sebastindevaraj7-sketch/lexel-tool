from left_recursion import read_grammar

def left_factoring(grammar):
    new_grammar = {}

    for non_terminal in grammar:
        productions = grammar[non_terminal]
        prefix_dict = {}

        for prod in productions:
            prefix = prod.split()[0]
            if prefix not in prefix_dict:
                prefix_dict[prefix] = []
            prefix_dict[prefix].append(prod)

        if any(len(v) > 1 for v in prefix_dict.values()):
            new_nt = non_terminal + "'"
            new_grammar[non_terminal] = []
            new_grammar[new_nt] = []

            for prefix in prefix_dict:
                if len(prefix_dict[prefix]) > 1:
                    new_grammar[non_terminal].append(prefix + " " + new_nt)
                    for prod in prefix_dict[prefix]:
                        remainder = prod[len(prefix):].strip()
                        new_grammar[new_nt].append(remainder if remainder else "#")
                else:
                    new_grammar[non_terminal].append(prefix_dict[prefix][0])
        else:
            new_grammar[non_terminal] = productions

    return new_grammar


if __name__ == "__main__":
    grammar = read_grammar("grammar_input.txt")
    factored = left_factoring(grammar)

    # Save output to a file
    with open("factored_grammar.txt", "w") as f:
        f.write("Grammar after Left Factoring:\n\n")
        for nt in factored:
            f.write(f"{nt} -> {' | '.join(factored[nt])}\n")

    print("Left factoring complete! Output saved to 'factored_grammar.txt'.")