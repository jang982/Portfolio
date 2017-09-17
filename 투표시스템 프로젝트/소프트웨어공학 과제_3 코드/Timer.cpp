#include "timer.h"
#include "Vote.h"
#include "VoteCollection.h"

#pragma warning(disable:4996)

Timer::Timer()
{
}

Timer::~Timer()
{
}


void Timer::setTime(string inputTime)
{
	strcpy(currentTime, inputTime.c_str());

	char charYear[5] = { 0 }, charMonth[3] = { 0 }, charDay[3] = { 0 }, charHour[3] = { 0 }, charMinute[3] = { 0 };
	for (int i = 0; i < inputTime.length(); i++) {
		if (i < 4)
			charYear[i] = currentTime[i];
		else if (i>4 && i < 7)
			charMonth[i - 5] = currentTime[i];
		else if (i > 7 && i < 10)
			charDay[i - 8] = currentTime[i];
		else if (i > 10 && i < 13)
			charHour[i - 11] = currentTime[i];
		else if (i > 13 && i < 16)
			charMinute[i - 14] = currentTime[i];
	}
	year = atoi(charYear);
	month = atoi(charMonth);
	day = atoi(charDay);
	hour = atoi(charHour);
	minute = atoi(charMinute);

}

string Timer::getTime()
{
	return currentTime;
}

void Timer::sortVote(VoteCollection* currentVote, VoteCollection* postVote, VoteCollection* preVote)
{
	allVoteList.clear();
	list<Vote>::iterator iter;
	iter = currentVote->findFirst();

	// currentVote, postVote, preVote 모두 => allListVote에 넣기
	while (iter != currentVote->findEnd())
	{
		Vote temp = *iter;
		allVoteList.push_back(temp);
		iter++;
	}
	currentVote->getVoteListHead()->clear();

	iter = postVote->findFirst();
	while (iter != postVote->findEnd())
	{
		Vote temp = *iter;
		allVoteList.push_back(temp);
		iter++;
	}
	postVote->getVoteListHead()->clear();

	iter = preVote->findFirst();
	while (iter != preVote->findEnd())
	{
		Vote temp = *iter;
		allVoteList.push_back(temp);
		iter++;
	}
	preVote->getVoteListHead()->clear();

	// 분리하기
	iter = allVoteList.begin();
	while (iter != allVoteList.end())
	{
		int startTime[5], endTime[5];

		stringTimeTointTime(iter->getStartTime(), startTime);
		stringTimeTointTime(iter->getEndTime(), endTime);

		unsigned int currentMin, startMin, endMin;

		currentMin = (year * 12 * 30 * 24 * 60) + (month * 30 * 24 * 60) + (day * 24 * 60) + (hour * 60) + minute;
		startMin = intTimeToMinute(startTime);
		endMin = intTimeToMinute(endTime);

		Vote temp = *iter;

		if (currentMin > endMin)
		{
			//prevote
			preVote->getVoteListHead()->push_back(temp);
		}
		else if (startMin <= currentMin && currentMin <= endMin) {
			//currentvote
			currentVote->getVoteListHead()->push_back(temp);
		}
		else if (currentMin < startMin) {
			//postVotecollection
			postVote->getVoteListHead()->push_back(temp);
		}
		iter++;
	}
	allVoteList.clear();
}
// Function : passingTime
// Description: 시간을 불러와 int로 파싱
// Parameters : string, int
// Return Value : 
//
// Created: 2017/5/30 22:00pm
// Author: 홍유남
//

void Timer::passingTime(string inputTime, int compare[4])
{
	char* timeToken[5], passingTime[50], *context;

	strcpy_s(passingTime, inputTime.c_str());
	timeToken[0] = strtok_s(passingTime, ":", &context);
	compare[0] = stoi(timeToken[0]);

	for (int i = 1; i < 5; i++)
	{
		timeToken[i] = strtok_s(NULL, ":", &context);
		compare[i] = stoi(timeToken[i]);
	}
}
void Timer::stringTimeTointTime(string time, int* result)
{
	char charYear[5] = { 0 }, charMonth[3] = { 0 }, charDay[3] = { 0 }, charHour[3] = { 0 }, charMinute[3] = { 0 };
	for (int i = 0; i < time.length(); i++) {
		if (i < 4)
			charYear[i] = time[i];
		else if (i>4 && i < 7)
			charMonth[i - 5] = time[i];
		else if (i > 7 && i < 10)
			charDay[i - 8] = time[i];
		else if (i > 10 && i < 13)
			charHour[i - 11] = time[i];
		else if (i > 13 && i < 16)
			charMinute[i - 14] = time[i];
	}
	result[0] = atoi(charYear);
	result[1] = atoi(charMonth);
	result[2] = atoi(charDay);
	result[3] = atoi(charHour);
	result[4] = atoi(charMinute);
}

int Timer::intTimeToMinute(int * intTime)
{
	//년 월 일 시 분을 전부 분으로 바꿔주는 함수.
	return ((intTime[0] * 12 * 30 * 24 * 60) + (intTime[1] * 30 * 24 * 60) + (intTime[2] * 24 * 60) + (intTime[3] * 60) + intTime[4]);
}

// Function : comPareTime 
// Description: 받은 시간 2개를 빼서 비교하는 함수
// Parameters : int int int
// Return Value :
//
// Created: 2017/5/30 22:00pm
// Author: 홍유남
//


void Timer::compareTime(int compare[4], int input1[4], int input2[4])
{
	for (int i = 0; i < 5; i++)
	{
		compare[i] = input1[i] - input2[i];
	}
}
// Function : plusTime
// Description: 두시가능을 뺀값을 양수화 시켜주는 함수
// Parameters : int
// Return Value : 
//
// Created: 2017/5/30 22:00pm
// Author: 홍유남
//

void Timer::plusTime(int compare[4])
{
	if (compare[4]<0)
	{
		compare[4] = compare[4] + 60;
		compare[3] = compare[3] - 1;
	}
	if (compare[3] < 0) {
		compare[3] = compare[3] + 24;
		compare[2] = compare[2] - 1;
	}
	if (compare[2] < 0) {
		compare[2] = compare[2] + 30;
		compare[1] = compare[1] - 1;
	}
	if (compare[1]<0) {
		compare[1] = compare[1] + 12;
		compare[0] = compare[0] - 1;
	}
}
// Function : deleteVOteMessage
// Description:  28일이 지난 것을 알려주는 함수
// Parameters : string
// Return Value : bool
//
// Created: 2017/5/30 22:00pm
// Author: 홍유남
//

bool Timer::deleteVoteMessage(string endTime)
{
	int compare[5];
	passingTime(endTime, compare);
	if (year - compare[0] > 0) {
		return true;
	}
	else{
		if (month - compare[1] > 0)
			return true;
		else
		{
			if (day - compare[2] > 27)
				return true;
		}
	}
	return false;
}
