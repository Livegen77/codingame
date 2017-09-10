import sys
import math
import string

deckp_1 = [];
deckp_2 = [];
stack_ingamecardplayer1 = []
stack_ingamecardplayer2 = []
stack_card_index = 0;

player_win = "";

nb_turn = 1

def givecards(receiverstack, cardstogivestack):
    for i in range(len(cardstogivestack)):
        receiverstack.append(cardstogivestack.pop(0))
        
    return

def cardversus(cardplayer1, cardplayer2):
    winner = 0
    
    if(cardplayer1 > cardplayer2):
        winner = 1
    elif(cardplayer1 < cardplayer2): 
        winner = 2
    
    return winner

def getcardvalue(value):
    
    factor = 0
    
    if(value == "2"):
        factor = 2
    elif(value == "3"):
        factor = 3
    elif(value == "4"):
        factor = 4
    elif(value == "5"):
        factor = 5
    elif(value == "6"):
        factor = 6
    elif(value == "7"):
        factor = 7
    elif(value == "8"):
        factor = 8
    elif(value == "9"):
        factor = 9
    elif(value == "10"):
        factor = 10
    elif(value == "J"):
        factor = 11
    elif(value == "Q"):
        factor = 12
    elif(value == "K"):
        factor = 13
    elif(value == "A"):
        factor = 14
          
        
    return factor

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

nbcardplayer1 = int(input())  # the number of cards for player 1
for i in range(nbcardplayer1):
    cardp_1 = input()  # the n cards of player 1
    deckp_1.append(cardp_1[:-1])
    
nbcardplayer2 = int(input())
for i in range(nbcardplayer2):
    cardp_2 = input()  # the m cards of player 2
    deckp_2.append(cardp_2[:-1])

try:
    while((len(deckp_1) > 0) & (len(deckp_2) > 0)):
        #print("debug : deck 1 length " + str(len(deckp_1)), file=sys.stderr)
        #print("debug : deck 2 length " + str(len(deckp_2)), file=sys.stderr)
        
        #for i in range(len(deckp_1)):
        #    print("debug : DECK 1 " + str(deckp_1[i]), file=sys.stderr)
            
        #for i in range(len(deckp_2)):
        #    print("debug : DECK 2 " + str(deckp_2[i]), file=sys.stderr)
            
        # get the player cards    
        stack_ingamecardplayer1.append(deckp_1.pop(0))
        stack_ingamecardplayer2.append(deckp_2.pop(0))
        
        # convert the card value to the power value
        valuecard_player1 = getcardvalue(stack_ingamecardplayer1[stack_card_index])
        valuecard_player2 = getcardvalue(stack_ingamecardplayer2[stack_card_index])
        
        print("debug : début du tour " + str(nb_turn), file=sys.stderr)
        print("debug : player 1 card " + str(stack_ingamecardplayer1[stack_card_index]) + "(" + str(valuecard_player1) + ")", file=sys.stderr)
        print("debug : VS", file=sys.stderr) 
        print("debug : player 2 card " + str(stack_ingamecardplayer2[stack_card_index]) + "(" + str(valuecard_player2) + ")", file=sys.stderr)
        
        # check who has the best card
        if(cardversus(valuecard_player1, valuecard_player2) == 1):
            givecards(deckp_1, stack_ingamecardplayer1)
            givecards(deckp_1, stack_ingamecardplayer2)
            stack_card_index = 0
            print("debug : player 1 win the turn " + str(nb_turn), file=sys.stderr)
        elif(cardversus(valuecard_player1, valuecard_player2) == 2):
            givecards(deckp_2, stack_ingamecardplayer1)
            givecards(deckp_2, stack_ingamecardplayer2)
            stack_card_index = 0
            print("debug : player 2 win the turn " + str(nb_turn), file=sys.stderr)
        else:
            print("debug : bataille ", file=sys.stderr)
            
            #if equal add 3 card the the stack of each player
            for i in range(3):
                stack_ingamecardplayer1.append(deckp_1.pop(0))
                stack_ingamecardplayer2.append(deckp_2.pop(0))
                
            #increase the index of the card to be read
            stack_card_index += 4
        
        print(" ", file=sys.stderr)  
          
        # increment the turn count if the game is not over
        # or if there is a battle
        if((len(deckp_1) > 0) & (len(deckp_2) > 0) & (stack_card_index == 0)):
            nb_turn += 1
        
    print("debug : game is over", file=sys.stderr)
    
    if(len(deckp_1) == 0):
        player_win = "2"
        
    if(len(deckp_2) == 0):
        player_win = "1"
    
    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr)
    
    print(player_win + " " + str(nb_turn))
except IndexError:
    # If we catch an exception IndexError during the game, 
    # this mean a player has no cards anymore during a battle
    # 
    print("PAT")
