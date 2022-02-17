#include <iostream>
using namespace std;

int counter_student, counter_book, Student[100][6], Book[100][6], bookData[100];

int year, month, day;

void menu();
void libraryOfficer();
void libraryStudent();
void addBookFirst();
void service();
void student(int, int, int, int);
void addStuedent(int);
void book(int, bool, int, int, bool);
void addBook(int);
bool delay_t(int, int, int);
void sortBook();
void sortStudent();
void deleteStudent(int);
void changepass(int);
void extendBook(int, int);
void convertDate(int [], int);
int date();
void printStudentData();
void printBookData();
int searchStudent(int);
int searchBook(int);
int delay(int, int, int);

//اطلاعات دانشجو به صورت زیر ذخیره میشود
//Student[i][1] = user student;
//Student[i][1] = pass;
//Student[i][2] = shabak;
//Student[i][3] = date trust;
//Student[i][4] = date return;
//Student[i][5] = delay;

//اطلاعات کتاب به صورت زیر ذخیره میشود
//Book[i][0] = shabk;
//Book[i][1] = entity;0=entity,1=not entity
//Book[i][2] = date1;
//Book[i][3] = date2;
//Book[i][5] = extend;0=not extend ,1=extend
//Book[i][4] = delay;

int main() {

	cout << endl << "***************************** WElCOME TO YOUR LIBRARY *****************************" << endl;
	addBookFirst();
	system("cls");
	menu();
}

void menu() {

	int choice;
	bool continuemenu = true;

	while (continuemenu) {
		//مرتب سازی لیست کتاب ها و دانشجویان
		sortBook();
		sortStudent();

		cout << endl << "***************************** UNIVERSITY LIBRARY *****************************" << endl;
		cout << "Login as :" << endl << "1)library officer" << endl << "2)student" << endl << "3)Exit" << endl << "your choice(just int) : ";
		cin >> choice;
		system("cls");

		switch (choice) {
		case 1: {
			libraryOfficer();
			break;
		}

		case 2: {
			libraryStudent();
			break;
		}

		case 3: {
			continuemenu = false;
		}

		default: {
			cout << "please enter your correct choice .";
		}
		}
	}
}

