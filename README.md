# String Class Recreation

This is a recreation of the string class using C++ pointers and operator overloads

Hosted here: https://repl.it/repls/MicroCrazyRedundantcode

## Project Goals

- [x] Recreate a working replica of the string class in C++
- [x] Use dynamic memory to allow for growing and shrinking of the string memory
- [x] Use operator overloads to allow for string concatenation and copying naturally

## Project Struggles

- Memory leaks and out of memory errors
  - These were an issue throughout the projects
  - Most were solved by simplifying the pointer manipulation I was performing
- Iterating C Strings correctly
  - Figuring out a fast way to iterate a null-terminated character array became a big challenge, I didn't want to iterate the array every time I wanted to get the string length
  - Solved by adding a 'length' variable to my string class and updated it whenever the string changed
  - This allowed for instant retrieval of the string length and avoided overhead caused by constant iteration
- Growing and Shrinking String
  - When attempting to grow or shrink the reserved memory for my string, I ran into a lot of pointer errors
  - These were solved by the simplification of my pointer usage by using a buffer char array to store the string, then destroy the memory and reallocate

## Output
I test my string class with a small snippet of code that inserts and concatenates words from a file into a JDString object, then pushes that object to a vector once it has concatenated five words into one string
 
## Conclusion

This project was a great opportunity for me to understand dynamic memory and memory management to a far greater extent then I have ever had before. By completing this project, I gained a working understanding of how to structure object-oriented code and how to work with memory correctly and efficiently