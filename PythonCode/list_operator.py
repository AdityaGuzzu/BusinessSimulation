def operator(lst,a):
    statement = False
    for i in lst:
        if i <= a:
            statement = True
    return statement
