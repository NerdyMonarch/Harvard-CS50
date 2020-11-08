# Questions

## What's `stdint.h`?

It is a header that declares sets of integer types which have specified widths. Widths in this case are the number of bits used to store its value in binary.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

It is to allocate a certain amount of bytes. Each of these datatypes can only hold a certain limit of data. For uint8_t, it is 0 to 255 because it can only hold 1 byte of data. If we use uint_32, the limit is 0 to 4294967295 because it can hold 4 bytes of data. Finally, if we use int_32, the limit is –2147483648 to 2147483647 because it is a signed integer vs uint_8 and uint_32 which were unsigned integers. The only difference is one can hold negatives and the other cannot.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

A Byte is a unsigned 1 byte integer, a DWord is a unsigned 4 byte integer, a Long is a signed 4 byte integer, and a Word is a unsigned 2 byte integer.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes of a BMP file identifies the BMP file format. 

## What's the difference between `bfSize` and `biSize`?

The difference between the bfSize and the biSize is that the biSize is number of bytes needed by the BITMAPINFOHEADER while the bfsize is the size of the whole file. This includes the bytes needed for both the header files and the image file.

## What does it mean if `biHeight` is negative?

If the biHeight is negative, the top row of the image is equivalant to the first row in memory. The memory starts creating the image from the top left.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount specifies the BMP's color depth.

## Why might `fopen` return `NULL` in `copy.c`?

Fopen might return NULL in copy.c because the infile provided might not exist. It might also return NULL if there isn't enough space to create the outfile.

## Why is the third argument to `fread` always `1` in our code?

Fread is always one in our code because sizeof(BITMAPINFOHEADER) times 1 lets us read all of the data. We don't need a bigger number because the sizeof(BITMAPINFOHEADER) already implicitly tells the computer to read all the information in that header.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

Padding recieves a value of 0.

## What does `fseek` do?

Fseek lets the programmer change the location of the file pointer.

## What is `SEEK_CUR`?

Seek_Cur changes the location of the pointer from it's current location.