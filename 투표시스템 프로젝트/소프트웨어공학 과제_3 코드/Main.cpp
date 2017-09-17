
#include"System.h"

#pragma warning(disable:4996)
using namespace std;

void doTask();
void makeAccount();			//1.1 ȸ������
void deleteAccount();		//1.2 ȸ��Ż��

void logIn();				//2.1 �α���
void logOut();				//2.2 �α׾ƿ�

void makeVote();			//3.1 ��ǥ����

void showCurrentVoteList();	//4.1 ������ǥ����Ʈ ��ȸ
void voting();				//4.2 ��ǥ
void showPostVoteList();	//4.3 ������ǥ������ ��ǥ����Ʈ ��ȸ
void showPreVoteList();		//4.4 ����� ��ǥ����Ʈ ��ȸ

void showEntireGroup();		//5.1 ��ü�׷� ��ȸ
void joinGroupMember();		//5.2 �׷찡��
void makeGroup();			//5.3 �׷����
void show_JoinedGroup();	//5.4 ���Ա׷� ��ȸ
void leave_Group();			//5.5 �׷�Ż��

void changeCurrnetTime();	//6.1 ����ð� ����
void changeSession();		//7.1 Session ����
void guestSession();		//7.2 guest Session���� ����
void program_Exit();		//8.1 ����

FILE* in_fp, *out_fp;

User guest("guest", "guest", "guest", "guest", "guest");
list<User> forGuest;
list<User>::iterator currentLoginUser; 

int main(void) {
	in_fp = fopen(INPUT_FILE_NAME, "r+");
	out_fp = fopen(OUTPUT_FILE_NAME, "w+");	;
	
	ControlAndCollection::GetInstance();		//��Ʈ�Ѱ� �ݷ����� �����մϴ�.
	forGuest.push_back(guest);
	currentLoginUser = forGuest.begin();


	doTask();
	
	return 0;
}

