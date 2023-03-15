#include <fstream>
#include <sstream>
#include<iostream>
#include<sys\stat.h>
#include<dirent.h>
#include<conio.h>

using namespace std;
void hexvalue(string str);
void file_detect();


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
          //cout<<"shakil \n\n\n";
          if(d->d_name[0]=='.')
               continue;
          cout<<d->d_name<<endl<<endl;
          string str=d->d_name;
          hexvalue(str);

      }
      closedir(dr);


    }
    else
    {
       ;

    }
    getch();

}


void hexvalue(string str)
{
    ifstream file("C:\\Users\\Pc7\\Desktop\\antivirus\\"+str, ios::binary);
    if (!file.is_open()) {
       cerr << "Error opening file\n";

    }

    stringstream ss;
    char ch;
    while (file.get(ch)) {
        ss << hex << uppercase << static_cast<int>(ch);
    }
    string hex = ss.str();

    cout << hex << endl;
    file.close();


}
using namespace std;

int main()
{
  file_detect();

   // hexvalue();
    return 0;

}
