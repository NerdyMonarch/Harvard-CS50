# Enables User Input
from cs50 import get_string

def main:
    # Obtains string and uses it with hello
    name = get_string("What is your name?: ")
    print(f"hello, {name}")


# Runs the program
if __name__ == '__main__':
    main()