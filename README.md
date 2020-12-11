# An Improved Algorithm for Lossless Data Compression

In statistical compression algorithms, it is required first to find the probabilities (i.e., frequencies, f) for all characters used in the data file. For text files, characters include all letters, digits, and punctuations. These characters are to be ordered in the sequence (s) from highest frequencies to the lowest. The second step is to find the equivalent binary code for each character according to the statistical data compression technique that has been used, e.g., Huffman coding, where the most common characters in the file have the shortest binary codes, and the least common have the longest. Then these binary codes are used to convert all characters in the data file to a binary code. Typically, in all statistical algorithms, a character word length of 8 bits is used, where the equivalent decimal value for each 8 bits (0–255) is calculated and converted to a character that is written to the output file.
For an 8- bits character word length, there exist 0 to 255 possible decimal values, i.e., 256 possibilities. In most cases, not all the 256 possible decimal values are used. Therefore, in this new approach, we try to use more than 8 bits to store a single character, say, for example, b bits, which give 2b possibilities (from 0 to 2b − 1 possible decimal values). This is not an issue; what is important is the number of the different decimal values (possibilities) that have been calculated, and if they are less than 256 possibilities, it is possible to use a character word length of b bits to store the character rather than 8 bits. It is important to find an optimum value for b which produces decimal values that are less than or equal to 256 possibilities.
In this new algorithm, a coder will go through the data file, convert each character into its appropriate binary code, and write the resulting bits to the output file after optimizing the compressed character word length. In order not to get the codes mixed up in the decoding process, all information is stored in the compressed file header.

## Output

Import your desired data to be compressed in "TextFile.txt", after running the program for compression, you will find the compressed file in "compressed.txt", and after running the program for decompression, you will find the decompressed file in "Original.txt".

## How to Run

## Linux terminal

open the terminal

cd Optimal-Data-Compression //change the working directory

## for compression:
gcc -o a huff.c -lm

./a

## for decompression:
gcc -o b unhuff.c -lm

./b

## Windows command prompt(cmd)

press Windows + R and type in cmd, and hit return

cd Optimal-Data-Compression //change the working directory

## for compression:
gcc -o a huff.c

.\a

## for decompression:
gcc -o b unhuff.c

.\b
