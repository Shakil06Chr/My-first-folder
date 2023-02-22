#include<stdio.h>
#include<dirent.h>
#include<string.h>

#include <sys/stat.h>


int count_files(char *dir_path)
{
    int count = 0;
    struct dirent *entry;
    DIR *dir = opendir(dir_path);

    if (dir == NULL)
    {
        return 0;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        char path[1024];
        struct stat statbuf;

        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        if (stat(path, &statbuf) == -1)
        {
            continue;
        }

        if (S_ISDIR(statbuf.st_mode))
        {
            count += count_files(path);
        }
        else
        {
            count++;
        }
    }

    closedir(dir);
    return count;
}





char* addString( char *s1,  char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1); // +1 to copy the null-terminator
    return result;
}

int fileOrDir(char* aa)
{


    if(strcmp(aa,"..") == 0 )
    {

        return 2;
    }

    if (strcmp(aa,".") == 0 )
        return 2;
    int length = strlen(aa);
    int i;

    for(i=length-1; i>0; i--)
    {
        if(aa[i] == '.')

            return 1;
    }
    return 0;
}

int deelet(char aa[])
{
    printf("%s\n",aa);

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (aa)) != NULL)
    {
        char* bb =aa;

        while ((ent = readdir (dir)) != NULL)
        {

            if(fileOrDir(ent->d_name) == 0)
            {

                char* bb = addString(aa,ent->d_name);
                bb = addString(bb,"\\");

                deelet(bb);

            }

            else if(fileOrDir(ent->d_name) == 1)
            {
                printf("    %s \n",ent->d_name) ;
                char* ee = addString(aa,ent->d_name);
                //ee = addString(ee,"\\");
                printf("     %s\n",ee);
                remove(ee);
            }
        }
        closedir (dir);
    }

    else
    {

        //perror ("");
        return  0;

    }

    return 0;
}


int  main()
{


    int count =

       printf("Total files: %d\n", count);


    int a =0;

    while(1)
    {
        a = count_files("C:\\Users\\USER\\Desktop\\test");
        if(count_files("C:\\Users\\USER\\Desktop\\test") != a)
        {
            a =  count_files("C:\\Users\\USER\\Desktop\\test");
            deelet("C:\\Users\\USER\\Desktop\\test");
        }


    }

}
