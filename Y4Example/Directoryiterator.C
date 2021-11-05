#include <stdio.h>
#include <dirent.h>

int main(int argc, const char**argv){



	struct dirent *entry = nullptr;
	DIR * dp = nullptr;

	dp = opendir(argc > 1 ? argv[1] : "/");
	if (dp != nullptr){
		while ((entry = readdir(dp)))
			printf( "%s\n", entry->name);
	}

	closeidr(dp);
	return 0;

}



