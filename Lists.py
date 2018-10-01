# Auther Hao Mei

if __name__ == '__main__':
    N = int(raw_input())
    simpleList = []
    for i in range(N):
        code = raw_input()
        parameters = code.split(' ')
        if parameters[0] == 'insert':
            simpleList.insert(int(parameters[1]), int(parameters[2]))
        if parameters[0] == 'print':
            print(simpleList)
        if parameters[0] == 'remove':
            simpleList.remove(int(parameters[1]))
        if parameters[0] == 'append':
            simpleList.append(int(parameters[1]))
        if parameters[0] == 'sort':
            simpleList.sort()
        if parameters[0] == 'pop':
            simpleList.pop()
        if parameters[0] == 'reverse':
            simpleList.reverse()