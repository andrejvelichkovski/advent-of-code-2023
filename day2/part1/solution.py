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


file = open("test-input.txt")
lines = file.readlines()

ind = 0
result = 0
for line in lines:
    ind += 1
    if line[-1] == '\n':
        line = line[:-1]
    
    first_split = line.split(":")
    
    game_data = first_split[-1]

    rounds = game_data.split(";")
    clean_rounds = get_clean_rounds_data(rounds)

    possible_game = True
    for clean_round in clean_rounds:
        if clean_round.get("red", 0) > 12:
            possible_game = False
        if clean_round.get("green", 0) > 13:
            possible_game = False
        if clean_round.get("blue", 0) > 14:
            possible_game = False
    
    if possible_game:
        result += ind

print(result)