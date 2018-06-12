package com.kpu.acs;

import java.util.*;
import java.awt.SecondaryLoop;
import java.time.*;
import java.io.*;

class Ticket {
	private String ticket_seat;
	private int entryday[]; // 입국일
	private int leaveday[]; // 출국일

	Ticket(String userticketseat, int userentryday[], int userleaveday[]) {
		ticket_seat = userticketseat;
		for (int i = 0; i < 3; i++) {
			entryday[i] = userentryday[i];
			leaveday[i] = userleaveday[i];
		}
	}
}

class User {
	private int passnum;
	private String name;
	private int age;
	private String region;
	private Ticket myTicket;

	public User() {
	}

	public User(int userpassnum, String username, int userage, String userregion, String userticketseat,
			int userentryday[], int userleaveday[]) {
		passnum = userpassnum;
		name = username;
		age = userage;
		region = userregion;
		myTicket = new Ticket(userticketseat, userentryday, userleaveday);
	}

	void banitem_check(int isBanitem) {
	}; // 금지물품 체크 가상함수

	public int blacklist() {
		return passnum;
	}

	public void showyou() {
		System.out.printf("Passnumber : %d Name : %s \n", passnum, name);
	}

}

class Leaveitem {
	private int isBanitem;

	Leaveitem() {
	}

	Leaveitem(int l) {
		isBanitem = l;
	}

	void isBanitem_init() {
		Random random = new Random();
		isBanitem = random.nextInt(20);
	}

	int sendban() {
		return isBanitem;
	}
}

class Leavelist extends User {
	private int leavelist_eday[];
	private int leavelist_lday[]; // 출국일 [0]은 년,[1]은 월,[2]은 일
	private Leaveitem leavepack; // 출국자 짐

	public Leavelist() {
	} // 출국자의 default 생성자

	public Leavelist(int userpassnum, String username, int userage, String userregion, String userticketseat,
			int userentryday[], int userleaveday[]) {
		super(userpassnum, username, userage, userregion, userticketseat, userentryday, userleaveday);
		for (int i = 0; i < 3; i++) {
			leavelist_eday[i] = userentryday[i];
			leavelist_lday[i] = userleaveday[i];
		}
		leavepack.isBanitem_init();

	}

	// 출국자 생성자 (여권번호, 이름, 나이, 국적, 출국일(연,월,일))
	public void banitem_check() {
		int i = leavepack.sendban();
		if (i == 0) {
			System.out.println("수화물 내 금지물품 존재");
			System.out.println("금지물품 폐기 완료 통과");
		} else {
			System.out.println("수화물 내 금지물품 없음 통과");
		}
	}// 출국자 짐 내의 금지물품 조사
}

class RFID {
	private int price;
	private int[] buyday;

	RFID() {
	}

	void RFID_init(int ipay, int[] ibuyday) {
		price = ipay;
		buyday = ibuyday;
	}

	int RFID_buypick(int[] entryday, int[] leaveday) {
		LocalDate entryDate = LocalDate.of(entryday[0], entryday[1], entryday[2]);
		LocalDate leaveDate = LocalDate.of(leaveday[0], leaveday[1], leaveday[2]);
		LocalDate buyDate = LocalDate.of(buyday[0], buyday[1], buyday[2]);

		if (buyDate.isAfter(entryDate) == buyDate.isBefore(leaveDate)) {

			return price;
		} else {
			return 0;
		}

	}
}

class Entryitem {
	private RFID rfid;

	Entryitem() {
	}

	void item_init() {
		Random random = new Random();
		int pay = random.nextInt(10000) * 100;
		int[] buyday = { 2013 + random.nextInt(5), 1 + random.nextInt(12), 1 + random.nextInt(27) };
		rfid.RFID_init(pay, buyday);
	}

	int passing_price(int[] entryday, int[] leaveday) {
		return rfid.RFID_buypick(entryday, leaveday);
	}
}

class Entrylist extends User {
	private int entrylist_eday[]; // 입국일 [0]은 년,[1]은 월,[2]은 일
	private int entrylist_lday[]; // 출국일 "
	private Entryitem entrypack[]; // 입국자 짐
	private int isBanitem;

	public Entrylist() {
	}

