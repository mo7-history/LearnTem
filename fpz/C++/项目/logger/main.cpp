#include <iostream>

using namespace std;

#include "Logger.h"
using namespace pzy::utils;

int main(void) {

	Logger::instance()->open("test.log");
	Logger::instance()->level(Logger::INFO);
	Logger::instance()->max(400);

	//Logger::instance()->log(Logger::DEBUG, __FILE__, __LINE__, "%s,I want to stay at your house,%s!","Lucy","David");
	//debug("hello, everyone");
	debug("Long time no see,%s! �㻹�ǵ�%s��", "V","David");
	info("last page");
	warn("ignore");
	error("in the end");
	return 0;

}
