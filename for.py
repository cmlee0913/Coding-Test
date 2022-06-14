text = input("python을 입력해주세요!")

for i in range(len(text)):
    for x in range(i+1):
        print(text[x],end = '')

    print()