	public Entrylist(int userpassnum, String username, int userage, String userregion, String userticketseat,
			int userentryday[], int userleaveday[]) {
		super(userpassnum, username, userage, userregion, userticketseat, userentryday, userleaveday);
		Random random = new Random();

		isBanitem = random.nextInt(100) % 20;
		for (int i = 0; i < 3; i++) {
			entrylist_eday[i] = userentryday[i]; // 입국일자 입력
			entrylist_lday[i] = userleaveday[i];
		}

		int j = 0; // 입국자 수화물 index 번호 지정을 위한 변수
		for (int i = (random.nextInt(100) % 6); i < 5; i++) // 입국자의 수화물 갯수를 (5-i)만큼 정해줌
		{
			entrypack[j] = new Entryitem(); // 입국자 수화물 생성 index 번호를 넣어주고 ++
			entrypack[j].item_init();
			entrypack[(j + 1)] = null;
			j++;
		}
	}

	public void banitem_check() {
		int i;
		for (int j = 0; j < 5; j++) {
			if (entrypack[j] != null) {
				i = sendban();
				if (i == 0) {
					System.out.println("수화물 내 금지물품 존재");
					System.out.println("금지물품 폐기 완료 통과");
					break;
				} else {
					System.out.println("수화물 내 금지물품 없음 통과");
					break;
				}
			}
		}
	}

	public void overEntrylist_check() {
		int lenghtofstay = 0; // 체류기간을 받는 변수
		Date today = new Date();
		Calendar cal = Calendar.getInstance();
		cal.setTime(today);// 오늘로 설정.

		Calendar cal2 = Calendar.getInstance();
		cal2.set(entrylist_eday[0], entrylist_eday[1], entrylist_eday[2]); //

		while (!cal2.after(cal)) {
			lenghtofstay++;
			cal2.add(Calendar.DATE, 1); // 다음날로 바뀜
		}
		System.out.printf("Lenght of stay :  %d \n", lenghtofstay);
	} // 불법체류여부 확인

	public int passing_price() {

		int pay = 0;
		for (int i = 0; entrypack[(i + 1)] == null; i++) {
			pay += entrypack[i].passing_price(entrylist_eday, entrylist_lday);

		}

		return pay;

	}

	public int sendban() {
		return isBanitem;
	}

}

class Flightschedule {
	private String airline;
	private String destination;
	private int seat[];
	private int hour2;
	private String shit2;
	private int min2;

	Flightschedule() {
	}

	Flightschedule(String fairline, String fdestination, int fseat[], int fhour, String fshit, int fmin) {
		airline = fairline;
		destination = fdestination;
		hour2 = fhour;
		shit2 = fshit;
		min2 = fmin;
		for (int i = 0; i < 3; i++) {
			seat[i] = fseat[i];
		}
	}

	void showthat() {
		if (min2 == 0)
			System.out.printf(airline, "\t", destination, "\t", seat[0], "\t", seat[1], "\t", seat[2], "\t", hour2,
					shit2, "0", min2);
		else
			System.out.printf("%s\t %s\t %d\t %d\t %d\t %d%s%d", airline, destination, seat[0], seat[1], seat[2], hour2,
					shit2, min2);
	}

	void takeoff_check(Controltower ct) {// 비행일정 및 좌석 체크 함수
		int set, set2;
		int i = 0;

		while (i == 0) {
			set = ct.weathercenter_check(); // 기상청
			set2 = ct.runway_check(); // 활주로

			if (min2 >= 60) {
				min2 -= 60;
				hour2 += 1;
			}
			showthat();
			if (set > 3 && set2 > 0) {
				System.out.println("\nDelay in Airplain, Reason : Bad weather. \n\n");
				min2 += 30;
			} else if (set2 == 0 && set < 4) {
				System.out.println("\nDelay in Airplain, Reason : Runway exceeded. \n\n");
				min2 += 10;
			} else if (set > 3 && set2 == 0) {
				System.out.println("\nDelay in Airplain, Reason : Bad weather and Runway exceeded.  \n\n");
				min2 += 40;
			} else {
				System.out.println("\nComplete.\n");
				i = 1;
			}
		}
	}

}

class Controltower {
	private int runway;
	private int weather;

	Controltower() {
	}

	int weathercenter_check() {
		Random rands = new Random();
		weather = 1 + rands.nextInt(5); // 1~5 랜덤숫자 부여
		return weather;
	}

	int runway_check() {
		Random rands2 = new Random();
		runway = rands2.nextInt(4); // 0~4 랜덤숫자 부여 , 0일시 남은 활주로 0
		return runway;
	}
}

class Blacklist {
	private int reason;

	Blacklist() {
	}

	int reason_print(int upass) {
		switch (upass % 100) {
		case 0:
			System.out.println("Reason : 불법체류 기록 존재");
			reason = 1;
			return reason;
		case 1:
			System.out.println("Reason : 밀입국 기록 존재");
			reason = 1;
			return reason;
		case 2:
			System.out.println("Reason : 테러리스트 분류");
			reason = 1;
			return reason;
		case 3:
			System.out.println("Reason : 형사재판 진행중");
			reason = 1;
			return reason;
		default:
			System.out.println("블랙리스트 해당사항 없음");
			reason = 0;
			return reason;
		}
	}
}

