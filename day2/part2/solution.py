def get_clean_rounds_data(rounds):
    clean_rounds = []
    for round in rounds:
        color_tuples = round.split(",")

        current_dict = {}
        for color_tuple in color_tuples:
            color_tuple_clean = color_tuple.split()
            current_dict[color_tuple_clean[1]] = int(color_tuple_clean[0])
        clean_rounds.append(current_dict)
    return clean_rounds


COLORS = ["red", "green", "blue"]

file = open("test-input.txt")
lines = file.readlines()

ind = 0
result = 0
for line in lines:
    ind += 1
    if line[-1] == "\n":
        line = line[:-1]

    first_split = line.split(":")

    game_data = first_split[-1]

    rounds = game_data.split(";")
    clean_rounds = get_clean_rounds_data(rounds)

    max_by_color = {}

    for clean_round in clean_rounds:
        for color in COLORS:
            max_by_color[color] = max(
                max_by_color.get(color, 0), clean_round.get(color, 0)
            )

    curr_result = 1
    for color in COLORS:
        if max_by_color.get(color, 0) > 0:
            curr_result *= max_by_color.get(color, 0)
    
    result += curr_result

print(result)
