#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define WIDTH_MAX  10000u
#define HEIGTH_MAX 10000u
#define JUMP_MAX   100u

int str2int(std::string str) {

    // Still need to add error checking 

    int i = 0;
    std::string::const_iterator it = str.begin();
    while (it != str.end()) {
        i *= 10;
        i += *it++ - '0';
    }

    return i;
}    

enum Direction
{
    DEFAULT = 0,
    UP,
    UP_RIGHT,
    RIGHT,
    DOWN_RIGHT,
    DOWN,
    DOWN_LEFT,
    LEFT,
    UP_LEFT,
    LIMIT_DIRECTION
};

class Coordinate
{
    public:
    Coordinate()
    {
        x = 0;
        y = 0;
    }
    
    int getX()
    {
        return x;
    }   
    
    int getY()
    {
        return y;
    }
    
    void setX(int x)
    {
        this->x = x;
    }
    
    void setY(int y)
    {
        this->y = y;
    }
    
    void setCoordinate(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    
    void printCoordinate()
    {
        cout << x << " " << y ;
    }
    
    void printCoordinateDebug()
    {
        cerr << "(" << x << "," << y << ")" ;
    }
    
    private:
        int x;
        int y;
};

class Building
{
    public: 
    
    void setBuildingSize(int W, int H)
    {
        width = W - 1;
        heigh = H - 1;
    }
    
    void setBatmanPosition(int X, int Y)
    {
        BatmanPosition.setX(X);
        BatmanPosition.setY(Y);
    }
    
    void Set_bombDirection(string& stringBombDirection)
    {
        if(stringBombDirection.compare("U") == 0)
            bombDirection = UP;
        else if(stringBombDirection.compare("UR") == 0)
            bombDirection = UP_RIGHT;
        else if(stringBombDirection.compare("R") == 0)
            bombDirection = RIGHT;
        else if(stringBombDirection.compare("DR") == 0)
            bombDirection = DOWN_RIGHT;
        else if(stringBombDirection.compare("D") == 0)
            bombDirection = DOWN;
        else if(stringBombDirection.compare("DL") == 0)
            bombDirection = DOWN_LEFT;
        else if(stringBombDirection.compare("L") == 0)
            bombDirection = LEFT;
        else if(stringBombDirection.compare("UL") == 0)
            bombDirection = UP_LEFT;
        else
            cout << "Error content stringBombDirection : " << stringBombDirection.size() << endl;
            
        cerr << "Direction of the bomb is : " << stringBombDirection << endl;    
    }
    
