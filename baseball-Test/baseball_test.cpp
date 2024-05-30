#include "pch.h"
#include "../BaseballGame/baseball.cpp"
#include <stdexcept>
using namespace std;

class BaseballFixture : public testing::Test {
public :
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		try
		{
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e)
		{
			//pass
		}
	}
};


TEST_F(BaseballFixture, ThrowExceptionWhenInputInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}
