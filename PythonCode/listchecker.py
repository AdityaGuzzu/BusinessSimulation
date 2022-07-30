'''''Returns True if the element is present in the list, else returns false'''
def check(lst,a):
    statement = False
    for i in lst:
        if i == a:
            statement = True
    return statement


def check_val(lst,a):
    statement = False
    empt = []
    for i in lst:
        if i == a:
            empt.append(i)
    return empt
def white_double_rent_checker(big_lst, small_lst):
    statement = False
    return_value = []
    for i in small_lst:
        for j in big_lst:
            if j == i:
                return_value.append(1)
    if len(return_value) == 2:
        statement = True
    return statement