//اختیارات مسئول کتابخانه
void libraryOfficer() {
	
	bool continuecase1 = true;
	int choice1, choice2;
	while (continuecase1) {
		sortBook();
		sortStudent();

		char user[5];
		int pass;

		cout << endl << "***************************** UNIVERSITY LIBRARY *****************************" << endl;
		cout << "0)return " << endl << "1)continue" << endl << "your choice(just int) : ";
		cin >> choice1;
		system("cls");

		if (choice1 == 1) {
			cout << "user name :";
			for (int i = 0; i < 5; i++)
				cin >> user[i];

			cout << endl << "password(just int) :";
			cin >> pass;

			system("cls");

			if (user[0] == 'a'&&user[1] == 'd'&&user[2] == 'm'&&user[3] == 'i'&&user[4] == 'n' && pass == 123) {
				bool continueif = true;

				while (continueif) {
					cout << endl << "***************************** UNIVERSITY LIBRARY *****************************" << endl;
					cout <<"1)Student Services"<<endl<<  "2)Add student" << endl << "3)Add new book" << endl << "4)search student and show details";
					cout << endl << "5)delete student" << endl << "6)change the student password" << endl;
					cout << "7)search book and show details" << endl << "8)book extension" << endl << "9)List of books" << endl;
					cout << "10)List of students " << endl << "11)return" << endl << endl << "your choice(just int) : ";
					cin >> choice2;
					system("cls");

					if (choice2 == 1) {
						service();
						system("cls");
					}

					else if (choice2 == 2) {
						int id;
						cout << endl << "New member user name(student number)(just int) :";
						cin >> id;
						addStuedent(id);

					}

					else if (choice2 == 3) {
						int shabak;
						cout << "shbak book(just int) :";
						cin >> shabak;
						addBook(shabak);

					}

					else if (choice2 == 4) {
						int id;
						cout << "enter user name student(number student)(just int) :";
						cin >> id;
						int i = searchStudent(id);
						if (i == -1)
							cout << endl << "Not found ! ";
						else {
							if (Student[i][0] != NULL)
								cout << "student number :" << Student[i][0] << endl;
							if (Student[i][1] != NULL)
								cout << "shabak :" << Student[i][2] << endl;
							if (Student[i][2] != NULL)
								cout << "borrowing book date :" << Student[i][2] << endl;
							if (Student[i][3] != NULL)
								cout << "come back book date :" << Student[i][3] << endl;
							if (Student[i][4] != NULL)
								cout << "The amount of debt to the library :" << Student[i][4] << endl;
						}
					}

					else if (choice2 == 5) {
						int id;
						cout << "enter user name student(number student)for delete student(just int) :";
						cin >> id;
						deleteStudent(id);
					}

					else if (choice2 == 6) {
						int id;
						cout << "enter user name student(number student)for change password(just int) :";
						cin >> id;
						changepass(id);
					}

					else if (choice2 == 7) {
						int shabak;
						cout << "enter shabak book(just int) :";
						cin >> shabak;
						int i = searchBook(shabak);
						if (i == -1)
							cout << endl << "Not found !";
						else {
							if (Book[i][0] != NULL)
								cout << "shabak :" << Book[i][0] << endl;
							if (Book[i][1] != NULL)
								if (Book[i][1])
									cout << endl << "book is entity";
								else
									cout << endl << "book is not entity";
							if (Book[i][2] != NULL)
								cout << "borrowing book date :" << Book[i][2] << endl;
							if (Book[i][3] != NULL)
								cout << "come back book date :" << Book[i][3] << endl;
							if (Book[i][4] != NULL)
								cout << "The amount of penalties a student can have for delaying the return of this library :" << Book[i][4] << endl;
						}

					}

					else if (choice2 == 8) {
						int id, shabak;
						cout << "enter student number for book extention(just int) :";
						cin >> id;
						cout << "enter shabak(just int) :";
						cin >> shabak;
						extendBook(id, shabak);

					}

					else if (choice2 == 9) {
						printBookData();
					}

					else if (choice2 == 10) {
						printStudentData();
					}

					else if (choice2 == 11) {
						continuecase1 = continueif = false;

					}
					else
						cout << "your choice is wrong.please enter your correct choice .";

				}
			}
			else
				cout << "the information entered is incorrect .";

		}
		else if (choice1 == 0) {
			continuecase1 = false;
		}

		else
			cout << endl << "please enter your correct choice ...";
	}
}

//اختیارات دانشجو
void libraryStudent() {
	bool continuecase2 = true, continueif = true;
	int choice1, choice2, userStudent, pass;

	while (continuecase2) {

		cout << endl << "***************************** UNIVERSITY LIBRARY *****************************" << endl;
		cout << endl << "1)continue" << endl << "0)return" << endl << "your choice(just int) : ";
		cin >> choice1;
		system("cls");

		if (choice1 == 1) {

			cout << endl << "***************************** UNIVERSITY LIBRARY *****************************" << endl;
			cout << "user name(student number)(just int) :";
			cin >> userStudent;
			cout << endl << "password(just int) :";
			cin >> pass;
			system("cls");

			int i = searchStudent(userStudent);

			
			if (i != -1 && Student[i][1] == pass) {
				while (continueif) {
					cout << endl << "***************************** UNIVERSITY LIBRARY *****************************" << endl;
					cout << "1)search book and show details" << endl << "2)change your password" << endl << "3)List of book " << endl << "4)return" << endl;
					cout << endl << "your choice(just int) :";
					cin >> choice2;
					system("cls");

					if (choice2 == 1) {

						int shabak;
						cout << "shabk(just int) :";
						cin >> shabak;
						int i = searchBook(shabak);
						if (i == -1)
							cout << endl << "Not found !";
						else {
							if (Book[i][0] != NULL)
								cout << "ahabak :" << Book[i][0] << endl;
							if (Book[i][1] != NULL)
								if (Book[i][1])
									cout << endl << "The book is entity";
								else
									cout << endl << "The book is not entity";
							if (Book[i][2] != NULL)
								cout << "borrowing book date :" << Book[i][2] << endl;
							if (Book[i][3] != NULL)
								cout << "come back book detail :" << Book[i][3] << endl;
							if (Book[i][4] != NULL)
								cout << "The amount of penalties a student should have for delaying the return of this library :" << Book[i][4] << endl;
						}

					}

					else if (choice2 == 2) {
						changepass(userStudent);
					}

					else if (choice2 == 3) {
						printBookData();
					}

					else if (choice2 == 4) {
						continueif = continuecase2 = false;
					}
					else
						cout << "your choice is incorrect ...";
				}
			}
				else
					cout << "The information entered for log in is incorrect .";
			
		
}
		else if (choice1 == 0)
			continuecase2 = false;
		else
			cout << "please enter your correct choice :";

	}
}

