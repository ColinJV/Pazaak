//#include "DataHandler.hpp"
//
///********************************************************************************************************
//* Function: DataHandler constructor
//* Date Created: 4/18/2024
//* Date Last Modified: 4/21/24
//* Programmer: Joshua Allard
//* Description: constructs data handler object which calls handler
//* Input parameters: input data and a count
//* Returns: void
//* Preconditions: None
//* Postconditions: None
//********************************************************************************************************/
//DataHandler::DataHandler(char* nData, int iCount)
//{
//	// might be a bit overdone here, could improve
//
//	// calls function "handler"
//	handler(nData, iCount);
//}
//
///********************************************************************************************************
//* Function: handler
//* Date Created: 4/21/2024
//* Date Last Modified: 4/22/24
//* Programmer: Joshua Allard
//* Description: goes through data printing
//* Input parameters: input data and a count
//* Returns: void
//* Preconditions: called in DataHandler constructor
//* Postconditions: None
//********************************************************************************************************/
//void DataHandler::handler(char* nData, int iCount)
//{
//	cout << "Data: " << endl;
//	// loop though iCount printing data
//	for (int nc = 0; nc < iCount; nc++)
//	{
//		// show data
//		cout << nData[nc];
//	}
//	// added newline
//	cout << endl;
//}