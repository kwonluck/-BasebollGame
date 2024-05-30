#include "pch.h"
#include "../BaseballGame/baseball.cpp"
#include <stdexcept>
using namespace std;

class BaseballFixture : public testing::Test {
public :
	Baseball game{ "123" };
	void assertIllegalArgument(string guessNumber) {
		try
		{
			game.playGame(guessNumber);
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

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.playGame("123");
	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolvedResultIf2s0b) {
	GuessResult result = game.playGame("124");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolvedResultIf1s2b) {
	GuessResult result = game.playGame("132");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}