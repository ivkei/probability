# Probability
This repository is intended to prove a simple math probability problem.  
Probably, everyone heard about a problem of winning, a.k.a. the Monty Hall dilemma, by switching doors on a TV show.
But it seems wrong at first, so I decided to write a simple C code to prove it.  

## Problem
You are given 3 doors, 1 with a car and 2 with goats.  
You randomly choose a door, then the host, who knows where the car is, opens one of the other doors with a goat.  
And now you are given a choice to switch to the other unopened door or stick to your original choice.  
Which strategy is better?  
Intuition says to stick, but math says otherwise.  

## Proper Solution
Initially, the probability of choosing the correct door is 1/3, and incorrect is 2/3.  
But after you are revealed a door with a goat, the chances inverse and become 2/3.  
The following table will explain best.  
| Behind door #1 | Behind door #2 | Behind door #3 | Result if staying at door #1 | Result if switching to door offered |
|---|---|---|---|---|
| Goat | Goat | Car | Wins goat | Wins car |
| Goat | Car | Goat | Wins goat | Wins car |
| Car | Goat | Goat | Wins car | Wins goat |

Also if this table doesnt tell you enough, you can consider the following:  
- You are offered a 1,000,000 doors, behind one of them is a car and the rest are goats.  
- You choose a door randomly.  
- The host opens 999,998 doors with goats.  
- Now you are offered to switch to the remaining door or stick to your original choice.  
- Obvious answer is to switch, no way you guessed right with a chance of 1/1,000,000.  

And even if 2 pieces of evidence from above dont convince you, just consider this:  
- Initially, chances are of you choosing a car is 1/3, and in the rest 2/3, they are - well - 2/3.  
- After host reveals a goat in that 2/3 of a right guess section, the section stays 2/3, but now with only 1 door.  

## Build It Yourself
* Via gcc:
```sh
gcc main.c -o prob
./prob
```
* Via clang:
```sh
clang main.c -o prob
./prob
```
* Via Visual Studio:
1. Open this file.  
2. Somehow execute it via some green button.  

## Credits
* [Wikipedia - Monty Hall problem](https://en.wikipedia.org/wiki/Monty_Hall_problem)
