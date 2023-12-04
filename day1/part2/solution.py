INT_MAX = 1000000

file = open("test-input.txt")

lines = file.readlines()

digit_strings = [
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
]

rev_digit_strings = [
    digit_str[::-1] for digit_str in digit_strings
]

digit_string_map = {
    digit_str: ind + 1 for (ind, digit_str) in enumerate(digit_strings)
}

rev_digit_string_map = {
    rev_str: digit_string_map[rev_str[::-1]] for rev_str in rev_digit_strings
}

result = 0
for line in lines:
    num_1='0'
    position_1 = INT_MAX
    num_2='0'
    position_2 = INT_MAX
    if line[-1] == '\n':
        line = line[:-1]
    for (ind, char) in enumerate(line):
        if char.isdigit():
            num_1 = char
            position_1 = ind
            break
    
    for digit_str in digit_strings:
        ind = line.find(digit_str)

        if ind != -1:
            if ind < position_1:
                position_1 = ind
                num_1 = digit_string_map[digit_str]
    
    for (ind, char) in enumerate(line[::-1]):
        if char.isdigit():
            num_2 = char
            position_2 = ind
            break
    
    for digit_str in rev_digit_strings:
        ind = line[::-1].find(digit_str)

        if ind != -1:
            if ind < position_2:
                position_2 = ind
                num_2 = rev_digit_string_map[digit_str]
        
    num = int(num_1) * 10 + int(num_2)
    result += num

print(result)