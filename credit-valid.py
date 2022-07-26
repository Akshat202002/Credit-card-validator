import sys
from cs50 import get_int, get_string


def main():
    number = get_int("Number: ")
    valid_digits(number)
    valid_sum(number)
    company(number)
    sys.exit(0)


def valid_digits(number):
    number = str(number)
    if len(number) != 13 and len(number) != 15 and len(number) != 16:
        print("INVALID")
        sys.exit(1)
    return


def valid_sum(number):
    number = str(number)
    # Reverse the number
    num_list = list(number[::-1])
    # List comprehension
    sum1 = [(int(x) * 2 // 10) + (int(x) * 2 % 10) for x in num_list[1::2]]
    sum2 = [int(x) for x in num_list[0::2]]
    total = sum(sum1) + sum(sum2)
    if total % 10 == 0:
        return
    else:
        print("INVALID")
        sys.exit(1)


def company(number):
    number = str(number)
    first_digit = int(number[0])
    second_digit = int(number[1])

    if first_digit == 3 and second_digit == 4 or second_digit == 7:
        print("AMEX")
    elif first_digit == 5 and 1 <= second_digit <= 5:
        print("MASTERCARD")
    elif first_digit == 4:
        print("VISA")
    else:
        print("INVALID")
        sys.exit(1)


main()
