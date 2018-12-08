# C Programming Fall 2018
In fall 2018 I took a C course, while I believe I didn't create anything to write home about it is still my work regaurdless. Best to have it stored rather than having nothing at all.

This repo holds multiple C projects, specifically the ones I believe are worth mentioning.

### The projects in this repo were all developed on cloud9 AWS

### Crack 2 & 3
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
