def calc(circuit):
    equS, equP, count = 0.0, 0.0, 0
    for i in range(1, len(circuit)):
        if circuit[i+1] == 'e': break
        elif circuit[i].isspace():
            j = i + 1
            temp = ""
            while circuit[j].isdigit() or circuit[j] == '.':
                temp += circuit[j]
                j += 1
            if temp == "": continue    
            equS += float(temp)
            equP += 1/float(temp)
            count += 1
        elif not circuit[i].isdigit() and circuit[i] != '.':
            print("Invalid circuit")
            exit()
    if circuit[0] == 'S' and count > 0:
        return equS  
    elif circuit[0] == 'P' and count > 1:      
        return 1/equP
    else:
        print("Invalid circuit")
        exit()
    
circuit = input("Enter the circuit: ")
for i in range(circuit.count('e')):
    e, P, S = circuit.find('e') + 1, circuit.rfind('P'), circuit.rfind('S')
    index = S if S > P else P
    circuit = circuit[:index] + str(calc(circuit[index:e])) + circuit[e:]
print(circuit)