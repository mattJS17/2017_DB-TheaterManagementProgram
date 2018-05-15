#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlda.h>
#include <sqlcpr.h>

EXEC SQL INCLUDE SQLCA;

EXEC SQL BEGIN DECLARE SECTION;

char * username = "s15010979";
char * password = "database979";
VARCHAR userID[20];

int movieID;
int peoNum;
int umovieID;
int upeoNum;

VARCHAR MovieOpenDate[44];

VARCHAR InsertMovieName[40];
VARCHAR InsertMovieDirector[30];
VARCHAR InsertMovieOpenDate[20];


struct smenu {
	char name[20];
	char mname[20];
	int price;
};
struct movie_screen {
	int movieid;
	char title[40];
	char dname[30];
	char date[10];
};
struct menu_res {
	char memid[20];
	int rid;
	char date[10];
	int rnum;
};
struct movie_time {
	int tid;
	int movieid;
	char tname[20];
	char date[10];
};
struct movie_res {
	char memid[20];
	int tid;
	int peonum;
};
struct movie_score {
	char memid[20];
	int mid;
	int score;
};
struct goods_res {
	int gid;
	char memid[20];
	char resdate[10];
	char duedate[10];
	int gnum;
};
struct res {
	char memid[20];
	int cnt;
};
struct smenu * menuPtr;
struct movie_screen * moviescreenPtr;
struct menu_res * menuresPtr;
struct movie_time * movietimePtr;
struct movie_res * movieresPtr;
struct movie_score * moviescorePtr;
struct goods_res * goodsresPtr;
struct movie_screen * rmsPtr;
struct movie_res * mrPtr;
struct res * grPtr;
struct res * songPtr;
struct res * gnPtr;
struct res * gradePtr;
struct res * resnumPtr;
struct res * resdownPtr;
struct res * avgPtr;
struct res * saPtr;
char rmemid[20];
char miamimid[40];
/*     User Table Structure    */

struct stheater {
	char tName[20];
	char tPlace[20];
};
struct goods {
	int gid;
	char gname[20];
	int gnum;
};
struct members {
	char memid[20];
	char memname[20];
	char membirth[20];
	char memgrade[20];
	char mempnum[20];
	int memreserve;
};
struct restaurant {
	int resid;
	char resname[20];
	int downpayment;
	char theatername[20];
};
struct movie_scheduled {
	int movieid;
	char movietitle[40];
	char directorname[30];
	char opendate[20];
};
struct employee {
	int empid;
	char empname[20];
	char empbirth[20];
	char emppos[20];
	char emppnum[20];
	char theatername[20];
};
struct music {
	char musictitle[20];
	char singer[20];
};

struct stheater * theaterPtr;
struct goods * goodsPtr;
struct members * membersPtr;
struct restaurant * restaurantPtr;
struct movie_scheduled * movie_scheduledPtr;
struct movie_scheduled * msPtr, *msPtr2;
struct employee * employeePtr;
struct music * musicPtr;
struct members * rmemPtr;
struct members * rmem1Ptr;
struct members * rmem2Ptr;
struct stheater * tPtr;
struct stheater * t1Ptr;
struct stheater * t2Ptr;
/*     Manager Table Structure    */

struct ticket {
	char mtitle[40];
	int cnt;
};
struct ticket * ticketPtr;
struct ticket * scorePtr;

