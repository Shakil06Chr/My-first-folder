#include <fstream>
#include <sstream>
#include<iostream>
#include<sys\stat.h>
#include<dirent.h>
#include<conio.h>

using namespace std;

void file_detect()
{
    struct dirent *d;
    struct stat dst;

    DIR *dr;

   string path= ".\\";
    dr=opendir(path.c_str());

    if(dr!=NULL)
    {
      for(d=readdir(dr);d!=NULL;d=readdir(dr))
      {
          string type=d->d_name;
          type=type;
          if(stat(type.c_str(),&dst)==0)
          {

             if(dst.st_mode &S_IFDIR)
              {
                   type="is a folder";
                  // continue;
              }
            else if(dst.st_mode & S_IFREG)
              {
                 type="is a file";
              }

          }
          cout<<d->d_name<<endl<<endl;

      }
      closedir(dr);


    }
    else
    {
       ;

    }
    getch();

}


void hexvalue()
{
    ifstream file("C:\\Users\\USER\\Desktop\\test\\A simple note for English.pdf", ios::binary); // replace "filename.bin" with the name of your file
    if (!file.is_open()) {
       cerr << "Error opening file\n";

    }

    stringstream ss; // create a stringstream object to store the hexadecimal values
    char ch;
    while (file.get(ch)) {
        ss << hex << uppercase << static_cast<int>(ch); // convert the character to its hexadecimal value and store it in the stringstream object
    }
    string hex = ss.str(); // convert the stringstream object to a string

    cout << hex << endl; // print the string of hexadecimal values
    file.close();


}
using namespace std;

int main()
{
    hexvalue();
    return 0;

}
