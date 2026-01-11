d = int(input()) # donuts when shop opens
e = int(input()) # events

for i in range (e):
    operation = input() # +/-
    value = int(input())
    if operation == '+':
        d = d + value
    else:
        d = d - value
    
print(d)