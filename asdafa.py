def add(a, b):
    return a + b
def sub(a, b):
    return a - b
def multi(a, b):
    return a * b
def div(a, b):
    if a == 0:
        print("not")
        return 0
    return a / b

def cal(a, b):
    print(add(a, b))
    print(sub(a, b))
    print(multi(a, b))
    print(div(a, b))

a = int(input("1 : "))
b = int(input("2 : "))

cal(a, b)
