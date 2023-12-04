file = open("input.txt")

lines = file.readlines()

result = 0
for line in lines:
    char_1 = 0
    char_2 = 0
    for char in line:
        if char.isdigit():
            char_1 = char
            break

    for char in line[::-1]:
        if char.isdigit():
            char_2 = char
            break

    num = int(char_1) * 10 + int(char_2)
    result += num

print(result)