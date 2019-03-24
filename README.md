# C Programming Fall 2018
In fall 2018 I took a C course, while I believe I didn't create anything to write home about it is still my work regardless. Best to have it stored rather than having nothing at all.

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
## Mini Preprocessor
Please note this is *not* a complete preprocessor. However it functions similary to one. This program will include any includes in a file so long as it can find it. If it can't be found or the include doesn't follow the required format the line will be left alone.

It can handle includes within includes, for a simple version use prep.c, for a more advanced version use mpp2.c.

prep.c

Input:
```
#include header.txt
Greetings, Earthlings!  // Note: change greeting for another planet
We have come to this planet to learn about your food. Please
send 1.2 million pounds of pizza, Frappuccinos, and chocolate
doughnuts with those adorable sprinkles on top
to our interplanetary address.
// Only 7.4 light years away
#include address.txt

Sincerely,
The Aliens
```

Output:
```
To: Inhabitants of Earth
From: Vogon Armada, Orion Division
Greetings, Earthlings! 
We have come to this planet to learn about your food. Please
send 1.2 million pounds of pizza, Frappuccinos, and chocolate
doughnuts with those adorable sprinkles on top
to our interplanetary address.

Digestable Comestible Investigations
Vogon Science and Research
Mailstop M42
Orion Cluster

Sincerely,
The Aliens
```

mpp2.c

Input:
```
#include header.txt
Greetings, Earthlings!  // Note: change greeting for another planet
We have come to this planet to learn about your food. Please
send 1.2 million pounds of pizza, Frappuccinos, and chocolate
doughnuts with those adorable sprinkles on top
to our interplanetary address.
// Only 7.4 light years away
#include address.txt

 #include header.txt
#include her.txt
#include 
"//Comment in quotes"

"This is a /* test */"

/* this is a small test */
/*
this is a

big

test */

Sincerely,
The Aliens
```

Output:
```
To: Inhabitants of Earth
From: Vogon Armada, Orion Division
Greetings, Earthlings! 
We have come to this planet to learn about your food. Please
send 1.2 million pounds of pizza, Frappuccinos, and chocolate
doughnuts with those adorable sprinkles on top
to our interplanetary address.

Digestable Comestible Investigations
Vogon Science and Research
Mailstop M42
Orion Cluster

Hello World

The above phrase should say "Hello World"

 #include header.txt
#include her.txt
#include 
"//Comment in quotes"

"This is a /* test */"

Sincerely,
The Aliens
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
