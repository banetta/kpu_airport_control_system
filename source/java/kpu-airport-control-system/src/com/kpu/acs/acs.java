package com.kpu.acs;

import java.util.*;
import java.awt.SecondaryLoop;
import java.time.*;
import java.io.*;

class Ticket {
	private String ticket_seat;
	private int entryday[] = {0,0,0}; // �Ա���
	private int leaveday[] = {0,0,0}; // �ⱹ��

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

	public User(int userpassnum, String username, int userage, String userregion, String userticketseat, int userentryday[], int userleaveday[]) {
		passnum = userpassnum;
		name = username;
		age = userage;
		region = userregion;
		myTicket = new Ticket(userticketseat, userentryday, userleaveday);
	}

	void banitem_check(int isBanitem) {
	}; // ������ǰ üũ �����Լ�

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
	private int leavelist_eday[] = {0,0,0};
	private int leavelist_lday[] = {0,0,0}; // �ⱹ�� [0]�� ��,[1]�� ��,[2]�� ��
	private Leaveitem leavepack = new Leaveitem(); // �ⱹ�� ��

	public Leavelist() {
	} // �ⱹ���� default ������

	public Leavelist(int userpassnum, String username, int userage, String userregion, String userticketseat, int userentryday[],
			int userleaveday[]) {
		super(userpassnum, username, userage, userregion, userticketseat, userentryday, userleaveday);
		for (int i = 0; i < 3; i++) {
			leavelist_eday[i] = userentryday[i];
			leavelist_lday[i] = userleaveday[i];
		}
		leavepack.isBanitem_init();

	}

	// �ⱹ�� ������ (���ǹ�ȣ, �̸�, ����, ����, �ⱹ��(��,��,��))
	public void banitem_check() {
		int i = leavepack.sendban();
		if (i == 0) {
			System.out.println("��ȭ�� �� ������ǰ ����");
			System.out.println("������ǰ ��� �Ϸ� ���");
		} else {
			System.out.println("��ȭ�� �� ������ǰ ���� ���");
		}
	}// �ⱹ�� �� ���� ������ǰ ����
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
	private RFID rfid = new RFID();

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
	private int entrylist_eday[] = {0,0,0}; // �Ա��� [0]�� ��,[1]�� ��,[2]�� ��
	private int entrylist_lday[] = {0,0,0}; // �ⱹ�� "
	private Entryitem entrypack[] = new Entryitem[5]; // �Ա��� ��
	private int isBanitem;

	public Entrylist() {
	}

	public Entrylist(int userpassnum, String username, int userage, String userregion, String userticketseat, int userentryday[],
			int userleaveday[]) {
		super(userpassnum, username, userage, userregion, userticketseat, userentryday, userleaveday);
		Random random = new Random();

		isBanitem = random.nextInt(100) % 20;
			
		for (int i = 0; i < 3; i++) {
			entrylist_eday[i] = userentryday[i]; // �Ա����� �Է�
			entrylist_lday[i] = userleaveday[i];
		}

		int j = 0; // �Ա��� ��ȭ�� index ��ȣ ������ ���� ����
		for (int i = (random.nextInt(100) % 6); i < 5; i++) // �Ա����� ��ȭ�� ������ (5-i)��ŭ ������
		{
			entrypack[j] = new Entryitem(); // �Ա��� ��ȭ�� ���� index ��ȣ�� �־��ְ� ++
			entrypack[j].item_init();
			//entrypack[(j + 1)] = null;
			j++;
		}
	}

	public void banitem_check() {
		int i;
		for (int j = 0; j < 5; j++) {
			if (entrypack[j] != null) {
				i = sendban();
				if (i == 0) {
					System.out.println("��ȭ�� �� ������ǰ ����");
					System.out.println("������ǰ ��� �Ϸ� ���");
					break;
				} else {
					System.out.println("��ȭ�� �� ������ǰ ���� ���");
					break;
				}
			}
		}
	}