    void CalcBombAr()
    {
        switch(bombDirection)
        {
            case UP:
                {
                    JumpCoordinate.setX(BatmanPosition.getX());
                    if(((BombUpperRight.getY()+BatmanPosition.getY())/2)==BatmanPosition.getY())
                        JumpCoordinate.setY(BatmanPosition.getY()-1);
                    else
                        JumpCoordinate.setY(((BombUpperRight.getY()+BatmanPosition.getY())/2));
                }
                    break;
            case DOWN:
                {
                    JumpCoordinate.setX(BatmanPosition.getX());
                    if(((BombDownRight.getY()+BatmanPosition.getY())/2)==BatmanPosition.getY())
                    {
                        JumpCoordinate.setY(BatmanPosition.getY()+1);
                    }
                    else
                    {
                        JumpCoordinate.setY((BombDownRight.getY()+BatmanPosition.getY())/2);
                    }
                }
                break;
            case LEFT:
                {
                    if(BatmanPosition.getX() == 1)
                    {
                        JumpCoordinate.setX(0);
                    }
                    else
                    {
                        JumpCoordinate.setX(BatmanPosition.getX()/2);
                    }
                    JumpCoordinate.setY(BatmanPosition.getY());
                }
                break;
            case RIGHT:
                {
                    if(((BatmanPosition.getX()+width)/2)==BatmanPosition.getX())
                    {
                        JumpCoordinate.setX(BatmanPosition.getX()+1);
                    }
                    else
                    {
                        JumpCoordinate.setX(((BatmanPosition.getX()+(width))/2));
                    }
                    JumpCoordinate.setY(BatmanPosition.getY());
                }
                break;
            case UP_RIGHT:
              {
                    if(((BombUpperRight.getX()+BatmanPosition.getX())/2)==BatmanPosition.getX())
                    {
                        JumpCoordinate.setX(BatmanPosition.getX()+1);
                    }
                    else
                    {
                        JumpCoordinate.setX(((BatmanPosition.getX()+BombUpperRight.getX())/2));
                    }
                    
                    if(((BatmanPosition.getY()+BombUpperRight.getY())/2)==BatmanPosition.getY())
                    {
                        JumpCoordinate.setY(BatmanPosition.getY()-1);
                    }
                    else
                    {
                        JumpCoordinate.setY((BatmanPosition.getY()+BombUpperRight.getY())/2);
                    }                    
                }
                break;
            case DOWN_RIGHT:
                {
                    if(((BombDownRight.getX()+BatmanPosition.getX())/2)==BatmanPosition.getX())
                    {
                        JumpCoordinate.setX(BatmanPosition.getX()+1);
                    }
                    else
                    {
                        JumpCoordinate.setX(((BatmanPosition.getX()+BombDownRight.getX())/2));
                    }
                    
                    if(((BombDownRight.getY()+BatmanPosition.getY())/2)==BatmanPosition.getY())
                    {
                        JumpCoordinate.setY(BatmanPosition.getY()+1);
                    }
                    else
                    {
                        JumpCoordinate.setY(((BatmanPosition.getY()+BombDownRight.getY())/2));
                    }                    
                }
                break;
            case DOWN_LEFT:
                {
                    if(((BombDownLeft.getX()+BatmanPosition.getX())/2)==BatmanPosition.getX())
                    {
                        JumpCoordinate.setX(BatmanPosition.getX()-1);
                    }
                    else
                    {
                        JumpCoordinate.setX(((BatmanPosition.getX()+BombDownLeft.getX())/2));
                    }
                    
                    if(((BombDownLeft.getY()+BatmanPosition.getY())/2)==BatmanPosition.getY())
                    {
                        JumpCoordinate.setY(BatmanPosition.getY()+1);
                    }
                    else
                    {
                        JumpCoordinate.setY(((BatmanPosition.getY()+BombDownLeft.getY())/2));
                    }                    
                }
                break;
            case UP_LEFT:
                    if(((BombUpperLeft.getX()+BatmanPosition.getX())/2)==BatmanPosition.getX())
                    {
                        JumpCoordinate.setX(BatmanPosition.getX()-1);
                    }
                    else
                    {
                        JumpCoordinate.setX(((BatmanPosition.getX()+BombUpperLeft.getX())/2));
                    }
                    
                    if(((BombUpperLeft.getY()+BatmanPosition.getY())/2)==BatmanPosition.getY())
                    {
                        JumpCoordinate.setY(BatmanPosition.getY()-1);
                    }
                    else
                    {
                        JumpCoordinate.setY(((BatmanPosition.getY()+BombUpperLeft.getY())/2));
                    }   
                break;
        }
    }
    
    void SetArea()
    {
        if(previousBombDirection == DEFAULT)
        {
            SetDefaultArea();
        }
        else if(previousBombDirection == bombDirection)
        {
           SetAreaSameDirection();
        }
        else
        {
            SetAreaDifferentDirection();
        }
    }
    
    void printBombArea()
    {
        cerr << "(" << BombUpperLeft.getX() << "," << BombUpperLeft.getY() << ")" <<  "   " << "(" << BombUpperRight.getX() << "," << BombUpperRight.getY() << ")" << endl;
        cerr << endl;
        cerr << "(" << BombDownLeft.getX() << "," << BombDownLeft.getY() << ")" <<  "   " << "(" << BombDownRight.getX() << "," << BombDownRight.getY() << ")" << endl;
    }
    
    void printBatmanCoordinate()
    {
        cerr << "Batman Coordinate : ";
        BatmanPosition.printCoordinateDebug();
        cerr << endl;
    }
    
    void printBatmanJump()
    {
        JumpCoordinate.printCoordinate();
    }
    
