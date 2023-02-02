# C Programming Fall 2018

## Crack 2 & 3
These projects perform the same function but are different in runtime. They will fill a dictonary with hashed password and then compare the non hashed passwords in the `rockyou` files to find matches. (Hashes are MD5)

Crack2: $O(n^2)$ - Bubble sort

Crack3: $O(logn)$ - Qsort and Bsearch

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
This is not a complete preprocessor. This program will include any valid include paths given to it. If the specified file can't be found or the include doesn't follow the required format the include line will be left alone.

### prep.c

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

### mpp2.c

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

## Knight
Uses pointers to update a text based chess board, simulates the moves a knight can make.

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
