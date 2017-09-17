
#include"System.h"

#pragma warning(disable:4996)
using namespace std;

void doTask();
void makeAccount();			//1.1 회원가입
void deleteAccount();		//1.2 회원탈퇴

void logIn();				//2.1 로그인
void logOut();				//2.2 로그아웃

void makeVote();			//3.1 투표제안

void showCurrentVoteList();	//4.1 현재투표리스트 조회
void voting();				//4.2 투표
void showPostVoteList();	//4.3 향후투표예정인 투표리스트 조회
void showPreVoteList();		//4.4 종료된 투표리스트 조회

void showEntireGroup();		//5.1 전체그룹 조회
void joinGroupMember();		//5.2 그룹가입
void makeGroup();			//5.3 그룹생성
void show_JoinedGroup();	//5.4 가입그룹 조회
void leave_Group();			//5.5 그룹탈퇴

void changeCurrnetTime();	//6.1 현재시간 설정
void changeSession();		//7.1 Session 변경
void guestSession();		//7.2 guest Session으로 변경
void program_Exit();		//8.1 종료

FILE* in_fp, *out_fp;

User guest("guest", "guest", "guest", "guest", "guest");
list<User> forGuest;
list<User>::iterator currentLoginUser; 

int main(void) {
	in_fp = fopen(INPUT_FILE_NAME, "r+");
	out_fp = fopen(OUTPUT_FILE_NAME, "w+");	;
	
	ControlAndCollection::GetInstance();		//컨트롤과 콜렉션을 생성합니다.
	forGuest.push_back(guest);
	currentLoginUser = forGuest.begin();


	doTask();
	
	return 0;
}

