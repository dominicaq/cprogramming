# C Programming Fall 2018
In fall 2018 I took a C course, while I believe I didn't create anything to write home about it is still my work regaurdless. Best to have it stored rather than having nothing at all.

This repo holds multiple C projects, specifically the ones I believe are worth mentioning.

### The projects in this repo were all developed on cloud9 AWS

## Crack 2 & 3
These projects perform the same function but are different in efficentcy, the main goal is to find the non hashed version of a password in the hash file using a large dictionary of words and hashing them to find matches. (Hashes are MD5)

Crack3 uses structs, qsort, and bsearch

Crack2 uses Bubble sort(n^2) and is far less efficent than crack3

Sample Output:
```
Match 30: xpumpkin, 5c9be7ced4e4667e0a0fbeafbfe24485
Match 31: coolkid, ef5907b3308531f6e45b0663ccdd25b6
Match 32: 840611, 1479de4a63dc4dc8b70e6c6be8a5e5b9
Match 33: crandall1, c43896cb63f63f8f2124bad68ea965a5
...
Passwords cracked: 100
```

## Weather app
This project uses Wunderground, with the recent removal of free API keys I am unsure of when my program will stop working. Until my key is revoked the project should work fine so long as you use libsocket.

Sample Output:
```
Observation Time: Last Updated on December 4, 10:02 AM PST
Location: Lincoln, CA
Temperature: 46.6 F
Humidity: 81%
Wind: ENE 3 mph

Forecast
Tuesday: 57 43
Wednesday: 53 39
Thursday: 57 35
Friday: 56 40
```

## Knight
A personal favorite, however most of the code is teacher code. The function I was required to create was int move_knight(). The goal was to teach us pointers.

Controls:
```
     2   3
   q       e
       K
   a       d
     z   x
 ```
Sample Output:
```
_ _ _ _ _ _ _ G 
_ _ _ _ _ K _ _ 
_ _ _ _ _ _ _ _ 
_ _ _ _ _ _ _ _ 
_ _ _ _ _ _ _ _ 
_ _ _ _ _ _ _ _ 
_ _ _ _ _ _ _ _ 
_ _ _ _ _ _ _ _ 
What's your move? e
_ _ _ _ _ _ _ K 
_ _ _ _ _ _ _ _ 
_ _ _ _ _ _ _ _ 
_ _ _ _ _ _ _ _ 
_ _ _ _ _ _ _ _ 
_ _ _ _ _ _ _ _ 
_ _ _ _ _ _ _ _ 
_ _ _ _ _ _ _ _ 
You won in 7 moves!
```
