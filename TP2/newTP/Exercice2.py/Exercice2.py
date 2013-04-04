#!/usr/bin/env python3
"""Corrigé de l'exercice 2"""
import string

def create_lexic() :
    """Fonction que l'on va utiliser pour générer un fichier lexic"""
    file = open("dico.txt", "w")
    for i in range(11) :
        file.write("mot{}:traduction{}\n".format(i, i))
    file.close()
    
def read_lexic(fileName) :
    """Ouvre le fichier entré en parametre et retourne le dictionnaire correspondant"""
    file = open(fileName, "r")
    dico = dict()
    for line in file :
        for space in string.whitespace :
            line = line.replace(space, "")
        line = line.split(":")
        dico[line[0]] = line[1]
    file.close()
    return dico

def add_word(dico, word1, word2) :
    dico[word1] = word2
    
def translate_word(dico, word) :
    if dico.__contains__(word) :
        return dico[word]
    else :
        return "Le dictionnaire ne contient pas ce mot."

def write_lexic(nameFile, dico) :
    file = open(nameFile, "w")
    for i in sorted(dico) :
        file.write("{}:{}\n".format(i, dico[i]))
    file.close()

def main() :
    """La fonction main"""
    dico = read_lexic("dico.txt")
    word = input("Bienvenue\nQuel est le mot que vous souhaitez traduire ? :\n")
    if dico.__contains__(word) :
        print(translate_word(dico, word))
    else :
        choice = input("Ce mot n'est pas référencé, souhaitez vous l'ajouter ?(y/n)")
        if choice == "y" :
            add_word(dico, word, input("Quelle est sa traduction ?"))
    write_lexic("dico.txt", dico)
    

if(__name__ == "__main__") :
    main()
