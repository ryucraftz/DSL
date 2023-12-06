def get_intersection(list1, list2):
    result = []
    for item in list1:
        if item in list2:
            result.append(item)
    return result

def get_symmetric_difference(list1, list2):
    result = []
    for item in list1:
        if item not in list2:
            result.append(item)
    for item in list2:
        if item not in list1:
            result.append(item)
    return result

def main():
    group_a = ["A1", "A2", "A3", "A4", "A5"]
    group_b = ["B1", "B2", "B3", "B4", "B5"]
    group_c = ["C1", "C2", "C3", "C4", "C5"]
    cricket_players = ["A1", "A2", "A3", "A4"]
    badminton_players = ["B1", "B2", "B3", "B4", "B5"]

    both_sports_players = get_intersection(cricket_players, badminton_players)
    print("a) List of students who play both cricket and badminton:", both_sports_players)

    either_sport_not_both = get_symmetric_difference(cricket_players, badminton_players)
    print("b) List of students who play either cricket or badminton but not both:", either_sport_not_both)

    neither_sport_players = get_symmetric_difference(get_symmetric_difference(group_a, group_b), group_c)
    print("c) Number of students who play neither cricket nor badminton:", len(neither_sport_players))

    football_players = ["C1", "C2", "C3", "C4", "C5"]
    cricket_football_not_badminton = get_symmetric_difference(
        cricket_players, get_intersection(badminton_players, football_players)
    )
    print(
        "d) Number of students who play cricket and football but not badminton:",
        len(cricket_football_not_badminton),
    )

if __name__ == "__main__":
    main()
