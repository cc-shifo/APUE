#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <dirent.h>
/*
 * /usr/include/dirent.h
 * opendir(), fopendir()
 * readdir(), readdir_r()
 * exit() stdlib.h, EXIT_SUCCESS, EXIT_FAILURE
 */
int main(int argc, char *args[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
	printf("usage: ls directory_name\n");

    if ((dp = opendir(args[1])) == NULL) {
	printf("can't open %s\n", args[1]);
	/*exit(1);*/
	exit(EXIT_FAILURE);
    }
    
    while ((dirp = readdir(dp)) != NULL) {
	printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    
    /*exit(0);*/
    exit(EXIT_SUCCESS);
}