class Tariff {
	private int pay_amount;
	private int tariff_amount;

	void getRFID_amount(Entrylist elist) {
		pay_amount = elist.passing_price();
	}

	void calcTariff(Entrylist elist) {
		getRFID_amount(elist);
		if (pay_amount >= 200000) {
			tariff_amount = (int) (pay_amount * 0.2);
		} else {
			tariff_amount = 0;
		}
	}

	void Tairff_print(Entrylist elist) {

		calcTariff(elist);
		System.out.println("이 이용자에게 부가될 총 관세는 " + tariff_amount + "원 입니다.");
	}
}

class main_func {
	void createUser(Entrylist elist[]) {
        int fpassnum;
        int fage;
        int []fentrtday; 
        int []fleaveday;
        String fname, fregion, fseat;
        
        File file=new File("entry.txt");
        try {
           Scanner sc = new Scanner(file);
           for (int i = 0; !sc.hasNext(); i++) {
              elist[i] = new Entrylist(fpassnum, fname, fage, fregion, fseat, fentrtday, fleaveday);
           }
        }
        catch(FileNotFoundException e) {
           System.out.println("file is empty.");
        }

	// if (file.is_open() == true)
	// {
	// file.close();
	// }
	// }

	void createban(Entrylist blist[]) {

        int fpassnum;
        int fage;
        int []fentrtday;
        int []fleaveday;
        String fname, fregion, fseat;
        File file=new File("Illegal_resident.txt");

        try {
              Scanner sc = new Scanner(file);
              for (int i = 0; !sc.hasNext()(); i++) {
                 file >> fpassnum >> fname >> fage >> fregion >> fseat >> fentrtday[0] >> fentrtday[1] >> fentrtday[2] >> fleaveday[0] >> fleaveday[1] >> fleaveday[2];
                 blist[i] = new Entrylist(fpassnum, fname, fage, fregion, fseat, fentrtday, fleaveday);
              }
           }
           catch(FileNotFoundException e) {
              System.out.println("file is empty.");
           }

	// if (file.is_open() == true)
	// {
	// file.close();
	// }
	// }

	void createUser(Leavelist llist[]) {

        int fpassnum, fage, fentrtday[], fleaveday[];
        String fname, fregion, fseat;
        
        File file=new File("leave.txt");

        try {
              Scanner sc = new Scanner(file);
              for (int i = 0; !sc.hasNext(); i++) {
                
              }
                 file >> fpassnum >> fname >> fage >> fregion >> fseat >> fentrtday[0] >> fentrtday[1] >> fentrtday[2] >> fleaveday[0] >> fleaveday[1] >> fleaveday[2];

                 llist[i] = new Leavelist(fpassnum, fname, fage, fregion, fseat, fentrtday, fleaveday);
              }
           }catch(

	FileNotFoundException e)
	{
		System.out.println("file is empty.");
	}

	// if (file.is_open() == true)
	// {
	// file.close();
	// }
	// }

	void createFlightSchedule(FlightSchedule fschedule[]) {

        String qairline;
        String qdestination;
        int qseat[];
        int qhour;
        String qshit;
        int qmin;
       
        int i = 0;
      
        File file=new File("Leave_Airplane.txt");

        try {
              Scanner sc = new Scanner(file);
              for (int i = 0; !sc.hasNext()(); i++) {
                 file >> qairline >> qdestination >> qseat[0] >> qseat[1] >> qseat[2] >> qhour >> qshit >> qmin;

                    fschedule[i] = new FlightSchedule(qairline, qdestination, qseat, qhour, qshit, qmin);
              }
           }
           catch(FileNotFoundException e) {
              System.out.println("file is empty.");
           }

        
          
       // if (file.is_open() == true)
       // {
        //   file.close();
       // }

       
        File file=new File("Entry_Airplane.txt");

        try {
              Scanner sc = new Scanner(file);
              for (int i = 0; !sc.hasNext()(); i++) 
              {
                 file >> qairline >> qdestination >> qseat[0] >> qseat[1] >> qseat[2] >> qhour >> qshit >> qmin;

                    fschedule[i] = new FlightSchedule(qairline, qdestination, qseat, qhour, qshit, qmin);
              }
           }
           catch(FileNotFoundException e) {
              System.out.println("file is empty.");
           }

	// if (file.is_open() == true)
	// {
	// file.close();
	// }
	// }

	void leaveprocess(Leavelist llist[])
     {
        Blacklist bl;
        int j;
        char z;
        Scanner s = new Scanner(System.in);
         
        for (int i = 0; i < 200; i++)
        {
           j = 0;
           System.out.println( "-----------------------------------------------");
           llist[i].showyou();
           j = bl.reason_print(llist[i].blacklist());
           if (j == 0)
           {
              llist[i].banitem_check();
              System.out.println( "-Departure process completed-" );
           }
           System.out.println( "-----------------------------------------------"); 

           System.out.println("");
           System.out.println( "Shall we proceed to the next person?   y/n" );
           System.out.println ( "[Leave]:# ");
           Scanner s1 = new Scanner(System.in);
           switch (s1.nextLine().charAt(0))
           {
           case'n':
              while (s1.nextLine().charAt(0) != '\n');
              System.out.println ("");
              System.out.println ( "-Departure process program end-" ) ;
              System.out.println ( "-----------------------------------------------" ) ;
              return;
           case'y':
              while (s1.nextLine().charAt(0) != '\n');
              break;
           default:
              while (s1.nextLine().charAt(0) != '\n');
              System.out.println ("") ;
              System.out.println ( "error!! worng char keep process" ( ;
              System.out.println ("");
              break;
           }
        }
     }

	void leaveprocess(Entrylist elist[]) {
		Blacklist bl;
		TARIFF ta;
		int j;
		for (int i = 0; i < 200; i++) {
			j = 0;
			System.out.println("-----------------------------------------------");
			elist[i].showyou();
			j = bl.reason_print(elist[i].blacklist());
			if (j == 0) {
				elist[i].banitem_check();
				ta.Tariff_print(elist[i]);
				System.out.println("-Departure process completed-");

			}
			System.out.println("-----------------------------------------------");

			System.out.println("");
			System.out.println("Shall we proceed to the next person?   y/n");
			System.out.println("[Entry]:# ");
			Scanner s1 = new Scanner(System.in);

			switch (s1.nextLine().charAt(0)) {
			case 'n':
				while (s1.nextLine().charAt(0) != '\n')
					;
				System.out.println("");
				System.out.println("-Departure process program end-");
				System.out.println("-----------------------------------------------");
				return;
			case 'y':
				while (s1.nextLine().charAt(0) != '\n')
					;
				break;
			default:
				while (s1.nextLine().charAt(0) != '\n')
					;
				System.out.println("");
				System.out.println("error!! worng char keep process");
				System.out.println("");
				break;
			}
		}
	}

	void Airplainlist(FlightSchedule fschedule[])
     {
        int i = 0;
        while (true)
        {
           System.out.println ( "Choose Schedule:");
           System.out.println ( "L. 『Leave Airline』");
           System.out.println ( "E. 『Entry Airline』");
           System.out.println ( "Q. 『Quit』" ) ;
           System.out.println ( "[Schedule]:# ");
           Scanner s1 = new Scanner(System.in);
           
           switch (s1.nextLine().charAt(0))
           {
           case'l':
           case'L':
        
              while (s1.nextLine().charAt(0)!= '\n');
              System.out.println ( "『Leave Airline』" ) ;
              System.out.println ( setw(21) ( "【 Airline 】" ) setw(19) ( "【 Destination 】" ) setw(14) ( "【 First 】" ) setw(17) ( "【 Bussiness 】" ) setw(16) ( "【 Economy 】" ) setw(14) ( "【 Time 】" ) ;
              for (i = 0; i < 80; i++)
              {
                 fschedule[i].showthat();
              }
              break;
           case'e':
           case'E':
              while (s1.nextLine().charAt(0)!= '\n');
              System.out.println ( "\n『Entry Airline』") ;
              System.out.println ( setw(21) ( "【 Airline 】" ) setw(19) ( "【 Destination 】" ) setw(14) ( "【 First 】" ) setw(17) ( "【 Bussiness 】" ) setw(16) ( "【 Economy 】" ) setw(14) ( "【 Time 】" ) ;
              for (i = 80; i < 100; i++)
              {
                 fschedule[i].showthat();
              }
              break;
           case'q':
           case'Q':
       
              while (s1.nextLine().charAt(0) != '\n');
              System.out.println ("");
              System.out.println ( "Schedule Print end" ) ;
              System.out.println ("");
              return;
           default:
              while (s1.nextLine().charAt(0) != '\n');
              System.out.println ("") ;
              System.out.println ( "error!! worng char") ;
              System.out.println ("");
              break;
           }
        }
     }

	void Airlinemanagement(Flightschedule fschedule[], Controltower ct) {
		System.out.println("-----------------------------------------------");
		for (int i = 0; i < 100; i++) {
			fschedule[i].takeoff_check(ct);
		}
		System.out.println("");
		System.out.println("");
		System.out.println("-Airline Management process program end-");
		System.out.println("-----------------------------------------------");
	}

	void Illegal_resident(Entrylist blist[]) {
		for (int i = 0; i < 20; i++) {
			System.out.println("-----------------------------------------------");
			blist[i].showyou();
			blist[i].overEntrylist_check();
			System.out.println("-----------------------------------------------");
			System.out.println();
			System.out.println();
			System.out.println("Shall we proceed to the next person?   y/n");
			System.out.println("[Illegal]:# ");
			Scanner s1 = new Scanner(System.in);

			switch (s1.nextLine().charAt(0)) {
			case 'n':
				while (s1.nextLine().charAt(0) != '\n')
					;
				System.out.println();
				System.out.println("-Illegal Resident process program end-");
				System.out.println("-----------------------------------------------");
				return;
			case 'y':
				while (s1.nextLine().charAt(0) != '\n')
					;
				break;
			default:
				while (s1.nextLine().charAt(0) != '\n')
					;
				System.out.println("");
				System.out.println("error!! worng char keep process");
				System.out.println("");
				break;
			}
		}
	}
}

public class acs {
	public static int main(String[] args) {
		// TODO Auto-generated method stub
		// Airport Control System Main Function
		// coding by Banetta Han Sang Kim

		Flightschedule[] fs;
		Controltower ct;
		Entrylist[] elist;
		Leavelist[] llist;
		Entrylist[] banlist;
		Scanner sc = new Scanner(System.in);

		System.out.println("===   Airport Control System [ACS]   ===\n");
		while (true) // Menu 구성
		{
			// Menu 출력
			System.out.println("=== Menu ===\n");
			System.out.println("i : File Input\n");
			System.out.println("e : Entry Process\n"); // 입국 절차
			System.out.println("l : Leave Process\n"); // 출국 절차
			System.out.println("t : Today Airplain list\n"); // 금일 입출항 목록
			System.out.println("a : Airplain Access Management\n"); // 항공기 입출항 관리
			System.out.println("o : OverEntryUser Check\n"); // 불법 체류자 체크
			System.out.println("q : Quit Program\n"); // 프로그램 종료
			System.out.println("[ACS]:# \n");

			switch (sc.nextLine().charAt(0)) // menu switch문 : getchar()를 이용, 문자를 받아서 적용
			{
			case 'i': // 이용자 정보 파일 입력 메뉴
				while (sc.nextLine().charAt(0) != '\n')
					; // getchar()사용시 버퍼에 입력값이 남아서 이중실행이 될 수 있기 때문에 버퍼를 비우는 작업을 한다.
				System.out.println("금일 항공기 입출항 정보를 불러옵니다");
				createFlightSchedule(fs);
				System.out.println("금일 항공기 입출항 정보 불러오기 완료");
				System.out.println("이용자 정보를 불러옵니다");
				createUser(elist);
				createUser(llist);
				createban(banlist);
				System.out.println("이용자 정보 불러오기 완료");
				break;
			case 'e': // 입국 절차 메뉴
				while (sc.nextLine().charAt(0) != '\n')
					; // 버퍼를 비우는 작업.
				leaveprocess(elist);
				break;
			case 'l': // 출국 절차 메뉴
				while (sc.nextLine().charAt(0) != '\n')
					; // 버퍼를 비우는 작업.
				leaveprocess(llist);
				break;
			case 't': // 금일 입출항 목록
				while (c != '\n')
					; // 버퍼를 비우는 작업.
				Airplainlist(fs);
				break;
			case 'a': // 비행기 입출항 관리 메뉴
				while (sc.nextLine().charAt(0) != '\n')
					; // 버퍼를 비우는 작업.
				Airlinemanagement(fs, ct);
				break;
			case 'o': // 불법 체류자 체크 메뉴
				while (sc.nextLine().charAt(0) != '\n')
					; // 버퍼를 비우는 작업.
				Illegal_resident(banlist);
				break;
			case 'q': // 프로그램 종료 메뉴
				while (sc.nextLine().charAt(0) != '\n')
					; // 버퍼를 비우는 작업.
				System.out.println("\n\n");
				System.out.println("end of program\n");
				return 0; // 프로그램 종료
			default: // error 경고문 출력 (메뉴 잘못 입력시)
				while (sc.nextLine().charAt(0) != '\n')
					; // 버퍼를 비우는 작업.
				System.out.println("\nerror!! worng char\n");
				break;
			}
		}
	}

}