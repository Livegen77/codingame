#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

enum PARSER_TYPE
{
    ID        = 0,
    NAME      = 1,
    ADDRESS   = 2,
    PHONE     = 3,
    LONGITUDE = 4,
    LATITUDE  = 5,
    LAST_VALUE
};

class Position
{
    public:
    
    void infoPositionPrint()
    {
        cout << "Longitude(d) : " << longitude << endl;
        cout << "Latitude(d) : " << latitude << endl;
    }
    
    void setLongitudeLatitude(string LON, string LAT)
    {
        string local_LON;
        string local_LAT;
        
        for(int i = 0; i < LON.size(); i++)
        {
            if(LON.at(i) == ',')
            {
                local_LON.append(1, '.');
            }
            else
            {
                local_LON.append(1, LON.at(i));
            }
        }
        
        for(int i = 0; i < LAT.size(); i++)
        {
            if(LAT.at(i) == ',')
            {
                local_LAT.append(1, '.');
            }
            else
            {
                local_LAT.append(1, LAT.at(i));
            }
        }
        
        longitude = stod(local_LON);
        latitude  = stod(local_LAT);     
    }
    
    double calculateDistance(double extern_longitude, double extern_lattitude)
    {
        //A = calling object
        //B = arguments
        double x,x1,x2;
        double y;
        double d,d1;
        
        x1 = (extern_longitude-longitude);
        x2 = cos((extern_lattitude+latitude)/2);
        x = x1*x2;
        y = extern_lattitude-latitude;
        d1 = pow(x,2) + pow(y,2);
        d  = sqrt(d1)*6371;
        
        return d;
    }
    
    double longitude;
    double latitude;
};

class Defibrilateur : public Position
{
    public:
    
    void parserInput(string DEFIB)
    {
        clearDefribrilateurInfo();

        //First element is the number
        int Parser_datatype = 0;
        for(int i = 0; i < DEFIB.size();i ++)
        {
            if(DEFIB.at(i) == ';')
            {
                Parser_datatype++;
                continue;
            }
            
            switch(Parser_datatype)
            {
                case(PARSER_TYPE::ID):
                    ID.append(1, DEFIB.at(i));
                    break;
                case(PARSER_TYPE::NAME):
                    Name.append(1, DEFIB.at(i));
                    break;
                case(PARSER_TYPE::ADDRESS):
                    Adress.append(1, DEFIB.at(i));
                    break;
                case(PARSER_TYPE::PHONE):
                    Phone.append(1, DEFIB.at(i));
                    break;
                case(PARSER_TYPE::LONGITUDE):
                    if(DEFIB.at(i) == ',')
                        Longitude.append(1, '.');
                    else
                        Longitude.append(1, DEFIB.at(i));
                    break;
                case(PARSER_TYPE::LATITUDE):
                    if(DEFIB.at(i) == ',')
                        Latitude.append(1, '.');
                    else
                        Latitude.append(1, DEFIB.at(i));
                    break;
                default:
                    cerr << "Default state in parser reached ERROR :"<< Parser_datatype << endl;
            }
         }
         
         latitude  = stod(Latitude);
         longitude = stod(Longitude);
    }
    
    void infoDefibrilateurPrint()
    {
        cout << endl;
        cout << "ID : " << ID << endl;
        cout << "Name : " << Name << endl;
        cout << "Adress : " << Adress << endl;
        cout << "Phone : " << Phone << endl;
        infoPositionPrint();
        cout << endl;
    }
    
    inline string getName()
    {
        return Name;
    }
    
    private:
        string ID;
        string Name;
        string Adress;
        string Phone;
        string Longitude;
        string Latitude;
        
    void clearDefribrilateurInfo()
    {
        ID.clear();
        Name.clear();
        Adress.clear();
        Phone.clear();
        Longitude.clear();
        Latitude.clear();
        latitude  = 0;
        longitude = 0;
    }
};
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    Defibrilateur myDefibrilateur;
    Position      userPosition;
    string        closerDefibrilateur;
    double closedistance = 9999999;
    double distance      = 0;
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    userPosition.setLongitudeLatitude(LON,LAT);
    //userPosition.infoPositionPrint();
    
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        myDefibrilateur.parserInput(DEFIB);
        //myDefibrilateur.infoDefibrilateurPrint();
        distance = myDefibrilateur.calculateDistance(userPosition.longitude, userPosition.latitude);
        if(closedistance > distance)
        {
            closedistance = distance;
            closerDefibrilateur.clear();
            closerDefibrilateur = myDefibrilateur.getName();
        }
    }
    

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << closerDefibrilateur << endl;
}
