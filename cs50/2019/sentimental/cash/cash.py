from cs50 import get_float


def main():
    # Ask user for changed owed
    change = get_float("Change Owed: ")
    # Reprompts user for positive number
    while change < 0:
        change = get_float("Change Owed: ")
    # Calculates number of pennies needed
    change *= 100
    # Turns float into an integer
    change = int(change)
    # Calculates number of coins needed
    coins = (change // 25) + ((change % 25) // 10) + (((change % 25) % 10) // 5) + (((change % 25) % 10) % 5)
    # Prints result
    print(coins)


# Runs the program
if __name__ == '__main__':
    main()