# matrix-crypt
Linear Algebra Project - ORT University Uruguay

### What this is
What this program does is encrypting and decrypting strings by means of an algo that consists on the following premises:
  * Takes a message as a string and turns it into a vector as long as 40 numbers.
  * Multiplies that vector with a matrix that needs to be square and invertible.
  * Returns the encrypted message as a vector of doubles.
  * Calculates the inverse matrix by means of cofactors.
  * Decrypts the message by multiplying it with the inverse of the encryption matrix.
  * Returns the decrypted message as a string.

### Features
* Includes a namespace called matrix that provides all the matrix operations necessary
* The matrix namespace also provides a gen() function that creates a test matrix to encrypt messages
* Includes a namespace called crypt that has the necessary operations to transform vectors and strings into each other and also encrypt and decrypt messages

### Sample Output
Since it takes so long to generate a complete output, here is the output I got after running it with exactly the same data that is hard coded here...

```
Encryption matrix generated!
Message set as: Hello World
Beginning encryption...
Encryption completed in: 0 milliseconds
Message encrypted as the following vector:
8 -8 5 -5 3 -1 3 -1 6 -4 9 -5 5 -1 6 -4 9 -7 3 -1 4 -4 10 -6 10 -6 10 -6 10 -6 10 -6 10 -6 10 -6 10 -6 10 -6 
Beginning decryption...
Decryption completed in: 21 minutes
Message decrypted as the following string: HELLO WORLD
Mission accomplished
```

### Coding Standard & License
* Code follows (or attempted to follow, didnt really enforce that) the Google C++ Style Guide which can be found here: https://google.github.io/styleguide/cppguide.html
* All the code is licensed with the MIT license.

> Note
>It takes 22 minutes to calculate the inverse of a very simple matrix like the one the program generates, use with caution...
