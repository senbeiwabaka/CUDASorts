This is Erik Krupa and Michael Yahner Parallel Processing Term Project

This project is focused on turning four sorting algorthims into parallel sorting algorthims and testing them via timing against their CPU counterparts. 

You use this program on windows by running it in the command line. It can accept one argument. The argument can be -h or -help to explain to you should you forget what to do or it can be a .txt file which will file an array for the sorting. The .txt file must be in this format: #the type of data you are importing; then on the next line you start entering the data you want with spaces inbetween the values. If you do not specify an arguments then it will randomanly fill an integer and floating point array for testing the sorts.

*Note: Must have a 2.0 or higher CUDA Capable card and a minimum version of cuda 4.o toolkit
**Note: commandline arguments for compiling Thrust Sorting.cu on visual studio command line is nvcc name.cu -o name -I C:/your location to cuda's include