	public void overEntrylist_check() {
		int lenghtofstay = 0; // ü���Ⱓ�� �޴� ����
		Date today = new Date();
		Calendar cal = Calendar.getInstance();
		cal.setTime(today);// ���÷� ����.

		Calendar cal2 = Calendar.getInstance();
		cal2.set(entrylist_eday[0], entrylist_eday[1], entrylist_eday[2]); //

		while (!cal2.after(cal)) {
			lenghtofstay++;
			cal2.add(Calendar.DATE, 1); // �������� �ٲ�
		}
		System.out.printf("Lenght of stay :  %d \n", lenghtofstay);
	} // �ҹ�ü������ Ȯ��

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
	private int seat[] = {0,0,0};
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
			System.out.printf(airline, "\t", destination, "\t", seat[0], "\t", seat[1], "\t", seat[2], "\t", hour2, shit2, "0", min2);
		else
			System.out.printf("%s\t %s\t %d\t %d\t %d\t %d%s%d", airline, destination, seat[0], seat[1], seat[2], hour2, shit2, min2);
	}

	void takeoff_check(Controltower ct) {// �������� �� �¼� üũ �Լ�
		int set, set2;
		int i = 0;

		while (i == 0) {
			set = ct.weathercenter_check(); // ���û
			set2 = ct.runway_check(); // Ȱ�ַ�

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
		weather = 1 + rands.nextInt(5); // 1~5 �������� �ο�
		return weather;
	}

	int runway_check() {
		Random rands2 = new Random();
		runway = rands2.nextInt(4); // 0~4 �������� �ο� , 0�Ͻ� ���� Ȱ�ַ� 0
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
			System.out.println("Reason : �ҹ�ü�� ��� ����");
			reason = 1;
			return reason;
		case 1:
			System.out.println("Reason : ���Ա� ��� ����");
			reason = 1;
			return reason;
		case 2:
			System.out.println("Reason : �׷�����Ʈ �з�");
			reason = 1;
			return reason;
		case 3:
			System.out.println("Reason : �������� ������");
			reason = 1;
			return reason;
		default:
			System.out.println("������Ʈ �ش���� ����");
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
		System.out.println("�� �̿��ڿ��� �ΰ��� �� ������ " + tariff_amount + "�� �Դϴ�.");
	}
}

class main_func {
	main_func(){};
	void createUser(Entrylist[] elist) throws IOException {
		
		String fbf = null;
        int fpassnum;
        int fage;
        int fentryday[] = {0,0,0}; 
        int fleaveday[] = {0,0,0};
        String fname, fregion, fseat;

		BufferedReader b = new BufferedReader(new FileReader("entry.txt"));
		String line = null;
		int i = 1;
		int j = 0;
		
		while ((line = b.readLine()) != null) {
			StringTokenizer tk = new StringTokenizer(line, "\t");
			String token = null;
			System.out.println(tk.countTokens());
			while (tk.hasMoreTokens()) {
				fbf = tk.nextToken();
				fpassnum = Integer.parseInt(fbf);
				fbf = null;
				fname = tk.nextToken();
				fbf = tk.nextToken();
				fage = Integer.parseInt(fbf);
				fbf = null;
				fregion = tk.nextToken();
				fseat = tk.nextToken();
				fbf = tk.nextToken();
				fentryday[0] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fentryday[1] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fentryday[2] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fleaveday[0] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fleaveday[1] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fleaveday[2] = Integer.parseInt(fbf);
				fbf = null;
				

				elist[j] = new Entrylist(fpassnum,fname,fage,fregion,fseat,fentryday,fleaveday);
			}
			i++;
			j++;
		}
		b.close();
	}

	void createban(Entrylist[] blist) throws IOException {

		String fbf = null;
        int fpassnum;
        int fage;
        int []fentryday = {0,0,0}; 
        int []fleaveday = {0,0,0};
        String fname, fregion, fseat;

		BufferedReader b = new BufferedReader(new FileReader("Illegal_resident.txt"));
		String line = null;
		int i = 1;
		int j = 0;
		
		while ((line = b.readLine()) != null) {
			StringTokenizer tk = new StringTokenizer(line, "\t");
			String token = null;
			System.out.println(tk.countTokens());
			while (tk.hasMoreTokens()) {
				fbf = tk.nextToken();
				fpassnum = Integer.parseInt(fbf);
				fbf = null;
				fname = tk.nextToken();
				fbf = tk.nextToken();
				fage = Integer.parseInt(fbf);
				fregion = tk.nextToken();
				fseat = tk.nextToken();
				fbf = tk.nextToken();
				fentryday[0] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fentryday[1] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fentryday[2] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fleaveday[0] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fleaveday[1] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fleaveday[2] = Integer.parseInt(fbf);
				fbf = null;
				
				//System.out.println(fpassnum+"\t"+ fname+"\t"+ fage+"\t"+ fregion+"\t"+ fseat+"\t"+ fentryday[0]+"\t"+fentryday[1]+"\t"+fentryday[2]+"\t"+ fleaveday[0]+"\t"+fleaveday[1]+"\t"+fleaveday[2]);
				blist[j] = new Entrylist(fpassnum, fname, fage, fregion, fseat, fentryday, fleaveday);
			}
			i++;
			j++;
		}
		b.close();
	}

