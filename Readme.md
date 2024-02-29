# Introduction

Bunch of utilities that I will create to revise C. 

## tcal

This prints the current month like a calender layout. The current date will get highlighted in green.

```bash
Su Mo Tu We Th Fr Sa
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 
```
---
## ttime

This just print the current time

`Tue Feb 27 19:44:12 2024`


# CI/CD

We utilitize cmake and make to create executable. The builds have only been tested in windows for now. 

## Building tcal

```bash
cd tcal
mkdir build && cd build
cmake .. -G"Unix Makefiles"
make
```

This should create a tcal executable. 

## Building ttime

Process is same as tcal. Just use the ttime folder rather than tcal.

**Note**: I am currently trying to integrate github actions as well.
