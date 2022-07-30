import random
def block_counter(n1):
    counter = 0
    z = 0
    while counter < n1:
        counter += 1
        y = random.randint(2,12)
        z += y
        print(f"Throw number {counter} is {y}")
        print(f"You are on block {z}")
        x = z//36
        if z < 36:
            print(0)
        else:
            print(x)
k1 = int(input("How many throws do you want to simulate? "))
block_counter(10)