	@SuppressWarnings("null")
	void createUser(Leavelist[] llist) throws IOException {

		String fbf = null;
        int fpassnum;
        int fage;
        int []fentryday = {0,0,0}; 
        int []fleaveday = {0,0,0};
        String fname, fregion, fseat;

		BufferedReader b = new BufferedReader(new FileReader("Illegal_resident.txt"));
		String line = null;
		int i = 1;
		int j = 0;
		
		while ((line = b.readLine()) != null) {
			StringTokenizer tk = new StringTokenizer(line, "\t");
			String token = null;
			System.out.println(tk.countTokens());
			while (tk.hasMoreTokens()) {
				fbf = tk.nextToken();
				fpassnum = Integer.parseInt(fbf);
				fbf = null;
				fname = tk.nextToken();
				fbf = tk.nextToken();
				fage = Integer.parseInt(fbf);
				fbf = null;
				fregion = tk.nextToken();
				fseat = tk.nextToken();
				fbf = tk.nextToken();
				fentryday[0] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fentryday[1] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fentryday[2] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fleaveday[0] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fleaveday[1] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				fleaveday[2] = Integer.parseInt(fbf);
				fbf = null;
				
				//System.out.println(fpassnum+"\t"+ fname+"\t"+ fage+"\t"+ fregion+"\t"+ fseat+"\t"+ fentryday[0]+"\t"+fentryday[1]+"\t"+fentryday[2]+"\t"+ fleaveday[0]+"\t"+fleaveday[1]+"\t"+fleaveday[2]);
				llist[i] = new Leavelist(fpassnum, fname, fage, fregion, fseat, fentryday, fleaveday);
			}
			i++;
			j++;
		}
		b.close();
	}
	@SuppressWarnings("null")
	void createFlightSchedule(Flightschedule[] fschedule) throws IOException{

		String fbf = null;
		String qairline;
		String qdestination;
        int qseat[] = {0,0,0};
        int qhour;
        String qshit;
        int qmin;

		BufferedReader b = new BufferedReader(new FileReader("Leave_Airplane.txt"));
		String line = null;
		int i = 1;
		int j = 0;
		
		while ((line = b.readLine()) != null) {
			StringTokenizer tk = new StringTokenizer(line, "\t");
			String token = null;
			System.out.println(tk.countTokens());
			while (tk.hasMoreTokens()) {
				qairline = tk.nextToken();
				qdestination = tk.nextToken();
				fbf = tk.nextToken();
				qseat[0] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				qseat[1] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				qseat[2] = Integer.parseInt(fbf);
				fbf = null;
				
				fbf = tk.nextToken();
				qhour = Integer.parseInt(fbf);
				fbf = null;
				
				qshit = tk.nextToken();
				fbf = tk.nextToken();
				qmin = Integer.parseInt(fbf);
				fbf = null;
				
				fschedule[j] = new Flightschedule(qairline, qdestination, qseat, qhour, qshit, qmin);
			}
			i++;
			j++;
		}
		b.close();
	}
        

