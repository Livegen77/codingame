import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

values = []
index = 0
maximum_buy_price = 0
maximum_loss = 0

n = int(input())
for i in input().split():
    new_price = int(i)
    values.append(new_price)
    
    #set the new maximum price (reference to be compared 
    if new_price > maximum_buy_price:
        maximum_buy_price = new_price
        print("Debug : new maximum_buy_price =  " + str(maximum_buy_price), file=sys.stderr)
    else:
        #Compare the maxmimum bought price with the new price
        loss = new_price - maximum_buy_price 
        print("Debug : compare " + str(new_price) + " with " + str(maximum_buy_price), file=sys.stderr)
        if maximum_loss > loss:
            maximum_loss = loss
    
    index += 1
    

#for indexvalue in range(len(values)):
#    for subindex in range(indexvalue, len(values)):
#        if(((subindex+1) <  len(values))):
#            if (values[subindex+1] < values[indexvalue]):
#                loss = values[subindex+1] - values[indexvalue]
#                print("Debug : compare " + str(values[indexvalue]) + "(" +  str(indexvalue) + ") with " + str(values[subindex+1]) + "(" + str(subindex+1) + ") = " + str(loss), file=sys.stderr)
#                if maximum_loss > loss:
#                    maximum_loss = loss
            

# Write an action using print
# To debug: print("Debug messages...", file=sys.stderr)

print(str(maximum_loss))
