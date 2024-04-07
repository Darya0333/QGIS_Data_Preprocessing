#include <iostream>

using namespace std;

bool getLine(FILE* fp, char* buf) {
	return fgets(buf, 2000, fp) != NULL;
}

class JSON {
	JSON() {}
	JSON(char* str) {

	}
};

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Please input a file.\n";
		return 0;
	}
	FILE* fp = fopen(argv[1], "r");
	char buf[2048];
	while (getLine(fp, buf)) {
		int ii = 0;
	}
	fclose(fp);
	return 0;
}