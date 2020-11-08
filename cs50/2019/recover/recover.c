#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check for start of Jpeg
bool startOfJpeg(unsigned char tempBuffer[512]);

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }
    
    // open input file
    FILE *lostFile = fopen(argv[1], "r");
    
    // ensures file is opened properly
    if (lostFile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }
    
    unsigned char buffer[512];
    
    // locates first jpeg
    do
    {
        // bytes from lostFile get stored into buffer as an unsigned char
        fread(&buffer, 1, 512, lostFile);
    }
    while (startOfJpeg(buffer) == false);
    
    // buffer for printing images
    char *printingBuffer;
    
    // counts number of images that have been found
    int imageCounter = 0;
    
    // counts number of blocks that are part of the Jpeg
    int blocksCounter = 1;
    
    // EOF Checker
    bool EOFlocator = false;
    
    // Number of bytes in EOF
    int EOFbytes = 0;
    
    // finds EOF
    while (EOFlocator == false)
    {
        
        // locates the whole Jpeg
        do
        {
            EOFbytes = fread(&buffer, 1, 512, lostFile);
            
            // checks for EOF
            if (EOFbytes != 512)
            {
                EOFlocator = true;
            }
            else
            {
                EOFbytes = 0;
                blocksCounter++;
            }
            
        }
        while (startOfJpeg(buffer) == false && EOFlocator == false);
        
        // goes back to the start of the Jpeg
        fseek(lostFile, ((-512 * blocksCounter) + EOFbytes), SEEK_CUR);
        
        // mallocs enough space to hold Jpeg data
        printingBuffer = malloc(((512 * (blocksCounter - 1)) + EOFbytes) * sizeof(char));
        
        strcpy(printingBuffer, "Initialized");
        
        // sets up the buffer as a Jpeg
        sprintf(printingBuffer, "%03i.jpg", imageCounter);
        
        // opens file for writing
        FILE *writingBuffer = fopen(printingBuffer, "w");
        
        // ensures file is opened properly
        if (writingBuffer == NULL)
        {
            fprintf(stderr, "Could not open %s.\n", "Writing Buffer");
            return 2;
        }
        
        // writes complete Jpeg out
        for (int i = 0; i < (blocksCounter - 1); i++)
        {
            // rereads the Jpeg
            fread(&buffer, 1, 512, lostFile);
            
            // writes the Jpeg now
            fwrite(&buffer, 1, 512, writingBuffer);
        }
        
        if (EOFlocator == true)
        {
            // reads EOF block
            fread(&buffer, 1, EOFbytes, lostFile);
            
            // writes EOF block
            fwrite(&buffer, 1, EOFbytes, writingBuffer);
        }
        
        // free memory to prevent memory leaks
        free(printingBuffer);
        
        // prevent segmentation fault
        if (EOFlocator == false) 
        {
            // reads into to check next block
            fread(&buffer, 1, 512, lostFile);
            
            // resets counter for reuse
            blocksCounter = 1;
            
            // update image counter
            imageCounter++;
        }
    }
}

// defining startOfJpeg
bool startOfJpeg(unsigned char tempBuffer[512])
{
    // condition that checks header
    if (tempBuffer[0] == 0xff &&
        tempBuffer[1] == 0xd8 &&
        tempBuffer[2] == 0xff &&
        (tempBuffer[3] & 0xf0) == 0xe0)
    {
        // returns true if start of Jpeg is found
        return true;
    }
    else
    {
        return false;
    }
}