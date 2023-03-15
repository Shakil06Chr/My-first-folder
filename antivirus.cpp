#include <fstream>
#include <sstream>
#include <iostream>
#include <sys/stat.h>
#include <dirent.h>
#include <conio.h>

using namespace std;

void hexvalue(string str1);

void file_detect()
{
    struct dirent *d;
    struct stat dst;

    DIR *dr;

    string path = ".\\";
    dr = opendir(path.c_str());

    if (dr != NULL)
    {
        while ((d = readdir(dr)) != NULL)
        {
            string type = d->d_name;
            if (stat(type.c_str(), &dst) == 0)
            {

                if (dst.st_mode & S_IFDIR)
                {
                    type = "is a folder";
                    // continue;
                }
                else if (dst.st_mode & S_IFREG)
                {
                    type = "is a file";
                }
            }
             cout<<" my name is Shakil hossain\n\n\n";
            cout << d->d_name << endl << endl;
            hexvalue(d->d_name);
        }

        closedir(dr);
    }
    else
    {
        cerr << "Error opening directory\n";
        return;
    }

    getch();
}

void hexvalue(string str1)
{
    ifstream file("C:\\Users\\USER\\Desktop\\test\\" + str1, ios::binary);
    if (!file.is_open())
    {
        cerr << "Error opening file\n";
        return;
    }

    stringstream ss;
    char ch;
    while (file.get(ch))
    {
        ss << hex << uppercase << static_cast<int>(ch);
    }

    string hex = ss.str();
    cout << hex <<"this is first hex\n\n\n"<< endl;
    file.close();
}

int main()
{
    file_detect();
    return 0;
}
