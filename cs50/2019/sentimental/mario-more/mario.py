from cs50 import get_int


def main():
    # Asks for height between 1 and 8
    scale = get_int("Height: ")
    while True:
        if scale > 8 or scale < 1:
            scale = get_int("Height: ")
        break

    # For loop for each line
    for i in range(scale):
        # Calculates left spaces
        space = i - scale + 1
        # Writes the left spaces
        for j in range(-1 * space):
            print(" ", end="")
        # Prints the left hashes
        for k in range(i + 1):
            print("#", end="")
        # Prints the space in the pyramid
        print("  ", end="")
        # Prints the right hashes
        for l in range(i + 1):
            print("#", end="")
        # Prints a new line
        print("")


# Runs the program
if __name__ == '__main__':
    main()