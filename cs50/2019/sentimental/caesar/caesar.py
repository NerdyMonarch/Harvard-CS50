from cs50 import get_string, get_int
from sys import argv, exit


def main():
    # Checks for correct number of argc
    if not len(argv) == 2:
        exit("python caesar.py [key]")
    # Key becomes an integer from 0 to 26
    key = (int(argv[1])) % 26
    # Prompts user for printText
    text = get_string("printtext: ")
    # Turns printText into a list of chars
    text = list(text)
    # Creates an empty list
    encryption = list()
    for i in range(len(text)):
        # Ascii value is put into encryption
        encryption.append(ord(text[i]))
        # For lowercase values
        if encryption[i] >= 97 and encryption[i] <= 122:
            # Turns into alphanumeral value
            encryption[i] -= 97
            # Encrypts value
            encryption[i] = (encryption[i] + key) % 26
            # Turns into ascii value
            encryption[i] += 97
        # For uppercase values
        elif encryption[i] >= 65 and encryption[i] <= 90:
            # Turns into alphanumeral value
            encryption[i] -= 65
            # Encrypts value
            encryption[i] = (encryption[i] + key) % 26
            # Turns into ascii value
            encryption[i] += 65
        # Turns ascii value into letters
        text[i] = chr(encryption[i])
    # Prints encrypted letter
    print(f"ciphertext: {''.join(text)}")


# Runs the program
if __name__ == '__main__':
    main()