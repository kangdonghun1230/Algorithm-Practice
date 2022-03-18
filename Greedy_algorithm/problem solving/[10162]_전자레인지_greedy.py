a = 300
b = 60
c = 10

def main(num):
    a_coin = 0
    b_coin = 0
    c_coin = 0
    if num / a != 0:
        a_coin = int(num / a)
        num %= a
    if num / b != 0:
        b_coin = int(num / b)
        num %= b
    if num / c != 0:
        c_coin = int(num / c)
        num %= c

    if num != 0:
        print(-1)
    else :
        print(a_coin, b_coin, c_coin)
num = int(input())
main(num)