//افزودن کتاب هنگام ورود
void addBookFirst() {
	int x, shabak;
	bool continueAddBook = true;
	
	cout << endl << "Enter 5 books to enter the program...";
	cout << endl << "***************************** UNIVERSITY LIBRARY *****************************" << endl;
	cout <<endl<< "shabak book(just int) : ";

	cin >> shabak;
	Book[0][0] = shabak;
	counter_book++;
	cout << endl << "the book is add to system ...";

	while (continueAddBook) {
		
		cout << endl << "***************************** UNIVERSITY LIBRARY *****************************" << endl;
		cout <<endl<< "shabak book(just int) : ";
		cin >> shabak;
		addBook(shabak);
		cout << endl << endl << counter_book << " the book is added to system ...";

		if (counter_book > 4) {
			cout << endl << endl << "If you no longer wish to add another book, enter (0) ";
			cout << endl << "and for add other new book enter other key(just int) :";
			cin >> x;

			if (x == 0)
				continueAddBook = false;
		}
	}
}

//امانت دادن کتاب
void trust() {
	int shabak, id;
	cout << endl << endl << "enter user student for trust book : ";
	cin >> id;
	cout << endl << "enter shabak book for trust book : ";
	cin >> shabak;
	int i = searchBook(shabak);
	int j = searchStudent(id);

	if (i == -1)
		cout << "book not found";
	else if (j == -1)
		cout << "student not found";
	else if (Student[j][2] != 0)
		cout << "It is a student loan book";
	else{
		if (Book[i][1] == 0) {
			Book[i][1] = 1;
			Student[j][2] = shabak;
			cout << endl << "Enter the borrowing date of the book " << endl;
			Book[i][2] = Student[j][3] = date();
			Book[i][3] = Student[j][4] = 0;
			cout << endl << "The book was loaned to the student concerned ...";
		}
		else
			cout << endl << "The book is not entity";
	}
	
}

//بازگشت زدن کتاب
void returnBook() {
	system("cls");
	int shabak, id;
	cout << endl << "***************************** UNIVERSITY LIBRARY *****************************" << endl;
	cout << endl << endl << "enter user student for return book : ";
	cin >> id;
	cout << endl << "enter shabak book for return book : ";
	cin >> shabak;
	int i = searchBook(shabak);
	int j = searchStudent(id);

	if (i == -1)
		cout << "book not found !!!";
	else if (j == -1)
		cout << "student not found !!!";
	else if (Student[j][2] != shabak)
		cout << "This book is not in trust for this student !!!";
	else {
		if (Book[i][1]==1) {
			Book[i][1] = 0;
			Student[j][2] = 0;
			cout << endl << "Enter the return date of the book ..." << endl;
			int Date = date();
			Book[i][3] = Student[j][4] = Date;
			Book[i][5] = 0;
			Student[i][5] = Student[i][5] + delay(Student[i][3], Date, Book[j][5]);
		
			cout << endl << "The book was returned to the library ...";
		}
		else
			cout << endl << "The book is not in extend !!!";
	}
}

//تابع تمدید کتاب
void extendBook(int id, int shabak) {
	int date[3];//date[0]=day , date[1]=month , date[2]=year
	int j = searchStudent(id);
	int i = searchBook(shabak);
	if ((i == -1 || j == -1 || Student[j][2] != shabak)) {
		cout << endl << "Shabak or student number is incorrect !!!";
	}
	else {
		if (Book[i][5] == 1)
			cout << endl << "This book has been extended once !!!";
		else {
			convertDate(date, Book[i][2]);
			if (31 - date[0] <= 10) {
				date[0] = 10 - (31 - date[0]);
				if (date[1] == 12) {
					date[1] = 01;
					date[2]++;
				}
				else
					date[1]++;
			}
			else {
				date[0] = date[0] + 10;
				Book[i][5] = 1;
				Book[i][2] = Student[j][3] = date[2] * 1000 + date[1] * 100 + date[0];
			}

			cout << endl << "Your book is extend .";

		}
	}
}

