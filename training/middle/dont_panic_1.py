import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
nbtour = 2;
previous_clone_pos = -1
poped_clone = 0


# nb_floors: number of floors
# width: width of the area
# nb_rounds: maximum number of rounds
# exit_floor: floor on which the exit is found
# exit_pos: position of the exit on its floor
# nb_total_clones: number of generated clones
# nb_additional_elevators: ignore (always zero)
# nb_elevators: number of elevators
nb_floors, width, nb_rounds, exit_floor, exit_pos, nb_total_clones, nb_additional_elevators, nb_elevators = [int(i) for i in input().split()]

elevators = [i for i in range(nb_elevators)]
elevators.append(0);

for i in range(nb_elevators):
    # elevator_floor: floor on which this elevator is found
    # elevator_pos: position of the elevator on its floor
    elevator_floor, elevator_pos = [int(j) for j in input().split()]
    elevators[elevator_floor] = elevator_pos


for i in range(len(elevators)):
    print("Debug : etage " + str(i) + " = position = " +  str(elevators[i]), file=sys.stderr)

# game loop
while True:
    # clone_floor: floor of the leading clone
    # clone_pos: position of the leading clone on its floor
    # direction: direction of the leading clone: LEFT or RIGHT
    clone_floor, clone_pos, direction = input().split()
    clone_floor = int(clone_floor)
    clone_pos = int(clone_pos)
    
    print("Debug : tour = " +  str(nbtour), file=sys.stderr)
    
    if (nbtour % 3) == 1:
        poped_clone += 1;
        print("Debug : pop clone" , file=sys.stderr)
        print("Debug : poped_clone = " + str(poped_clone) , file=sys.stderr)
       
    
    #print("Debug : nb_floors = " + str(nb_floors), file=sys.stderr)
    print("Debug : width = " + str(width), file=sys.stderr)
    #print("Debug : nb_rounds = " + str(nb_rounds), file=sys.stderr)
    #print("Debug : nb_total_clones = " + str(nb_total_clones), file=sys.stderr)
    #print("Debug : nb_additional_elevators = " + str(nb_total_clones), file=sys.stderr)
    #print("Debug : nb_elevators = " + str(nb_total_clones), file=sys.stderr)
    print("Debug : clone_floor = " + str(clone_floor), file=sys.stderr)
    if exit_floor != clone_floor:
        print("Debug : position elevator on this floor = " + str(elevators[clone_floor]), file=sys.stderr)
        
        if ((direction == "RIGHT") & (clone_pos > elevators[clone_floor])):
            print("BLOCK")
        elif ((direction == "LEFT") & (clone_pos < elevators[clone_floor])):
            print("BLOCK")
        else:
            print("WAIT")
    else:
        print("Debug : exit_pos = " + str(exit_pos), file=sys.stderr)
        
        if ((direction == "RIGHT") & (clone_pos > exit_pos)):
            print("BLOCK")
        elif ((direction == "LEFT") & (clone_pos < exit_pos)):
            print("BLOCK")
        else:
            print("WAIT")    
            
        
    print("Debug : clone_pos = " + str(clone_pos), file=sys.stderr)
    print("Debug : direction = " + direction, file=sys.stderr)
    
    #if (clone_floor == -1) & (clone_pos == -1) & (direction == "NONE"):
      #  print("Debug : no head clone" , file=sys.stderr)

    #if clone_pos == 0 | clone_pos < -1 :
        #print("Debug : clone_pos detroy" , file=sys.stderr)
        
    #if (previous_clone_pos < clone_pos) & previous_clone_pos != -1:
        #print("Debug : a clone died " , file=sys.stderr)

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr)




    
    nbtour += 1
