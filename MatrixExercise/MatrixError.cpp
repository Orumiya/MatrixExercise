#include "pch.h"
#include "MatrixError.h"


MatrixError::MatrixError(const string& message_) : _message(message_)
{
}


MatrixError::~MatrixError()
{
}

string MatrixError::getMessage() {
	return _message;
}