void doTask()
{
	// 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;

	// 종료 메뉴(8.1)가 입력되기 전까지 반복함
	while (menu_level_1 != 8 || menu_level_2 != 1)
	{
		// 입력파일에서 메뉴 숫자 2개를 읽기
		fscanf(in_fp,"%d %d", &menu_level_1, &menu_level_2);
		// 메뉴 구분 및 해당 연산 수행
		
		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1:   // "1.1. 회원가입“ 메뉴 부분
			{
				makeAccount();
				break;
			}
			case 2:	  // "1.2. 회원탈퇴“ 메뉴 부분
			{
				deleteAccount();
				break;
			}
			}
			break;
		}
		case 2:
		{
			switch (menu_level_2)
			{
			case 1:   // "2.1. 로그인“ 메뉴 부분
			{
				logIn();
				break;
			}
			case 2:	// "2.2. 로그아웃“ 메뉴 부분
			{
				logOut();
				break;
			}
			}
			break;
		}
		case 3:
		{
			if (currentLoginUser->getJoinedGroup() == "none") {
				fprintf(out_fp, "가입된 그룹이 없습니다.\n");
				break;
			}
			switch (menu_level_2)
			{
			case 1:   // "3.1. 투표 제안“ 메뉴 부분
			{
				makeVote();
				break;
			}
			}
			break;
		}
		case 4:
		{
			if (currentLoginUser->getJoinedGroup() == "none") {
				fprintf(out_fp, "가입된 그룹이 없습니다.\n");
				break;
			}
			switch (menu_level_2)
			{
			case 1:   // "4.1. 현재 진행 중인 투표 리스트“ 메뉴 부분
			{
				showCurrentVoteList();
				break;
			}
			case 2:	 // "4.2. 투표“ 메뉴 부분
			{
				voting();
				break;
			}
			case 3:	 // "4.3. 향후 진행 예정인 투표 리스트“ 메뉴 부분
			{
				showPostVoteList();
				break;
			}
			case 4:
			{
				showPreVoteList();
				break;
			}
			}
			break;
		}
		case 5:
		{
			switch (menu_level_2)
			{
			case 1:   // "5.1. 전체 그룹 조회“ 메뉴 부분
			{
			    showEntireGroup();
				break;
			}
			case 2:   // "5.2. 그룹 가입“ 메뉴 부분	
			{
				joinGroupMember();
				break;
			}
			case 3:   // "5.3. 그룹 생성“ 메뉴 부분	
			{
				makeGroup();
				break;
			}
			case 4:   // "5.4. 가입 그룹 조회“ 메뉴 부분	
			{

				show_JoinedGroup();
				break;
			}
			case 5:   // "5.5. 그룹 탈퇴“ 메뉴 부분	
			{
				leave_Group();
				break;
			}
			}
			break;
		}
		case 6:
		{
			switch (menu_level_2)
			{
			case 1:   // "6.1 현재시간 설정“ 메뉴 부분
			{
				changeCurrnetTime();
				break;
			}
			}
			break;
		}
		case 7:
		{
			switch (menu_level_2)
			{
			case 1:   // "7.1. session 변경“ 메뉴 부분
			{
				changeSession();
				break;
			}
			case 2:   // "7.2. guest sessiond으로 변경“ 메뉴 부분
			{
				guestSession();
				break;
			}
			}
			break;
		}
		case 8:
		{
			switch (menu_level_2)
			{
			case 1:   // "8.1. 종료“ 메뉴 부분
			{
				program_Exit();
				break;
			}
			}
		}
		}
		fprintf(out_fp, "\n");
	}
 }
  //1.1 회원가입
  // Function : void makeAccount()
  // Description: 회원 가입 하는 함수
  // Parameters :   void
  // Return Value : void
  //
  // Created: 2017/5/29 8:30 pm
  // Author: 조현정
  //
 void makeAccount() {
	 Join *join = ControlAndCollection::GetInstance()->getJoin();
	 JoinUI* joinUI = ControlAndCollection::GetInstance()->getJoin()->callJoinUIStartInterface(*ControlAndCollection::GetInstance()->getJoin());
	 char name[MAX_STRING], SSN[MAX_STRING],
		 address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
	 bool error;

	 // 입력 형식 : 이름, 주민번호, 주소, ID, 비밀번호를 파일로부터 읽음
	 fscanf(in_fp, "%s %s %s %s %s\n", name, SSN, address, ID, password);

	 error = joinUI->enterUserInfo(name, SSN, address, ID, password);

	 if (error)
		 fprintf(out_fp, "1.1. Error: 이미 존재하는 ID 입니다.\n");
	 else
		 fprintf(out_fp, "1.1. 회원가입 \n> %s %s %s %s %s \n", name, SSN, address, ID, password);

 }
  //1.2 회원탈퇴
  // Function : void deleteAccount()
  // Description: 회원 탈퇴 하는 함수
  // Parameters :   void
  // Return Value : void
  //
  // Created: 2017/5/30 5:08 pm
  // Author: 조현정
  //
 void deleteAccount() {
	 Withdrwal *withdrwal = ControlAndCollection::GetInstance()->getWithdrwal();
	 WithdrwalUI *withdrwalUI = withdrwal->callWithdrwalUIStartInterface(*withdrwal);
	 char ID[MAX_STRING];
	 bool error;

	 strcpy(ID, currentLoginUser->getUserID().c_str());
	 error = withdrwalUI->clickWithdrwal(ID);

	 if (error)
		 fprintf(out_fp, "1.2. Error: 탈퇴할 수 없는 회원입니다.\n");
	 else
	 {
		 currentLoginUser = forGuest.begin();
		 fprintf(out_fp, "1.2. 회원탈퇴\n>%s \n", ID);
	 }
 }
 
  //2.1 로그인
  // Function : void logIn()
  // Description: 로그인 하는 함수
  // Parameters :   void
  // Return Value : void
  //
  // Created: 2017/5/30 2:30 am
  // Author: 조현정
  //
 void logIn() {
	 Login *login = ControlAndCollection::GetInstance()->getLogin();
	 UserCollection *userCollection = ControlAndCollection::GetInstance()->getUserCollection();
	 LoginUI* loginUI = login->callLoginUIStartInterface(*login);
	 char ID[MAX_STRING], Pwd[MAX_STRING];
	 bool error;

	 fscanf(in_fp, "%s %s", ID, Pwd);
	 
	 error = loginUI->getUserInfo(ID, Pwd, currentLoginUser);
	 if (error)
		 fprintf(out_fp, "2.1. Error: 일치하는 정보가 없습니다. \n");
	 else {
		 currentLoginUser = userCollection->findUser(ID);
		 fprintf(out_fp, "2.1. 로그인\n> %s %s \n", ID, Pwd);
	 }
 }
  //2.2 로그아웃

  //Function :void logOut()
  //Description : 로그아웃 하는 함수
  //Parameters : void
  //Return Value : void
  //Created : 2017/05/30 9:38 am
  //Author : 조현정
 void logOut() {
	 Logout *logout = ControlAndCollection::GetInstance()->getLogout();
	 LogoutUI *logoutUI = logout->callLogoutUIStartInterface(*logout);
	 char ID[MAX_STRING];
	 strcpy(ID, currentLoginUser->getUserID().c_str());
	 logoutUI->clickLogout(ID);
	 currentLoginUser = forGuest.begin();
	 fprintf(out_fp, "2.2. 로그아웃\n> %s\n", ID);

 }
  //3.1 투표 제안
  //Function :void makeVote()
  //Description : 투표 제안 기능을 위해 input 값을 전달하고 output 값을 받아 출력한다.
  //Parameters : void
  //Return Value : void
  //Created : 2017/6/1 15:00 pm
  //Author : 김윤영
 void makeVote() {
	 CreateVote *createVote = ControlAndCollection::GetInstance()->getCreateVote();
	 CreateVoteUI *createVoteUI = createVote->callCreateVoteUIStartInterface(*createVote);
	 char subject[MAX_STRING],startTime[MAX_STRING],endTime[MAX_STRING];
	 int numberOfItems;
	 
	 int errorFurture1[5],errorFuture2[5];
	 int currentMinute, startTimeMinute;
	 bool error;

	 fscanf(in_fp, "%s %d %s %s \n",subject,&numberOfItems, startTime,endTime);

	timer.stringTimeTointTime(startTime,errorFurture1);
	timer.stringTimeTointTime(timer.getTime(), errorFuture2);

	startTimeMinute=timer.intTimeToMinute(errorFurture1);
	currentMinute=timer.intTimeToMinute(errorFuture2);

	if(startTimeMinute<currentMinute){
		fprintf(out_fp, "3.1. 투표 시작 시간은 현재 시간보다 이후여야 합니다.\n");
	}
	else
	{
		error = createVoteUI->inputDate(subject, numberOfItems, startTime, endTime, currentLoginUser->getJoinedGroup());
		if (error)
			fprintf(out_fp, "3.1. 누락된 항목이 있습니다. \n");
		else {
			fprintf(out_fp, "3.1. 투표 제안\n");
			fprintf(out_fp, "%s %d %s %s\n", subject, numberOfItems, startTime, endTime);

		}
	}
 }
 //4.1 현재 진행중인 투표 조회

 //Function: 현재 진행중인 투표 조회
 //Description: 함수 
 //created: 2017/5/24 22:00pm
 //Author: 홍유남
 //mail: bcdass@naver.com

 //Function: 현재 진행중인 투표 조회
 //Description: 함수 수정
 //created: 2017/5/31 10:30pm
 //Author: 홍유남
 //mail: bcdass@naver.com

 void showCurrentVoteList()
 {
	 CurrentVoteList* currentVoteList = ControlAndCollection::GetInstance()->getCurrentVoteList();
	 CurrentVoteListUI* currentVoteListUI = currentVoteList->callCurrentVoteListUIStartInterface(*currentVoteList);

	 string subject[MAX_STRING], endTime[MAX_STRING], startTime[MAX_STRING], belongsTo[MAX_STRING];
	 int items[MAX_STRING];
	 currentVoteListUI->confirmView(subject, items, startTime, endTime, belongsTo);

	 fprintf(out_fp, "4.1. 현재 진행 중인 투표 리스트\n");
	 for (int i = 0; subject[i].size() != 0; i++) {
		 char temp1[MAX_STRING];
		 strcpy(temp1, belongsTo[i].c_str());
		 if (currentLoginUser->getJoinedGroup() == temp1) {
			 
			 char forOutput1[MAX_STRING];
			 int forOutput2, compare[5];
			 int endTimeTokenInt[5], currentTimeTokenInt[5];
			 //현재시간 파싱
			 timer.passingTime(timer.getTime(), currentTimeTokenInt);
			 strcpy(forOutput1, subject[i].c_str());
			 forOutput2 = items[i];
			 // strcpy(forOutput3, endTime[i].c_str());
			 //종료시간 파싱
			 timer.passingTime(endTime[i], endTimeTokenInt);
			 //시간 비교
			 timer.compareTime(compare, endTimeTokenInt, currentTimeTokenInt);
			 timer.plusTime(compare);
			 fprintf(out_fp, "> %s %d %d:%d:%d:%d:%d \n", forOutput1, forOutput2, compare[0], compare[1], compare[2], compare[3], compare[4]);
		 }
	 }
 }

 //4.2 투표
 //Function :void voting()
 //Description : 투표 기능을 위해 input 값을 전달하고 output 값을 받아 출력한다.
 //Parameters : void
 //Return Value : void
 //Created : 2017/6/1 15:00 pm
 //Author : 김윤영
 void voting() {
	 VoteFor *voteFor = ControlAndCollection::GetInstance()->getVoteFor();
	 VoteForUI *voteForUI = voteFor->callVoteForUIStartInterface(*voteFor);
	 char subject[MAX_STRING];
	 int itemNumber;
	 int error;

	 fscanf(in_fp, "%s %d \n", subject, &itemNumber);

	 error = voteForUI->inputData(subject, itemNumber, currentLoginUser->getJoinedGroup(), currentLoginUser->getPersonalNumber());

	 if (error==0) {
		 fprintf(out_fp, "4.2. 없는 투표 주제이거나 항목번호가 잘못되었습니다. \n");
	 }
	 else if (error == 1) {
		 fprintf(out_fp, "4.2. 이미 투표하였습니다. \n");
	 }
	 else if(error==2) {
		 fprintf(out_fp, "4.2. 투표\n");
		 fprintf(out_fp, "%s %d\n", subject, itemNumber);
	 }
 }
 
 //Function: 향후 진행 예정인 투표리스트 조회
 //Description: 함수 
 //created: 2017/5/24 22:00pm
 //Author: 홍유남
 //mail: bcdass@naver.com

 //4.3 향후 진행 예정인 투표 리스트
 void showPostVoteList()
 {
	 PostVoteList *postVoteList = ControlAndCollection::GetInstance()->getPostVoteList();
	 PostVoteListUI* postVoteListUI = postVoteList->callPostVoteListUIStartInterface(*postVoteList);

	 string subject[MAX_STRING], endTime[MAX_STRING], startTime[MAX_STRING], belongsTo[MAX_STRING];
	 int items[MAX_STRING];

	 postVoteListUI->confirmView(subject, items, startTime, endTime, belongsTo);

	 fprintf(out_fp, "4.3. 향후 진행 예정인 투표 리스트\n");
	 for (int i = 0; subject[i].size() != 0; i++) {
		 char temp1[MAX_STRING];
		 strcpy(temp1, belongsTo[i].c_str());
		 if (currentLoginUser->getJoinedGroup() == temp1) {
			 char forOutput1[MAX_STRING], forOutput3[MAX_STRING], forOutput4[MAX_STRING];
			 int forOutput2;

			 strcpy(forOutput1, subject[i].c_str());
			 forOutput2 = items[i];
			 strcpy(forOutput3, startTime[i].c_str());

			 strcpy(forOutput4, endTime[i].c_str());
			 fprintf(out_fp, "> %s %d %s %s \n", forOutput1, forOutput2, forOutput3, forOutput4);
		 }
	 }

 }

 //Function:종료된 투표 조회
 //Description: 함수 
 //created: 2017/5/24 22:00pm
 //Author: 홍유남
 //mail: bcdass@naver.com

 //4.4 종료된 투표 조회
 void showPreVoteList()
 {
	 PreVoteList *preVoteList = ControlAndCollection::GetInstance()->getPreVoteList();
	 PreVoteListUI* preVoteListUI = preVoteList->callPreVoteListUIStartInterface(*preVoteList);
	 
	 string subject[MAX_STRING], endTime[MAX_STRING], startTime[MAX_STRING], belongsTo[MAX_STRING];
	 int items[MAX_STRING], *result[MAX_STRING];

	 preVoteListUI->confirmView(subject, items, startTime, endTime, belongsTo, result);

	 fprintf(out_fp, "4.4. 종료된 투표 리스트\n"); 
	 
	  for (int i = 0; subject[i].size() != 0; i++) {
		 //timer에서 4주 시간이 지나면 지났다는 것을 UI에 알려준다

		 if (timer.deleteVoteMessage(endTime[i])) {
			 preVoteListUI->weekLater(endTime[i]);
			 continue;
		 }

		char temp1[MAX_STRING];
		strcpy(temp1, belongsTo[i].c_str());

		if (currentLoginUser->getJoinedGroup() == temp1) {

			 char forOutput1[MAX_STRING];
			 int forOutput2;
			 int* forOutpu3;

			 strcpy(forOutput1, subject[i].c_str());
			 forOutput2 = items[i];
			 forOutpu3 = result[i];
			 fprintf(out_fp, " %s", forOutput1);
			 for (int j = 0; j < items[i]; j++)
			 {
				 fprintf(out_fp, " %d:%d", j+1, forOutpu3[j]);
			 }
			 fprintf(out_fp, "\n");
		 }
	 }
 }


 //Function:전체그룹 조회
 //Description: 전체그룹조회함수를 부릅니다 
 //created: 2017/5/28 23:00pm
 //Author: 장현석
 //mail: jang8018@naver.com

 //5.1 전체 그룹 조회
 void showEntireGroup() {
	 ShowAllGroup *showAllGroup = ControlAndCollection::GetInstance()->getShowAllGroup();
	 ShowAllGroupUI *showAllGroupUI = showAllGroup->callShowAllGroupUIStartInterface(*showAllGroup);
	 string groupList[MAX_STRING];

	 showAllGroupUI->confirmView(groupList);

	 fprintf(out_fp, "5.1. 전체그룹 조회\n");
	 for (int i = 0; groupList[i].size() != 0; i++) {
		 char forOutput[MAX_STRING];
		 strcpy(forOutput, groupList[i].c_str());
		 fprintf(out_fp, "> %s \n", forOutput);
	 }

 }

 //Function:그룹 가입
 //Description: 그룹가입함수를 부릅니다 
 //created: 2017/5/28 23:10pm
 //Author: 장현석
 //mail: jang8018@naver.com

 //5.2 그룹 가입
 void joinGroupMember() {
	 JoinGroup *joinGroup = ControlAndCollection::GetInstance()->getJoinGroup();
	 JoinGroupUI *joinGroupUI = joinGroup->callJoinGroupUIStartInterface(*joinGroup);
	 char buf[MAX_STRING];
	 bool error;
	 //문자열을 받습니다
	 fscanf(in_fp, "%s", buf);
	 string inputGroupName(buf);

	 //가입함수 호출
	 error = joinGroupUI->selectGroup(inputGroupName, currentLoginUser);
	 if (error == true)
		 fprintf(out_fp, "5.2. Error: 존재하지않는 그룹 이름입니다.\n");
	 else
		 fprintf(out_fp, "5.2. 그룹 가입\n> %s\n", buf);

 }


 //Function:그룹 생성
 //Description: 그룹생성함수 부릅니다 
 //created: 2017/5/27 11:10pm
 //Author: 장현석
 //mail: jang8018@naver.com

 //5.3 그룹 생성
 void makeGroup() { 
	 CreateGroup *createGroup = ControlAndCollection::GetInstance()->getCreateGroup();
	 CreateGroupUI *createGroupUI = createGroup->callCreateGroupUIStartInterface(*createGroup);
	 GroupCollection *groupCollection = ControlAndCollection::GetInstance()->getGroupCollection();
	 char buf[MAX_STRING];
	 bool error;
	 //문자열을 받습니다.
	 fscanf(in_fp, "%s", buf);
	 string inputGroupName(buf);

	 //생성함수 호출
	 error=createGroupUI->setGroupName(inputGroupName, currentLoginUser);
	 if (error == true) 
		 fprintf(out_fp, "5.3. Error: 그룹을 생성할 수 없습니다.\n");
	 else
		 fprintf(out_fp, "5.3. 그룹 생성\n> %s \n", buf);

	 //groupCollection.printAllGroup();
 }

 //Function:가입그룹조회
 //Description: 가입그룹조회를 부릅니다 
 //created: 2017/5/27 11:30pm
 //Author: 장현석
 //mail: jang8018@naver.com

 //5.4 가입그룹 조회
 void show_JoinedGroup()
 {
	 ShowJoinedGroup *showJoinedGroup = ControlAndCollection::GetInstance()->getShowJoinedGroup();
	 ShowJoinedGroupUI *showJoinedGroupUI = showJoinedGroup->callShowJoinedGroupUIStartInterface(*showJoinedGroup);
	 char buf[MAX_STRING];
	 bool error;
	 string joinedGroupName;

	 error = showJoinedGroupUI->confirmView(currentLoginUser, joinedGroupName);
	 if (error == true)
		 fprintf(out_fp, "5.4. Error: 가입된 그룹이 없습니다.\n");
	 else
	 {
		 strcpy(buf, joinedGroupName.c_str());
		 fprintf(out_fp, "5.4. 가입그룹 조회\n> %s \n", buf);
	 }
 }


 //Function:그룹탈퇴
 //Description: 그룹탈퇴함수를 부릅니다 
 //created: 2017/5/27 12:10pm
 //Author: 장현석
 //mail: jang8018@naver.com

 //5.5 그룹탈퇴
 void leave_Group()
 {
	 LeaveGroup *leaveGroup = ControlAndCollection::GetInstance()->getLeaveGroup();
	 LeaveGroupUI *leaveGroupUI = leaveGroup->callJoinGroupUIStartInterface(*leaveGroup);
	 char buf[MAX_STRING];
	 bool error;
	 string joinedGroupName;

	 error = leaveGroupUI->confirmLeaveGroup(currentLoginUser, joinedGroupName);
	 if (error == true)
		 fprintf(out_fp, "5.5. Error: 그룹리더는 탈퇴할 수 없습니다.\n");
	 else
	 {
		 strcpy(buf, joinedGroupName.c_str());
		 fprintf(out_fp, "5.5. 그룹 탈퇴\n> %s \n", buf);
	 }
 }

 //6.1 현재시간설정
 //Function :void changeCurrentTIme()
 //Description : 시간을 입력받으면, 그것을 현재시간으로 설정해주는 함수.
 //Parameters : void
 //Return Value : void
 //Created : 2017/6/1 15:00 pm
 //Author : 김윤영
 void changeCurrnetTime() {
	 //Timer timer;
	 VoteCollection *currentVoteCollection = ControlAndCollection::GetInstance()->getCurrentVoteCollection();
	 VoteCollection *postVoteCollection = ControlAndCollection::GetInstance()->getPostVoteCollection();
	 VoteCollection *preVoteCollection = ControlAndCollection::GetInstance()->getPreVoteCollection();
	 char currentTime[MAX_STRING];
	 fscanf(in_fp, "%s", currentTime);

	 timer.setTime(currentTime);
	 timer.sortVote(currentVoteCollection, postVoteCollection, preVoteCollection);

	 fprintf(out_fp, "6.1. 현재시간 설정\n> %s\n", currentTime);
 }

 // 7.1 Session 변경
 //Function :void changeSession()
 //Description : 입력된 ID로 세션을 변경해 주는 함수
 //Parameters : void
 //Return Value : void
 //Created : 2017/6/1 15:00 pm
 //Author : 김윤영
 void changeSession() {
	 char ID[MAX_STRING];
	 //UserCollection userCollection = ControlAndCollection::GetInstance()->getUserCollection();

	 fscanf(in_fp, "%s \n", ID);
	 // list에서 login on 인 유저중 ID= 인것 찾기.
	// currentLoginUser = userCollection.findUser(ID);
	 fprintf(out_fp, "7.1. Session 변경\n> %s \n", ID);
 }

 // 7.2 guest Session으로 변경
 //Function :void guestSession()
 //Description : 현재 유저=guest로 변경해주는 함.
 //Parameters : void
 //Return Value : void
 //Created : 2017/6/1 15:00 pm
 //Author : 김윤영
 void guestSession() {
	 fprintf(out_fp, "7.2. guest session으로 변경\n");
	 currentLoginUser=forGuest.begin();
 }

void program_Exit() {
	fprintf(out_fp, "8.1. 종료\n");
}