void doTask()
{
	// �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0;

	// ���� �޴�(8.1)�� �ԷµǱ� ������ �ݺ���
	while (menu_level_1 != 8 || menu_level_2 != 1)
	{
		// �Է����Ͽ��� �޴� ���� 2���� �б�
		fscanf(in_fp,"%d %d", &menu_level_1, &menu_level_2);
		// �޴� ���� �� �ش� ���� ����
		
		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1:   // "1.1. ȸ�����ԡ� �޴� �κ�
			{
				makeAccount();
				break;
			}
			case 2:	  // "1.2. ȸ��Ż�� �޴� �κ�
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
			case 1:   // "2.1. �α��Ρ� �޴� �κ�
			{
				logIn();
				break;
			}
			case 2:	// "2.2. �α׾ƿ��� �޴� �κ�
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
				fprintf(out_fp, "���Ե� �׷��� �����ϴ�.\n");
				break;
			}
			switch (menu_level_2)
			{
			case 1:   // "3.1. ��ǥ ���ȡ� �޴� �κ�
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
				fprintf(out_fp, "���Ե� �׷��� �����ϴ�.\n");
				break;
			}
			switch (menu_level_2)
			{
			case 1:   // "4.1. ���� ���� ���� ��ǥ ����Ʈ�� �޴� �κ�
			{
				showCurrentVoteList();
				break;
			}
			case 2:	 // "4.2. ��ǥ�� �޴� �κ�
			{
				voting();
				break;
			}
			case 3:	 // "4.3. ���� ���� ������ ��ǥ ����Ʈ�� �޴� �κ�
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
			case 1:   // "5.1. ��ü �׷� ��ȸ�� �޴� �κ�
			{
			    showEntireGroup();
				break;
			}
			case 2:   // "5.2. �׷� ���ԡ� �޴� �κ�	
			{
				joinGroupMember();
				break;
			}
			case 3:   // "5.3. �׷� ������ �޴� �κ�	
			{
				makeGroup();
				break;
			}
			case 4:   // "5.4. ���� �׷� ��ȸ�� �޴� �κ�	
			{

				show_JoinedGroup();
				break;
			}
			case 5:   // "5.5. �׷� Ż�� �޴� �κ�	
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
			case 1:   // "6.1 ����ð� ������ �޴� �κ�
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
			case 1:   // "7.1. session ���桰 �޴� �κ�
			{
				changeSession();
				break;
			}
			case 2:   // "7.2. guest sessiond���� ���桰 �޴� �κ�
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
			case 1:   // "8.1. ���ᡰ �޴� �κ�
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
  //1.1 ȸ������
  // Function : void makeAccount()
  // Description: ȸ�� ���� �ϴ� �Լ�
  // Parameters :   void
  // Return Value : void
  //
  // Created: 2017/5/29 8:30 pm
  // Author: ������
  //
 void makeAccount() {
	 Join *join = ControlAndCollection::GetInstance()->getJoin();
	 JoinUI* joinUI = ControlAndCollection::GetInstance()->getJoin()->callJoinUIStartInterface(*ControlAndCollection::GetInstance()->getJoin());
	 char name[MAX_STRING], SSN[MAX_STRING],
		 address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
	 bool error;

	 // �Է� ���� : �̸�, �ֹι�ȣ, �ּ�, ID, ��й�ȣ�� ���Ϸκ��� ����
	 fscanf(in_fp, "%s %s %s %s %s\n", name, SSN, address, ID, password);

	 error = joinUI->enterUserInfo(name, SSN, address, ID, password);

	 if (error)
		 fprintf(out_fp, "1.1. Error: �̹� �����ϴ� ID �Դϴ�.\n");
	 else
		 fprintf(out_fp, "1.1. ȸ������ \n> %s %s %s %s %s \n", name, SSN, address, ID, password);

 }
  //1.2 ȸ��Ż��
  // Function : void deleteAccount()
  // Description: ȸ�� Ż�� �ϴ� �Լ�
  // Parameters :   void
  // Return Value : void
  //
  // Created: 2017/5/30 5:08 pm
  // Author: ������
  //
 void deleteAccount() {
	 Withdrwal *withdrwal = ControlAndCollection::GetInstance()->getWithdrwal();
	 WithdrwalUI *withdrwalUI = withdrwal->callWithdrwalUIStartInterface(*withdrwal);
	 char ID[MAX_STRING];
	 bool error;

	 strcpy(ID, currentLoginUser->getUserID().c_str());
	 error = withdrwalUI->clickWithdrwal(ID);

	 if (error)
		 fprintf(out_fp, "1.2. Error: Ż���� �� ���� ȸ���Դϴ�.\n");
	 else
	 {
		 currentLoginUser = forGuest.begin();
		 fprintf(out_fp, "1.2. ȸ��Ż��\n>%s \n", ID);
	 }
 }
 
  //2.1 �α���
  // Function : void logIn()
  // Description: �α��� �ϴ� �Լ�
  // Parameters :   void
  // Return Value : void
  //
  // Created: 2017/5/30 2:30 am
  // Author: ������
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
		 fprintf(out_fp, "2.1. Error: ��ġ�ϴ� ������ �����ϴ�. \n");
	 else {
		 currentLoginUser = userCollection->findUser(ID);
		 fprintf(out_fp, "2.1. �α���\n> %s %s \n", ID, Pwd);
	 }
 }
  //2.2 �α׾ƿ�

  //Function :void logOut()
  //Description : �α׾ƿ� �ϴ� �Լ�
  //Parameters : void
  //Return Value : void
  //Created : 2017/05/30 9:38 am
  //Author : ������
 void logOut() {
	 Logout *logout = ControlAndCollection::GetInstance()->getLogout();
	 LogoutUI *logoutUI = logout->callLogoutUIStartInterface(*logout);
	 char ID[MAX_STRING];
	 strcpy(ID, currentLoginUser->getUserID().c_str());
	 logoutUI->clickLogout(ID);
	 currentLoginUser = forGuest.begin();
	 fprintf(out_fp, "2.2. �α׾ƿ�\n> %s\n", ID);

 }
  //3.1 ��ǥ ����
  //Function :void makeVote()
  //Description : ��ǥ ���� ����� ���� input ���� �����ϰ� output ���� �޾� ����Ѵ�.
  //Parameters : void
  //Return Value : void
  //Created : 2017/6/1 15:00 pm
  //Author : ������
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
		fprintf(out_fp, "3.1. ��ǥ ���� �ð��� ���� �ð����� ���Ŀ��� �մϴ�.\n");
	}
	else
	{
		error = createVoteUI->inputDate(subject, numberOfItems, startTime, endTime, currentLoginUser->getJoinedGroup());
		if (error)
			fprintf(out_fp, "3.1. ������ �׸��� �ֽ��ϴ�. \n");
		else {
			fprintf(out_fp, "3.1. ��ǥ ����\n");
			fprintf(out_fp, "%s %d %s %s\n", subject, numberOfItems, startTime, endTime);

		}
	}
 }
 //4.1 ���� �������� ��ǥ ��ȸ

 //Function: ���� �������� ��ǥ ��ȸ
 //Description: �Լ� 
 //created: 2017/5/24 22:00pm
 //Author: ȫ����
 //mail: bcdass@naver.com

 //Function: ���� �������� ��ǥ ��ȸ
 //Description: �Լ� ����
 //created: 2017/5/31 10:30pm
 //Author: ȫ����
 //mail: bcdass@naver.com

 void showCurrentVoteList()
 {
	 CurrentVoteList* currentVoteList = ControlAndCollection::GetInstance()->getCurrentVoteList();
	 CurrentVoteListUI* currentVoteListUI = currentVoteList->callCurrentVoteListUIStartInterface(*currentVoteList);

	 string subject[MAX_STRING], endTime[MAX_STRING], startTime[MAX_STRING], belongsTo[MAX_STRING];
	 int items[MAX_STRING];
	 currentVoteListUI->confirmView(subject, items, startTime, endTime, belongsTo);

	 fprintf(out_fp, "4.1. ���� ���� ���� ��ǥ ����Ʈ\n");
	 for (int i = 0; subject[i].size() != 0; i++) {
		 char temp1[MAX_STRING];
		 strcpy(temp1, belongsTo[i].c_str());
		 if (currentLoginUser->getJoinedGroup() == temp1) {
			 
			 char forOutput1[MAX_STRING];
			 int forOutput2, compare[5];
			 int endTimeTokenInt[5], currentTimeTokenInt[5];
			 //����ð� �Ľ�
			 timer.passingTime(timer.getTime(), currentTimeTokenInt);
			 strcpy(forOutput1, subject[i].c_str());
			 forOutput2 = items[i];
			 // strcpy(forOutput3, endTime[i].c_str());
			 //����ð� �Ľ�
			 timer.passingTime(endTime[i], endTimeTokenInt);
			 //�ð� ��
			 timer.compareTime(compare, endTimeTokenInt, currentTimeTokenInt);
			 timer.plusTime(compare);
			 fprintf(out_fp, "> %s %d %d:%d:%d:%d:%d \n", forOutput1, forOutput2, compare[0], compare[1], compare[2], compare[3], compare[4]);
		 }
	 }
 }

 //4.2 ��ǥ
 //Function :void voting()
 //Description : ��ǥ ����� ���� input ���� �����ϰ� output ���� �޾� ����Ѵ�.
 //Parameters : void
 //Return Value : void
 //Created : 2017/6/1 15:00 pm
 //Author : ������
 void voting() {
	 VoteFor *voteFor = ControlAndCollection::GetInstance()->getVoteFor();
	 VoteForUI *voteForUI = voteFor->callVoteForUIStartInterface(*voteFor);
	 char subject[MAX_STRING];
	 int itemNumber;
	 int error;

	 fscanf(in_fp, "%s %d \n", subject, &itemNumber);

	 error = voteForUI->inputData(subject, itemNumber, currentLoginUser->getJoinedGroup(), currentLoginUser->getPersonalNumber());

	 if (error==0) {
		 fprintf(out_fp, "4.2. ���� ��ǥ �����̰ų� �׸��ȣ�� �߸��Ǿ����ϴ�. \n");
	 }
	 else if (error == 1) {
		 fprintf(out_fp, "4.2. �̹� ��ǥ�Ͽ����ϴ�. \n");
	 }
	 else if(error==2) {
		 fprintf(out_fp, "4.2. ��ǥ\n");
		 fprintf(out_fp, "%s %d\n", subject, itemNumber);
	 }
 }
 
 //Function: ���� ���� ������ ��ǥ����Ʈ ��ȸ
 //Description: �Լ� 
 //created: 2017/5/24 22:00pm
 //Author: ȫ����
 //mail: bcdass@naver.com

 //4.3 ���� ���� ������ ��ǥ ����Ʈ
 void showPostVoteList()
 {
	 PostVoteList *postVoteList = ControlAndCollection::GetInstance()->getPostVoteList();
	 PostVoteListUI* postVoteListUI = postVoteList->callPostVoteListUIStartInterface(*postVoteList);

	 string subject[MAX_STRING], endTime[MAX_STRING], startTime[MAX_STRING], belongsTo[MAX_STRING];
	 int items[MAX_STRING];

	 postVoteListUI->confirmView(subject, items, startTime, endTime, belongsTo);

	 fprintf(out_fp, "4.3. ���� ���� ������ ��ǥ ����Ʈ\n");
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

 //Function:����� ��ǥ ��ȸ
 //Description: �Լ� 
 //created: 2017/5/24 22:00pm
 //Author: ȫ����
 //mail: bcdass@naver.com

 //4.4 ����� ��ǥ ��ȸ
 void showPreVoteList()
 {
	 PreVoteList *preVoteList = ControlAndCollection::GetInstance()->getPreVoteList();
	 PreVoteListUI* preVoteListUI = preVoteList->callPreVoteListUIStartInterface(*preVoteList);
	 
	 string subject[MAX_STRING], endTime[MAX_STRING], startTime[MAX_STRING], belongsTo[MAX_STRING];
	 int items[MAX_STRING], *result[MAX_STRING];

	 preVoteListUI->confirmView(subject, items, startTime, endTime, belongsTo, result);

	 fprintf(out_fp, "4.4. ����� ��ǥ ����Ʈ\n"); 
	 
	  for (int i = 0; subject[i].size() != 0; i++) {
		 //timer���� 4�� �ð��� ������ �����ٴ� ���� UI�� �˷��ش�

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


 //Function:��ü�׷� ��ȸ
 //Description: ��ü�׷���ȸ�Լ��� �θ��ϴ� 
 //created: 2017/5/28 23:00pm
 //Author: ������
 //mail: jang8018@naver.com

 //5.1 ��ü �׷� ��ȸ
 void showEntireGroup() {
	 ShowAllGroup *showAllGroup = ControlAndCollection::GetInstance()->getShowAllGroup();
	 ShowAllGroupUI *showAllGroupUI = showAllGroup->callShowAllGroupUIStartInterface(*showAllGroup);
	 string groupList[MAX_STRING];

	 showAllGroupUI->confirmView(groupList);

	 fprintf(out_fp, "5.1. ��ü�׷� ��ȸ\n");
	 for (int i = 0; groupList[i].size() != 0; i++) {
		 char forOutput[MAX_STRING];
		 strcpy(forOutput, groupList[i].c_str());
		 fprintf(out_fp, "> %s \n", forOutput);
	 }

 }

 //Function:�׷� ����
 //Description: �׷찡���Լ��� �θ��ϴ� 
 //created: 2017/5/28 23:10pm
 //Author: ������
 //mail: jang8018@naver.com

 //5.2 �׷� ����
 void joinGroupMember() {
	 JoinGroup *joinGroup = ControlAndCollection::GetInstance()->getJoinGroup();
	 JoinGroupUI *joinGroupUI = joinGroup->callJoinGroupUIStartInterface(*joinGroup);
	 char buf[MAX_STRING];
	 bool error;
	 //���ڿ��� �޽��ϴ�
	 fscanf(in_fp, "%s", buf);
	 string inputGroupName(buf);

	 //�����Լ� ȣ��
	 error = joinGroupUI->selectGroup(inputGroupName, currentLoginUser);
	 if (error == true)
		 fprintf(out_fp, "5.2. Error: ���������ʴ� �׷� �̸��Դϴ�.\n");
	 else
		 fprintf(out_fp, "5.2. �׷� ����\n> %s\n", buf);

 }


 //Function:�׷� ����
 //Description: �׷�����Լ� �θ��ϴ� 
 //created: 2017/5/27 11:10pm
 //Author: ������
 //mail: jang8018@naver.com

 //5.3 �׷� ����
 void makeGroup() { 
	 CreateGroup *createGroup = ControlAndCollection::GetInstance()->getCreateGroup();
	 CreateGroupUI *createGroupUI = createGroup->callCreateGroupUIStartInterface(*createGroup);
	 GroupCollection *groupCollection = ControlAndCollection::GetInstance()->getGroupCollection();
	 char buf[MAX_STRING];
	 bool error;
	 //���ڿ��� �޽��ϴ�.
	 fscanf(in_fp, "%s", buf);
	 string inputGroupName(buf);

	 //�����Լ� ȣ��
	 error=createGroupUI->setGroupName(inputGroupName, currentLoginUser);
	 if (error == true) 
		 fprintf(out_fp, "5.3. Error: �׷��� ������ �� �����ϴ�.\n");
	 else
		 fprintf(out_fp, "5.3. �׷� ����\n> %s \n", buf);

	 //groupCollection.printAllGroup();
 }

 //Function:���Ա׷���ȸ
 //Description: ���Ա׷���ȸ�� �θ��ϴ� 
 //created: 2017/5/27 11:30pm
 //Author: ������
 //mail: jang8018@naver.com

 //5.4 ���Ա׷� ��ȸ
 void show_JoinedGroup()
 {
	 ShowJoinedGroup *showJoinedGroup = ControlAndCollection::GetInstance()->getShowJoinedGroup();
	 ShowJoinedGroupUI *showJoinedGroupUI = showJoinedGroup->callShowJoinedGroupUIStartInterface(*showJoinedGroup);
	 char buf[MAX_STRING];
	 bool error;
	 string joinedGroupName;

	 error = showJoinedGroupUI->confirmView(currentLoginUser, joinedGroupName);
	 if (error == true)
		 fprintf(out_fp, "5.4. Error: ���Ե� �׷��� �����ϴ�.\n");
	 else
	 {
		 strcpy(buf, joinedGroupName.c_str());
		 fprintf(out_fp, "5.4. ���Ա׷� ��ȸ\n> %s \n", buf);
	 }
 }


 //Function:�׷�Ż��
 //Description: �׷�Ż���Լ��� �θ��ϴ� 
 //created: 2017/5/27 12:10pm
 //Author: ������
 //mail: jang8018@naver.com

 //5.5 �׷�Ż��
 void leave_Group()
 {
	 LeaveGroup *leaveGroup = ControlAndCollection::GetInstance()->getLeaveGroup();
	 LeaveGroupUI *leaveGroupUI = leaveGroup->callJoinGroupUIStartInterface(*leaveGroup);
	 char buf[MAX_STRING];
	 bool error;
	 string joinedGroupName;

	 error = leaveGroupUI->confirmLeaveGroup(currentLoginUser, joinedGroupName);
	 if (error == true)
		 fprintf(out_fp, "5.5. Error: �׷츮���� Ż���� �� �����ϴ�.\n");
	 else
	 {
		 strcpy(buf, joinedGroupName.c_str());
		 fprintf(out_fp, "5.5. �׷� Ż��\n> %s \n", buf);
	 }
 }

 //6.1 ����ð�����
 //Function :void changeCurrentTIme()
 //Description : �ð��� �Է¹�����, �װ��� ����ð����� �������ִ� �Լ�.
 //Parameters : void
 //Return Value : void
 //Created : 2017/6/1 15:00 pm
 //Author : ������
 void changeCurrnetTime() {
	 //Timer timer;
	 VoteCollection *currentVoteCollection = ControlAndCollection::GetInstance()->getCurrentVoteCollection();
	 VoteCollection *postVoteCollection = ControlAndCollection::GetInstance()->getPostVoteCollection();
	 VoteCollection *preVoteCollection = ControlAndCollection::GetInstance()->getPreVoteCollection();
	 char currentTime[MAX_STRING];
	 fscanf(in_fp, "%s", currentTime);

	 timer.setTime(currentTime);
	 timer.sortVote(currentVoteCollection, postVoteCollection, preVoteCollection);

	 fprintf(out_fp, "6.1. ����ð� ����\n> %s\n", currentTime);
 }

 // 7.1 Session ����
 //Function :void changeSession()
 //Description : �Էµ� ID�� ������ ������ �ִ� �Լ�
 //Parameters : void
 //Return Value : void
 //Created : 2017/6/1 15:00 pm
 //Author : ������
 void changeSession() {
	 char ID[MAX_STRING];
	 //UserCollection userCollection = ControlAndCollection::GetInstance()->getUserCollection();

	 fscanf(in_fp, "%s \n", ID);
	 // list���� login on �� ������ ID= �ΰ� ã��.
	// currentLoginUser = userCollection.findUser(ID);
	 fprintf(out_fp, "7.1. Session ����\n> %s \n", ID);
 }

 // 7.2 guest Session���� ����
 //Function :void guestSession()
 //Description : ���� ����=guest�� �������ִ� ��.
 //Parameters : void
 //Return Value : void
 //Created : 2017/6/1 15:00 pm
 //Author : ������
 void guestSession() {
	 fprintf(out_fp, "7.2. guest session���� ����\n");
	 currentLoginUser=forGuest.begin();
 }

void program_Exit() {
	fprintf(out_fp, "8.1. ����\n");
}