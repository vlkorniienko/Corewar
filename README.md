# Corewar

#### In this project, you need to create a virtual “arena” in which programs will fight against one another (the “Champions”).You need also to create an assembler to compile those Champions as well as a Champion to show the world that you can create life from coffee.

#### About
> Core War is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called  > > "warriors") compete for control of a virtual computer. These battle programs are written in an abstract assembly language > > called Redcode.

#### The project is divied in 3 parts :
* Assembler
* Virtual Machine
* Champion

### In this project my part of job was assembler(the goal is to make binary files for corewar virtual machine from list of assembler commands).

##### Example of list commands
![](https://github.com/vlkorniienko/Corewar/blob/master/Command%20list.png)

##### Example output
![](https://github.com/vlkorniienko/Corewar/blob/master/Binary%20file.png)

### Usage
```
git clone https://github.com/vlkorniienko/Corewar
cd Corewar
make
./asm V3M.s(to make file with .cor extension)
./corewar -v V3M.cor vm_champs/champs/Gagnant.cor
```

#### Game example
![](https://github.com/vlkorniienko/Corewar/blob/master/Game%20example.png)
