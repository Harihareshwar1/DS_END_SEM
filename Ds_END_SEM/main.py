def evaluate(expression:str):
    stack = []
    for i in expression:
        if i.isnumeric():
            stack.append(int(i))
        else:
            val1 = stack.pop()
            val2 = stack.pop()
            stack.append(eval(f"{val1}{i}{val2}"))
    return stack.pop()


print(evaluate('253+5*-'))