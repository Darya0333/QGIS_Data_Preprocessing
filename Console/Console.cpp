#include <iostream>

using namespace std;

bool getLine(FILE* fp, char* buf) {
	return fgets(buf, 65500, fp) != NULL;
}

FILE * openFile() {
	static int nFiles = 0;
	nFiles++;
	char outfilename[260];
	sprintf(outfilename, "out%d.json", nFiles);
	return fopen(outfilename, "w");
}

char buf[65536];
char result[65536];

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Please input a file.\n";
		return 0;
	}

	FILE* fp = fopen(argv[1], "r");
	FILE* outfp = openFile();
	while (getLine(fp, buf)) {
		char * s1 = strstr(buf, "[ [ [");
		char * s2 = strstr(buf, "] ] ]");
		int nLen = strlen(buf);
		if (s1 && s2) {
			int idx1 = s1 - buf;
			int idx2 = s2 - buf;
			static int nLines = 0;
			if (nLines == 1000000) {
				nLines = 0;
				fflush(outfp);
				fclose(outfp);
				outfp = openFile();
			}
			strcpy(result, buf + idx1);
			result[idx2 - idx1 + 5] = 0;
			fprintf(outfp, "%s\n", result);
			nLines++;
		}
	}
	fclose(fp);
	fclose(outfp);
	return 0;
}