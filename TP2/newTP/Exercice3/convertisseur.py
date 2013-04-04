#!/usr/bin/env python3
import sys

def celsius(n) :
    print((n-32) * 5/9)

def fahrenheit(n) :
    print(n*9/5 + 32)

def metre(n) :
    print(n*1.0936)

def yard(n) :
    print(n/1.0936)

def help() :
    print("Referez vous au manuel pour l'utilisation du programme")

def main() :
    if not len(sys.argv) == 4 :
        help()
    else :
        if not (type(int(sys.argv[3])) == int) :
            help()
        else :
            if(sys.argv[2]) == "-t" :
                if(sys.argv[3]) == "-A" :
                    celsius(int(sys.argv[3]))

if(__name__ == "__main__") :
    main()
