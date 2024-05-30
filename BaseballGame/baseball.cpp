#include <string>
#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};


class Baseball {
public:
	explicit Baseball(const string& question) : question(question) {

	}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question)
		{
			return { true, 3, 0 };
		}
		return { false, 0, 0 };
	}

private:
	string question;

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.size() != 3)
		{
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber)
		{
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
};