    void updateBatmanPosition()
    {
        BatmanPosition = JumpCoordinate;
    }
    
    int nextJumpX()
    {
        return JumpCoordinate.getX();
    }
    
    int nextJumpY()
    {
        return JumpCoordinate.getY();
    }
    
    void saveCurrentInformation()
    {
        previousBombDirection  = bombDirection;
        PreviousBatmanPosition = BatmanPosition;
    }
    
    private:
    void SetDefaultArea()
    {
        
        switch(bombDirection)
        {
            case UP:
                BombUpperLeft.setCoordinate(BatmanPosition.getX(),0);
                BombUpperRight.setCoordinate(BatmanPosition.getX(),0);
                BombDownLeft.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                BombDownRight.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                break;
            case DOWN:
                BombUpperLeft.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                BombUpperRight.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                BombDownLeft.setCoordinate(BatmanPosition.getX(),heigh);
                BombDownRight.setCoordinate(BatmanPosition.getX(),heigh);
                break;
            case LEFT:
                BombUpperLeft.setCoordinate(0,BatmanPosition.getY());
                BombUpperRight.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                BombDownLeft.setCoordinate(0,BatmanPosition.getY());
                BombDownRight.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                break;
            case RIGHT:
                BombUpperLeft.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                BombUpperRight.setCoordinate(width,BatmanPosition.getY());
                BombDownLeft.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                BombDownRight.setCoordinate(width,BatmanPosition.getY());
                break;
            case UP_RIGHT:
                BombUpperLeft.setCoordinate(BatmanPosition.getX(), 0);
                BombUpperRight.setCoordinate(width, 0);
                BombDownLeft.setCoordinate(BatmanPosition.getX(), BatmanPosition.getY());
                BombDownRight.setCoordinate(width, BatmanPosition.getY());
                break;
            case DOWN_RIGHT:
                BombUpperLeft.setCoordinate(BatmanPosition.getX(), BatmanPosition.getY());
                BombUpperRight.setCoordinate(width,BatmanPosition.getY());
                BombDownLeft.setCoordinate(BatmanPosition.getX(),heigh);
                BombDownRight.setCoordinate(width,heigh);
                break;
            case DOWN_LEFT:
                BombUpperLeft.setCoordinate(0,BatmanPosition.getY());
                BombUpperRight.setCoordinate(BatmanPosition.getX(), BatmanPosition.getY());
                BombDownLeft.setCoordinate(0,heigh);
                BombDownRight.setCoordinate(BatmanPosition.getX(),heigh);
                break;
            case UP_LEFT:
                BombUpperLeft.setCoordinate(0,0);
                BombUpperRight.setCoordinate(BatmanPosition.getX(),0);
                BombDownLeft.setCoordinate(0,BatmanPosition.getY());
                BombDownRight.setCoordinate(BatmanPosition.getX(), BatmanPosition.getY());
                break;
                
            
        }
        
        cerr << "Initialisation bomb area done " << endl;
    }
    
