from cs50 import get_int

def main():
    hight = get_hight()
    for j in range(hight):

        for k in range(hight-j-1):
            print(" ", end="")

        for l in range(j+1):
            print("#", end="")

        print()

def get_hight():
    i = 0
    while 1 > i or i > 8:
        i = get_int("hight: ")
    else:
        return i
main()
