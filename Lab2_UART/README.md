<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Lab 3 Notes

Keep a digital log of your work using the readme file where appropriate.

# Pseudo Code for Pre-Lab

- You can use a simple algorithm that iterates through all the numbers up to 300, and checks if they can be exactly divided by numbers smaller than it using the modulo operator
- Here is an example algorithm you could use
> - Create an array that could store 62 numbers (note the variable type should allow storing integers up to 300)
> - Create a variable *i* to hold the position in the array where you will store next prime number and initialize this to 0
> - Create a variable *N* to hold the number we are going to check and see if it is a prime number (note the variable type should allow storing integers up to 300)
> - Create a counter variable *j* to iterate through numbers up to the number we want to check if it is a prime number (note the variable type should allow storing integers up to 300)
> - Create a variable *isPrime* that can be used as a flag to indicate its a prime number
> - In a 1st *for loop* increment *N* from 2 to 300 and within this loop
>   - Set the flag *isPrime*
>   - In a 2nd *for loop* increment *j* from 2 to N-1 and within this loop
>   - If *N % j* is 0 then *N* is not a prime number so clear *isPrime* and *break* the *for loop*
>   - If *isPrime* is set at the end of 2nd *for loop* then store *N* in the *i* position of the array and increment *i*
> - Continue with the 1st *for loop* until N reach 300 
