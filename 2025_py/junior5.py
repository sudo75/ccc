r = int(input())
c = int(input())

m = int(input())

interval_min = c-1
interval_max = c+1

def createGrid():
    grid = []
    for i in range (0, r*c):
        grid.append(i % m + 1)
        
    return grid

grid = createGrid()

cost_min = None
for i in range (c):
    cost = grid[i]
    for j in range (i + interval_min, i + interval_max):
        if j < len(grid) and j >= c: 
            cost += grid[j]
    
            if cost_min == None:
                cost_min = cost
            elif cost < cost_min:
                cost_min = cost
        
print(cost_min)