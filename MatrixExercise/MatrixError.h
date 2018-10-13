#include <string>
using namespace std;

class MatrixError
{
public:
	MatrixError(const string&);
	~MatrixError();

	string getMessage();
private:
	string _message;
};

