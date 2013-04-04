#!/usr/bin/env python3

def diviseur(n) :
    return [i for i in range(1, n+1) if n%i==0]

def sans_e(chaine) :
    liste = chaine.split(" ")
    liste = [mot for mot in liste if not mot.__contains__('e')]
    return liste

def anti_begue(chaine) :
    liste = chaine.split(" ")
    liste = [mot for indice, mot in enumerate(liste) if (int(indice) == 0 or (int(indice)> 0 and liste[int(indice)-1] != liste[int(indice)]))]
    return liste

def main() :
    l = [i for i in range(0, 11)]
    print("Liste :\n{}".format(l))

    #Q1
    print([i for i in l if i%2==0])

    #Q2
    l = [i for i in range(1, 11)]
    print([y for x, y in enumerate(l) if x%2==0])

    #Q3
    print("Les diviseur de 5 : {}".format(diviseur(15)))

    #Q4
    chaine = "Il etait une fois un mec qui s'appelait Gauthier"
    print(sans_e(chaine))

    #Q5
    chaine = "Il etait etait une fois fois un mec qui qui etait Gauthier Gogo"
    print(anti_begue(chaine))

if(__name__ == "__main__") :
    main()