    void SetAreaSameDirection()
    {
         switch(bombDirection)
            {
                case UP:
                        BombUpperLeft.setX(BatmanPosition.getX());
                        BombUpperRight.setX(BatmanPosition.getX());
                        BombDownLeft.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                        BombDownRight.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                        break;
                    case DOWN:
                        BombUpperLeft.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                        BombUpperRight.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                        BombDownLeft.setX(BatmanPosition.getX());
                        BombDownRight.setX(BatmanPosition.getX());
                        break;
                    case LEFT:
                        BombUpperLeft.setY(BatmanPosition.getY());
                        BombUpperRight.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                        BombDownLeft.setY(BatmanPosition.getY());
                        BombDownRight.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                        break;
                    case RIGHT:
                        BombUpperLeft.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                        BombUpperRight.setY(BatmanPosition.getY());
                        BombDownLeft.setCoordinate(BatmanPosition.getX(),BatmanPosition.getY());
                        BombDownRight.setY(BatmanPosition.getY());
                        break;
                    case UP_RIGHT:
                        BombUpperLeft.setX(BatmanPosition.getX());
                        BombDownLeft.setCoordinate(BatmanPosition.getX(), BatmanPosition.getY());
                        BombDownRight.setY(BatmanPosition.getY());
                        break;
                    case DOWN_RIGHT:
                        BombUpperLeft.setCoordinate(BatmanPosition.getX(), BatmanPosition.getY());
                        BombUpperRight.setY(BatmanPosition.getY());
                        BombDownLeft.setX(BatmanPosition.getX());
                        break;
                    case DOWN_LEFT:
                        BombUpperLeft.setY(BatmanPosition.getY());
                        BombUpperRight.setCoordinate(BatmanPosition.getX(), BatmanPosition.getY());
                        BombDownRight.setX(BatmanPosition.getX());
                        break;
                    case UP_LEFT:
                        BombUpperRight.setX(BatmanPosition.getX());
                        BombDownLeft.setY(BatmanPosition.getY());
                        BombDownRight.setCoordinate(BatmanPosition.getX(), BatmanPosition.getY());
                        break;       
            }
            
            cerr << "Bomb as the same direction than before" << endl;
    }
    
    void SetAreaDifferentDirection()
    {
         switch(bombDirection)
            {
                    case UP:
                        BombDownLeft.setY(BatmanPosition.getY());
                        BombDownRight.setY(BatmanPosition.getY());
                        break;
                    case DOWN:
                        BombUpperLeft.setY(BatmanPosition.getY());
                        BombUpperRight.setY(BatmanPosition.getY());
                        break;
                    case LEFT:
                         break;
                    case RIGHT:
                        
                        break;
                    case UP_RIGHT:
                        BombUpperLeft.setX(BatmanPosition.getX());
                        BombDownLeft.setCoordinate(BatmanPosition.getX(), BatmanPosition.getY());
                        BombDownRight.setY(BatmanPosition.getY());
                        break;
                    case DOWN_RIGHT:
                        BombUpperLeft.setCoordinate(BatmanPosition.getX(), BatmanPosition.getY());
                        BombUpperRight.setY(BatmanPosition.getY());
                        BombDownLeft.setX(BatmanPosition.getX());
                        break;
                    case DOWN_LEFT:
                        BombUpperLeft.setY(BatmanPosition.getY());
                        BombUpperRight.setCoordinate(BatmanPosition.getX(), BatmanPosition.getY());
                        BombDownRight.setX(BatmanPosition.getX());
                        break;
                    case UP_LEFT:
                        BombUpperRight.setX(BatmanPosition.getX());
                        BombDownLeft.setY(BatmanPosition.getY());
                        BombDownRight.setCoordinate(BatmanPosition.getX(), BatmanPosition.getY());

                        break;       
            }
            
            cerr << "Bomb as a different direction than before" << endl;
    }
    
    int width;//X
    int heigh;//Y
    Coordinate BombUpperLeft;
    Coordinate BombUpperRight;
    Coordinate BombDownLeft;
    Coordinate BombDownRight;
    Coordinate BatmanPosition;
    Coordinate PreviousBatmanPosition;
    Coordinate JumpCoordinate;

    Direction bombDirection;
    Direction previousBombDirection;
};
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    Building myBuilding;
    
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    cerr << "width : " << W << " " << "heigth : " << H << endl;
    cerr << "Jump limit : " << N << endl;
    myBuilding.setBuildingSize(W, H);
    
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    cerr << "Start position : " << X0 << " " << Y0 << endl;
    myBuilding.setBatmanPosition(X0, Y0);
    

    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();
        //cerr << "Bomb direction " << bombDir << endl;
        myBuilding.printBatmanCoordinate();
        myBuilding.Set_bombDirection(bombDir);
        myBuilding.SetArea();
        myBuilding.printBombArea();
        myBuilding.CalcBombAr();
        myBuilding.updateBatmanPosition();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // the location of the next window Batman should jump to.
        cout << myBuilding.nextJumpX() << " " << myBuilding.nextJumpY() << endl;
    
        myBuilding.updateBatmanPosition();
        myBuilding.saveCurrentInformation();
    }
}
