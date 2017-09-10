#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define NBNODEMAX 30
#define WIDTH_MAX 30
#define HEIGHT_MAX 30



class NODE
{
    public:
        NODE()
        {
            x = -1;
            y = -1;
        }
    
        void init()
        {
            x = -1;
            y = -1;
        }
        
        int getX()
        {
            return x;
        }
        
        void setX(int x)
        {
            this->x = x; 
        }
        
        void setY(int y)
        {
            this->y = y;
        }
            
        int getY()
        {
            return y;
        }
        
        bool isNode()
        {
            if((x != -1) && (y != -1))
                return true;
            else
                return false;
        }
        
        void printCoordinate()
        {
            cout << x << " " << y;
        } 
        
        void printCoordinateDbg()
        {
            cerr << x << " " << y;
        }
        
    private:
        int x;
        int y;
};

class TRAY
{
    public:
        void setNode(int x, int y)
        {
            ListNode[x][y].setX(x);
            ListNode[x][y].setY(y);
        }
        
        bool isCellaNode(int x, int y)
        {
            return ListNode[x][y].isNode();
        }
        
        void printNode(int x, int y)
        {
            bool xNodeFound = false;
            bool yNodeFound = false;
            int index_x = x;
            int index_y = y;
            ListNode[x][y].printCoordinate();
            cout << " ";
            cerr << "Starting node research for " << x << " " << y << endl;
            //Print Next x node
            do
            {
                if(ListNode[index_x+1][y].isNode())
                {
                    ListNode[index_x+1][y].printCoordinate();
                    xNodeFound = true;
                    cerr << "X : Node found at " << (index_x +1) << " " << y << endl;
                    ListNode[index_x+1][y].printCoordinateDbg();
                    cerr << endl;
                }
                index_x++;
            }
            while((xNodeFound == false) && (index_x+1 < WIDTH_MAX));
            
            if(xNodeFound == false)
            {
                cerr << "X no node found" << endl;
                printEmptyCell();
            }
                
            cout << " ";
            
            //Print Next y node
            do
            {
                if(ListNode[x][index_y+1].isNode())
                {
                    ListNode[x][index_y+1].printCoordinate();
                    yNodeFound = true;
                    cerr << "Y : Node found at " << (x) << " " << (index_y+1) << endl;
                    ListNode[x][index_y+1].printCoordinateDbg();
                    cerr << endl;
                }
                index_y++;
            }
            while((yNodeFound == false) && (index_y+1 < HEIGHT_MAX));
            
            if(yNodeFound == false)
            {
                cerr << "Y no node found" << endl;
                printEmptyCell();
            }
            
            cout << endl;
        }
        
        void printEmptyCell()
        {
            cout << -1 << " " << -1;
        }
        
    private:
        NODE ListNode[WIDTH_MAX+1][HEIGHT_MAX+1];
};
/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    TRAY gameTray;
     
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
   
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();

    cerr << width << " " << height << endl;
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        cerr << line << endl;
        for(int indexLine = 0; indexLine < line.size(); indexLine ++)
        {
            if(line.at(indexLine) == '0')
            {
                gameTray.setNode(indexLine, i);
            }
        }
    }
    
    for(int x = 0; x < width; x ++)
    {
        for(int y = 0; y < height; y ++)
        {
            if(gameTray.isCellaNode(x, y))
            {
                 gameTray.printNode(x,y);
            }
        }
    }


    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // Three coordinates: a node, its right neighbor, its bottom neighbor

}
