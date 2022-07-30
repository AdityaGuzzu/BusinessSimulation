def winner_decider(random_list):
    z = len(random_list)
    if z > 0:
        counter_lst = []
        y = max(random_list)
        while len(random_list) > 0 and y == max(random_list):
            m = max(random_list)
            k = random_list.index(m)
            x = len(random_list)
            n = k + (z - x) + 1
            counter_lst.append(n)
            random_list.remove(y)
        return counter_lst
some = [7,7]
if len(winner_decider(some)) > 2:
    print("It's a draw")