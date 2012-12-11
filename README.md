This is Erik Krupa and Michael Yahner Parallel Processing Term Project

This project is focused on turning two sorting algorthims into parallel sorting algorthims and testing them via timing against their CPU counterparts.

The algorithms being iterave merge sort and bubble sort.

You use this program on windows by running it in the command line. It can accept up to three arguments. Sending just -h or -help will explain to you, should you forget, what to do. Instead you could send up to three .txt files which will fill the files desnigated array for sorting. The .txt file must be in this format: #the type of data you are importing; space then the array size; then on the next line you start entering the data you want with spaces inbetween the values. If you do not specify any arguments then it will randomanly fill an integer, floating point, and char array for testing the sorts.

You will see three folders. One being Sorting which is our implementation of merge and bubble on the CPU and GPU. You will see another folder called File Generation which will generate files for our sorting implementation in powers of 2. The last folder you will see a folder called Thrust. This folder has our implementation of thrust sorting on the CPU and GPU using char, double, and a complex object that has key pair(s) sorting. 

*Note: Must have a 2.0 or higher CUDA Capable card and a minimum version of cuda 4.0 toolkit
**Note: commandline arguments for compiling Thrust Sorting.cu on visual studio command line is nvcc -arch=sm_(value no less than 20) name.cu -o name [optional: -I C:/your location to cuda's include]
***Note: For our implementation of the sorts, the values loaded in must be a power of two.