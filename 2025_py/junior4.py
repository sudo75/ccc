n = int(input())

weather = []
for i in range (n):
    day = input() # 'S' or 'P'
    weather.append(day)
    
length = len(weather)

maxSun = 0
alteredIndex = 0
for i in range (length):
    m_weather = weather
        
    if i > 0:
        if m_weather[alteredIndex] == 'P':
            m_weather[alteredIndex] = 'S'
        else:
            m_weather[alteredIndex] = 'P'
    
    
    if (m_weather[i] == 'S'):

        alteredIndex = i
        if m_weather[i] == 'P':
            m_weather[i] = 'S'
        else:
            m_weather[i] = 'P'
        
        lastDayWasSun = False
        daysWithSun = 0
        for j in range (length):
            if m_weather[j] == 'S':
                lastDayWasSun = True
                daysWithSun += 1
            else:
                lastDayWasSun = False
                daysWithSun = 0
                
                
            if daysWithSun > maxSun:
                maxSun = daysWithSun
print(maxSun)