//خدمات مربوط به دانشجو 
void service() {
	
	int userStudent, shabak, choice;
	bool continueService = true;
	while (continueService) {
		cout << endl << "***************************** UNIVERSITY LIBRARY *****************************" << endl;
		cout << endl << "1)extend book" << endl << "2)trust book" << endl << "3)return book" << endl << "4)Check late";
		cout << endl << "5)return" << endl << "enter your choice : ";
		cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			cout << endl << "***************************** UNIVERSITY LIBRARY *****************************" << endl;
			cout << endl << endl << "enter user student for extend : ";
			cin >> userStudent;
			cout << endl << "enter shabak book for extend : ";
			cin >> shabak;
			extendBook(userStudent, shabak);
			break;
		}

		case 2: {
			system("cls");
			cout << endl << "***************************** UNIVERSITY LIBRARY *****************************" << endl;
			
			trust();
			break;
		}
		case 3: {
			
			returnBook();
			break;
		}
		case 4: {
			system("cls");
			cout << endl << "***************************** UNIVERSITY LIBRARY *****************************" << endl;
			int choice2, shabak, i, id;
			cout << "1)late book review" << endl << "2)late student review" << endl << "3)The amount of student debt" << endl << "enter your choice : ";
			cin >> choice2;
			if (choice2 == 1) {
				cout << endl << "enter shabak book for review :";
				cin >> shabak;
				i = searchBook(shabak);
				if (i == -1)
					cout << "book is not found !!!";
				
				else {
					cout << endl << "enter date today for review ...";
					int t2 = date();
					if (delay_t(Book[i][2], t2, Book[i][5]))
						cout << endl << "Student has delayed returning this book !!!";
					else
						cout << endl << "Student has <not> delayed returning this book !!!";
				}

			}
			else if (choice2 == 2) {
				cout << endl << "enter student number for review : ";
				cin >> id;
				cout << "enter shabak book :";
				cin >> shabak;

				i = searchStudent(id);
				int j = searchBook(shabak);
				if (i == -1)
					cout << endl << "student or book not found or student user and shabak is incorrect !!!";
				else if (j == -1)
					cout << endl << "Book not found !!!";
				else if (Student[i][2] != shabak)
					cout << endl << "This book is not in trust for this student";
				else {
					cout << endl << "enter date today for review ...";
					int t2 = date();
					if (delay_t(Student[i][3], t2, Book[j][5])) {
						cout << endl << "Student has delayed returning this book !!!";
						
					}

					else
						cout << endl << "Student has <not> delayed returning this book !!!";
				}
			}
			else if (choice2 == 3) {
				cout << endl << "enter user student : ";
				cin >> id;
				int i = searchStudent(id);
				if (i == -1)
					cout << "Student not found !!!";
				else if (Student[i][5] != 0) {
					cout << endl << "The amount of student debt = " << Student[i][5];
				}
				else
					cout << endl << "The amount of student debt = 0";
			}
			else
				cout << endl << "your choice is incorrect";
			break;
		}
		case 5: {

			continueService = false;
			break;
		}
		default:
			cout << "your choice is incorrect";
		}
	}
}

//تابعی برای تبدیل شکل تاریخ از حالت 13980201 به روز و ماه و سال و ذخیره در ارایه ی ورودی
void convertDate(int A[3],int date) {
	A[0] = date % 100;
	date = date / 100;
	A[1] = date % 100;
	A[2] = date / 100;

}

//افزودن دانشجو*
void addStuedent(int id) {
	int pass;
	if (counter_student == 0) {
		cout << endl << "enter a password for new member :";
		cin >> pass;
		
		Student[counter_student ][0] = id;
		Student[counter_student ][1] = pass;
		counter_student++;

		cout << "new member add to system ...";
	}
	else {
		int i = searchStudent(id);
		if (i == -1) {
			cout << endl << "enter a password for new member :";
			cin >> pass;
			Student[counter_student][0] = id;
			Student[counter_student][1] = pass;
			counter_student++;
			cout << "new member add to system .";
		}
		else
			cout << "There is a member with similar student number .";
	}
}

//افزودن کتاب
void addBook(int shabak) {

	int i = searchBook(shabak);

	if (i == -1) {
		Book[counter_book][0] = shabak;
		counter_book++;
		cout << "New book is add";
	}
	else
		cout << "There is a book with similar shabak !!!";
}

//جستجوی دانشجو
int searchStudent(int id) {
	for (int i = 0; i <= counter_student; i++) {
		if (Student[i][0] == id)
			return i;
		else if (i == counter_student )
			return -1;
	}
}