EXEC SQL END DECLARE SECTION;
void sql_error(char *msg) { // sql error function
	EXEC SQL WHENEVER SQLERROR CONTINUE;

	printf("\n%s", msg);
	printf("\n% .70s \n", sqlca.sqlerrm.sqlerrmc);

	EXEC SQL ROLLBACK WORK RELEASE;
	exit(EXIT_FAILURE);
}
void insertMovieReservation() { // 영화 예매 정보 입력
	EXEC SQL WHENEVER SQLERROR DO sql_error("Insert Movie Reservation error:");
	EXEC SQL INSERT INTO movie_reservation VALUES(:userID, : movieID, : peoNum);
	printf("\nUser %s, Movie Reservation Success\n", userID.arr);
}
void deleteMovieReservation() { // 영화 예매 정보 삭제
	EXEC SQL WHENEVER SQLERROR DO sql_error("Delete Movie Reservation error:");
	EXEC SQL DELETE FROM movie_reservation WHERE memid = :userID and movieID = : movieID;
	printf("\nUser %s, Delete Reservation Success\n", userID.arr);
}
void updateMovieReservation() { // 영화 예매 정보 수정
	EXEC SQL WHENEVER SQLERROR DO sql_error("Delete Movie Reservation error:");
	EXEC SQL UPDATE movie_reservation SET numofPeo = :upeoNum WHERE memid = : userID and  movieID = : movieID;
	printf("\nUser %s, Update Reservation Success\n", userID.arr);
}
void insertMovie() { // 개봉 예정 영화 정보 삽입
	EXEC SQL WHENEVER SQLERROR DO sql_error("Insert Movie Registration error:");
	//MovieOpenDate = "to_date('20300518000000','yyyymmddhh24miss')";
	//InsertMovieOpenDate.arr = "30001230000000";
	EXEC SQL INSERT INTO movie_scheduled VALUES(:movieID, : InsertMovieName, : InsertMovieDirector, to_date(:InsertMovieOpenDate, 'yyyymmddhh24miss'));
	printf("\nMovie Insert Success\n");
}
void deleteMovie() { // 개봉 예정 영화 정보 삭제
	EXEC SQL WHENEVER SQLERROR DO sql_error("Delete Movie Registration error:");
	EXEC SQL DELETE FROM movie_scheduled WHERE movieID = :movieID;
	printf("\nMovie Delete Success\n");
}
void updateMovie() { // 개봉 예정 영화 정보 수정
	EXEC SQL WHENEVER SQLERROR DO sql_error("Update Movie Reservation error:");
	EXEC SQL UPDATE movie_scheduled SET movieTitle = :InsertMovieName WHERE movieID = : movieID;
	EXEC SQL UPDATE movie_scheduled SET directorName = :InsertMovieDirector WHERE movieID = : movieID;
	EXEC SQL UPDATE movie_scheduled SET openDate = to_date(:InsertMovieOpenDate, 'yyyymmddhh24miss') WHERE movieID = : movieID;
	printf("\nMovie Update Success\n");
}
void insertData() { // 초기 데이터 삽입
	EXEC SQL WHENEVER SQLERROR DO sql_error("Insert Data error:");

	EXEC SQL INSERT INTO menu VALUES('res1', 'menu1', 1000);
	EXEC SQL INSERT INTO menu VALUES('res1', 'menu2', 200);
	EXEC SQL INSERT INTO menu VALUES('res1', 'menu3', 3000);
	EXEC SQL INSERT INTO menu VALUES('res1', 'menu4', 3000);
	EXEC SQL INSERT INTO menu VALUES('res2', 'menu5', 400);
	EXEC SQL INSERT INTO menu VALUES('res2', 'menu6', 600);
	EXEC SQL INSERT INTO menu VALUES('res2', 'menu7', 900);
	EXEC SQL INSERT INTO menu VALUES('res2', 'menu8', 400);
	EXEC SQL INSERT INTO menu VALUES('res3', 'menu9', 5000);
	EXEC SQL INSERT INTO menu VALUES('res3', 'menu10', 600);
	EXEC SQL INSERT INTO menu VALUES('res3', 'menu11', 10000);
	EXEC SQL INSERT INTO menu VALUES('res3', 'menu12', 200);

	EXEC SQL INSERT INTO restaurant VALUES(1, 'res1', 5000000, 't1');
	EXEC SQL INSERT INTO restaurant VALUES(2, 'res2', 5000000, 't2');
	EXEC SQL INSERT INTO restaurant VALUES(3, 'res3', 5000000, 't3');
	EXEC SQL INSERT INTO restaurant VALUES(4, 'res4', 4000000, 't4');
	EXEC SQL INSERT INTO restaurant VALUES(5, 'res5', 6000000, 't5');
	EXEC SQL INSERT INTO restaurant VALUES(6, 'res6', 58000000, 't6');
	EXEC SQL INSERT INTO restaurant VALUES(7, 'res7', 9600000, 't7');
	EXEC SQL INSERT INTO restaurant VALUES(8, 'res8', 6300000, 't8');
	EXEC SQL INSERT INTO restaurant VALUES(9, 'res9', 8200000, 't9');
	EXEC SQL INSERT INTO restaurant VALUES(10, 'res10', 1000000, 't10');
	EXEC SQL INSERT INTO restaurant VALUES(11, 'res11', 3500000, 't10');
	EXEC SQL INSERT INTO restaurant VALUES(12, 'res12', 8500000, 't12');

	EXEC SQL INSERT INTO members VALUES('p1', 'member1', to_date('19550109000000', 'yyyymmddhh24miss'), 'silver', '010-1234-5678', 1000);
	EXEC SQL INSERT INTO members VALUES('p2', 'member2', to_date('19451208000000', 'yyyymmddhh24miss'), 'gold', '010-5678-1234', 2000);
	EXEC SQL INSERT INTO members VALUES('p3', 'member3', to_date('19580719000000', 'yyyymmddhh24miss'), 'silver', '010-1234-1234', 800);
	EXEC SQL INSERT INTO members VALUES('p4', 'member4', to_date('19310620000000', 'yyyymmddhh24miss'), 'gold', '010-5678-5678', 2500);
	EXEC SQL INSERT INTO members VALUES('p5', 'member5', to_date('19520915000000', 'yyyymmddhh24miss'), 'vip', '010-1122-1234', 10000);
	EXEC SQL INSERT INTO members VALUES('p6', 'member6', to_date('19960917000000', 'yyyymmddhh24miss'), 'silver', '010-3542-4783', 3500);
	EXEC SQL INSERT INTO members VALUES('p7', 'member7', to_date('19960223000000', 'yyyymmddhh24miss'), 'gold', '010-3641-3541', 20000);
	EXEC SQL INSERT INTO members VALUES('p8', 'member8', to_date('19930312000000', 'yyyymmddhh24miss'), 'silver', '010-4561-4345', 10000);
	EXEC SQL INSERT INTO members VALUES('p9', 'member9', to_date('19320604000000', 'yyyymmddhh24miss'), 'gold', '010-4532-4354', 35000);
	EXEC SQL INSERT INTO members VALUES('p10', 'member10', to_date('20050505000000', 'yyyymmddhh24miss'), 'bronze', '010-3455-1234', 100);
	EXEC SQL INSERT INTO members VALUES('p11', 'member11', to_date('20060606000000', 'yyyymmddhh24miss'), 'bronze', '010-4343-4341', 3000);
	EXEC SQL INSERT INTO members VALUES('p12', 'member12', to_date('20070707000000', 'yyyymmddhh24miss'), 'vip', '010-9544-4345', 200);

	EXEC SQL INSERT INTO theater VALUES('t1', 'miami');
	EXEC SQL INSERT INTO theater VALUES('t2', 'sandom');
	EXEC SQL INSERT INTO theater VALUES('t3', 'ansan');
	EXEC SQL INSERT INTO theater VALUES('t4', 'seoul');
	EXEC SQL INSERT INTO theater VALUES('t5', 'busan');
	EXEC SQL INSERT INTO theater VALUES('t6', 'daejun');
	EXEC SQL INSERT INTO theater VALUES('t7', 'cleveland');
	EXEC SQL INSERT INTO theater VALUES('t8', 'los angeles');
	EXEC SQL INSERT INTO theater VALUES('t9', 'seattle');
	EXEC SQL INSERT INTO theater VALUES('t10', 'new england');
	EXEC SQL INSERT INTO theater VALUES('t11', 'new york');
	EXEC SQL INSERT INTO theater VALUES('t12', 'chicago');

	EXEC SQL INSERT INTO employee VALUES(1, 'employee1', to_date('19550109000000', 'yyyymmddhh24miss'), 'Chairman', '010-1111-2222', 't1');
	EXEC SQL INSERT INTO employee VALUES(2, 'employee2', to_date('19451208000000', 'yyyymmddhh24miss'), 'vice-chairman', '010-1111-3333', 't1');
	EXEC SQL INSERT INTO employee VALUES(3, 'employee3', to_date('19580719000000', 'yyyymmddhh24miss'), 'Chairman', '010-4444-2222', 't2');
	EXEC SQL INSERT INTO employee VALUES(4, 'employee4', to_date('19310620000000', 'yyyymmddhh24miss'), 'CEO', '010-1111-5555', 't3');
	EXEC SQL INSERT INTO employee VALUES(5, 'employee5', to_date('19520915000000', 'yyyymmddhh24miss'), 'Director', '010-6666-2222', 't4');
	EXEC SQL INSERT INTO employee VALUES(6, 'employee6', to_date('19360608000000', 'yyyymmddhh24miss'), 'CTO', '010-2222-3333', 't6');
	EXEC SQL INSERT INTO employee VALUES(7, 'employee7', to_date('19930605000000', 'yyyymmddhh24miss'), 'COO', '010-3333-4444', 't10');
	EXEC SQL INSERT INTO employee VALUES(8, 'employee8', to_date('19950301000000', 'yyyymmddhh24miss'), 'Associate', '010-4444-5555', 't6');
	EXEC SQL INSERT INTO employee VALUES(9, 'employee9', to_date('19960917000000', 'yyyymmddhh24miss'), 'Chief', '010-5555-6666', 't12');
	EXEC SQL INSERT INTO employee VALUES(10, 'employee10', to_date('19960223000000', 'yyyymmddhh24miss'), 'Director', '010-6666-7777', 't11');
	EXEC SQL INSERT INTO employee VALUES(11, 'employee11', to_date('19910101000000', 'yyyymmddhh24miss'), 'Director', '010-7777-8888', 't6');
	EXEC SQL INSERT INTO employee VALUES(12, 'employee12', to_date('19931225000000', 'yyyymmddhh24miss'), 'Chief', '010-8888-9999', 't7');

	EXEC SQL INSERT INTO goods VALUES(1, 'umbrella', 100);
	EXEC SQL INSERT INTO goods VALUES(2, '3D glasses', 100);
	EXEC SQL INSERT INTO goods VALUES(3, 'cushion', 100);
	EXEC SQL INSERT INTO goods VALUES(4, 'Cup', 100);
	EXEC SQL INSERT INTO goods VALUES(5, 'Straw', 65);
	EXEC SQL INSERT INTO goods VALUES(6, 'Bin', 84);
	EXEC SQL INSERT INTO goods VALUES(7, 'Cap', 10);
	EXEC SQL INSERT INTO goods VALUES(8, 'Battery', 69);
	EXEC SQL INSERT INTO goods VALUES(9, 'USB', 87);
	EXEC SQL INSERT INTO goods VALUES(10, 'USB-C', 36);
	EXEC SQL INSERT INTO goods VALUES(11, 'USB-A', 15);
	EXEC SQL INSERT INTO goods VALUES(12, 'Adaptor', 69);

	EXEC SQL INSERT INTO movie_screening VALUES(1, 'beauty and the beast', 'kim', to_date('20170301000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_screening VALUES(2, 'avengers', 'shim', to_date('20160401000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_screening VALUES(3, 'avengers 2', 'hahaha', to_date('20170503000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_screening VALUES(4, 'beauty and the beast 2', 'mohaji', to_date('20170510000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_screening VALUES(5, 'Guardians of the Galaxy', 'James', to_date('20170302000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_screening VALUES(6, 'The Sheriff In Town', 'Matt', to_date('20170621000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_screening VALUES(7, 'The Boss Baby', 'Kim', to_date('20170511000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_screening VALUES(8, 'The Shack', 'Go', to_date('20170512000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_screening VALUES(9, 'Alien: Covenant', 'Shim', to_date('20170513000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_screening VALUES(10, 'A Silent Voice', 'Nam', to_date('20170514000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_screening VALUES(11, 'The Tooth and the Nail', 'Kim', to_date('20170515000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_screening VALUES(12, 'The Kings Case Note', 'Hyjsn', to_date('20170516000000', 'yyyymmddhh24miss'));

	EXEC SQL INSERT INTO menu_reservation VALUES('p1', 1, to_date('20170915000000', 'yyyymmddhh24miss'), 5);
	EXEC SQL INSERT INTO menu_reservation VALUES('p2', 1, to_date('20170916000000', 'yyyymmddhh24miss'), 5);
	EXEC SQL INSERT INTO menu_reservation VALUES('p3', 1, to_date('20160915000000', 'yyyymmddhh24miss'), 1);
	EXEC SQL INSERT INTO menu_reservation VALUES('p2', 2, to_date('20170915000000', 'yyyymmddhh24miss'), 5);
	EXEC SQL INSERT INTO menu_reservation VALUES('p3', 3, to_date('20160915000000', 'yyyymmddhh24miss'), 5);
	EXEC SQL INSERT INTO menu_reservation VALUES('p6', 5, to_date('20160916000000', 'yyyymmddhh24miss'), 3);
	EXEC SQL INSERT INTO menu_reservation VALUES('p9', 6, to_date('20160917000000', 'yyyymmddhh24miss'), 7);
	EXEC SQL INSERT INTO menu_reservation VALUES('p10', 9, to_date('20160918000000', 'yyyymmddhh24miss'), 12);
	EXEC SQL INSERT INTO menu_reservation VALUES('p12', 11, to_date('20160919000000', 'yyyymmddhh24miss'), 6);
	EXEC SQL INSERT INTO menu_reservation VALUES('p5', 11, to_date('20160910000000', 'yyyymmddhh24miss'), 11);
	EXEC SQL INSERT INTO menu_reservation VALUES('p9', 2, to_date('20160911000000', 'yyyymmddhh24miss'), 7);
	EXEC SQL INSERT INTO menu_reservation VALUES('p7', 10, to_date('20160910000000', 'yyyymmddhh24miss'), 9);

	EXEC SQL INSERT INTO movie_time VALUES(1, 1, 't1', to_date('20170511090000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(2, 1, 't1', to_date('20170511120000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(3, 1, 't1', to_date('20170511150000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(4, 1, 't1', to_date('20170511190000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(5, 1, 't1', to_date('20170511210000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(6, 2, 't1', to_date('20170511090000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(7, 2, 't1', to_date('20170511120000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(8, 2, 't1', to_date('20170511150000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(9, 2, 't1', to_date('20170511190000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(10, 3, 't2', to_date('20170511210000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(11, 3, 't2', to_date('20170511090000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(12, 3, 't2', to_date('20170511120000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(13, 3, 't2', to_date('20170511150000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(14, 3, 't2', to_date('20170511190000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(15, 3, 't2', to_date('20170511210000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(16, 3, 't2', to_date('20170511210000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(17, 4, 't3', to_date('20170511090000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(18, 4, 't3', to_date('20170511120000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(19, 4, 't3', to_date('20170511150000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(20, 4, 't3', to_date('20170511190000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_time VALUES(21, 4, 't3', to_date('20170511210000', 'yyyymmddhh24miss'));

	EXEC SQL INSERT INTO movie_reservation VALUES('p1', 1, 3);
	EXEC SQL INSERT INTO movie_reservation VALUES('p1', 2, 2);
	EXEC SQL INSERT INTO movie_reservation VALUES('p1', 3, 5);
	EXEC SQL INSERT INTO movie_reservation VALUES('p1', 4, 1);
	EXEC SQL INSERT INTO movie_reservation VALUES('p2', 5, 1);
	EXEC SQL INSERT INTO movie_reservation VALUES('p2', 6, 3);
	EXEC SQL INSERT INTO movie_reservation VALUES('p2', 7, 3);
	EXEC SQL INSERT INTO movie_reservation VALUES('p2', 8, 3);
	EXEC SQL INSERT INTO movie_reservation VALUES('p3', 9, 3);
	EXEC SQL INSERT INTO movie_reservation VALUES('p3', 10, 9);
	EXEC SQL INSERT INTO movie_reservation VALUES('p3', 11, 3);
	EXEC SQL INSERT INTO movie_reservation VALUES('p3', 12, 3);
	EXEC SQL INSERT INTO movie_reservation VALUES('p4', 2, 3);
	EXEC SQL INSERT INTO movie_reservation VALUES('p5', 3, 3);
	EXEC SQL INSERT INTO movie_reservation VALUES('p6', 4, 3);
	EXEC SQL INSERT INTO movie_reservation VALUES('p7', 5, 3);
	EXEC SQL INSERT INTO movie_reservation VALUES('p8', 6, 3);
	EXEC SQL INSERT INTO movie_reservation VALUES('p9', 7, 3);

	EXEC SQL INSERT INTO movie_score VALUES('p1', 1, 59);
	EXEC SQL INSERT INTO movie_score VALUES('p1', 2, 70);
	EXEC SQL INSERT INTO movie_score VALUES('p1', 3, 10);
	EXEC SQL INSERT INTO movie_score VALUES('p1', 4, 39);
	EXEC SQL INSERT INTO movie_score VALUES('p2', 1, 59);
	EXEC SQL INSERT INTO movie_score VALUES('p2', 2, 68);
	EXEC SQL INSERT INTO movie_score VALUES('p2', 3, 70);
	EXEC SQL INSERT INTO movie_score VALUES('p2', 4, 59);
	EXEC SQL INSERT INTO movie_score VALUES('p3', 1, 25);
	EXEC SQL INSERT INTO movie_score VALUES('p3', 2, 99);
	EXEC SQL INSERT INTO movie_score VALUES('p3', 3, 10);
	EXEC SQL INSERT INTO movie_score VALUES('p3', 4, 39);

	EXEC SQL INSERT INTO goods_reservation VALUES(1, 'p1', to_date('20170511000000', 'yyyymmddhh24miss'), to_date('20170611000000', 'yyyymmddhh24miss'), 10);
	EXEC SQL INSERT INTO goods_reservation VALUES(2, 'p1', to_date('20170511000000', 'yyyymmddhh24miss'), to_date('20170711000000', 'yyyymmddhh24miss'), 10);
	EXEC SQL INSERT INTO goods_reservation VALUES(3, 'p1', to_date('20170511000000', 'yyyymmddhh24miss'), to_date('20170711000000', 'yyyymmddhh24miss'), 10);
	EXEC SQL INSERT INTO goods_reservation VALUES(9, 'p1', to_date('20170511000000', 'yyyymmddhh24miss'), to_date('20170711000000', 'yyyymmddhh24miss'), 10);
	EXEC SQL INSERT INTO goods_reservation VALUES(2, 'p2', to_date('20170511000000', 'yyyymmddhh24miss'), to_date('20170711000000', 'yyyymmddhh24miss'), 10);
	EXEC SQL INSERT INTO goods_reservation VALUES(3, 'p10', to_date('20170511000000', 'yyyymmddhh24miss'), to_date('20170811000000', 'yyyymmddhh24miss'), 6);
	EXEC SQL INSERT INTO goods_reservation VALUES(3, 'p11', to_date('20170411000000', 'yyyymmddhh24miss'), to_date('20170811000000', 'yyyymmddhh24miss'), 4);
	EXEC SQL INSERT INTO goods_reservation VALUES(5, 'p12', to_date('20170312000000', 'yyyymmddhh24miss'), to_date('20170811000000', 'yyyymmddhh24miss'), 8);
	EXEC SQL INSERT INTO goods_reservation VALUES(9, 'p5', to_date('20170512000000', 'yyyymmddhh24miss'), to_date('20170811000000', 'yyyymmddhh24miss'), 5);
	EXEC SQL INSERT INTO goods_reservation VALUES(10, 'p7', to_date('20170513000000', 'yyyymmddhh24miss'), to_date('20170811000000', 'yyyymmddhh24miss'), 2);
	EXEC SQL INSERT INTO goods_reservation VALUES(11, 'p9', to_date('20170514000000', 'yyyymmddhh24miss'), to_date('20170811000000', 'yyyymmddhh24miss'), 2);
	EXEC SQL INSERT INTO goods_reservation VALUES(12, 'p6', to_date('20170515000000', 'yyyymmddhh24miss'), to_date('20170811000000', 'yyyymmddhh24miss'), 9);

	EXEC SQL INSERT INTO movie_scheduled VALUES(1, 'avengers infinity war', 'stan lee', to_date('20200511000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_scheduled VALUES(2, 'harry potter reboot', 'emma watson', to_date('20220511000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_scheduled VALUES(3, 'deadfool', 'stan lee', to_date('20300511000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_scheduled VALUES(4, 'King Arthur', 'John', to_date('20300511000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_scheduled VALUES(5, 'The Merciless', 'Kai', to_date('20300512000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_scheduled VALUES(6, 'Blue Busking', 'Jin', to_date('20300516000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_scheduled VALUES(7, 'Manjhi', 'WhoRU', to_date('20300516000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_scheduled VALUES(8, 'Get Out', 'RYUJEHONG', to_date('20300518000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_scheduled VALUES(9, 'Lost in Paris', 'Tobi', to_date('20300517000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_scheduled VALUES(10, 'Loyal Swordman', 'ZunBa', to_date('20300531000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_scheduled VALUES(11, 'Pirates of the Caribbean', 'Miro', to_date('20300611000000', 'yyyymmddhh24miss'));
	EXEC SQL INSERT INTO movie_scheduled VALUES(12, 'The Jungle Book', 'Esca', to_date('20300711000000', 'yyyymmddhh24miss'));

	EXEC SQL INSERT INTO music VALUES('pallete', 'IU');
	EXEC SQL INSERT INTO music VALUES('autoreverse', 'psy');
	EXEC SQL INSERT INTO music VALUES('Knock Knock', 'twice');
	EXEC SQL INSERT INTO music VALUES('paris', 'the chainsmokers');
	EXEC SQL INSERT INTO music VALUES('the one', 'the chainsmokers');
	EXEC SQL INSERT INTO music VALUES('inside out', 'the chainsmokers');
	EXEC SQL INSERT INTO music VALUES('something like this', 'the chainsmokers');
	EXEC SQL INSERT INTO music VALUES('scientist', 'coldplay');
	EXEC SQL INSERT INTO music VALUES('fix you', 'coldplay');
	EXEC SQL INSERT INTO music VALUES('yellow', 'coldplay');
	EXEC SQL INSERT INTO music VALUES('viva la vida', 'coldplay');
	EXEC SQL INSERT INTO music VALUES('paradise', 'coldplay');
}
void userPrint() { // 사용자 테이블 전체 출력
	if ((menuPtr = (struct smenu*)malloc(sizeof(struct smenu))) == 0) {
		printf("menuPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	if ((moviescreenPtr = (struct movie_screen*)malloc(sizeof(struct movie_screen))) == 0) {
		printf("moviescreenPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	if ((menuresPtr = (struct menu_res*)malloc(sizeof(struct menu_res))) == 0) {
		printf("menuresPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	if ((movietimePtr = (struct movie_time*)malloc(sizeof(struct movie_time))) == 0) {
		printf("movietimePtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	if ((movieresPtr = (struct movie_res*)malloc(sizeof(struct movie_res))) == 0) {
		printf("movieresPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	if ((moviescorePtr = (struct movie_score*)malloc(sizeof(struct movie_score))) == 0) {
		printf("moviescorePtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	if ((goodsresPtr = (struct goods_res*)malloc(sizeof(struct goods_res))) == 0) {
		printf("goodsresPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	/* memory allocation */

	EXEC SQL WHENEVER SQLERROR DO sql_error("User Print error:");

	printf("\n### USER TABLE ###\n");

	EXEC SQL DECLARE cur CURSOR FOR // 커서 선언
		SELECT * FROM menu;
	EXEC SQL OPEN cur;
	printf("\nMenu Table");
	printf("\nRes Name\tMenu Name\t\tMenu Price");
	printf("\n------\t\t--------\t\t--------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH cur INTO : menuPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%s %s %d\n", menuPtr->name, menuPtr->mname, menuPtr->price);
	}
	EXEC SQL CLOSE cur; // menu table print

	EXEC SQL DECLARE cur1 CURSOR FOR // 커서 선언
		SELECT * FROM menu_reservation;
	EXEC SQL OPEN cur1;
	printf("\nRestaurant Reservation Table");
	printf("\nMem ID\t\tRes ID\t\tRes Time\tRes Num");
	printf("\n------\t\t--------\t--------\t--------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH cur1 INTO : menuresPtr; // 커서의 내용 구조체 포인터에 넣음 // 커서의 내용 구조체 포인터에 넣음
		printf("%s %d\t\t%s\t%d\n", menuresPtr->memid, menuresPtr->rid, menuresPtr->date, menuresPtr->rnum);
	}
	EXEC SQL CLOSE cur1; // menu_reservation table print

	EXEC SQL DECLARE cur2 CURSOR FOR // 커서 선언
		SELECT * FROM movie_screening;
	EXEC SQL OPEN cur2;
	printf("\nMovie Screening Table");
	printf("\nMovie ID\tMovie Title\t\t\t\tDirectore Name\t\t\tdate");
	printf("\n------\t\t--------\t\t\t\t--------\t\t\t--------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH cur2 INTO : moviescreenPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%d\t\t%s %s %s\n", moviescreenPtr->movieid, moviescreenPtr->title, moviescreenPtr->dname, moviescreenPtr->date);
	}
	EXEC SQL CLOSE cur2; // movie_screening table print

	EXEC SQL DECLARE cur3 CURSOR FOR // 커서 선언
		SELECT * FROM movie_time;
	EXEC SQL OPEN cur3;
	printf("\nMovie Time Table");
	printf("\nTime ID\t\tMovie ID\tTheater Name\t\tDate");
	printf("\n------\t\t--------\t--------\t\t--------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH cur3 INTO : movietimePtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%d\t\t%d\t\t%s\t%s\n", movietimePtr->tid, movietimePtr->movieid, movietimePtr->tname, movietimePtr->date);
	}
	EXEC SQL CLOSE cur3; // movie_time table print

	EXEC SQL DECLARE cur4 CURSOR FOR // 커서 선언
		SELECT * FROM movie_reservation;
	EXEC SQL OPEN cur4;
	printf("\nMovie Reservation Table");
	printf("\nMem ID\t\tMovie ID\tPerson Number");
	printf("\n------\t\t--------\t--------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH cur4 INTO : movieresPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%s %d \t\t%d\n", movieresPtr->memid, movieresPtr->tid, movieresPtr->peonum);
	}
	EXEC SQL CLOSE cur4; // movie_reservation table print

	EXEC SQL DECLARE cur5 CURSOR FOR // 커서 선언
		SELECT * FROM movie_score;
	EXEC SQL OPEN cur5;
	printf("\nMovie Score Table");
	printf("\nMem ID\t\tMovie ID\tScore");
	printf("\n------\t\t--------\t--------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH cur5 INTO : moviescorePtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%s %d\t\t%d\n", moviescorePtr->memid, moviescorePtr->mid, moviescorePtr->score);
	}
	EXEC SQL CLOSE cur5; // movie_score table print

	EXEC SQL DECLARE cur6 CURSOR FOR // 커서 선언
		SELECT * FROM goods_reservation;
	EXEC SQL OPEN cur6;
	printf("\nGoods Reservation Table");
	printf("\nGoods ID\tMem ID\t\tRes Date\tDue Date\tRes Num");
	printf("\n------\t\t--------\t--------\t--------\t--------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH cur6 INTO : goodsresPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%d\t\t%s%s %s\t\t%d\n", goodsresPtr->gid, goodsresPtr->memid, goodsresPtr->resdate, goodsresPtr->duedate, goodsresPtr->gnum);
	}
	EXEC SQL CLOSE cur6; // goods_reservation table print
}
void managerPrint() {
	if ((theaterPtr = (struct stheater *)malloc(sizeof(struct stheater))) == 0) {
		printf("theaterPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	if ((goodsPtr = (struct goods *)malloc(sizeof(struct goods))) == 0) {
		printf("goodsPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	if ((membersPtr = (struct members *)malloc(sizeof(struct members))) == 0) {
		printf("membersPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	if ((restaurantPtr = (struct restaurant *)malloc(sizeof(struct restaurant))) == 0) {
		printf("restaurantPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	if ((movie_scheduledPtr = (struct movie_scheduled *)malloc(sizeof(struct movie_scheduled))) == 0) {
		printf("movie_scheduledPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	if ((employeePtr = (struct employee *)malloc(sizeof(struct employee))) == 0) {
		printf("employeePtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	if ((musicPtr = (struct music *)malloc(sizeof(struct music))) == 0) {
		printf("musicPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	EXEC SQL WHENEVER SQLERROR DO sql_error("Manager Print error:");

	userPrint(); // 관리자는 사용자 테이블도 볼 수 있다

	printf("\n### MANAGER TABLE ###\n");

	EXEC SQL DECLARE c CURSOR FOR // 커서 선언
		SELECT * FROM theater;
	EXEC SQL OPEN c;
	printf("\nTheater Table");
	printf("\nName\t\t\tPlace");
	printf("\n------\t\t\t--------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH c INTO : theaterPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%s\t%s\n", theaterPtr->tName, theaterPtr->tPlace);
	}
	EXEC SQL CLOSE c; // theater table print

	EXEC SQL DECLARE c2 CURSOR FOR // 커서 선언
		SELECT * FROM goods;
	EXEC SQL OPEN c2;
	printf("\nGoods Table");
	printf("\nGoodsID\t\tGoodsName\t\tGoodNum");
	printf("\n-------\t\t---------\t\t-------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH c2 INTO : goodsPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%d\t\t%s \t%d\n", goodsPtr->gid, goodsPtr->gname, goodsPtr->gnum);
	}
	EXEC SQL CLOSE c2; // goods table print

	EXEC SQL DECLARE c3 CURSOR FOR // 커서 선언
		SELECT * FROM members;
	EXEC SQL OPEN c3;
	printf("\nMembers Table");
	printf("\nMemberID\t\tMemName\t\tMemBirth\t\tMemGrade\t\tMemPnum\t\tMemReserve");
	printf("\n-------\t\t\t--------\t---------\t\t---------\t\t---------\t----------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH c3 INTO : membersPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%s %s %s\t%s %s %d\n", membersPtr->memid, membersPtr->memname, membersPtr->membirth, membersPtr->memgrade, membersPtr->mempnum, membersPtr->memreserve);
	}
	EXEC SQL CLOSE c3; // members table print

	EXEC SQL DECLARE c4 CURSOR FOR // 커서 선언
		SELECT * FROM restaurant;
	EXEC SQL OPEN c4;
	printf("\nRestaurant Table");
	printf("\nResId\t\tResName\t\tDownPayment\t\tTheaterName");
	printf("\n-------\t\t---------\t----------\t\t---------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH c4 INTO : restaurantPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%d\t\t%s %d \t\t%s\n", restaurantPtr->resid, restaurantPtr->resname, restaurantPtr->downpayment, restaurantPtr->theatername);
	}
	EXEC SQL CLOSE c4; // restaurant table print

	EXEC SQL DECLARE c5 CURSOR FOR // 커서 선언
		SELECT * FROM movie_scheduled;
	EXEC SQL OPEN c5;
	printf("\nMovie_scheduled Table");
	printf("\nMovieId\t\tMovieTitle\t\t\t\tDirectorName\t\t\tOpenDate");
	printf("\n-------\t\t---------\t\t\t\t----------\t\t\t--------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH c5 INTO : movie_scheduledPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%d\t\t%s %s %s\n", movie_scheduledPtr->movieid, movie_scheduledPtr->movietitle, movie_scheduledPtr->directorname, movie_scheduledPtr->opendate);
	}
	EXEC SQL CLOSE c5; // movie_scheduled table print

	EXEC SQL DECLARE c6 CURSOR FOR // 커서 선언
		SELECT * FROM employee;
	EXEC SQL OPEN c6;
	printf("\nEmployee Table");
	printf("\nEmpId\tEmpName\t\tEmpBirth\t\tEmpPos\t\t\tEmpPnum\t\tTheaterName");
	printf("\n-------\t---------\t----------\t\t---------\t\t----------\t----------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH c6 INTO : employeePtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%d\t%s %s %s %s %s\n", employeePtr->empid, employeePtr->empname, employeePtr->empbirth, employeePtr->emppos, employeePtr->emppnum, employeePtr->theatername);
	}
	EXEC SQL CLOSE c6; // employee table print

	EXEC SQL DECLARE c7 CURSOR FOR // 커서 선언
		SELECT * FROM music;
	EXEC SQL OPEN c7;
	printf("\nMusic Table");
	printf("\nMusictitle\t\tSinger");
	printf("\n-------\t\t\t-------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH c7 INTO : musicPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%s\t%s\n", musicPtr->musictitle, musicPtr->singer);
	}
	EXEC SQL CLOSE c7; // music table print
}
void initDatabase() { // 데이터베이스 초기화 function
	EXEC SQL WHENEVER NOT FOUND CONTINUE;
	EXEC SQL DELETE FROM goods;
	EXEC SQL DELETE FROM theater;
	EXEC SQL DELETE FROM members;
	EXEC SQL DELETE FROM restaurant;
	EXEC SQL DELETE FROM menu;
	EXEC SQL DELETE FROM movie_screening;
	EXEC SQL DELETE FROM menu_reservation;
	EXEC SQL DELETE FROM movie_time;
	EXEC SQL DELETE FROM movie_reservation;
	EXEC SQL DELETE FROM movie_score;
	EXEC SQL DELETE FROM goods_reservation;
	EXEC SQL DELETE FROM movie_scheduled;
	EXEC SQL DELETE FROM employee;
	EXEC SQL DELETE FROM music;
	/* 테이블 내용 삭제 */

	insertData(); // 초기 데이터 삽입
	printf("\tInit Database!\n\n");
}
void showMovieList() { // 상영 중인 영화 정보 출력
	if ((rmsPtr = (struct movie_screen *)malloc(sizeof(struct movie_screen))) == 0) {
		printf("rmsPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	EXEC SQL WHENEVER SQLERROR DO sql_error("Show Movie error:");

	EXEC SQL DECLARE mcur CURSOR FOR // 커서 선언
		SELECT * FROM movie_screening;
	EXEC SQL OPEN mcur;
	printf("\nMovie Screening Table");
	printf("\nMovie ID\tMovie Title\t\t\t\tDirectore Name\t\t\tdate");
	printf("\n------\t\t--------\t\t\t\t--------\t\t\t--------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH mcur INTO : rmsPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%d\t\t%s %s %s\n", rmsPtr->movieid, rmsPtr->title, rmsPtr->dname, rmsPtr->date);
	}
	EXEC SQL CLOSE mcur; // movie_screening table print
}
void showMovieScheduledList() { // 상영 예정인 영화 정보 출력
	if ((msPtr2 = (struct movie_scheduled *)malloc(sizeof(struct movie_scheduled))) == 0) {
		printf("movie_scheduledPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	EXEC SQL DECLARE scur CURSOR FOR // 커서 선언
		SELECT * FROM movie_scheduled;
	EXEC SQL OPEN scur;
	printf("\nMovie_scheduled Table");
	printf("\nMovie ID\tMovie Title\t\t\t\tDirectore Name\t\t\tdate");
	printf("\n------\t\t--------\t\t\t\t--------\t\t\t--------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH scur INTO : msPtr2; // 커서의 내용 구조체 포인터에 넣음
		printf("%d\t\t%s %s %s\n", msPtr2->movieid, msPtr2->movietitle, msPtr2->directorname, msPtr2->opendate);
	}
	EXEC SQL CLOSE scur; // movie_scheduled table print
}

void showReservationList() { // 영화 예매 내역 정보 출력
	free(mrPtr);
	if ((mrPtr = (struct movie_res*)malloc(sizeof(struct movie_res))) == 0) {
		printf("movieresPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	EXEC SQL WHENEVER SQLERROR DO sql_error("Show Reservation error:");

	EXEC SQL DECLARE rcur CURSOR FOR // 커서 선언
		SELECT * FROM movie_reservation;
	EXEC SQL OPEN rcur;
	printf("\nMovie Reservation Table");
	printf("\nMem ID\t\tMovie ID\tPerson Number");
	printf("\n------\t\t--------\t--------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH rcur INTO : mrPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%s %d \t\t%d\n", mrPtr->memid, mrPtr->tid, mrPtr->peonum);
	}
	EXEC SQL CLOSE rcur; // movie_reservation
}
void makeReservation() { // 영화 예매 정보 삽입
	int flag = 0;

	system("clear");
	printf("\n\n");
	printf("\t=====================================\n");
	printf("\t     MOVIE RESERVATION\n");
	printf("\t-------------------------------------\n");
	printf("\t   Insert ID : ");
	scanf("%s", userID.arr);
	userID.len = strlen(userID.arr);
	/* memid 입력 받음 */

	if ((rmemPtr = (struct members *)malloc(sizeof(struct members))) == 0) {
		printf("rmemPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	EXEC SQL WHENEVER SQLERROR DO sql_error("Make Reservation error:");

	EXEC SQL DECLARE rcur1 CURSOR FOR // 커서 선언
		SELECT * FROM members WHERE memid = :userID; // 입력받은 memid를 데이터베이스에 검색
	EXEC SQL OPEN rcur1;
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH rcur1 INTO : rmemPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("\n\t   Welcome %s\n", rmemPtr->memname);
		flag = 1; // 입력받은 memid를 데이터베이스에 있다면 flag = 1 없다면 flag = 0
	}
	EXEC SQL CLOSE rcur1; // members

	if (flag) { // 입력받은 memid가 회원이 맞을 때
		showMovieList(); // 상영 중인 영화 정보 출력
		printf("Input Movie ID : ");
		scanf("%d", &movieID);
		printf("Input Number of People : ");
		scanf("%d", &peoNum);
		/* 예매할 영화 id와 인원 수 입력 */
		insertMovieReservation(); // 입력받은 영화 예매 정보 삽입 function
	}
	else { // 회원 아닐 때
		printf("\n\tSorry, You are not our User\n");
	}

	getchar();
}

void InsertMovieScheduled() { // 개봉 예정 영화 삽입
	int flag = 0;

	system("clear");
	printf("\n\n");
	printf("\t=====================================\n");
	printf("\t     ADD MOVIE \n");
	printf("\t-------------------------------------\n");

	showMovieScheduledList(); // 개봉 예정 영화 정보 출력
	printf("Input Movie ID : ");
	scanf("%d", &movieID);
	printf("Input MovieTitle : ");
	scanf("%s", &InsertMovieName.arr);
	InsertMovieName.len = strlen(InsertMovieName.arr);
	printf("Input directorName : ");
	scanf("%s", &InsertMovieDirector.arr);
	InsertMovieDirector.len = strlen(InsertMovieDirector.arr);
	printf("Input Opendate(YYYYMMDD) :");
	scanf("%s", InsertMovieOpenDate.arr);
	InsertMovieOpenDate.len = strlen(InsertMovieOpenDate.arr);
	/* 삽입할 영화의 id, 제목, 감독이름, 날짜 입력 */

	insertMovie(); // 입력받은 개봉 예정 영화 정보 삽입

	getchar();
}

void deleteReservation() { // 영화 예매 정보 삭제
	int flag = 0;

	system("clear");
	printf("\n\n");
	printf("\t=====================================\n");
	printf("\t     DELETE RESERVATION\n");
	printf("\t-------------------------------------\n");
	printf("\t   Insert ID : ");
	scanf("%s", userID.arr);
	userID.len = strlen(userID.arr);
	/* memid 입력 받음 */

	if ((rmem1Ptr = (struct members *)malloc(sizeof(struct members))) == 0) {
		printf("rmem1Ptr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	EXEC SQL WHENEVER SQLERROR DO sql_error("Delete Reservation error:");

	EXEC SQL DECLARE rcur2 CURSOR FOR // 커서 선언
		SELECT * FROM members WHERE memid = :userID; // 입력받은 memid를 데이터베이스에 검색
	EXEC SQL OPEN rcur2;
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH rcur2 INTO : rmem1Ptr; // 커서의 내용 구조체 포인터에 넣음
		printf("\n\t   Welcome %s\n", rmem1Ptr->memname);
		flag = 1; // 입력받은 memid를 데이터베이스에 있다면 flag = 1 없다면 flag = 0
	}
	EXEC SQL CLOSE rcur2; // members

	if (flag) { // 입력받은 memid가 회원이 맞을 때
		showReservationList(); // 영화 예매 내역 검색
		printf("Input Movie ID : ");
		scanf("%d", &movieID); // 삭제할 예매의 영화 id 입력

		deleteMovieReservation(); // 입력받은 영화 예매 정보 삭제
	}
	else { // 회원 아닐 때
		printf("\n\tSorry, You are not our User\n");
	}

	getchar();
}
void deleteMovieScheduled() { // 개봉 예정 영화 정보 삭제
	system("clear");
	printf("\n\n");
	printf("\t=====================================\n");
	printf("\t     DELETE Movie\n");
	printf("\t-------------------------------------\n");

	EXEC SQL WHENEVER SQLERROR DO sql_error("Delete Movie error:");

	showMovieScheduledList(); // 개봉 예정 영화 정보 출력
	printf("Input Movie ID : ");
	scanf("%d", &movieID); // 삭제할 개봉 예정 영화 id입력

	deleteMovie(); // 입력받은 개봉 예정 영화 정보 삭제

	getchar();
}
void updateMovieScheduled() { // 개봉 예정 영화 정보 수정
	system("clear");
	printf("\n\n");
	printf("\t=====================================\n");
	printf("\t     UPDATE Movie\n");
	printf("\t-------------------------------------\n");

	showMovieScheduledList(); // 개봉 예정 영화 정보 출력
	printf("Input Movie ID : ");
	scanf("%d", &movieID);
	printf("Input Movie Name : ");
	scanf("%s", &InsertMovieName.arr);
	InsertMovieName.len = strlen(InsertMovieName.arr);

	printf("Input DirectorName : ");
	scanf("%s", &InsertMovieDirector.arr);
	InsertMovieDirector.len = strlen(InsertMovieDirector.arr);

	printf("Input OpenDate(YYYYMMDD) : ");
	scanf("%s", &InsertMovieOpenDate.arr);
	InsertMovieOpenDate.len = strlen(InsertMovieOpenDate.arr);
	/* 수정할 영화의 id, 제목, 감독이름, 날짜 입력 */

	updateMovie(); // 입력받은 개봉 예정 영화 정보 수정

	getchar();
}
void updateReservation() { // 영화 예매 정보 수정
	int flag = 0;

	system("clear");
	printf("\n\n");
	printf("\t=====================================\n");
	printf("\t     UPDATE RESERVATION\n");
	printf("\t-------------------------------------\n");
	printf("\t   Insert ID : ");
	scanf("%s", userID.arr);
	userID.len = strlen(userID.arr);
	/* memid 입력 받음 */

	if ((rmem2Ptr = (struct members *)malloc(sizeof(struct members))) == 0) {
		printf("rmem2Ptr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	EXEC SQL WHENEVER SQLERROR DO sql_error("Update Reservation error:");

	EXEC SQL DECLARE rcur3 CURSOR FOR // 커서 선언
		SELECT * FROM members WHERE memid = :userID; // 입력받은 memid를 데이터베이스에 검색
	EXEC SQL OPEN rcur3;
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH rcur3 INTO : rmem2Ptr; // 커서의 내용 구조체 포인터에 넣음
		printf("\n\t   Welcome %s\n", rmem2Ptr->memname);
		flag = 1; // 입력받은 memid를 데이터베이스에 있다면 flag = 1 없다면 flag = 0
	}
	EXEC SQL CLOSE rcur3; // members

	if (flag) { // 입력받은 memid가 회원이 맞을 때
		showReservationList(); // 영화 예매 내역 출력
		printf("Input Movie ID : ");
		scanf("%d", &movieID);
		printf("Input Update Number of People : ");
		scanf("%d", &upeoNum);
		/* 정보 수정 대상인 영화 id입력 후, 수정할 인원수 입력 */

		updateMovieReservation(); // 입력받은 영화 예매 정보 수정
	}
	else { // 회원 아닐 때
		printf("\n\tSorry, You are not our User\n");
	}

	getchar();
}
void ticket() { // 티켓 판매 통계 함수
	if ((ticketPtr = (struct ticket*)malloc(sizeof(struct ticket))) == 0) {
		printf("ticketPtr Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}

	EXEC SQL DECLARE ticketcur CURSOR FOR // 커서 선언
		SELECT movie_screening.movieTitle, sum(numofPeo) // 영화 제목, 영화 예매 인원수의 합
		FROM movie_screening, movie_reservation
		WHERE movie_screening.movieID = movie_reservation.movieID
		GROUP BY movie_screening.movieTitle;
	EXEC SQL OPEN ticketcur;
	printf("\nTicket Sales");
	printf("\nMovie Title\t\t\t\tTotal Ticket Num");
	printf("\n------\t\t\t\t\t--------\n");
	EXEC SQL WHENEVER NOT FOUND DO break;
	for (;;) {
		EXEC SQL FETCH ticketcur INTO : ticketPtr; // 커서의 내용 구조체 포인터에 넣음
		printf("%s %d\n", ticketPtr->mtitle, ticketPtr->cnt);
	}
	EXEC SQL CLOSE ticketcur; // 티켓 판매 통계 출력
}
int displayMainMenu(int modeFlag) { // 메인 메뉴 출력 function
	int nMenu;

	system("clear");
	printf("\n\n");
	printf("\t=====================================\n");
	printf("\t     MOVIE DATABASE PROGRAM MENU\n");
	printf("\t-------------------------------------\n");
	printf("\t   1. Mode Switch\n");
	printf("\t   2. User - Print Table\n");
	printf("\t   3. User - Make Reservation\n");
	printf("\t   4. User - Delete Reservation\n");
	printf("\t   5. User - Update Reservation\n");
	printf("\t   6. User - Search\n");
	if (modeFlag == 0) {
		printf("\t   7. Manager - Print Table\n");
		printf("\t   8. Manager - Register Movie\n");
		printf("\t   9. Manager - Delete Movie\n");
		printf("\t   10. Manager - Update Movie\n");
		printf("\t   11. Manager - Search\n");
		printf("\t   12. Init Database\n");
	}
	printf("\t-------------------------------------\n");
	printf("\t   13. EXIT\n");
	printf("\t=====================================\n");
	printf("\t   >> ");
	scanf("%d", &nMenu); // 메뉴 번호 입력받아서 반환
	getchar();
	return nMenu;
	// 메뉴 번호 입력받아서 반환
}
int searchUserMenu() { // 사용자 검색 메뉴
	int nSearchMenu;
	EXEC SQL WHENEVER SQLERROR DO sql_error("Search User error:");

	system("clear");
	printf("\n\n");
	printf("\t=====================================\n");
	printf("\t     USER SEARCH MENU\n");
	printf("\t-------------------------------------\n");
	printf("\t   1. Member's Movie Score Average\n");
	printf("\t   2. Movie Score Rank(Over 40)\n");
	printf("\t   3. Member's Goods Reservation Num\n");
	printf("\t   4. Members - didn't reserve res1\n");
	printf("\t   5. Movie Screening in t1 Theater\n");
	printf("\t-------------------------------------\n");
	printf("\t   0. Previous\n");
	printf("\t=====================================\n");
	printf("\t   >> ");
	scanf("%d", &nSearchMenu);

	switch (nSearchMenu) { // switch
	case 1: // groupby, Member's Movie Score Average
		if ((saPtr = (struct res*)malloc(sizeof(struct res))) == 0) {
			printf("grPtr Memory allocation error.\n");
			exit(EXIT_FAILURE);
		}
		EXEC SQL DECLARE msacur CURSOR FOR // 커서 선언
			SELECT memid, avg(moveScore)
			FROM movie_score
			GROUP BY memid
			HAVING avg(moveScore) > 0;
		EXEC SQL OPEN msacur;
		printf("\nMember's Movie Score Average");
		printf("\nMem ID\t\t\tAvg Movie Score");
		printf("\n------\t\t\t--------\n");
		EXEC SQL WHENEVER NOT FOUND DO break;
		for (;;) {
			EXEC SQL FETCH msacur INTO : saPtr; // 커서의 내용 구조체 포인터에 넣음
			printf("%s\t%d\n", saPtr->memid, saPtr->cnt);
		}
		EXEC SQL CLOSE msacur;
		break;

	case 2: // groupby/having, Movie Score Rank(Over 40)
		if ((scorePtr = (struct ticket*)malloc(sizeof(struct ticket))) == 0) {
			printf("scorePtr Memory allocation error.\n");
			exit(EXIT_FAILURE);
		}

		EXEC SQL DECLARE scoreCur CURSOR FOR // 커서 선언
			SELECT movie_screening.movieTitle, avg(moveScore)
			FROM movie_screening, movie_score
			WHERE movie_screening.movieID = movie_score.movieID
			GROUP BY movie_score.movieID, movie_screening.movieTitle
			HAVING avg(moveScore) > 40
			ORDER BY avg(moveScore) DESC;
		EXEC SQL OPEN scoreCur;
		printf("\nMovie Score Over 40");
		printf("\nMovie Title\t\t\t\tAvg Score");
		printf("\n------\t\t\t\t\t--------\n");
		EXEC SQL WHENEVER NOT FOUND DO break;
		for (;;) {
			EXEC SQL FETCH scoreCur INTO : scorePtr; // 커서의 내용 구조체 포인터에 넣음
			printf("%s %d\n", scorePtr->mtitle, scorePtr->cnt);
		}
		EXEC SQL CLOSE scoreCur;
		break;

	case 3: // groupby/having, Member's Goods Reservation Num
		if ((grPtr = (struct res*)malloc(sizeof(struct res))) == 0) {
			printf("grPtr Memory allocation error.\n");
			exit(EXIT_FAILURE);
		}
		EXEC SQL DECLARE grcur CURSOR FOR // 커서 선언
			SELECT memid, sum(goodsNum)
			FROM goods_reservation
			GROUP BY memid
			HAVING sum(goodsNum) > 0
			ORDER BY memid ASC;
		EXEC SQL OPEN grcur;
		printf("\nMember's Goods Reservation Num");
		printf("\nMem ID\t\t\tTotal Res Num");
		printf("\n------\t\t\t--------\n");
		EXEC SQL WHENEVER NOT FOUND DO break;
		for (;;) {
			EXEC SQL FETCH grcur INTO : grPtr; // 커서의 내용 구조체 포인터에 넣음
			printf("%s\t%d\n", grPtr->memid, grPtr->cnt);
		}
		EXEC SQL CLOSE grcur;
		break;

	case 4: // sub-query, Members - didn't reserve res1
		EXEC SQL DECLARE rescur CURSOR FOR // 커서 선언
			SELECT memid
			FROM menu_reservation
			WHERE resid NOT IN(
				SELECT resID
				FROM restaurant
				WHERE resName = 'res1'
			);
		EXEC SQL OPEN rescur;
		printf("\nMember those didn't reserve res1");
		printf("\nMem ID");
		printf("\n------\n");
		EXEC SQL WHENEVER NOT FOUND DO break;
		for (;;) {
			EXEC SQL FETCH rescur INTO : rmemid; // varchar 변수에 커서의 내용 넣음
			printf("%s\n", rmemid);
		}
		EXEC SQL CLOSE rescur;
		break;

	case 5: // sub-query, Movie Screening in t1 Theater
		EXEC SQL DECLARE miamicur CURSOR FOR // 커서 선언
			SELECT movieTitle
			FROM movie_screening
			WHERE movieID IN(
				SELECT movieID
				FROM movie_time
				WHERE theaterName = 't1'
			);
		EXEC SQL OPEN miamicur;
		printf("\nMovie Screening in t1 Theater");
		printf("\nMovie Title");
		printf("\n------\n");
		EXEC SQL WHENEVER NOT FOUND DO break;
		for (;;) {
			EXEC SQL FETCH miamicur INTO : miamimid; // varchar 변수에 커서의 내용 넣음
			printf("%s\n", miamimid);
		}
		EXEC SQL CLOSE miamicur;
		break;

	case 0:
		return; // 돌아가기
		break;

	default:
		printf("\tWrong Input!\n");
	}
	getchar();
}
int searchManagerMenu() { // 관리자 검색 함수
	int nSearchMenu;
	EXEC SQL WHENEVER SQLERROR DO sql_error("Search Manager error:");

	system("clear");
	printf("\n\n");
	printf("\t=====================================\n");
	printf("\t     MANAGER SEARCH MENU\n");
	printf("\t-------------------------------------\n");
	printf("\t   1. Ticket Sales Statistics\n");
	printf("\t   2. t1 Theater Employee\n");
	printf("\t   3. Restaurant not in t10 Theater\n");
	printf("\t   4. Goods Name - Goods Num over 50\n");
	printf("\t   5. Grade Reserve Money Rank\n");
	printf("\t   6. Restaurant Numbers in Theater\n");
	printf("\t   7. Restaurant Menu Average Price\n");
	printf("\t   8. Movie Information - opens at 30/05/16\n");
	printf("\t   9. Singer's Total Song Num\n");
	printf("\t-------------------------------------\n");
	printf("\t   0. Previous\n");
	printf("\t=====================================\n");
	printf("\t   >> ");
	scanf("%d", &nSearchMenu);

	switch (nSearchMenu) { // switch
	case 1: // Ticket Sales Statistics
		ticket();
		break;

	case 2: // sub-query, t1 Theater Employee
		EXEC SQL DECLARE empcur CURSOR FOR // 커서 선언 // 커서 선언
			SELECT empName
			FROM employee
			WHERE theaterName IN(
				SELECT theaterName
				FROM theater
				WHERE theaterName = 't1'
			);
		EXEC SQL OPEN empcur;
		printf("\nt1 Theater Employee");
		printf("\nEmployee Name");
		printf("\n------\n");
		EXEC SQL WHENEVER NOT FOUND DO break;
		for (;;) {
			EXEC SQL FETCH empcur INTO : rmemid; // varchar 변수에 커서의 내용 넣음
			printf("%s\n", rmemid);
		}
		EXEC SQL CLOSE empcur;
		break;

	case 3: // sub-query, Restaurant not in t10 Theater
		EXEC SQL DECLARE rescur1 CURSOR FOR // 커서 선언
			SELECT resName
			FROM restaurant
			WHERE theaterName NOT IN(
				SELECT theaterName
				FROM theater
				WHERE theaterName = 't10'
			)
			ORDER BY resName ASC;
		EXEC SQL OPEN rescur1;
		printf("\nRestaurant not in t10 Theater");
		printf("\nRestaurant Name");
		printf("\n------\n");
		EXEC SQL WHENEVER NOT FOUND DO break;
		for (;;) {
			EXEC SQL FETCH rescur1 INTO : rmemid; // varchar 변수에 커서의 내용 넣음
			printf("%s\n", rmemid);
		}
		EXEC SQL CLOSE rescur1;
		break;

	case 4: // Goods Name - Goods Num over 50
		if ((gnPtr = (struct res*)malloc(sizeof(struct res))) == 0) {
			printf("gnPtr Memory allocation error.\n");
			exit(EXIT_FAILURE);
		}
		EXEC SQL DECLARE gncur CURSOR FOR // 커서 선언
			SELECT goodsName, goodNum
			FROM goods
			WHERE goodNum > 50;
		EXEC SQL OPEN gncur;
		printf("\nGoods Name - Goods Num over 50");
		printf("\nGoods Name\t\tGoods Num");
		printf("\n------\t\t\t--------\n");
		EXEC SQL WHENEVER NOT FOUND DO break;
		for (;;) {
			EXEC SQL FETCH gncur INTO : gnPtr; // 커서의 내용 구조체 포인터에 넣음
			printf("%s\t%d\n", gnPtr->memid, gnPtr->cnt);
		}
		EXEC SQL CLOSE gncur;
		break;

	case 5: // groupby/having, Grade Reserve Money Rank
		if ((gradePtr = (struct res*)malloc(sizeof(struct res))) == 0) {
			printf("gradePtr Memory allocation error.\n");
			exit(EXIT_FAILURE);
		}
		EXEC SQL DECLARE gradecur CURSOR FOR // 커서 선언
			SELECT memGrade, sum(memReserve)
			FROM members
			GROUP BY memGrade
			HAVING sum(memReserve) > 0
			ORDER BY sum(memReserve) DESC;
		EXEC SQL OPEN gradecur;
		printf("\nGrade Reserve Money Rank");
		printf("\nGrade\t\t\tTotal Reserve Money");
		printf("\n------\t\t\t--------\n");
		EXEC SQL WHENEVER NOT FOUND DO break;
		for (;;) {
			EXEC SQL FETCH gradecur INTO : gradePtr; // 커서의 내용 구조체 포인터에 넣음
			printf("%s\t%d\n", gradePtr->memid, gradePtr->cnt);
		}
		EXEC SQL CLOSE gradecur;
		break;

	case 6: // Restaurant Numbers in Theater
		if ((resnumPtr = (struct res*)malloc(sizeof(struct res))) == 0) {
			printf("resnumPtr Memory allocation error.\n");
			exit(EXIT_FAILURE);
		}
		EXEC SQL DECLARE resnumcur CURSOR FOR // 커서 선언
			SELECT theaterName, count(*)
			FROM restaurant
			GROUP BY theaterName
			ORDER BY count(*) ASC;
		EXEC SQL OPEN resnumcur;
		printf("\nRestaurant Numbers in Theater");
		printf("\nTheather ID\t\tRestaurant Number ");
		printf("\n------\t\t\t--------\n");
		EXEC SQL WHENEVER NOT FOUND DO break;
		for (;;) {
			EXEC SQL FETCH resnumcur INTO : resnumPtr; // 커서의 내용 구조체 포인터에 넣음
			printf("%s\t%d\n", resnumPtr->memid, resnumPtr->cnt);
		}
		EXEC SQL CLOSE resnumcur;
		break;

	case 7: // Restaurant Menu Average Price
		if ((avgPtr = (struct res*)malloc(sizeof(struct res))) == 0) {
			printf("avgPtr Memory allocation error.\n");
			exit(EXIT_FAILURE);
		}
		EXEC SQL DECLARE resavgcur CURSOR FOR // 커서 선언
			SELECT resName, avg(menuPrice)
			FROM menu
			GROUP BY resName;
		EXEC SQL OPEN resavgcur;
		printf("\nRestaurant Menu Average Price");
		printf("\nRestaurant Name\t\tAverage Price");
		printf("\n------\t\t\t--------\n");
		EXEC SQL WHENEVER NOT FOUND DO break;
		for (;;) {
			EXEC SQL FETCH resavgcur INTO : avgPtr; // 커서의 내용 구조체 포인터에 넣음
			printf("%s\t%d\n", avgPtr->memid, avgPtr->cnt);
		}
		EXEC SQL CLOSE resavgcur;
		break;

	case 8: // Movie Information - opens at 30/05/16
		if ((msPtr = (struct movie_scheduled *)malloc(sizeof(struct movie_scheduled))) == 0) {
			printf("movie_scheduledPtr Memory allocation error.\n");
			exit(EXIT_FAILURE);
		}
		EXEC SQL DECLARE mscur CURSOR FOR // 커서 선언
			SELECT * FROM movie_scheduled WHERE openDate = '30/05/16';
		EXEC SQL OPEN mscur;
		printf("\nMovie_scheduled Table");
		printf("\nMovieTitle\t\t\t\tDirectorName");
		printf("\n---------\t\t\t\t----------\n");
		EXEC SQL WHENEVER NOT FOUND DO break;
		for (;;) {
			EXEC SQL FETCH mscur INTO : msPtr; // 커서의 내용 구조체 포인터에 넣음
			printf("%s %s\n", msPtr->movietitle, msPtr->directorname);
		}
		EXEC SQL CLOSE mscur;
		break;

	case 9: // groupby/having, Singer's Total Song Num
		if ((songPtr = (struct res*)malloc(sizeof(struct res))) == 0) {
			printf("songPtr Memory allocation error.\n");
			exit(EXIT_FAILURE);
		}
		EXEC SQL DECLARE songcur CURSOR FOR // 커서 선언
			SELECT singer, count(*)
			FROM music
			GROUP BY singer
			HAVING count(*) > 0;
		EXEC SQL OPEN songcur;
		printf("\nSinger's Total Song Num");
		printf("\nSinger\t\t\tTotal Song Num");
		printf("\n------\t\t\t--------\n");
		EXEC SQL WHENEVER NOT FOUND DO break;
		for (;;) {
			EXEC SQL FETCH songcur INTO : songPtr; // 커서의 내용 구조체 포인터에 넣음
			printf("%s\t%d\n", songPtr->memid, songPtr->cnt);
		}
		EXEC SQL CLOSE songcur;
		break;

	case 0:
		return; // 돌아가기
		break;

	default:
		printf("\tWrong Input!\n");
	}
	getchar();
}
void main()
{
	int bIterationFlag = 1;
	int menuNum;
	int modeFlag = 1; // user = 1, manager = 0;
	char pw[10];
	int enterFlag = 1;

	/* Connect to ORACLE. */
	EXEC SQL WHENEVER SQLERROR DO sql_error("Connect error:");

	EXEC SQL CONNECT : username IDENTIFIED BY : password;
	printf("\nConnected to ORACLE as user: %s\n", username);

	while (bIterationFlag) {
		menuNum = displayMainMenu(modeFlag);

		switch (menuNum) {
		case 1: // mode switch
			if (modeFlag) { // User일 때
				printf("\tInput Manager PassWord : ");
				scanf("%s", pw); // manager pw 입력
				if (strcmp(pw, "dbm1234") == 0) { // login 성공
					printf("\tDB Manager Login Success!!\n");
					modeFlag = 0;
				}
				else // login 실패
					printf("\tDB Manager Login Fail!!\n");
			}
			else // Manager일 때
				modeFlag = 1;
			break;

		case 2: // User - Print Table
			userPrint();
			break;

		case 3: // User - Make Reservation
			makeReservation();
			break;

		case 4: // User - Delete Reservation
			deleteReservation();
			break;

		case 5: // User - Update Reservation
			updateReservation();
			break;
		case 6: // User - Search Menu
			searchUserMenu();
			break;

		case 7: // Manager - Print Table
			if (modeFlag == 0) { // manager일때
				managerPrint();
			}
			break;

		case 8: // Manager - Input Movie Scheduled
			if (modeFlag == 0) { // manager일때
				InsertMovieScheduled();
			}
			break;

		case 9: // Manager - Delete Movie Scheduled
			if (modeFlag == 0) { // manager일때
				deleteMovieScheduled();
			}
			break;

		case 10: // Manager - Update Movie Scheduled
			if (modeFlag == 0) { // manager일때
				updateMovieScheduled();
			}
			break;

		case 11: // Manager - Search Menu
			if (modeFlag == 0) { // manager일때
				searchManagerMenu();
			}
			break;

		case 12: // init database
			if (modeFlag == 0) { // manager일때
				initDatabase();
			}
			break;

		case 13: // exit
			bIterationFlag = 0;
			printf("\tExit Movie Database\n\n");
			enterFlag = 0;
			break;

		default:
			printf("\tWrong Input!\n");
		}

		if (enterFlag) {
			printf("\n\tPress Enter to Continue\n");
			getchar();
		}
	}

	EXEC SQL COMMIT WORK RELEASE;
	exit(EXIT_SUCCESS);
}
