#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};


class Baseball {
public:
	explicit Baseball(const string& collectAnswer) : correctAnswer(collectAnswer) {

	}

	GuessResult playGame(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		
		if (isPerfectAnswer(guessNumber)){
			return result;
		}
		
		result.strikes = getStrikeCount(guessNumber);
		result.balls = getBallCount(guessNumber);
		return result;
	}

private:
	string correctAnswer;
	GuessResult result{ false, 0, 0 };

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.size() != 3)
			throw length_error("Must be three letters.");

		for (char ch : guessNumber)	{
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("must be number");
		}

		if (isDuplicatedNumber(guessNumber))
			throw invalid_argument("must not have same number");
	}

	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[1] == guessNumber[2]
			|| guessNumber[2] == guessNumber[0];
	}

	bool isPerfectAnswer(const std::string& guessNumber) {
		if (guessNumber == correctAnswer) {
			result = { true, 3, 0 };
			return true;
		}	
		return false;
	}

	int getStrikeCount(const std::string& guessNumber)
	{
		int strike = 0;
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == correctAnswer[i])
				strike++;
		}
		return strike;
	}

	int getBallCount(const std::string& guessNumber) {
		int ball = 0;
		for (int guessIdx = 0; guessIdx < 3; guessIdx++) {
			for (int correctIdx = 0; correctIdx < 3; correctIdx++) {

				if (guessIdx == correctIdx) continue;

				if (guessNumber[guessIdx] == correctAnswer[correctIdx])
					ball++;
			}
		}
		return ball;
	}
};