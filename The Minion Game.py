# Auther: Hao Mei

import math

def minion_game(string):
    subStringList = []
    stuartList = []
    kevinList = []
    for i in range(len(string)):
        for j in range(i+1,len(string)+1):
            subStringList.append(string[i:j])
    for subString in subStringList:
        if subString[0] in ['A','E','I','O','U']:
            kevinList.append(subString)
        else:
            stuartList.append(subString)
    if len(stuartList) > len(kevinList):
        print 'Stuart', len(stuartList)
    elif len(stuartList) < len(kevinList):
        print 'Kevin', len(kevinList)
    else:
        print 'Draw'

if __name__ == '__main__':
    s = raw_input()
    minion_game(s)