	@SuppressWarnings("null")
	void leaveprocess(Leavelist llist[])
     {
        Blacklist bl = new Blacklist();
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
              System.out.println ( "error!! worng char keep process" ) ;
              System.out.println ("");
              break;
           }
        }
     }

	void leaveprocess(Entrylist elist[]) {
		Blacklist bl = new Blacklist();
		Tariff ta = new Tariff();
		int j;
		for (int i = 0; i < 200; i++) {
			j = 0;
			System.out.println("-----------------------------------------------");
			elist[i].showyou();
			j = bl.reason_print(elist[i].blacklist());
			if (j == 0) {
				elist[i].banitem_check();
				ta.Tairff_print(elist[i]);
				System.out.println("-Departure process completed-");

			}
			System.out.println("-----------------------------------------------");

			System.out.println("");
			System.out.println("Shall we proceed to the next person?   y/n");
			System.out.println("[Entry]:# ");
			Scanner s1 = new Scanner(System.in);

			switch (s1.nextLine().charAt(0)) {
			case 'n':
				System.out.println("");
				System.out.println("-Departure process program end-");
				System.out.println("-----------------------------------------------");
				return;
			case 'y':
				break;
			default:
				System.out.println("");
				System.out.println("error!! worng char keep process");
				System.out.println("");
				break;
			}
		}
	}

	void Airplainlist(Flightschedule fschedule[])
     {
		int i = 0;
        while (true)
        {
           System.out.println ( "Choose Schedule:");
           System.out.println ( "L. ��Leave Airline��");
           System.out.println ( "E. ��Entry Airline��");
           System.out.println ( "Q. ��Quit��" ) ;
           System.out.println ( "[Schedule]:# ");
           Scanner s1 = new Scanner(System.in);
           
           switch (s1.nextLine().charAt(0))
           {
           case'l':
           case'L':
        
              while (s1.nextLine().charAt(0)!= '\n');
              System.out.println ( "��Leave Airline��" ) ;
              System.out.println ( "\t"+ ( "�� Airline ��" ) +"\t"+ ( "�� Destination ��" ) +"\t"+ ( "�� First ��" ) +"\t"+ ( "�� Bussiness ��" ) +"\t"+ ( "�� Economy ��" ) +"\t"+ ( "�� Time ��" )) ;
              for (i = 0; i < 80; i++)
              {
                 fschedule[i].showthat();
              }
              break;
           case'e':
           case'E':
              while (s1.nextLine().charAt(0)!= '\n');
              System.out.println ( "\n��Entry Airline��") ;
              System.out.println ( "\t"+ ( "�� Airline ��" ) +"\t"+ ( "�� Destination ��" ) +"\t"+ ( "�� First ��" ) +"\t"+ ( "�� Bussiness ��" ) +"\t"+ ( "�� Economy ��" ) +"\t"+ ( "�� Time ��" )) ;
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
		public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		// Airport Control System Main Function
		// coding by Banetta Han Sang Kim

		Controltower ct = new Controltower();
		
		Scanner sc = new Scanner(System.in);
		main_func mf = new main_func();
		
		Flightschedule[] fs = new Flightschedule[100];
		Entrylist[] elist = new Entrylist[200];
		Leavelist[] llist = new Leavelist[200];
		Entrylist[] banlist = new Entrylist[30];

		System.out.println("===   Airport Control System [ACS]   ===\n");
		while (true) // Menu ����
		{
			// Menu ���
			System.out.println("=== Menu ===\n");
			System.out.println("i : File Input\n");
			System.out.println("e : Entry Process\n"); // �Ա� ����
			System.out.println("l : Leave Process\n"); // �ⱹ ����
			System.out.println("t : Today Airplain list\n"); // ���� ������ ���
			System.out.println("a : Airplain Access Management\n"); // �װ��� ������ ����
			System.out.println("o : OverEntryUser Check\n"); // �ҹ� ü���� üũ
			System.out.println("q : Quit Program\n"); // ���α׷� ����
			System.out.println("[ACS]:# \n");

			switch (sc.nextLine().charAt(0)) // menu switch�� : getchar()�� �̿�, ���ڸ� �޾Ƽ� ����
			{
			case 'i': // �̿��� ���� ���� �Է� �޴�
				//while (sc.nextLine().charAt(0) != '\n'); // getchar()���� ���ۿ� �Է°��� ���Ƽ� ���߽����� �� �� �ֱ� ������ ���۸� ���� �۾��� �Ѵ�.
				System.out.println("���� �װ��� ������ ������ �ҷ��ɴϴ�");
				mf.createFlightSchedule(fs);
				System.out.println("���� �װ��� ������ ���� �ҷ����� �Ϸ�");
				System.out.println("�̿��� ������ �ҷ��ɴϴ�");
				mf.createUser(elist);
				mf.createUser(llist);
				mf.createban(banlist);
				System.out.println("�̿��� ���� �ҷ����� �Ϸ�");
				break;
			case 'e': // �Ա� ���� �޴�
				//while (sc.nextLine().charAt(0) != '\n')
					; // ���۸� ���� �۾�.
				mf.leaveprocess(elist);
				break;
			case 'l': // �ⱹ ���� �޴�
				//while (sc.nextLine().charAt(0) != '\n')
					; // ���۸� ���� �۾�.
				mf.leaveprocess(llist);
				break;
			case 't': // ���� ������ ���
				//while (sc.nextLine().charAt(0) != '\n')
					; // ���۸� ���� �۾�.
				mf.Airplainlist(fs);
				break;
			case 'a': // ����� ������ ���� �޴�
				//while (sc.nextLine().charAt(0) != '\n')
					; // ���۸� ���� �۾�.
				mf.Airlinemanagement(fs, ct);
				break;
			case 'o': // �ҹ� ü���� üũ �޴�
				//while (sc.nextLine().charAt(0) != '\n')
					; // ���۸� ���� �۾�.
				mf.Illegal_resident(banlist);
				break;
			case 'q': // ���α׷� ���� �޴�
				//while (sc.nextLine().charAt(0) != '\n')
					; // ���۸� ���� �۾�.
				System.out.println("\n\n");
				System.out.println("end of program\n");
				return; // ���α׷� ����
			default: // error ��� ��� (�޴� �߸� �Է½�)
				//while (sc.nextLine().charAt(0) != '\n')
					; // ���۸� ���� �۾�.
				System.out.println("\nerror!! worng char\n");
				break;
			}
		}
	}

}