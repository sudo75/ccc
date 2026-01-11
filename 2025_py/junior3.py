n = int(input())

arr = []

all_codes = []
for i in range (n):
    code = input()
    
    length = len(code)
    
    new_code = ''
    
    num_arr= []
    num = 0
    
    last_wasNeg = False
    last_wasNum = False
    preNum = 0
    for j in range (length):
        char = code[j]
        
        if str.isupper(char):
            new_code += char
        
        if char.isdigit():
            if last_wasNeg == True:
                preNum = -1 * int(char)
                #num -= int(char)
            else:
                if last_wasNum == True:
                    preNum = preNum * 10
                    if preNum > 0:
                        preNum = preNum + int(char)
                    else:
                        preNum = preNum - int(char)
                else:
                    preNum = int(char)
                
            last_wasNum = True
        else:
            last_wasNum = False
            num = num + preNum
            preNum = 0
        
        last_wasNeg = False
        if (char == '-'):
            last_wasNeg = True
        
        
    num = num + preNum
    all_codes.append(new_code + str(num))
    
    

for i in range (n):
    print(all_codes[i])