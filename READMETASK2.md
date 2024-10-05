# Very Large Prime Number Calculation

## Approach
The Very Large Prime Number Calculation project utilizes a linked list to represent a 1024-bit random number, split across multiple nodes. Each node of the linked list contains a 64-bit unsigned integer, allowing the program to manage and perform calculations on large numbers that exceed the capacity of standard data types. 

### Key Features:
- **Linked List Structure**: The linked list stores each 64-bit segment of the 1024-bit number, facilitating easy traversal and manipulation.
- **Random Number Generation**: A random 1024-bit number is generated using the Mersenne Twister algorithm for randomness.
- **Primality Test**: The project includes a simple primality test that checks for divisibility by 2 and odd numbers up to the square root of the largest possible unsigned 64-bit integer. The modulo operation is performed across the linked list nodes to ensure accuracy without losing precision.

## Assumptions
- The random number generated is uniformly distributed over the range of 1024 bits.
- Each node can successfully store a 64-bit integer without overflow.
- The primality test is limited to smaller divisors for simplicity; enhancements could be implemented for more comprehensive testing.


## Challenges Faced
- Managing memory effectively while using a linked list to store a large number without causing leaks.
- Implementing the modulo operation accurately across multiple nodes to ensure the correctness of the primality test.
- Ensuring that the primality test operates efficiently and effectively, particularly given the size of the number and the limits of the standard data types.
- Handling edge cases, such as the number being even or small enough to be evaluated directly.

