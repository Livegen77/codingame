#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

class Extension
{
    public:
        Extension(){};
        /*Debug method */
        void printShortAndFullName()
        {
            cout << ShortNameExtension << " " << FullNameExtension << endl;
        }
        void setShortAndFullName(string ShortNameExtension, string FullNameExtension)
        {
            this->ShortNameExtension = ShortNameExtension;
            this->FullNameExtension  = FullNameExtension;
            //Convert to low case
            for(int i = 0; i < this->ShortNameExtension.size(); i ++)
                this->ShortNameExtension[i] = std::tolower(this->ShortNameExtension[i]);
        }
        inline string get_ShortNameExtension()
        {
            return ShortNameExtension;
        }
        
        inline string get_FullNameExtension()
        {
            return FullNameExtension;
        }
        string ShortNameExtension; 
        string FullNameExtension;
    private:

};

class FileName
{
    public:
        FileName(){};
        void printFullFileName()
        {
            cout << FullFileName << " Extension : " << FileExtension <<endl;
        }
        void setFullFileName(string FullFileName)
        {
            bool trigger = false;
            string localFileExtension;
            this->FullFileName = FullFileName;
            //cout << this->FullFileName << endl;
            if(this->FullFileName.size() > 0)
            {
                for(int index = 0; index < this->FullFileName.size(); index++)
                {
                    if(this->FullFileName.at(index) == '.')
                    {
                        localFileExtension.clear();
                        trigger = true;
                        continue;    
                    }
                    
                    if(trigger)
                    {
                        char pchar = (this->FullFileName.at(index));
                        localFileExtension.append(1, pchar);
                    }
                }
                
                //cout << localFileExtension << endl;
                
                FileExtension = localFileExtension;
                for(int i = 0; i < FileExtension.size(); i ++)
                    FileExtension[i] = std::tolower(FileExtension[i]);


            }
        }
        void printFullNameExtension()
        {
            cout << FullNameExtension << endl;
        }
        void searchFullNameExtension(array<Extension, 9999>* ExtensionList)
        {
                bool isSuccess = false;
                
                if(FileExtension.size() > 0)
                {
                    //Parsing list if end has not been reached and no solution is found
                    for(int i = 0; (i < ExtensionList->size()) && (isSuccess == false); i ++)
                    {
                        //Compare first size
                        if(ExtensionList->at(i).ShortNameExtension.size() == FileExtension.size())
                        {
                            //if size is equal, compare content
                            if(ExtensionList->at(i).ShortNameExtension == FileExtension)
                            {
                                isSuccess = true;
                                FullNameExtension = ExtensionList->at(i).FullNameExtension;
                            }
                        }
                    }
                }
                
                if(isSuccess == false)
                {
                    FullNameExtension = "UNKNOWN";
                }
                    
        }
    
    private:
        string FullFileName;
        Extension fileExtension;
        string FileExtension;
        string shortFilename;
        string FullNameExtension;
};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    std::array<Extension, 9999> ArrayExtension;
    Extension fileExtension;
    FileName  fileName;
    string FNAME; // One file name per line.       

    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    
    //cout << N << " -> number of different format" << endl;
    //cout << Q << " -> number of files to be analyzed" << endl;

    //List des extensions
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        //cout << EXT << " " << MT << endl;
        ArrayExtension[i].setShortAndFullName(EXT, MT);
    }
    
    //cout << ExtensionList.size() << " Element in the vector ExtensionList" << endl;
    //out << "ExtensionList : " << endl;
    
    //for(int i = 0; i < ExtensionList.size(); i++)
    //{
    //    cout << i << " : ";
    //    ExtensionList.at(i).printShortAndFullName();
    //}
    
    //List des fichiers
    for (int i = 0; i < Q; i++) {
        FNAME.clear();
        getline(cin, FNAME);
        //cout << FNAME << endl;
        fileName.setFullFileName(FNAME);
        fileName.searchFullNameExtension(&ArrayExtension);
        fileName.printFullNameExtension();
        //cout << i << endl;
    }
    
}
