import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# w: number of columns.
# h: number of rows.
x, y = [int(i) for i in input().split()]

print("Debug : dimension is " + str(x) + " x " + str(y), file=sys.stderr)

game_map_type = [[0 for x in range(x)] for y in range(y)]

for row in range(y):
    line = input()  # represents a line in the grid and contains W integers. Each integer represents one room of a given type
    char_index = 0
    for cell in range(x): 
        game_map_type[row][cell] =  line[char_index]
        if (len(line)-1) != char_index:
            if line[char_index+1] != " ":
                game_map_type[row][cell] = (game_map_type[row][cell]) + line[char_index+1]
                char_index += 1
        char_index += 2
        print("Debug : room type[" + str(row) + "][" + str(cell) +"]  = " + game_map_type[row][cell], file=sys.stderr)
ex = int(input())  # the coordinate along the X axis of the exit (not useful for this first mission, but must be read).

def getnextroom(currentx, currenty, roomtype, origin):
    
    roomtype = int(roomtype)
    
    nextx = currentx
    nexty = currenty
    
    if((roomtype == 1) or (roomtype == 3) or (roomtype == 7) or (roomtype == 8) or (roomtype == 9) or (roomtype == 12) or (roomtype == 13)):
        nexty += 1
    elif (roomtype == 2) and (origin == "RIGHT"):
        nextx -= 1
    elif (roomtype == 2) and (origin == "LEFT"):
        nextx += 1
    elif (roomtype == 4) and (origin == "TOP"):
        nextx -= 1
    elif (roomtype == 4) and (origin == "RIGHT"):
        nexty += 1
    elif (roomtype == 5) and (origin == "TOP"):
        nextx += 1
    elif (roomtype == 5) and (origin == "LEFT"):
        nexty += 1
    elif (roomtype == 6) and (origin == "TOP"):
        nextx += 1
    elif (roomtype == 6) and (origin == "LEFT"):
        nextx += 1
    elif (roomtype == 6) and (origin == "RIGHT"):
        nextx -= 1
    elif (roomtype == 10):
        nextx -= 1
    elif (roomtype == 11):
        nextx += 1
    else:
        print("debug : room type not found (" + roomtype + ")", file=sys.stderr)
    
    print("debug : " + str(nexty) + " " + str(nextx), file=sys.stderr)
    
    return {'x': nextx, 'y':nexty}

# game loop
while True:
    xi, yi, pos = input().split()
    xi = int(xi)
    yi = int(yi)
    
    print("Debug : current room type[" + str(yi) + "][" + str(xi) +"]  = " + game_map_type[yi][xi] + " from " + pos , file=sys.stderr)

    dictnextpos = getnextroom(xi, yi, game_map_type[yi][xi], pos)
    
    print("Debug : next room position is [" + str(dictnextpos['x']) + "][" + str(dictnextpos['y']) + "]" , file=sys.stderr)

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr)


    # One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
    print(str(dictnextpos['x']) + " " +  str(dictnextpos['y']))
