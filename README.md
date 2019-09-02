
# Simple Address Book

## Why This

To practice C++ and basic data structure, this simple address book based on hash table was built years later.

It helps to save contacts and search records rapidly.

## Structure

basic structure

```bash
# windows
SimpleAddressBook-Windows/
├── HashTable.cpp   --  build hashtable
├── HashTable.h
├── Interface.cpp   --  make interface
├── Interface.h
├── MailList.cpp    --  main functions
├── MailList.h
├── SimpleAddressBook.cbp       --  codeblocks project conf
├── SimpleAddressBook.depend
├── SimpleAddressBook.layout
├── bin
│   └── Debug
│       └── SimpleAddressBook.exe   --  output executable file on windows
├── main.cpp
└── obj
    └── Debug
        ├── HashTable.o
        ├── Interface.o
        ├── MailList.o
        └── main.o

4 directories, 15 files

# Linux
SimpleAddressBook-Linux/
├── HashTable.cpp   --  build hashtable
├── HashTable.h
├── Interface.cpp   --  make interface
├── Interface.h
├── MailList.cpp    --  main functions
├── MailList.h
├── bin
│   └── SimpleAddressBook   --  output executable file on linux
├── main.cpp
└── obj
    ├── HashTable.o
    ├── Interface.o
    ├── MailList.o
    └── main.o

2 directories, 12 files

```

## Usage

- git source

```bash
git clone https://github.com/TyeYeah/SimpleAddressBook.git
```

- build it in codeblocks.
 or in bash(what I built before may not function well on your machine):

```bash
cd SimpleAddressBook

# Windows
cd SimpleAddressBook-Windows
mingw32-g++.exe -Wall -fexceptions -g  -c HashTable.cpp -o obj/Debug/HashTable.o
mingw32-g++.exe -Wall -fexceptions -g  -c Interface.cpp -o obj/Debug/Interface.o
mingw32-g++.exe -Wall -fexceptions -g  -c MailList.cpp -o obj/Debug/MailList.o
mingw32-g++.exe -Wall -fexceptions -g  -c main.cpp -o obj/Debug/main.o
mingw32-g++.exe  -o bin/Debug/SimpleAddressBook.exe obj/Debug/HashTable.o obj/Debug/Interface.o obj/Debug/MailList.o obj/Debug/main.o

# Linux
cd SimpleAddressBook-Linux
g++ -Wall -fexceptions -g  -c ./HashTable.cpp -o ./obj/HashTable.o
g++ -Wall -fexceptions -g  -c ./Interface.cpp -o ./obj/Interface.o
g++ -Wall -fexceptions -g  -c ./MailList.cpp -o ./obj/MailList.o
g++ -Wall -fexceptions -g  -c ./main.cpp -o ./obj/main.o
g++  -o ./bin/SimpleAddressBook ./obj/HashTable.o ./obj/Interface.o ./obj/MailList.o ./obj/main.o

```

- run executable file in windows cmd or linux bash.
the started interface is like

```bash

         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                 Simple         Address         Book

         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         ~~ 1-------Show All                               ~~
         ~~ 2-------Add                                    ~~
         ~~ 3-------Build HashTable                        ~~
         ~~ 4-------Fuzzy Query                            ~~
         ~~ 5-------Query By Name                          ~~
         ~~ 6-------Query By Phone                         ~~
         ~~ 7-------Delete Record                          ~~
         ~~ 0-------Exit                                   ~~
         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
```

## Feature

It helps you to: add contact records, show records, query and delete records

A record contains Name, Age, Phone Number, Sex and Class

and

1. After added, build hash table first and then do query
2. Before doing query by name, set name as hash table's key
3. Before doing query by phone number, set phone number as hash table's key
4. Follow every rules you see when using