//جستجوی کتاب
int searchBook(int shabak) {
	for (int i = 0; i <= counter_book; i++) {
		if (Book[i][0] == shabak)
			return i;
		else if (i == counter_book )
			return -1;
	}
}

//محاسبه جریمه دیرکرد
int delay(int t1, int t2, int tamdid) {
	int A[3];
	
	if (delay_t(t1, t2, tamdid)) {
		if (tamdid==1) {
			convertDate(A, t2 - (t1 + 10));
		}
		else {
			convertDate(A, t2 - (t1 + 15));
		}
		return (A[2] * 365 + A[1] * 30 + A[0]) * 1000;
	}
	else
		return 0;
}

//بررسی دیرکرد
bool delay_t(int t1, int t2, int tamdid) {
	if (tamdid == 1) {
		if (t2 - t1 > 10)
			return true;
	}
	else
		if (t2 - t1 > 15)
			return true;
	return false;
}

//مرتب سازی کتاب ها بر اساس شابک
void sortBook() {
	int temp;
	for (int i = counter_book - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (Book[j][0] > Book[j + 1][0])
				for (int k = 0; k < 5; k++) {
					temp = Book[j][k];
					Book[j][k] = Book[j + 1][k];
					Book[j + 1][k] = temp;
				}

}

//مرتب سازی دانشجویان بر اساس شماره دانشجویی
void sortStudent() {
	int temp;
	for (int i = counter_student - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (Student[j][0] > Student[j + 1][0])
				for (int k = 0; k < 6; k++) {
					temp = Student[j][k];
					Student[j][k] = Student[j + 1][k];
					Student[j + 1][k] = temp;
				}

}

//تابع حذف یک دانشجو*
void deleteStudent(int id) {
	int i = searchStudent(id);
	if (i != -1) {
		for (int j = i; j < counter_student; j++)
			for (int k = 0; k < 6; k++)
				Student[j][k] = Student[j + 1][k];
		cout << endl << "the student deleted ...";
	}
	else
		cout << endl << "Not found the student";
}

//تابع تغییر پسوورد*
void changepass(int id) {
	int i = searchStudent(id), newpass;

	if (i == -1) {
		cout << "Not found the student ...";
	}

	else {
		cout << "Please enter new password(just int) :";
		cin >> newpass;
		Student[i][1] = newpass;
		cout << "password changed ...";
	}
		

}

//تابع دریافت تاریخ 
int date() {
	int x, y, z;
	bool t = true;
	cout << endl << "day(just int) : ";
	cin >> x;
	cout << endl << "month(just int) :";
	cin >> y;
	cout << endl << "year(just int) :";
	cin >> z;

	while (t) {
		if (x >= 1 && x <= 31 && y >= 1 && y <= 12 && z >= 1398) {
			day = x;
			month = y;
			year = z;
			cout << endl << "date was recorded..." << endl;
			t = false;
		}
		
		else {
			cout << "the date is incorrect .1<=day<=31 , 1<=month<=12 , 1398<=year .enter true date " << endl;
			cout << endl << "day(just int) : ";
			cin >> x;
			cout << endl << "month(just int) :";
			cin >> y;
			cout << endl << "year(just int) :";
			cin >> z;
		}
		
	}
	return year * 10000 + month * 100 + day;
}

//چاپ لیست کتاب ها
void printBookData() {
	for (int i = 0; i < counter_book; i++) {
		cout << endl << i+1 << " )";
		cout << endl << "shabk : " << Book[i][0];
		cout << endl << "entity : " << Book[i][1];
		cout << endl << "Lending date : " << Book[i][2];
		cout << endl << "Return date : " << Book[i][3];
		cout << endl << "debt for this book : " << Book[i][4];
		cout << endl << "**********************************************" << endl;
	}
}

//چاپ لیست دانشجویان عضو کتابخانه
void printStudentData() {
	for (int i = 0; i < counter_student; i++) {
		cout <<endl<< i+1 << " )";
		cout << endl << "student number(user name) : " << Student[i][0];
		cout << endl << "shabk loan book taken : " << Student[i][2];
		cout << endl << "Lending date : " << Student[i][3];
		cout << endl << "Return date : " << Student[i][4];
		cout << endl << "Debt to Library : " << Student[i][5];
		cout << endl << "**********************************************" << endl;
		
	}
}